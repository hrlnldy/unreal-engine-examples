#include "MineAsyncTask.h"

void FMineAsyncTask::DoWork()
{
	
	// Your code
}

void FMineAsyncTask::StartTask()
{
	//开启后台任务

	FAsyncTask<FMineAsyncTask>* Task = new FAsyncTask<FMineAsyncTask>( 5 );
	Task->StartBackgroundTask();

	//--or --

	// 同步任务，运行等待完成
	Task->StartSynchronousTask();

	
	// 这里不可以轮询，可以每帧一次
	if (Task->IsDone())
	{
	}

	//Ensure the task is done, doing the task on the current thread if it has not been started, waiting until completion in all cases.

	Task->EnsureCompletion();
	delete Task;
}
