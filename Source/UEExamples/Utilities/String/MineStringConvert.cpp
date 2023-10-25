#include "MineStringConvert.h"

const char* FStringConvert::ToUTF8(const FString& Text)
{
	return reinterpret_cast<const char*>(StringCast<UTF8CHAR>(*Text).Get());
}

void FStringConvert::ToUTF8(const FString& Text, TArray<uint8>& OutUtf8)
{
	const int32 DestLen = FPlatformString::ConvertedLength<UTF8CHAR>(*Text, Text.Len());
	if (DestLen > 0)
	{
		OutUtf8.AddUninitialized(DestLen);
		FPlatformString::Convert<TCHAR, UTF8CHAR>(reinterpret_cast<UTF8CHAR*>(OutUtf8.GetData()), DestLen, *Text, DestLen);
	}
}
