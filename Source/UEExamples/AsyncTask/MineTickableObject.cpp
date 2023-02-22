#include "MineTickableObject.h"

void FMineTickableObject::Tick(float DeltaTime)
{
}

TStatId FMineTickableObject::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(FMineTickableObject, STATGROUP_Tickables);
}