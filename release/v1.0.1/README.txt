==========================================
  Potassium v1.0.1
  Mix Bus Processor — Ium Audio
==========================================

Changelog:
  v1.0.1: 修复状态保存, UI Zoom 按钮组, 窗口缩放
  v1.0.0: 首次正式发布

信号链:
  InputGain -> ButterComp2 -> Drive(PurestDrive) -> SmoothEQ3 -> StereoFX -> Limiter -> OutputGain

算法来源 (AirWindows):
  ButterComp2   — 双极性四态交错压缩器 (by Chris Johnson)
  PurestDrive   — sin() 波形塑形饱和器 (by Chris Johnson)
  SmoothEQ3     — 三段式 EQ, 分频 200Hz/4kHz, 三阶 Butterworth (by Chris Johnson)
  以上算法来自 AirWindows 开源库, 经适配用于 Potassium 信号链

安装:
  把 Potassium.vst3 整个文件夹复制到:
    C:\Program Files\Common Files\VST3\
  重启 DAW.

参数:
  Push        0-200%    主控强度 (同步控制 Comp/Drive/Wide)
  Dark        0~+6dB    低频增强 (200Hz 以下)
  Bright      0~+6dB    中频增强 (200Hz-4kHz)
  Air         0~+6dB    高频增强 (4kHz 以上)
  Limit Gain  0~+12dB   限制器输入增益 (透明砖墙)
  Input Gain  -12~+12dB
  Output Gain -24~+24dB
  Oversampling Off/2x/4x/8x

甜点 (Push=100%):
  Comp 0.40, Drive 0.50, Wide 0.50

UI控件:
  ZOOM 按钮在右下角 - 75/100/125/200 (同步缩放窗口 + 内容)
  OVER 按钮 - Off/2x/4x/8x 过采样

系统要求:
  Windows 10/11 64-bit, VST3
  WebView2 Runtime (Win11自带, Win10需安装)

==========================================
  (c) 2026 Ium Audio
==========================================
