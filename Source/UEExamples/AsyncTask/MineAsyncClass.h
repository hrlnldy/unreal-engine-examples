#pragma once

#include "Containers/Ticker.h"

/**
 * FTSTicker::GetCoreTicker() Tick, 无需获取 WorldContex
 */
class MineAsyncClass
{
	FTSTicker::FDelegateHandle TickDelegateHandle;
	FTickerDelegate TickDelegate;
public:
	
	void StartTimer();
	bool HandleTicker(float DeltaTime);
};
