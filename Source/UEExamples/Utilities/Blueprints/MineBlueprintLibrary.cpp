// Fill out your copyright notice in the Description page of Project Settings.


#include "MineBlueprintLibrary.h"


bool UMineBlueprintLibrary::IsGameWorld(UObject* WorldContextObject)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);

	return World && World->IsGameWorld();
}

bool UMineBlueprintLibrary::GetGameMode(UObject* WorldContextObject)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);

	return World && World->IsGameWorld();
}
