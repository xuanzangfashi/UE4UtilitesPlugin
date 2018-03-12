// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VRInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UVRInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

/**
 * 
 */
class VRPLUGIN_API IVRInterface
{
	GENERATED_IINTERFACE_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VRInterface")
		void OnHoverR(UObject* HoverObject);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VRInterface")
		void OnHoverL(UObject* HoverObject,FVector SelectPositon);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VRInterface")
		void OnOverlapR(UPrimitiveComponent* Hand, FName HitBoneName);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VRInterface")
		void OnOverlapL(UPrimitiveComponent* Hand, FName HitBoneName);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VRInterface")
		void OnTriggerDownR(UPrimitiveComponent* Hand, FName HitBoneName, UObject* HitObject, UCameraComponent* Camera);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VRInterface")
		void OnTriggerDownL(UPrimitiveComponent* Hand, FName HitBoneName, UObject* HitObject, FVector SelectPosition);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VRInterface")
		void OnTriggerUpR();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VRInterface")
		void OnTriggerUpL();
	
};
