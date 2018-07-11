// Fill out your copyright notice in the Description page of Project Settings.

#include "TurretAttachmentButton.h"




void UTurretAttachmentButton::SetAttachment(ETurretAttachment Attachment)
{
	_Attachment = Attachment;
	OnPressed.AddDynamic(this, &UTurretAttachmentButton::Pressed);
}

void UTurretAttachmentButton::Pressed()
{
	OnPressed_Custom.Broadcast(_Attachment);
}
