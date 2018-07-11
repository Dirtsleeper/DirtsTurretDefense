// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "TurretAttachmentEnum.h"

#include "CoreMinimal.h"
#include "HUD/Main//BaseWidgets/DropdownMenuChild.h"
#include "TurretAttachmentSelectionWidget.generated.h"

/**
 * 
 */
UCLASS()
class DIRTSTURRETDEFENSE_API UTurretAttachmentSelectionWidget : public UDropdownMenuChild
{
	GENERATED_BODY()
private:

protected:

public:

public:
	virtual void NativePreConstruct() override;

protected:

private:
	UFUNCTION()
	void EquipAttachment(ETurretAttachment Attachment);
	
};
