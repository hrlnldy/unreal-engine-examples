#pragma once

/**
 * void AsyncTask(ENamedThreads::Type Thread, TUniqueFunction<void()> Function)
 * 在指定线程开始异步任务，主线程，或者其它线程, 其实是一种 TGraphTask
 * 
 * TGraphTask	高性能多线程框架，可以管理任务之间的依赖关系和优先级。TGraphTask 需要使用 CreateTask 和 ConstructAndDispatchWhenReady 方法来创建和分发任务，并且需要指定任务的优先级和所属线程池。
 *
 * 与FAsyncTask的异同
 * FAsyncTask 和 TGraphTask 都是 UE4 中的多线程类，用于执行异步任务。
 * FAsyncTask 是一个模板类，可以继承并重写 DoWork 方法来定义任务的逻辑。 FAsyncTask 可以在任何线程中创建和启动，但只能在主线程中销毁。1 FAsyncTask 的生命周期由调用者负责，可以使用 IsDone、WaitCompletionWithTimeout、EnsureCompletion 等方法来控制任务的状态。
 * TGraphTask 是一个封装了用户定义任务的类，用于在 Task Graph 系统中执行任务。 Task Graph 系统是 UE4 中的一个高性能多线程框架，可以管理任务之间的依赖关系和优先级。 TGraphTask 需要使用 CreateTask 和 ConstructAndDispatchWhenReady 方法来创建和分发任务，并且需要指定任务的优先级和所属线程池。
 * FAsyncTask 和 TGraphTask 的区别主要在于：FAsyncTask 更简单易用，但不支持任务之间的依赖关系；TGraphTask 更灵活高效，但需要使用 Task Graph 系统来管理任务。
 */ 

class FMineGraphTask
{
public:
	/**
	 * 在主线程开启异步任务
	 */
	void StartGameThreadAsyncTask();

	/**
	 * 异步任务后返回主线程
	 */
	void StartAsyncTaskBackToGame();
};
