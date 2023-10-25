#include "MineJsonUtil.h"

TSharedPtr<FJsonObject> FMineJsonUtil::ToJson(const FString& Text)
{
	TSharedPtr<FJsonObject> JsonObj = MakeShared<FJsonObject>();
	const TSharedRef<TJsonReader<TCHAR>> Reader = FJsonStringReader::Create(Text);
	if (FJsonSerializer::Deserialize(Reader, JsonObj))
	{
		return JsonObj;
	}
	return nullptr;
}

TSharedPtr<FJsonObject> FMineJsonUtil::ToJson(FString&& Text)
{
	TSharedPtr<FJsonObject> JsonObj = MakeShared<FJsonObject>();
	const TSharedRef<TJsonReader<TCHAR>> Reader = FJsonStringReader::Create(MoveTemp(Text));
	if (FJsonSerializer::Deserialize(Reader, JsonObj))
	{
		return JsonObj;
	}
	return nullptr;
}

FString FMineJsonUtil::FromJson(const TSharedPtr<FJsonObject>& Json)
{
	FString OutJsonString;
	const auto JsonWriter = TJsonWriterFactory<TCHAR, TPrettyJsonPrintPolicy<TCHAR>>::Create(&OutJsonString);
	FJsonSerializer::Serialize(Json.ToSharedRef(), JsonWriter);

	return OutJsonString;
}

bool FMineJsonUtil::FromJson(const TSharedPtr<FJsonObject>& Json, FString& OutJsonString)
{
	const auto JsonWriter = TJsonWriterFactory<TCHAR, TPrettyJsonPrintPolicy<TCHAR>>::Create(&OutJsonString);
	return  FJsonSerializer::Serialize(Json.ToSharedRef(), JsonWriter);
}