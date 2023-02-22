#include "MineHttpHelper.h"

#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"

void MineHttpHelper::Get(const FString& Url, TFunction<void(FString Str)> Delegate)
{
	FHttpRequestRef HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetURL(Url);
	HttpRequest->OnProcessRequestComplete().BindLambda([Delegate]
		(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
	{
		if (bSucceeded && HttpResponse.IsValid())
		{
			Delegate(HttpResponse->GetContentAsString());
		}
	});

	HttpRequest->ProcessRequest();

}

void MineHttpHelper::Post(const FString& Url, TFunction<void(FString Str)> Delegate)
{
	FHttpRequestRef HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetURL(Url);
	HttpRequest->SetVerb(TEXT("POST"));
	HttpRequest->OnProcessRequestComplete().BindLambda([Delegate]
	(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
	{
		if (bSucceeded && HttpResponse.IsValid())
		{
			Delegate(HttpResponse->GetContentAsString());
		}
	});

	HttpRequest->ProcessRequest();
}
