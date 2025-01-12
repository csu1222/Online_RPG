// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class OnlineRPG : ModuleRules
{
	public OnlineRPG(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Sockets", "Networking", "EnhancedInput" });

		PrivateDependencyModuleNames.AddRange(new string[] { "ProtobufCore" });

		PrivateIncludePaths.AddRange(new string[] 
		{ 
			"OnlineRPG/", 
			"OnlineRPG/Network/",
            "OnlineRPG/Game/",
        });

	}
}
