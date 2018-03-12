// Fill out your copyright notice in the Description page of Project Settings.

#include "VRPlugin.h"
#include "VRGameModeEx.h"
#include "VRPawnEx.h"


AVRGameModeEx::AVRGameModeEx()
{
	this->DefaultPawnClass = AVRPawnEx::StaticClass();
}

void AVRGameModeEx::BeginPlay()
{

}

void AVRGameModeEx::Tick(float DeltaSecnonds)
{

}
