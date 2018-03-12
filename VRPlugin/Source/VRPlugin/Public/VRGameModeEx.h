// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "VRGameModeEx.generated.h"

/**
 * 
 */
UCLASS()
class VRPLUGIN_API AVRGameModeEx : public AGameMode
{
	GENERATED_BODY()
public:
	AVRGameModeEx();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSecnonds) override;

public: //Other Components

	
	
};
