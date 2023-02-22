// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class UEExamplesTarget : TargetRules
{
	public UEExamplesTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_1;
		ExtraModuleNames.Add("UEExamples");
		
		ApplySharedTargetSettings(this);
	}

	/// <summary>
	/// 统一设置Target，自定义编译策略
	/// </summary>
	/// <param name="Target"></param>
	internal static void ApplySharedTargetSettings(TargetRules Target)
	{
		bool bIsTest = Target.Configuration == UnrealTargetConfiguration.Test;
		bool bIsShipping = Target.Configuration == UnrealTargetConfiguration.Shipping;
		bool bIsDedicatedServer = Target.Type == TargetType.Server;
		if (Target.BuildEnvironment == TargetBuildEnvironment.Unique)
		{
			Target.bUseLoggingInShipping = true;
			Target.ShadowVariableWarningLevel = WarningLevel.Error;
			if (bIsShipping && !bIsDedicatedServer)
			{
				//Target.bDisableUnverifiedCertificates = true;
			}
			if (bIsShipping || bIsTest)
			{
				// Disable reading generated/non-ufs ini files
				Target.bAllowGeneratedIniWhenCooked = false;
				Target.bAllowNonUFSIniWhenCooked = false;
			}
			if (Target.Type != TargetType.Editor)
			{
				// We don't use the path tracer at runtime, only for beauty shots, and this DLL is quite large
				Target.DisablePlugins.Add("OpenImageDenoise");
			}
			ConfigureGameFeaturePlugins(Target);
		}
		else
		{
			if (Target.Type == TargetType.Editor)
			{
				ConfigureGameFeaturePlugins(Target);
			}
		}
	}

	/// <summary>
	/// 处理GameFeature加载策略
	/// </summary>
	/// <param name="Target"></param>
	static public void ConfigureGameFeaturePlugins(TargetRules Target)
	{
		
	}
}
