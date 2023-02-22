// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

/// <summary>
/// TargetRules 定义描述了整个程序的编译目标；
/// TargetType指定了目标类型如：Game、Editor（编辑器模式）、Client、Server等，Target可以在编译器中指定
/// </summary>
public class UEExamplesEditorTarget : TargetRules
{
	public UEExamplesEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_1;
		
		// 列出程序编译的模块。
		ExtraModuleNames.AddRange(new []{"UEExamples", "UEExamplesEditor"});

		UEExamplesTarget.ApplySharedTargetSettings(this);
	}
}
