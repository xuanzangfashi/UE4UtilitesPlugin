#include "VRPlugin.h"
#include "HttpDownLoadManager.h"

#include "Http.h"

//UHttpDownloadManager::UHttpDownloadManager(const FObjectInitializer& objIniter) :Super(objIniter)
//{
//
//}


UHttpDownloadManager* UHttpDownloadManager::DownLoadFile(FString url, FString dir)
{
	UHttpDownloadManager* Downloader = NewObject<UHttpDownloadManager>();
	Downloader->Url = url;
	Downloader->FilePath = dir;
	//FString fileName = FPaths::GetCleanFilename("");
	
	Downloader->StartDownload();
	return Downloader;
}

void UHttpDownloadManager::StartDownload()
{
	TSharedRef<class IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->OnProcessRequestComplete().BindUObject(this, &UHttpDownloadManager::OnDownloadCompelete);
	HttpRequest->OnRequestProgress().BindUObject(this, &UHttpDownloadManager::OnDownloadProgress);
	HttpRequest->SetURL(this->Url);
	HttpRequest->SetVerb(TEXT("GET"));
	HttpRequest->ProcessRequest();
}

void UHttpDownloadManager::OnDownloadCompelete(FHttpRequestPtr httpRequest, FHttpResponsePtr httpResponse, bool bSucceeded)
{
	if (bSucceeded)
	{
		TArray<uint8> bytes = httpResponse->GetContent();
		FFileHelper::SaveArrayToFile(bytes, *this->FilePath);
		OnSuccess.Broadcast(this->FilePath, 1);
		return;
	}
	else
	{
		UE_LOG(LogClass, Warning, TEXT("Failed to cheack file!"));
		OnFail.Broadcast(TEXT("Failed to cheack file!"), 0);
		return;
	}
}

void UHttpDownloadManager::OnDownloadProgress(FHttpRequestPtr httpRequest, int upLoaded, int downLoaded)
{
	UE_LOG(LogClass, Warning, TEXT("Download Progress %d   %d"), upLoaded, downLoaded);
	float raio = (downLoaded*1.0f) / httpRequest->GetResponse()->GetContentLength();
	OnProgress.Broadcast(this->FilePath, raio);
}

