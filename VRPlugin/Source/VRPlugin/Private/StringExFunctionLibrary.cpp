// Fill out your copyright notice in the Description page of Project Settings.

#include "VRPlugin.h"
#include "StringExFunctionLibrary.h"
#include "Kismet/KismetStringLibrary.h"

FString UStringExFunctionLibrary::StringPlus(FString A, FString B)
{
	return A + B;
}

FString UStringExFunctionLibrary::StringMinus(UPARAM(ref)FString &A, FString B)
{
	FString OutString = A;
	int32 Start = UKismetStringLibrary::FindSubstring(A, B);
	int32 BLenth = B.Len();
	for (int32 i = Start; i < BLenth; i++)
	{
		A.RemoveAt(i);
	}
	FString OutPut = A;
	return OutPut;
}

FString UStringExFunctionLibrary::StringArrayToString(TArray<FString> InStringArray)
{
	FString OutString = "";
	for (int i = 0; i < InStringArray.Num(); i++)
	{
		OutString = OutString + InStringArray[i];
	}
	return OutString;
}
