# Potassium — 技术规范

## 框架
- JUCE 8.0.14
- C++20
- VST3 only, Stereo only

## 构建
```bash
cmake -G "Visual Studio 18 2026" -DJUCE_ROOT="C:/H/Program Files/juce-8.0.14-windows/JUCE" /c/PotassiumProj
cmake --build . --config Release
```

## 参数列表
| ID | 名称 | 范围 | 默认 | 说明 |
|----|------|------|------|------|
| inputGain | Input Gain | -12~+12 dB | 0 | 输入增益 |
| compThreshold | Comp Threshold | 0~1 | 0.5 | ButterComp2 压缩量 |
| compRelease | Comp Release | 0~1 | 0.5 | (ButterComp2 不使用) |
| compCharacter | Comp Character | -1~+1 | 0.5 | 干湿比 |
| satDrive | Sat Drive | 0~1 | 0.2 | PurestDrive 强度 |
| satCharacter | Sat Character | 0~1 | 0.5 | (PurestDrive 不使用) |
| eqLowShelf | EQ Low | -6~+6 dB | 0 | SmoothEQ3 bass |
| eqHighShelf | EQ High | -6~+6 dB | 0 | SmoothEQ3 treble |
| stereoWide | Stereo Wide | 0~1 | 0 | StereoFX width |
| density | Density | 0~1 | 0 | 缩放 Sat Drive |
| outputGain | Output Gain | -24~+24 dB | 0 | 输出增益 |
| overMode | Oversampling | Off/2x/4x | Off | 过采样 |
| bypass | Bypass | On/Off | Off | 旁路 |

## 仪表参数（只读）
- sweetSpot (0~1)
- limiterGR (0~24 dB) — 已移除 Limiter，保留参数兼容
- inputLevel (-60~0 dB)

## DSP 模块文件
```
Source/dsp/
  OversamplingStage.h
  InputGainStage.h
  CompressorStage.h   → ButterComp2
  SaturatorStage.h    → PurestDrive
  EQStage.h           → SmoothEQ3
  StereoWidthStage.h  → StereoFX
  OutputGainStage.h
```
