// Copyright © hrlnldy@163.com 2023. All rights reserved.

#pragma once

#include "CoreMinimal.h"

class FStringConvert
{
public:
	/**
	 * String to UTF8
	 * @param Text 
	 * @return 
	 */
	static const char* ToUTF8(const FString& Text);
	static void ToUTF8(const FString& Text, TArray<uint8>& OutUtf8);
};
