// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "TurretAttachmentEnum.h"

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "TurretAttachmentButton.generated.h"

/**
 * 
 */
UCLASS()
class DIRTSTURRETDEFENSE_API UTurretAttachmentButton : public UButton
{
	GENERATED_BODY()

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnButtonPressedSignature, ETurretAttachment, Attachment);

private:
	ETurretAttachment _Attachment;

protected:

public:
	UPROPERTY(BlueprintAssignable)
	FOnButtonPressedSignature OnPressed_Custom;

public:
	void SetAttachment(ETurretAttachment Attachment);

protected:

private:
	UFUNCTION()
	void Pressed();
};
