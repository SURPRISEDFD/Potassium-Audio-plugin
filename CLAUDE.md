# CLAUDE.md — Potassium 项目

## 项目概述
The God Particle 风格混音总线插件 VST3。JUCE 8.0.14 + C++20。

## 标准文件路径
- 项目需求: `docs/requirements.md`
- 技术规范: `docs/technical-spec.md`
- 开发计划: `docs/development-plan.md`
- 开发日志: `devlog/YYYY-MM-DD.md`

## 构建命令
```bash
# 用 VS 2026 生成
cmake -G "Visual Studio 18 2026" -DJUCE_ROOT="C:/H/Program Files/juce-8.0.14-windows/JUCE" /c/PotassiumProj
cmake --build . --config Release
```

## 源文件
- 主处理器: `Source/PluginProcessor.h`, `Source/PluginProcessor.cpp`
- 编辑器: `Source/PluginEditor.h`, `Source/PluginEditor.cpp`
- 入口: `Source/createPluginFilter.cpp`
- DSP 模块: `Source/dsp/*.h`
- 构建系统: `CMakeLists.txt`

## 工作原则
1. 每次修改后同步源码到 `/c/PotassiumProj/Source/` 再编译
2. VST3 输出: `/c/PotassiumBuild/Potassium_artefacts/Release/VST3/Potassium.vst3`
3. 项目副本: `/c/PotassiumProj/` (纯英文路径，避免 CMake 中文路径 bug)
4. 每天结束时更新 devlog
5. 编译前关闭 DAW/PluginDoctor（文件锁）
