#include "MineStringUtil.h"

TSharedPtr<FJsonObject> FMineStringUtil::ToJson(const FString& Text)
{
	TSharedPtr<FJsonObject> JsonObj = MakeShared<FJsonObject>();
	// 可以使用MoveTemp(Text)提高性能
	TSharedRef<TJsonReader<TCHAR>> Reader = FJsonStringReader::Create(Text);
	if (FJsonSerializer::Deserialize(Reader, JsonObj))
	{
		return JsonObj;
	}
	return nullptr;
}

FString FMineStringUtil::FromJson(TSharedPtr<FJsonObject>& Json)
{
	FString OutJsonString;
	auto JsonWriter = TJsonWriterFactory<TCHAR, TPrettyJsonPrintPolicy<TCHAR>>::Create(&OutJsonString);
	FJsonSerializer::Serialize(Json.ToSharedRef(), JsonWriter);

	return OutJsonString;
}

TArray<uint8> FMineStringUtil::ToUTF8(const FString& Text)
{

	//
	TCHAR_TO_UTF8(*Text);

	// Or
	
	const auto Out = FTCHARToUTF8(*Text, Text.Len());
	auto Utf8Str = Out.Get();
	auto Len = Out.Length();

	// Or

	int32 Utf8Length = FTCHARToUTF8_Convert::ConvertedLength(*Text, Text.Len()); 
	TArray<uint8> Buffer; 
	Buffer.SetNumUninitialized(Utf8Length); 
	FTCHARToUTF8_Convert::Convert((ANSICHAR*)Buffer.GetData(), Buffer.Num(), *Text, Text.Len());

	return Buffer;
}

FString FMineStringUtil::FromUTF8(const TArray<uint8>& Utf8)
{
	//
	UTF8_TO_TCHAR(Utf8.GetData());

	// Or
	auto CharStr = FUTF8ToTCHAR((const ANSICHAR*)Utf8.GetData(), Utf8.Num()); 
	FString Str = FString(CharStr.Length(), CharStr.Get());

	// Or

	TArray<TCHAR> ResultArray;
	int32 Len = FUTF8ToTCHAR_Convert::ConvertedLength(reinterpret_cast<const ANSICHAR*>(Utf8.GetData()), Utf8.Num());
	ResultArray.AddUninitialized(Len + 1); // +1 for the null terminator
	FUTF8ToTCHAR_Convert::Convert(ResultArray.GetData(), ResultArray.Num(), reinterpret_cast<const ANSICHAR*>(Utf8.GetData()), Utf8.Num());
	ResultArray[Len] = TEXT('\0');

	return FString(ResultArray.GetData());
}
