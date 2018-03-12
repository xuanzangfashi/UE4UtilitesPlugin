#pragma once
#include "Kismet/BlueprintAsyncActionBase.h"
#include "IHttpRequest.h"
#include "HttpDownLoadManager.generated.h"
using namespace UF;
using namespace UP;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDownloadFileDelegate, FString, DestinationPath, float, DownloadPercent);

UCLASS()
class VRPLUGIN_API UHttpDownloadManager:public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "UHttpDownloadManager")
		static UHttpDownloadManager* DownLoadFile(FString url, FString dir);
	UPROPERTY(BlueprintAssignable)
		FDownloadFileDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
		FDownloadFileDelegate OnFail;

	UPROPERTY(BlueprintAssignable)
		FDownloadFileDelegate OnProgress;
private:
	void StartDownload();
	FString Url;
	FString FilePath;
	int FileTotalSize;
	int FileCurrentSize;

	void OnDownloadCompelete(FHttpRequestPtr httpRequest, FHttpResponsePtr httpResponse, bool bSucceeded);
	void OnDownloadProgress(FHttpRequestPtr httpRequest, int upLoaded, int downLoaded);
};

