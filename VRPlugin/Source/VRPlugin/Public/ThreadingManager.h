// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Kismet/BlueprintFunctionLibrary.h"
#include "ThreadingManager.generated.h"
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBlueprintThreadFunc, TArray<UObject*>, ParamsName);
/**
 * 
 */
UCLASS()
class VRPLUGIN_API UThreadingManager : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	
	UPROPERTY(BlueprintAssignable)
		FBlueprintThreadFunc ThreadFunction;

	//UFUNCTION(BlueprintCallable, Category = "UThreadingManager")
	//	static bool CreateThreadForBlueprint(FBlueprintThreadFunc& tf);
};
