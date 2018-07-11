// Fill out your copyright notice in the Description page of Project Settings.

#include "TurretAttachmentSelectionWidget.h"

#include "TurretAttachmentButton.h"


void UTurretAttachmentSelectionWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (m_DropDown)
	{
		m_DropDown->SetTitleText(FText::FromString(TEXT("Turret Attachments")));
		for (ETurretAttachment Attachment : EnumGetList<ETurretAttachment>(TEXT("ETurretAttachment")))
		{
			UTurretAttachmentButton* Button = WidgetTree->ConstructWidget<UTurretAttachmentButton>();
			Button->SetAttachment(Attachment);
			Button->OnPressed_Custom.AddDynamic(this, &UTurretAttachmentSelectionWidget::EquipAttachment);
			UTextBlock* Text = WidgetTree->ConstructWidget<UTextBlock>();
			Text->SetText(FText::FromString(EnumAsString<ETurretAttachment>(TEXT("ETurretAttachment"), Attachment, TEXT("TA_"), true)));
			Button->AddChild(Text);
			m_DropDown->AddChild(Button);
		}
	}
}

void UTurretAttachmentSelectionWidget::EquipAttachment(ETurretAttachment Attachment)
{
	m_GameMode->EquipTurretAttachment(Attachment);
}

