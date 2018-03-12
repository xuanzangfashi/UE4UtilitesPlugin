// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "MotionControllerComponent.h"
#include "Runtime/UMG/Public/Components/WidgetInteractionComponent.h"
#include "VRPawnEx.generated.h"

UCLASS()
class VRPLUGIN_API AVRPawnEx : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AVRPawnEx();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

public: //Components
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VRPawnEx", meta = (AllowPrivateAccess = "true"))
		USceneComponent* Root;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VRPawnEx", meta = (AllowPrivateAccess = "true"))
		UCameraComponent* VRPawnExCamera;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VRPawnEx", meta = (AllowPrivateAccess = "true"))
		UMotionControllerComponent* LeftHand;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VRPawnEx", meta = (AllowPrivateAccess = "true"))
		UMotionControllerComponent* RightHand;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VRPawnEx", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* LeftHandMesh;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VRPawnEx", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* RightHandMesh;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VRPawnEx", meta = (AllowPrivateAccess = "true"))
		UWidgetInteractionComponent* WidgetSelecter;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VRPawnEx", meta = (AllowPrivateAccess = "true"))
		UFloatingPawnMovement* FloatingPawnMovementCom;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VRPawnEx", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* RayComR;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "VRPawnEx", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* RayComL;


public: //Origin Vars
	UPROPERTY(BlueprintReadWrite, Category = "VRPawnEx")
		bool Moveable;
	UPROPERTY(BlueprintReadWrite, Category = "VRPawnEx")
		float MoveSpeed;
	UPROPERTY(BlueprintReadWrite, Category = "VRPawnEx")
		bool LeftOrRightMove;
public: //Events
	UFUNCTION()
		virtual void TriggerDownR();
	UFUNCTION()
		virtual void TriggerUpR();
	UFUNCTION()
		virtual void TriggerDownL();
	UFUNCTION()
		virtual void TriggerUpL();
	UFUNCTION()
		virtual void OnFaceButtonForward(float Axis);
	UFUNCTION()
		virtual void OnFaceButtonRight(float Axis);

private: //Tmp Vars
	UPrimitiveComponent* RightHandCastComponent;
	UPrimitiveComponent* LeftHandCastComponent;
	AActor* RightHandCastActor;
	AActor* LeftHandCastActor;

private: //Blueprint Support
	AActor* FunctionLibrary;
};
