// Fill out your copyright notice in the Description page of Project Settings.

#include "VRPlugin.h"
#include "FilesManager.h"
#include "./Runtime/Core/Public/Misc/Base64.h"
#include "./Runtime/ImageWrapper/Public/Interfaces/IImageWrapperModule.h"
#include <fstream>
#pragma optimize("",off)
FString UFilesManager::GetFullGameContentPath()
{
	return FPaths::GameContentDir();
}

FString UFilesManager::GetFullGameSavePath()
{
	return FPaths::GameSavedDir();
}

bool UFilesManager::IsFileExist(FString Path)
{
	bool re = FPlatformFileManager::Get().GetPlatformFile().FileExists(*Path);
	return re;
}

bool UFilesManager::CreateFolder(FString Path)
{
	bool re = FPlatformFileManager::Get().GetPlatformFile().CreateDirectoryTree(*Path);
	return re;
}

void UFilesManager::CreateFile(FString Path)
{
	bool isexist = IsFileExist(Path);
	if (!isexist)
	{
		FString Tmp = Path;
		TArray<TCHAR> Str;
		Str = Tmp.GetCharArray();
		int lastindex = Str.Num() - 1;
		int toindex = lastindex;
		while (Str[toindex] != '/')
		{
			Tmp.RemoveAt(toindex);
			toindex--;
		}
		Tmp = Tmp + "/";
		CreateFolder(Tmp);
	}
	TCHAR* PathInChars = Path.GetCharArray().GetData();
	FILE *fp = fopen(TCHAR_TO_ANSI(PathInChars), "w");
	fclose(fp);
}

bool UFilesManager::GetFileSize(FString Path, int& size)
{
	size = FPlatformFileManager::Get().GetPlatformFile().FileSize(*Path);
	return true;
}

bool UFilesManager::DeleteFile(FString Path)
{
	bool re = FPlatformFileManager::Get().GetPlatformFile().DeleteFile(*Path);
	return re;
}

bool UFilesManager::DeleteFolder(FString Path)
{
	bool re = FPlatformFileManager::Get().GetPlatformFile().DeleteDirectory(*Path);
	return re;
}



bool UFilesManager::ReadFile(FString Path, TArray<FString>& OutChars)
{
	bool re = FFileHelper::LoadANSITextFileToStrings(*Path, NULL, OutChars);
	return re;
}

bool UFilesManager::WriteFile(FString Path, FString InChars, bool Overwrite)
{
	bool isexist = UFilesManager::IsFileExist(*Path);
	if (!isexist)
	{
		CreateFile(Path);
	}
	if (Overwrite)
	{
		FFileHelper::SaveStringToFile(InChars, *Path);
	}
	else
	{
		TArray<FString> CHars;
		FFileHelper::LoadANSITextFileToStrings(*Path, NULL, CHars);
		FString Chars = "";
		for (int i = 0; i < CHars.Num(); i++)
		{
			Chars = Chars + CHars[i];
		}
		InChars = Chars + InChars;
		FFileHelper::SaveStringToFile(InChars, *Path);
	}

	return isexist;
}

FString UFilesManager::LoadFileToStrBuffer(FString absPath)
{
	FString buffer = FString();
	bool re = FFileHelper::LoadFileToString(buffer, *absPath);
	return buffer;
}

bool UFilesManager::LoadFileToByteBuffer(FString absPath, TArray<uint8>& outByte)
{
	
	return FFileHelper::LoadFileToArray(outByte, *absPath);
}

void UFilesManager::EncodingToBase64Str(FString source,FString& outStr)
{
	outStr = TCHAR_TO_ANSI(*source);
}

void UFilesManager::EncodingToBase64FromByte(TArray<uint8> bytes, FString& base64STR)
{
	base64STR = FBase64::Encode(bytes);
}

UObject* UFilesManager::LoadAsset_Runtime(TSubclassOf<UObject> InClass, FString LocalPath)
{
	UObject* Outer = StaticLoadObject(InClass, 0, *LocalPath);
	return Outer;
}

IImageWrapperPtr UFilesManager::GetImageWrapperByExtention(const FString InImagePath)
{
	IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));
	if (InImagePath.EndsWith(".png"))
	{
		return ImageWrapperModule.CreateImageWrapper(EImageFormat::PNG);
	}
	else if (InImagePath.EndsWith(".jpg") || InImagePath.EndsWith(".jpeg"))
	{
		return ImageWrapperModule.CreateImageWrapper(EImageFormat::JPEG);
	}
	else if (InImagePath.EndsWith(".bmp"))
	{
		return ImageWrapperModule.CreateImageWrapper(EImageFormat::BMP);
	}
	else if (InImagePath.EndsWith(".ico"))
	{
		return ImageWrapperModule.CreateImageWrapper(EImageFormat::ICO);
	}
	else if (InImagePath.EndsWith(".exr"))
	{
		return ImageWrapperModule.CreateImageWrapper(EImageFormat::EXR);
	}
	else if (InImagePath.EndsWith(".icns"))
	{
		return ImageWrapperModule.CreateImageWrapper(EImageFormat::ICNS);
	}
	return nullptr;
}

UTexture2D* UFilesManager::LoadTexture2D(const FString& ImagePath, bool& IsValid, int32& OutWidth, int32& OutHeight)
{
	UTexture2D* Texture = nullptr;
	IsValid = false;
	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*ImagePath))
	{
		return nullptr;
	}
	TArray<uint8> CompressedData;
	if (!FFileHelper::LoadFileToArray(CompressedData, *ImagePath))
	{
		return nullptr;
	}
	IImageWrapperPtr ImageWrapper = GetImageWrapperByExtention(ImagePath);
	if (ImageWrapper.IsValid() && ImageWrapper->SetCompressed(CompressedData.GetData(), CompressedData.Num()))
	{
		const TArray<uint8>* UncompressedRGBA = nullptr;
		if (ImageWrapper->GetRaw(ERGBFormat::RGBA, 8, UncompressedRGBA))
		{
			Texture = UTexture2D::CreateTransient(ImageWrapper->GetWidth(), ImageWrapper->GetHeight(), PF_R8G8B8A8);
			if (Texture != nullptr)
			{
				IsValid = true;
				OutWidth = ImageWrapper->GetWidth();
				OutHeight = ImageWrapper->GetHeight();
				void* TextureData = Texture->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
				FMemory::Memcpy(TextureData, UncompressedRGBA->GetData(), UncompressedRGBA->Num());
				Texture->PlatformData->Mips[0].BulkData.Unlock();
				Texture->UpdateResource();
			}
		}
	}
	return Texture;
}
#pragma optimize("",on)