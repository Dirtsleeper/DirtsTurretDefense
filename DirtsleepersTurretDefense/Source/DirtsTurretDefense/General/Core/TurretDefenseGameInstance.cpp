// Fill out your copyright notice in the Description page of Project Settings.

#include "TurretDefenseGameInstance.h"




void UTurretDefenseGameInstance::Init()
{

}

void UTurretDefenseGameInstance::SetSelectedGamemode(EGamemode NewGamemode)
{
	m_SelectedGamemode = NewGamemode;
}

void UTurretDefenseGameInstance::SetSaveSlot(int32 Slot)
{
	_CurrentSaveSlot = Slot;
}

int32 UTurretDefenseGameInstance::GetSaveSlot()
{
	return _CurrentSaveSlot;
}
