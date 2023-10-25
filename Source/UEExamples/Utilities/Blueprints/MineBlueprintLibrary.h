// Copyright © hrlnldy@163.com 2023. All rights reserved.


#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MineBlueprintLibrary.generated.h"

/**
 * 
 */
UCLASS()
class UEEXAMPLES_API UMineBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// UFUNCTION(BlueprintCallable, Category = "Utilities", meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	// UFUNCTION(BlueprintCallable, Category = "Utilities", meta = (WorldContext = "WorldContextObject"))

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static bool IsGameWorld(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static AGameModeBase* GetGameMode(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static bool IsServer(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static void Quit(UObject* WorldContextObject);
};
