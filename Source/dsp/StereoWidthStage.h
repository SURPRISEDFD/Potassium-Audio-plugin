#pragma once
#include <juce_dsp/juce_dsp.h>
#include <cmath>

/**
 * Stereo Width — PurestDrive saturation on Side channel (original colour)
 * + subtle 2kHz+ high-shelf lift on Side for extra air/spread.
 * M/S → Side saturation + HF boost → L/R reconstruct.
 */
class StereoWidthStage
{
public:
    StereoWidthStage() = default;

    void prepare(double sr, int) {
        // 1st-order highpass at 2kHz for Side HF shelf
        double w0 = 2.0 * 3.14159265358979 * 2000.0 / sr;
        hpCoeff = std::exp(-w0);
    }

    void reset() { prevSide = 0.0; hpState = 0.0; }
    void setWidth(float w) { wide = juce::jlimit(0.0f, 1.0f, w); }

    void process(juce::dsp::AudioBlock<float>& block) {
        auto ns = block.getNumSamples();
        if (block.getNumChannels() < 2 || wide < 0.001f) return;

        float sideGain = 1.0f + wide * 0.33f;   // original saturation drive
        float satAmt   = wide * 0.25f;            // original saturation amount
        float hfBoost  = 1.0f + wide * 0.20f;     // 2kHz+ Side lift, max ~+1.7dB

        for (int s = 0; s < (int)ns; ++s) {
            float L = block.getChannelPointer(0)[s];
            float R = block.getChannelPointer(1)[s];

            float mid  = (L + R) * 0.5f;
            float side = (L - R) * 0.5f;

            // ── Original PurestDrive saturation on Side (preserved) ──
            float drySide = side * sideGain;
            float wetSide = std::sin(drySide);
            float apply = std::fabs(prevSide + wetSide) * 0.5f * satAmt;
            side = drySide * (1.0f - apply) + wetSide * apply;
            prevSide = std::sin(drySide);

            // ── Subtle 2kHz+ lift on Side (new) ──
            double hp = side - hpState;
            hpState += hpCoeff * hp;
            side += (hfBoost - 1.0f) * (float)hp;

            block.getChannelPointer(0)[s] = mid + side;
            block.getChannelPointer(1)[s] = mid - side;
        }
    }

private:
    float wide = 0.0f;
    double prevSide = 0.0;
    double hpCoeff = 0.0, hpState = 0.0;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(StereoWidthStage)
};
