#pragma once

class MineHttpHelper
{
public:

	void Get(const FString&Url, TFunction<void(FString Str)> Delegate);

	void Post(const FString&Url, TFunction<void(FString Str)> Delegate);
};
