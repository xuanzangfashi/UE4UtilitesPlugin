// Fill out your copyright notice in the Description page of Project Settings.

#include "VRPlugin.h"
#include "MathExFunctionLibrary.h"




void UMathExFunctionLibrary::FloatPlusEquals(UPARAM(ref)float &Float, float Add, float &FloatOut)
{
	Float += Add;
	FloatOut = Float;
}

void UMathExFunctionLibrary::FloatMinusEquals(UPARAM(ref)float &Float, float Sub, float &FloatOut)
{
	Float -= Sub;
	FloatOut = Float;
}

void UMathExFunctionLibrary::FloatMultiEquals(UPARAM(ref)float &Float, float X, float& FloatOut)
{
	FloatOut = (Float *= X);
}

void UMathExFunctionLibrary::FloatDivisionEquals(UPARAM(ref)float &Float, float X, float& FloatOut)
{
	FloatOut = (Float /= X);
}

void UMathExFunctionLibrary::IntegerPlusEquals(UPARAM(ref)int32 &Int, int32 Add, int32 &IntOut)
{
	Int += Add;
	IntOut = Int;
}

void UMathExFunctionLibrary::IntegerMinusEquals(UPARAM(ref)int32 &Int, int32 Sub, int32 &IntOut)
{
	Int -= Sub;
	IntOut = Int;
}

void UMathExFunctionLibrary::IntegerMultiEquals(UPARAM(ref)int32 &Int, int32 X, int32& IntOut)
{
	IntOut = (Int *= X);
}

void UMathExFunctionLibrary::IntegerDivisionEquals(UPARAM(ref)int32 &Int, int32 X, int32& IntOut)
{
	IntOut = (Int /= X);
}

void UMathExFunctionLibrary::Vector3MinusEqualsVector3(UPARAM(ref)FVector &Vector, FVector Sub, FVector& VectorOut)
{
	VectorOut = (Vector -= Sub);
}

void UMathExFunctionLibrary::Vector3PlusEqualsVector3(UPARAM(ref)FVector& Vector, FVector Add, FVector& VectorOut)
{
	VectorOut = (Vector += Add);
}

void UMathExFunctionLibrary::Vector3MultiEqualsVector3(UPARAM(ref)FVector& Vector, FVector X, FVector& VectorOut)
{
	VectorOut = (Vector *= X);
}

void UMathExFunctionLibrary::Vector3DivisionEqualsVector3(UPARAM(ref)FVector& Vector, FVector X, FVector& VectorOut)
{
	VectorOut = (Vector /= X);
}

void UMathExFunctionLibrary::Vector3MultiEqualsFloat(UPARAM(ref)FVector& Vector, float X, FVector& VectorOut)
{
	VectorOut = (Vector *= X);
}

void UMathExFunctionLibrary::Vector3DivisionEqualsFloat(UPARAM(ref)FVector& Vector, float X, FVector& VectorOut)
{
	VectorOut = (Vector /= X);
}

void UMathExFunctionLibrary::Vector2MinusEqualsVector2(UPARAM(ref)FVector2D &Vector, FVector2D Sub, FVector2D& VectorOut)
{
	VectorOut = (Vector -= Sub);
}

void UMathExFunctionLibrary::Vector2PlusEqualsVector2(UPARAM(ref)FVector2D& Vector, FVector2D Add, FVector2D& VectorOut)
{
	VectorOut = (Vector += Add);
}

void UMathExFunctionLibrary::Vector2MultiEqualsVector2(UPARAM(ref)FVector2D& Vector, FVector2D X, FVector2D& VectorOut)
{
	VectorOut = (Vector *= X);
}

void UMathExFunctionLibrary::Vector2DivisionEqualsVector2(UPARAM(ref)FVector2D& Vector, FVector2D X, FVector2D& VectorOut)
{
	VectorOut = (Vector /= X);
}

void UMathExFunctionLibrary::Vector2MultiEqualsFloat(UPARAM(ref)FVector2D& Vector, float X, FVector2D& VectorOut)
{
	VectorOut = (Vector *= X);
}

void UMathExFunctionLibrary::Vector2DivisionEqualsFloat(UPARAM(ref)FVector2D& Vector, float X, FVector2D& VectorOut)
{
	VectorOut = (Vector /= X);
}
