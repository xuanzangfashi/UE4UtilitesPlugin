#pragma once
#include "IHttpRequest.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "HttpRequestManager.generated.h"

using namespace UF;
using namespace UP;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FHttpRequestManagerDelegate, FString, Content, int32, StatusCode);

UENUM()
enum EHttpRequestType
{
	_Get,_Post,
};

UCLASS()
class VRPLUGIN_API UHttpRequestManager : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category = "UHttpRequestManager")
		static UHttpRequestManager* HttpRequestString(FString url, EHttpRequestType reType, FString content, TArray<uint8> content1, bool isbyte = false);

	UPROPERTY(BlueprintAssignable)
		FHttpRequestManagerDelegate OnSuccess;
	UPROPERTY(BlueprintAssignable)
		FHttpRequestManagerDelegate OnFailed;

private:
	void StartRequest(FString url, EHttpRequestType reType, FString content, TArray<uint8> content1, bool isbyte);
	void OnRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded);
};