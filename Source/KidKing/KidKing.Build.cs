// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class KidKing : ModuleRules
{
	public KidKing(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] {
			"Core", "CoreUObject", "Engine",
			"InputCore", "EnhancedInput",
			"UMG",
			"NavigationSystem",
			"AIModule",
			"GameplayAbilities", "GameplayTags", "GameplayTasks"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		PrivateDependencyModuleNames.AddRange(new string[] {
			"Slate",
			"SlateCore",
			"GameplayAbilities",
			"GameplayTags",
			"GameplayTasks"
		});

		// Uncomment if you are using online features
		PrivateDependencyModuleNames.Add("OnlineSubsystem");
		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true


		PublicIncludePaths.AddRange(new string[] {
			"KidKing/",
			"KidKing/Animation/",
			"KidKing/BlueprintFunctionLibrary/",
			"KidKing/Bot/",
			"KidKing/Character/",
			"KidKing/Widget/",
			"KidKing/Core/",
			"KidKing/Items/",
			"KidKing/Ability/"
		});

	}
}
