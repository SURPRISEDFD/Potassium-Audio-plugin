==========================================
  Potassium v0.9
  Mix Bus Processor
  Ium Audio
==========================================

安装方法：
  把 Potassium.vst3 整个文件夹复制到：
  C:\Program Files\Common Files\VST3\

  重启 DAW，搜索 "Potassium" 即可加载。

信号链：
  InputGain → ButterComp2 → Drive(PurestDrive) → SmoothEQ3 → StereoFX → Limiter → OutputGain

参数：
  Push      0-200%  主控强度 (联动 Comp/Drive/Wide)
  Dark      0~+6dB  低频增强
  Bright    0~+6dB  中频增强
  Air       0~+6dB  高频增强
  Limit Gain 0~+12dB  限制器输入增益
  Input Gain -12~+12dB
  Output Gain -24~+24dB
  Oversampling  Off/2x/4x/8x (默认4x)

甜点值 (Push=100%):
  Comp 0.40, Drive 0.50, Wide 0.50

已知限制：
  - UI 使用系统通用控件 (WebView UI 开发中)
  - 仅支持 VST3 / 立体声
  - Windows 10/11 64-bit

反馈请联系开发者。
