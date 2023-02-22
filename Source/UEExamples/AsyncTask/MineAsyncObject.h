// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MineAsyncObject.generated.h"

/**
 * GetWorld()->GetTimerManager() 异步任务，需要获取 WorldContext
 */
UCLASS()
class UEEXAMPLES_API UMineAsyncObject : public UObject
{
	GENERATED_BODY()

	FTimerHandle TimerHandle;
public:
	
	/**
	 * 定时器 或 Delay 执行
	 */
	void StartTimer();
	/**
	 * 下一帧执行
	 */
	void ExecuteNextTick();
};