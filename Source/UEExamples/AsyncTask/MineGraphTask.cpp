#include "MineGraphTask.h"

void FMineGraphTask::StartGameThreadAsyncTask()
{
	AsyncTask(ENamedThreads::GameThread, []()
	{
		// Your code
	});
}

void FMineGraphTask::StartAsyncTaskBackToGame()
{
	AsyncTask(ENamedThreads::AnyHiPriThreadNormalTask, []()
	{
		// Do the actual I/O on the background thread
		TArray<uint8> ObjectBytes;
		FString FileContent;
		FFileHelper::LoadFileToString(FileContent, TEXT("1.txt"));

		// Now schedule the serialize and callback on the game thread
		AsyncTask(ENamedThreads::GameThread, [FileContent]()
		{
			// Your code
		});
	});
}
