#pragma once

class FMineStringUtil
{
public:
	TSharedPtr<FJsonObject> ToJson(const FString& Text);

	FString FromJson(TSharedPtr<FJsonObject>& Json);

	TArray<uint8> ToUTF8(const FString& Text);

	FString FromUTF8(const TArray<uint8>& Utf8);
};
