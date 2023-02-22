// Fill out your copyright notice in the Description page of Project Settings.


#include "MineBlueprintLibrary.h"

#include "Android/AndroidPlatformApplicationMisc.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Windows/WindowsApplication.h"


bool UMineBlueprintLibrary::IsGameWorld(UObject* WorldContextObject)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);

	return World && World->IsGameWorld();
}

AGameModeBase* UMineBlueprintLibrary::GetGameMode(UObject* WorldContextObject)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	check(World);
	return  World->GetAuthGameMode();
}

bool UMineBlueprintLibrary::IsServer(UObject* WorldContextObject)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);

	return World->GetNetMode() != ENetMode::NM_DedicatedServer;
}

void UMineBlueprintLibrary::Quit(UObject* WorldContextObject)
{
	UKismetSystemLibrary::QuitGame(WorldContextObject, nullptr, EQuitPreference::Quit, true);

	// Or

	FPlatformMisc::RequestExit(true);
}

