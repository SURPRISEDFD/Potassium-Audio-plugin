# Potassium — 开发执行计划

## Phase 1: 原型机 ✅
- [x] DSP 模块实现
- [x] 参数系统
- [x] VST3 编译
- [x] 甜点检测系统

## Phase 1.5: DSP 算法替换（当前）
- [x] Compressor → ButterComp2
- [x] Saturator → PurestDrive
- [ ] EQ → SmoothEQ3 (待修复)
- [x] Stereo Widening → StereoFX (Wide only)
- [ ] 移除问题 Limiter

## Phase 2: Push 大旋钮
将 Comp + Sat + Stereo 三个参数映射到一个 "Push" knob (0-200%)
- 0% = bypass
- 100% = 原型机调试好的默认值
- 200% = 极限推动

## Phase 3: UI
- WebView 框架搭建
- 原始 UI 草图 → WebView 实现
- 仪表显示

## Phase 4: 发布
- 最终测试
- 打包发布
