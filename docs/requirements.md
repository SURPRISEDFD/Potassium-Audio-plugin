# Potassium — 项目需求文档

## 项目概述
The God Particle 风格混音总线插件。核心特色：Gain Staging 甜点系统。

## 信号链
InputGain → ButterComp2 → PurestDrive → SmoothEQ3 → StereoFX → OutputGain

## 模块算法来源
| 模块 | 算法 | 许可 |
|------|------|------|
| InputGain | 自研（PurestGain 启发） | — |
| Compressor | AirWindows ButterComp2 | MIT |
| Saturator | AirWindows PurestDrive | MIT |
| EQ | AirWindows SmoothEQ3 | MIT |
| Stereo Widening | AirWindows StereoFX (Wide only) | MIT |
| OutputGain | 自研 | — |

## 未来计划
- Phase 2: "Push" 大旋钮 (0-200%)，整合 Comp+Sat+Stereo→一个 knob
- Phase 3: WebView UI
- Phase 4: VST3 封装发布

## 甜点范围
- Solo Kick: -12 dB
- Full Mix: -6 ~ -5 dB
