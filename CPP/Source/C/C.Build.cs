// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class C : ModuleRules
{
	public C(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"C",
			"C/Variant_Platforming",
			"C/Variant_Platforming/Animation",
			"C/Variant_Combat",
			"C/Variant_Combat/AI",
			"C/Variant_Combat/Animation",
			"C/Variant_Combat/Gameplay",
			"C/Variant_Combat/Interfaces",
			"C/Variant_Combat/UI",
			"C/Variant_SideScrolling",
			"C/Variant_SideScrolling/AI",
			"C/Variant_SideScrolling/Gameplay",
			"C/Variant_SideScrolling/Interfaces",
			"C/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
