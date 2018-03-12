// Fill out your copyright notice in the Description page of Project Settings.

#include "VRPlugin.h"
#include "VRActor.h"


// Sets default values
AVRActor::AVRActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVRActor::BeginPlay()
{
	Super::BeginPlay();
	//check(GetClass()->ImplementsInterface(UVRInterface::StaticClass()));
}

// Called every frame
void AVRActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AVRActor::OnHoverR_Implementation(UObject* HoverObject)
{

}

void AVRActor::OnHoverL_Implementation(UObject* HoverObject, FVector SelectPositon)
{

}

void AVRActor::OnOverlapR_Implementation(UPrimitiveComponent* Hand, FName HitBoneName)
{

}

void AVRActor::OnOverlapL_Implementation(UPrimitiveComponent* Hand, FName HitBoneName)
{

}

void AVRActor::OnTriggerDownR_Implementation(UPrimitiveComponent* Hand, FName HitBoneName, UObject* HitObject, UCameraComponent* Camera)
{

}

void AVRActor::OnTriggerDownL_Implementation(UPrimitiveComponent* Hand, FName HitBoneName, UObject* HitObject, FVector SelectPosition)
{

}

void AVRActor::OnTriggerUpR_Implementation()
{

}

void AVRActor::OnTriggerUpL_Implementation()
{

}
