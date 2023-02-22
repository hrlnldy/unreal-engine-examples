// Fill out your copyright notice in the Description page of Project Settings.


#include "MineAsyncObject.h"

void UMineAsyncObject::StartTimer()
{
	bool bIsLoopTimer = false;
	// InFirstDelay 决定了定时器第一次执行的延迟时间，< 0.f 第一次执行时间为 InRate
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, []
	{
		// Your code
	}, 0.5f, bIsLoopTimer, -1.f);
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);

	GetWorld()->GetTimerManager().PauseTimer(TimerHandle);
	GetWorld()->GetTimerManager().UnPauseTimer(TimerHandle);
}

void UMineAsyncObject::ExecuteNextTick()
{
	GetWorld()->GetTimerManager().SetTimerForNextTick([]
	{
		// Your code
	});
}
