#include "VRPlugin.h"
#include "HttpRequestManager.h"
#include "Http.h"
#include "CoreUObject.h"

DEFINE_LOG_CATEGORY_STATIC(LogHttpRequest, Warning, All);


//UHttpRequestManager::UHttpRequestManager(const FObjectInitializer& objiniter) :Super(objiniter)
//{
//
//}



UHttpRequestManager* UHttpRequestManager::HttpRequestString(FString url, EHttpRequestType reType, FString content,TArray<uint8> content1,bool isbyte)
{
	UHttpRequestManager* mManager = NewObject<UHttpRequestManager>();
	mManager->StartRequest(url, reType, content, content1, isbyte);
	return mManager;
}

void UHttpRequestManager::StartRequest(FString url, EHttpRequestType reType, FString content, TArray<uint8> content1, bool isbyte)
{
	TSharedRef<class IHttpRequest> httpRequest = FHttpModule::Get().CreateRequest();
	httpRequest->OnProcessRequestComplete().BindUObject(this, &UHttpRequestManager::OnRequestComplete);
	httpRequest->SetURL(url);
	if (reType == EHttpRequestType::_Get)
	{
		httpRequest->SetVerb(TEXT("GET"));
	}
	else {
		httpRequest->SetHeader(TEXT("Content-Type"), TEXT("text/html; charset=utf-8"));
		httpRequest->SetVerb(TEXT("POST"));
		if (!isbyte)
			httpRequest->SetContentAsString(content);
		else
			httpRequest->SetContent(content1);
	}
	httpRequest->ProcessRequest();
}

void UHttpRequestManager::OnRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
{
	if (bSucceeded)
	{
		OnSuccess.Broadcast(HttpResponse->GetContentAsString(), HttpResponse->GetResponseCode());
	}
	else
	{
		if (HttpResponse.IsValid())
		{
			OnFailed.Broadcast("", HttpResponse->GetResponseCode());
		}
		else
		{
			OnFailed.Broadcast("Error!", 0);
		}
	}
}

