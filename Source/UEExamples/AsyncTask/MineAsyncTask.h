#pragma once

/**
 * 不可中断任务
 */
class FMineAsyncTask : public FNonAbandonableTask
{
public:
	friend class FAsyncTask<FMineAsyncTask>;

	int32 ExampleData;

	FMineAsyncTask(int32 InExampleData)
	 : ExampleData(InExampleData)
	{
	}

	void DoWork();

	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(FMineAsyncTask, STATGROUP_ThreadPoolAsyncTasks);
	}
	

	static void StartTask();
};
