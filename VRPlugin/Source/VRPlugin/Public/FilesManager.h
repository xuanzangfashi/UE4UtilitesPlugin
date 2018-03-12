// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "./Runtime/ImageWrapper/Public/Interfaces/IImageWrapper.h"
#include "FilesManager.generated.h"

/**
 *
 */
UCLASS()
class VRPLUGIN_API UFilesManager : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	//Paths
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "Paths", Keywords = "GetFullGameContentPath"), Category = "UFilesManager|Paths|Paths")
		static FString GetFullGameContentPath();
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "Paths", Keywords = "GetFullGameSavePath"), Category = "UFilesManager|Paths|Paths")
		static FString GetFullGameSavePath();

	//Files
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "Files", Keywords = "IsFileExist"), Category = "UFilesManager|Files|Files")
		static bool IsFileExist(FString Path);
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "Files", Keywords = "CreateFolder"), Category = "UFilesManager|Files|Files")
		static bool CreateFolder(FString Path);
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "Files", Keywords = "CreateFile"), Category = "UFilesManager|Files|Files")
		static void CreateFile(FString Path);
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "Files", Keywords = "GetFileSize"), Category = "UFilesManager|Files|Files")
		static bool GetFileSize(FString Path, int& size);
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "Files", Keywords = "DeleteFile"), Category = "UFilesManager|Files|Files")
		static bool DeleteFile(FString Path);
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "Files", Keywords = "DeleteFolder"), Category = "UFilesManager|Files|Files")
		static bool DeleteFolder(FString Path);


	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "Files", Keywords = "ReadFile"), Category = "UFilesManager|Files|Files")
		static bool ReadFile(FString Path, TArray<FString>& OutChars);
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "Files", Keywords = "WirteFile"), Category = "UFilesManager|Files|Files")
		static bool WriteFile(FString Path, FString InChars, bool Overwrite);
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "Files", Keywords = "ReadFile"), Category = "UFilesManager|Files|Files")
		static FString LoadFileToStrBuffer(FString absPath);
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "Files", Keywords = "ReadFile"), Category = "UFilesManager|Files|Files")
		static bool LoadFileToByteBuffer(FString absPath, TArray<uint8>& outByte);

	UFUNCTION(BlueprintCallable, Category = "UFilesManager")
		static void EncodingToBase64Str(FString source, FString& OutStr);
	UFUNCTION(BlueprintCallable, Category = "UFilesManager")
		static void EncodingToBase64FromByte(TArray<uint8> bytes, FString& base64STR);

	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "Files", Keywords = "ReadFile"), Category = "UFilesManager|Files|Files")
		static UObject* LoadAsset_Runtime(TSubclassOf<UObject> InClass, FString LocalPath);

	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "Files", Keywords = "ReadFile"), Category = "UFilesManager|Files|Files")
		static UTexture2D* LoadTexture2D(const FString& ImagePath, bool& IsValid, int32& OutWidth, int32& OutHeight);
private:
	static IImageWrapperPtr GetImageWrapperByExtention(const FString InImagePath);
};
