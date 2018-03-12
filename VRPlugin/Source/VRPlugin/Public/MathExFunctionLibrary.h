// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "MathExFunctionLibrary.generated.h"

/**
 *
 */
UCLASS()
class VRPLUGIN_API UMathExFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	//
	//Number
	//


	//float 
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "+=", Keywords = "increment float"), Category = "MathExFunctionLibrary|Math|Float")
		static void FloatPlusEquals(UPARAM(ref)float &Float, float Add, float &FloatOut);

	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "-=", Keywords = "decrement float"), Category = "MathExFunctionLibrary|Math|Float")
		static void FloatMinusEquals(UPARAM(ref)float &Float, float Sub, float &FloatOut);

	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "*=", Keywords = "multi float"), Category = "MathExFunctionLibrary|Math|Float")
		static void FloatMultiEquals(UPARAM(ref)float &Float, float X, float& FloatOut);

	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "/=", Keywords = "division float"), Category = "MathExFunctionLibrary|Math|Float")
		static void FloatDivisionEquals(UPARAM(ref)float &Float, float X, float& FloatOut);


	//int

	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "+=", Keywords = "increment Integer"), Category = "MathExFunctionLibrary|Math|Integer")
		static void IntegerPlusEquals(UPARAM(ref)int32 &Int, int32 Add, int32 &IntOut);

	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "-=", Keywords = "decrement Integer"), Category = "MathExFunctionLibrary|Math|Integer")
		static void IntegerMinusEquals(UPARAM(ref)int32 &Int, int32 Sub, int32 &IntOut);

	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "*=", Keywords = "multi Integer"), Category = "MathExFunctionLibrary|Math|Integer")
		static void IntegerMultiEquals(UPARAM(ref)int32 &Int, int32 X, int32& IntOut);

	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "/=", Keywords = "division Integer"), Category = "MathExFunctionLibrary|Math|Integer")
		static void IntegerDivisionEquals(UPARAM(ref)int32 &Int, int32 X, int32& IntOut);


	//
	//Vector
	//


	//3D
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "-=", Keywords = "decrement Vector3"), Category = "MathExFunctionLibrary|Math|Vector3")
		static void Vector3MinusEqualsVector3(UPARAM(ref)FVector &Vector, FVector Sub, FVector& VectorOut);

	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "+=", Keywords = "increment Vector3"), Category = "MathExFunctionLibrary|Math|Vector3")
		static void Vector3PlusEqualsVector3(UPARAM(ref)FVector& Vector, FVector Add, FVector& VectorOut);

	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "*=", Keywords = "multi Vector3"), Category = "MathExFunctionLibrary|Math|Vector3")
		static void Vector3MultiEqualsVector3(UPARAM(ref)FVector& Vector, FVector X, FVector& VectorOut);

	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "/=", Keywords = "division Vector3"), Category = "MathExFunctionLibrary|Math|Vector3")
		static void Vector3DivisionEqualsVector3(UPARAM(ref)FVector& Vector, FVector X, FVector& VectorOut);

	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "*=", Keywords = "multi Vector3"), Category = "MathExFunctionLibrary|Math|Vector3")
		static void Vector3MultiEqualsFloat(UPARAM(ref)FVector& Vector, float X, FVector& VectorOut);

	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "/=", Keywords = "division Vector3"), Category = "MathExFunctionLibrary|Math|Vector3")
		static void Vector3DivisionEqualsFloat(UPARAM(ref)FVector& Vector, float X, FVector& VectorOut);





	//2D
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "-=", Keywords = "decrement Vector2"), Category = "MathExFunctionLibrary|Math|Vector2")
		static void Vector2MinusEqualsVector2(UPARAM(ref)FVector2D &Vector, FVector2D Sub, FVector2D& VectorOut);

	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "+=", Keywords = "increment Vector2"), Category = "MathExFunctionLibrary|Math|Vector2")
		static void Vector2PlusEqualsVector2(UPARAM(ref)FVector2D& Vector, FVector2D Add, FVector2D& VectorOut);

	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "*=", Keywords = "multi Vector2"), Category = "MathExFunctionLibrary|Math|Vector2")
		static void Vector2MultiEqualsVector2(UPARAM(ref)FVector2D& Vector, FVector2D X, FVector2D& VectorOut);

	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "/=", Keywords = "division Vector2"), Category = "MathExFunctionLibrary|Math|Vector2")
		static void Vector2DivisionEqualsVector2(UPARAM(ref)FVector2D& Vector, FVector2D X, FVector2D& VectorOut);

	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "*=", Keywords = "multi Vector2"), Category = "MathExFunctionLibrary|Math|Vector2")
		static void Vector2MultiEqualsFloat(UPARAM(ref)FVector2D& Vector, float X, FVector2D& VectorOut);

	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "/=", Keywords = "division Vector2"), Category = "MathExFunctionLibrary|Math|Vector2")
		static void Vector2DivisionEqualsFloat(UPARAM(ref)FVector2D& Vector, float X, FVector2D& VectorOut);

};
