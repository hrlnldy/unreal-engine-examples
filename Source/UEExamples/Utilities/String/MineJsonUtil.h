// Copyright © hrlnldy@163.com 2023. All rights reserved.

#pragma once

class FMineJsonUtil
{
public:
	/**
	 * String to json
	 * @param Text 
	 * @return 
	 */
	static TSharedPtr<FJsonObject> ToJson(const FString& Text);
	static TSharedPtr<FJsonObject> ToJson(FString&& Text);

	/**
	 * Json to string
	 * @param Json 
	 * @return 
	 */
	static FString FromJson(const TSharedPtr<FJsonObject>& Json);
	static bool FromJson(const TSharedPtr<FJsonObject>& Json, FString& OutJsonString);
};
