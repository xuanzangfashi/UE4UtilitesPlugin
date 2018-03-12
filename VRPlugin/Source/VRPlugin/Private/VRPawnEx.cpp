// Fill out your copyright notice in the Description page of Project Settings.

#include "VRPlugin.h"
#include "VRPawnEx.h"
#include "FunctionLibrary.h"
#include "VRInterface.h"

// Sets default values
AVRPawnEx::AVRPawnEx()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = TEnumAsByte<EAutoReceiveInput::Type>::EnumType::Player0;
	AutoReceiveInput = TEnumAsByte<EAutoReceiveInput::Type>::EnumType::Player0;

	this->RootComponent = CreateDefaultSubobject<USceneComponent>("Root");

	VRPawnExCamera = CreateDefaultSubobject<UCameraComponent>("Camera");
	VRPawnExCamera->AttachToComponent(this->RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	LeftHand = CreateDefaultSubobject<UMotionControllerComponent>("LeftHand");
	RightHand = CreateDefaultSubobject<UMotionControllerComponent>("RightHand");
	LeftHand->AttachToComponent(this->RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	RightHand->AttachToComponent(this->RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	LeftHand->Hand = TEnumAsByte<EControllerHand>::EnumType::Left;
	RightHand->Hand = TEnumAsByte<EControllerHand>::EnumType::Right;
	LeftHandMesh = CreateDefaultSubobject<UStaticMeshComponent>("LeftHandMesh");
	RightHandMesh = CreateDefaultSubobject<UStaticMeshComponent>("RightHandMesh");
	UObject* HandMesh = StaticLoadObject(UStaticMesh::StaticClass(), 0,
		TEXT("/Engine/VREditor/Devices/Vive/VivePreControllerMesh.VivePreControllerMesh"));
	RightHandMesh->SetStaticMesh((UStaticMesh*)HandMesh);
	LeftHandMesh->SetStaticMesh((UStaticMesh*)HandMesh);
	LeftHandMesh->AttachToComponent(LeftHand, FAttachmentTransformRules::KeepRelativeTransform);
	RightHandMesh->AttachToComponent(RightHand, FAttachmentTransformRules::KeepRelativeTransform);
	WidgetSelecter = CreateDefaultSubobject<UWidgetInteractionComponent>("WidgetSelecter");
	WidgetSelecter->AttachToComponent(RightHand, FAttachmentTransformRules::KeepRelativeTransform);

	FloatingPawnMovementCom = CreateDefaultSubobject<UFloatingPawnMovement>("MovementComponent");

	RayComR = CreateDefaultSubobject<UStaticMeshComponent>("RayComR");
	RayComL = CreateDefaultSubobject<UStaticMeshComponent>("RayComL");
	RayComR->AttachToComponent(RightHandMesh, FAttachmentTransformRules::KeepRelativeTransform);
	RayComL->AttachToComponent(LeftHandMesh, FAttachmentTransformRules::KeepRelativeTransform);

	UStaticMesh*Cube = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), 0, TEXT("/Engine/BasicShapes/Cube.Cube")));
	RayComR->SetStaticMesh(Cube);
	RayComR->SetRelativeScale3D(FVector(5.0f, 0.005f, 0.005f));
	RayComR->SetRelativeLocation(FVector(250.0f, 0.0f, 0.0f));
	RayComL->SetStaticMesh(Cube);
	RayComL->SetRelativeScale3D(FVector(5.0f, 0.005f, 0.005f));
	RayComL->SetRelativeLocation(FVector(250.0f, 0.0f, 0.0f));
	UMaterial* RedMaterial = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(), 0, TEXT("/Game/VRPlayer/Red.Red")));
	UMaterial* BlueMaterial = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(), 0, TEXT("/Game/VRPlayer/Blue.Blue")));
	RayComL->SetMaterial(0, BlueMaterial);
	RayComR->SetMaterial(0, RedMaterial);
}



