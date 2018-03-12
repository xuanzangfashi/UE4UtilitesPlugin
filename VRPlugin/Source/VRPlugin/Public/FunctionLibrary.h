// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "FunctionLibrary.generated.h"


/**
 * 
 */
UCLASS()
class VRPLUGIN_API UFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	static TArray<AActor*>RayCastIgoneActors;
public:
	UFUNCTION(BlueprintCallable,Category = "FunctionLibrary")
	static FHitResult RayCast(FVector Start, FVector Dir, APawn* player);
	
	UFUNCTION(BlueprintCallable, Category = "FunctionLibrary")
		static void AddIgoneActor(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category = "FunctionLibrary")
		static void RemoveIgoneActor(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category = "FunctionLibrary")
		static void GetIgoneActors(TArray<AActor*>& OutActors);
	UFUNCTION(BlueprintCallable, Category = "FunctionLibrary")
		static void ClearIgoneActors();

	UFUNCTION(BlueprintPure, meta = (CompactNodeTitle = "NULL", Keywords = "NULL|0|null"), Category = "UFunctionLibrary|NULL|NULL")
		static UObject* GetNULL();

public:

};




