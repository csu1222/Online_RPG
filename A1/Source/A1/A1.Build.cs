// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class A1 : ModuleRules
{
	public A1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Sockets", "Networking", "EnhancedInput" });

		PrivateDependencyModuleNames.AddRange(new string[] { "ProtobufCore" });

		PrivateIncludePaths.AddRange(new string[] 
		{ 
			"A1/",
			"A1/Network",
            "A1/Game/",
        });
    }
}
