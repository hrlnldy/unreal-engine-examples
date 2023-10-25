#include "MineHttpHelper.h"

#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"

void FMineHttpUtil::Get(const FString& Url, FOnGetUrl Delegate)
{
	Get(Url, TMap<FString, FString>(), Delegate);
}

void FMineHttpUtil::Get(const FString& Url, const TMap<FString, FString>& Headers, FOnGetUrl Delegate)
{
	const FHttpRequestRef HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetURL(Url);
	// set Headers
	for (const auto& Header : Headers)
	{
		HttpRequest->SetHeader(Header.Key, Header.Value);
	}
	HttpRequest->OnProcessRequestComplete().BindLambda([Delegate]
		(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
	{
		// ReSharper disable once CppExpressionWithoutSideEffects
		Delegate.ExecuteIfBound(bSucceeded, HttpResponse.IsValid()?HttpResponse->GetContentAsString():TEXT(""));
	});

	HttpRequest->ProcessRequest();
}

void FMineHttpUtil::Post(const FString& Url, FOnGetUrl Delegate)
{
	Post(Url, TMap<FString, FString>(), TArray<uint8>(), Delegate);
}

void FMineHttpUtil::Post(const FString& Url, const TMap<FString, FString>& Headers, TArray<uint8> PostContent,
	FOnGetUrl Delegate)
{
	const FHttpRequestRef HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetURL(Url);
	// set headers
	for (const auto& Header : Headers)
	{
		HttpRequest->SetHeader(Header.Key, Header.Value);
	}
	HttpRequest->SetContent(PostContent);
	HttpRequest->SetVerb(TEXT("POST"));
	HttpRequest->OnProcessRequestComplete().BindLambda([Delegate]
	(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
	{
		if (bSucceeded && HttpResponse.IsValid())
		{
			// ReSharper disable once CppExpressionWithoutSideEffects
			Delegate.ExecuteIfBound(bSucceeded, HttpResponse.IsValid()?HttpResponse->GetContentAsString():TEXT(""));
		}
	});

	HttpRequest->ProcessRequest();
}