// Called when the game starts or when spawned
void AVRPawnEx::BeginPlay()
{
	Super::BeginPlay();

	//Init Var(s)
	LeftOrRightMove = true;

	// Get Outside Function library
	TArray<AActor*> TmpActorList;
	UGameplayStatics::GetAllActorsWithTag(this, "VRPawnExFunctions", TmpActorList);
	if (!(TmpActorList.Num() < 1))
		this->FunctionLibrary = TmpActorList[0];

	// Out Function
	FOutputDeviceNull Outer;
	if (this->FunctionLibrary)
		this->FunctionLibrary->CallFunctionByNameWithArguments(TEXT("VRPawnExBeginPlay"), Outer, 0, true);
	UFunctionLibrary::AddIgoneActor(this);
}

// Called every frame
void AVRPawnEx::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FHitResult ReR = UFunctionLibrary::RayCast(RightHandMesh->GetComponentLocation(), RightHandMesh->GetForwardVector(), this);
	AActor* HitActorR = ReR.Actor.Get();
	UPrimitiveComponent* HitComR = ReR.Component.Get();

	IVRInterface* HitActorRI = Cast<IVRInterface>(HitActorR);
	if (HitActorRI)
	{

		HitActorRI->Execute_OnHoverR(HitActorR, HitComR);
	}

	IVRInterface* HitComRI = Cast<IVRInterface>(HitComR);
	if (HitComRI)
	{
		HitActorRI->Execute_OnHoverR(HitComR, HitComR);
	}


	FHitResult ReL = UFunctionLibrary::RayCast(LeftHandMesh->GetComponentLocation(), LeftHandMesh->GetForwardVector(), this);
	AActor* HitActorL = ReL.Actor.Get();
	UPrimitiveComponent* HitComL = ReL.Component.Get();
	IVRInterface* HitActorLI = Cast<IVRInterface>(HitActorL);
	if (HitActorLI)
	{
		HitActorLI->Execute_OnHoverL(HitActorL, HitComL, ReL.Location);
	}

	IVRInterface* HitComLI = Cast<IVRInterface>(HitComL);
	if (HitComLI)
	{
		HitComLI->Execute_OnHoverL(HitComL, HitComL, ReL.Location);
	}

	// Out Function
	FOutputDeviceNull Outer;
	if (this->FunctionLibrary)
		this->FunctionLibrary->CallFunctionByNameWithArguments(TEXT("VRPawnExTick"), Outer, 0, true);
}

// Called to bind functionality to input
void AVRPawnEx::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAction("TriggerR", EInputEvent::IE_Pressed, this, &AVRPawnEx::TriggerDownR);
	InputComponent->BindAction("TriggerR", EInputEvent::IE_Released, this, &AVRPawnEx::TriggerUpR);
	InputComponent->BindAction("TriggerL", EInputEvent::IE_Pressed, this, &AVRPawnEx::TriggerDownL);
	InputComponent->BindAction("TriggerL", EInputEvent::IE_Released, this, &AVRPawnEx::TriggerUpL);
	if (LeftOrRightMove)
	{
		InputComponent->BindAxis("VRPawnExForwardL", this, &AVRPawnEx::OnFaceButtonForward);
		InputComponent->BindAxis("VRPawnExRightL", this, &AVRPawnEx::OnFaceButtonRight);
	}
	else
	{
		InputComponent->BindAxis("VRPawnExForwardR", this, &AVRPawnEx::OnFaceButtonForward);
		InputComponent->BindAxis("VRPawnExRightR", this, &AVRPawnEx::OnFaceButtonRight);
	}

}

void AVRPawnEx::TriggerDownR()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "DownR");
	FHitResult Re;
	Re = UFunctionLibrary::RayCast(RightHandMesh->GetComponentLocation(), RightHandMesh->GetForwardVector(), this);
	AActor* HitActor = Re.Actor.Get();
	UPrimitiveComponent* HitComponent = Re.Component.Get();
	if (Re.Actor != NULL)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Black, Re.Actor->GetName());
	IVRInterface* HitActorI = Cast<IVRInterface>(HitActor);
	if (HitActorI)
	{
		HitActorI->Execute_OnTriggerDownR(HitActor, this->RightHand, Re.BoneName, HitComponent, this->VRPawnExCamera);
		RightHandCastActor = HitActor;
	}

	IVRInterface* HitComponentI = Cast<IVRInterface>(HitComponent);
	if (HitComponentI)
	{
		HitComponentI->Execute_OnTriggerDownR(HitComponent, this->RightHand, Re.BoneName, HitComponent, this->VRPawnExCamera);
		RightHandCastComponent = HitComponent;
	}

	WidgetSelecter->PressPointerKey(FKey("LeftMouseButton"));



	// Out Function
	FOutputDeviceNull Outer;
	FString Cmdline = "VRPawnExTriggerDownR";
	if (this->FunctionLibrary)
		this->FunctionLibrary->CallFunctionByNameWithArguments(*Cmdline, Outer, 0, true);

	//ConstructorHelpers::FObjectFinder<UBlueprint> BlueprintObj(TEXT("Blueprint'/Game/Blueprints/SomeBlueprint.SomeBlueprint'"));
	//UBlueprint* blueprint;
	//if (BlueprintObj.Succeeded())
	//	blueprint = BlueprintObj.Object;
}

