// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "StringExFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class VRPLUGIN_API UStringExFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure, meta = (CompactNodeTitle = "+", Keywords = "increment string", CommutativeAssociativeBinaryOperator = "true"), Category = "StringExFunctionLibrary|String|FString")
		static FString StringPlus(FString A,FString B);
	
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "-=", Keywords = "decrement string"), Category = "StringExFunctionLibrary|String|FString")
		static FString StringMinus(UPARAM(ref)FString &A, FString B);
	
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "StringArrayToString", Keywords = "String Effect"), Category = "StringExFunctionLibrary|String|FString")
		static FString StringArrayToString(TArray<FString> InStringArray);
};
