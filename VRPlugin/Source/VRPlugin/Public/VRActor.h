// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "VRInterface.h"
#include "VRActor.generated.h"

UCLASS()
class VRPLUGIN_API AVRActor : public AActor,public IVRInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVRActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VRInterface1")
		void OnHoverR(UObject* HoverObject);
	virtual void OnHoverR_Implementation(UObject* HoverObject)override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VRInterface1")
		void OnHoverL(UObject* HoverObject, FVector SelectPositon);
	virtual void OnHoverL_Implementation(UObject* HoverObject, FVector SelectPositon)override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VRInterface1")
		void OnOverlapR(UPrimitiveComponent* Hand, FName HitBoneName);
	virtual void OnOverlapR_Implementation(UPrimitiveComponent* Hand, FName HitBoneName)override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VRInterface1")
		void OnOverlapL(UPrimitiveComponent* Hand, FName HitBoneName);
	virtual void OnOverlapL_Implementation(UPrimitiveComponent* Hand, FName HitBoneName)override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VRInterface1")
		void OnTriggerDownR(UPrimitiveComponent* Hand, FName HitBoneName, UObject* HitObject, UCameraComponent* Camera);
	virtual void OnTriggerDownR_Implementation(UPrimitiveComponent* Hand, FName HitBoneName, UObject* HitObject, UCameraComponent* Camera)override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VRInterface1")
		void OnTriggerDownL(UPrimitiveComponent* Hand, FName HitBoneName, UObject* HitObject, FVector SelectPosition);
	virtual void OnTriggerDownL_Implementation(UPrimitiveComponent* Hand, FName HitBoneName, UObject* HitObject, FVector SelectPosition)override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VRInterface1")
		void OnTriggerUpR();
	virtual void OnTriggerUpR_Implementation()override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VRInterface1")
		void OnTriggerUpL();
	virtual void OnTriggerUpL_Implementation()override;

	
};