void AVRPawnEx::TriggerUpR()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "UpR");
	if (RightHandCastActor)
	{
		IVRInterface* HitActorI = Cast<IVRInterface>(RightHandCastActor);
		HitActorI->Execute_OnTriggerUpR(RightHandCastActor);
		RightHandCastActor = 0;
	}

	if (RightHandCastComponent)
	{
		IVRInterface* HitComponentI = Cast<IVRInterface>(RightHandCastComponent);
		HitComponentI->Execute_OnTriggerUpR(RightHandCastComponent);
		RightHandCastComponent = 0;
	}
	WidgetSelecter->ReleasePointerKey(FKey("LeftMouseButton"));



	// Out Function
	FOutputDeviceNull Outer;
	if (this->FunctionLibrary)
		this->FunctionLibrary->CallFunctionByNameWithArguments(TEXT("VRPawnExTriggerUpR"), Outer, 0, true);
}

void AVRPawnEx::TriggerDownL()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "DownL");
	FHitResult Re;
	Re = UFunctionLibrary::RayCast(LeftHandMesh->GetComponentLocation(), LeftHandMesh->GetForwardVector(), this);
	AActor* HitActor = Re.Actor.Get();
	UPrimitiveComponent* HitComponent = Re.Component.Get();

	IVRInterface* HitActorI = Cast<IVRInterface>(HitActor);
	if (HitActorI)
	{
		HitActorI->Execute_OnTriggerDownL(HitActor, this->LeftHand, Re.BoneName, HitComponent, Re.Location);
		LeftHandCastActor = HitActor;
	}


	IVRInterface* HitComponentI = Cast<IVRInterface>(HitComponent);
	if (HitComponentI)
	{
		HitComponentI->Execute_OnTriggerDownL(HitComponent, this->LeftHand, Re.BoneName, HitComponent, Re.Location);
		LeftHandCastComponent = HitComponent;
	}



	// Out Function
	FOutputDeviceNull Outer;
	if (this->FunctionLibrary)
		this->FunctionLibrary->CallFunctionByNameWithArguments(TEXT("VRPawnExTriggerDownL"), Outer, 0, true);
}

void AVRPawnEx::TriggerUpL()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "UpL");
	if (LeftHandCastActor)
	{
		IVRInterface* HitActorI = Cast<IVRInterface>(LeftHandCastActor);
		HitActorI->Execute_OnTriggerUpR(LeftHandCastActor);
		LeftHandCastActor = 0;
	}

	if (LeftHandCastComponent)
	{
		IVRInterface* HitComponentI = Cast<IVRInterface>(LeftHandCastComponent);
		HitComponentI->Execute_OnTriggerUpR(LeftHandCastComponent);
		LeftHandCastComponent = 0;
	}



	// Out Function
	FOutputDeviceNull Outer;
	if (this->FunctionLibrary)
		this->FunctionLibrary->CallFunctionByNameWithArguments(TEXT("VRPawnExTriggerUpL"), Outer, 0, true);
}

void AVRPawnEx::OnFaceButtonForward(float Axis)
{
	this->AddMovementInput(this->VRPawnExCamera->GetForwardVector(), Axis * MoveSpeed);
}

void AVRPawnEx::OnFaceButtonRight(float Axis)
{
	this->AddMovementInput(this->VRPawnExCamera->GetRightVector(), Axis * MoveSpeed);
}

