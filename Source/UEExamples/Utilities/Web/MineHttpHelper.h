#pragma once

class FMineHttpUtil
{
	DECLARE_DELEGATE_TwoParams(FOnGetUrl, bool, FString);

public:
	/**
	 * Send 'get' request to Url
	 * @param Url 
	 * @param Delegate 
	 */
	static void Get(const FString& Url, FOnGetUrl Delegate);
	static void Get(const FString& Url, const TMap<FString, FString>& Headers, FOnGetUrl Delegate);

	/**
	 * Send 'post' request to Url
	 * @param Url 
	 * @param Delegate 
	 */
	static void Post(const FString& Url, FOnGetUrl Delegate);
	static void Post(const FString& Url, const TMap<FString, FString>& Headers, TArray<uint8> PostContent,  FOnGetUrl Delegate);
};
