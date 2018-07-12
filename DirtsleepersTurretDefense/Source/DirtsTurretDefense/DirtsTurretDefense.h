// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "General/Core/TurretDefenseGameInstance.h"
#include "Kismet/GameplayStatics.h"

#include "CoreMinimal.h"

template<typename T>
static FORCEINLINE T* GetRandomItem(const TArray<T*>& Array)
{
	return Array[FMath::RandRange(0, Array.Num() - 1)];
}

template<typename TEnum>
static FORCEINLINE FString EnumAsString(const FString& Name, TEnum Value, const FString& Prefix = FString(""), bool bSpaceCamelCase = false)
{
	const UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, *Name, true);
	if (!enumPtr)
	{
		return FString("Invalid");
	}
	FString enumString = enumPtr->GetNameByValue((int64)Value).ToString();
	enumString.ReplaceInline(*(Name + FString("::")), TEXT(""));
	if (Prefix != FString(""))
	{
		enumString.ReplaceInline(*Prefix, TEXT(""));
	}
	enumString.ReplaceInline(TEXT("_"), TEXT(" "));
	if (bSpaceCamelCase)
	{
		FString newString = FString(enumString.Mid(0, 1));
		for (int32 i = 1; i < enumString.Len(); i++)
		{
			FString curChar = enumString.Mid(i, 1);
			if (curChar.Equals(curChar.ToUpper()))
			{
				newString += TEXT(" ");
			}
			newString += curChar;
		}
		return newString;
	}
	return enumString;
}

template<typename T>
static FORCEINLINE TArray<T> EnumGetList(const FString& enumName)
{
	TArray<T> lResult;
	UEnum* pEnum = FindObject<UEnum>(ANY_PACKAGE, *enumName, true);
	for (int i = 0; i <= pEnum->GetMaxEnumValue(); ++i)
	{
		if (pEnum->IsValidEnumValue(i))
			lResult.Add(static_cast<T>(i));
	}
	//remove MAX
	lResult.RemoveAt(lResult.Num() - 1);
	return lResult;
}
