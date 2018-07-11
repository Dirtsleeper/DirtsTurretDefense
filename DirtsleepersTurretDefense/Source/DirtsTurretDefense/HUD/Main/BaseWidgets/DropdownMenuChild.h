// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "DropdownMenuWidget.h"
#include "Blueprint/WidgetTree.h"

#include "CoreMinimal.h"
#include "MainWidget.h"
#include "DropdownMenuChild.generated.h"

/**
 * 
 */
UCLASS()
class DIRTSTURRETDEFENSE_API UDropdownMenuChild : public UMainWidget
{
	GENERATED_BODY()
private:

protected:
	UPROPERTY(meta = (BindWidget))
	class UDropdownMenuWidget* m_DropDown;

public:

public:
	UDropdownMenuChild();

protected:

private:	
	
};
