
#pragma  once
#include "CoreMinimal.h"
#include "UObject/GCObject.h"

#include "HUD/Main/Upgrades/UpgradeTypeEnum.h"

class FSaveManager : public FGCObject
{
private:
	static FSaveManager* _singleton;

	int32 _CurrentSaveSlot = 0;

	class UTurretSave* _TurretSave;

	class UWeaponUnlockSave* _WeaponUnlocks;

	class UWeaponUpgradeSave* _WeaponUpgrades;

	class UTurretUnlockSave* _TurretUnlocks;

	class UTurretUpgradeSave* _TurretUpgrades;

protected:

public:

public:
	FSaveManager();

	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;

	static FSaveManager& Get();

	void SetSaveSlot(int32 NewSaveSlot);

	int32 GetSaveSlot();

	void SaveTurret(class ATurret* Turret);

	void UnlockWeapon(int32 WeaponID);

	bool IsWeaponUnlocked(int32 WeaponID);

	void UpgradeWeapon(int32 WeaponID, struct FWeaponUpgrade WeaponUpgrades);

	struct FWeaponUpgrade GetWeaponUpgrades(int32 WeaponID);

	void UnlockTurretUpgrade(ETurretUpgradeType Upgrade);

	bool IsTurretUpgradeUnlocked(ETurretUpgradeType Upgrade);

	void UpgradeTurret(ETurretUpgradeType Upgrade, struct FTurretUpgrade TurretUpgrades);

	struct FTurretUpgrade GetTurretUpgrades(ETurretUpgradeType Upgrade);

	UTurretSave* GetTurretSave();

protected:

private:
	static void Destroy();

	// Loading
	void LoadSaveFiles();

	void LoadTurret();

	void LoadWeaponUnlocks();

	void LoadWeaponUpgrades();

	void LoadTurretUnlocks();

	void LoadTurretUpgrades();


	// Saving
	void SaveWeaponUnlocks();

	void SaveWeaponUpgrades();

	void SaveTurretUnlocks();

	void SaveTurretUpgrades();
	
};