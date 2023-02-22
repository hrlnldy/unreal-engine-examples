#include "MineAsyncClass.h"

void MineAsyncClass::StartTimer()
{
	// 绑定委托
	TickDelegate.BindRaw(this, &MineAsyncClass::HandleTicker);
	TickDelegate = FTickerDelegate::CreateRaw(this, &MineAsyncClass::HandleTicker);

	// 定时器
	TickDelegateHandle = FTSTicker::GetCoreTicker().AddTicker(TickDelegate, 4.0f);
	FTSTicker::GetCoreTicker().RemoveTicker(TickDelegateHandle);
}
bool MineAsyncClass::HandleTicker( float DeltaTime )
{
	return false;
}
