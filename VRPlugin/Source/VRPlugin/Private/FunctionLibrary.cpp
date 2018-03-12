// Fill out your copyright notice in the Description page of Project Settings.

#include "VRPlugin.h"
#include "FunctionLibrary.h"

TArray<AActor*> UFunctionLibrary::RayCastIgoneActors;




FHitResult UFunctionLibrary::RayCast(FVector Start, FVector Dir, APawn* player)
{
	FHitResult Outer;
	TArray<AActor*> IgoneActors;
	GetIgoneActors(IgoneActors);
	FCollisionQueryParams P = FCollisionQueryParams();
	
	P.AddIgnoredActors(IgoneActors);
	
	player->GetWorld()->LineTraceSingleByChannel(Outer, Start, Start + Dir * 3000.0f, ECollisionChannel::ECC_Visibility,P);
	return Outer;

}

void UFunctionLibrary::AddIgoneActor(AActor* InActor)
{
	UFunctionLibrary::RayCastIgoneActors.Add(InActor);
}

void UFunctionLibrary::RemoveIgoneActor(AActor* InActor)
{
	UFunctionLibrary::RayCastIgoneActors.Remove(InActor);
}

void UFunctionLibrary::GetIgoneActors(TArray<AActor*>& OutActors)
{
	OutActors = UFunctionLibrary::RayCastIgoneActors;
}

void UFunctionLibrary::ClearIgoneActors()
{
	UFunctionLibrary::RayCastIgoneActors.Empty();
}

UObject* UFunctionLibrary::GetNULL()
{
	return nullptr;
}
