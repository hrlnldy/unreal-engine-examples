// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;


public class UEExamplesEditor : ModuleRules
{
	public UEExamplesEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UEExamples"});

		PrivateDependencyModuleNames.AddRange(new string[] {  });
	}
}