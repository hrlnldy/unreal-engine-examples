// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

/// <summary>
/// ModuleRules 定义单个模块的编译选项、依赖性。一个游戏可有用多个模块，插件也是模块。
/// 游戏可以可以包含多个非游戏模块
/// https://zhuanlan.zhihu.com/p/45398694
/// https://docs.unrealengine.com/5.1/zh-CN/module-properties-in-unreal-engine/
/// </summary>
public class UEExamples : ModuleRules
{
	public UEExamples(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
