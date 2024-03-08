#pragma once
#include "EngineCore/Actor.h"

class UnitStatus : public AActor
{
public:
	// constrcuter destructer
	UnitStatus();
	~UnitStatus();

	// delete Function
	UnitStatus(const UnitStatus& _Other) = delete;
	UnitStatus(UnitStatus&& _Other) noexcept = delete;
	UnitStatus& operator=(const UnitStatus& _Other) = delete;
	UnitStatus& operator=(UnitStatus&& _Other) noexcept = delete;

	void SetHP(int _HP)
	{
		HP = _HP;
	}

	void SetMaxHP(int _MaxHP)
	{
		MaxHP = _MaxHP;
	}

	void SetMinAttck(int _MinAttck)
	{
		MinAttck = _MinAttck;
	}

	void SetMaxAttck(int _MaxAttck)
	{
		MaxAttck = _MaxAttck;
	}

	void SetDefense(int _Defense)
	{
		Defense = _Defense;
	}

	void SetStamina(int _Stamina)
	{
		Stamina = _Stamina;
	}

	void SetAttackSpeed(float _AttackSpeed)
	{
		AttackSpeed = _AttackSpeed;
	}

	void SetAttackGauge(float _AttackGauge)
	{
		AttackGauge = _AttackGauge;
	}

	void SetHPRegen(int _HPRegen)
	{
		HPRegen = _HPRegen;
	}

	void SetEvasion(int _Evasion)
	{
		Evasion = _Evasion;
	}

	void SetCritical(int _Critical)
	{
		Critical = _Critical;
	}

	void SetCounterAttack(int _CounterAttack)
	{
		CounterAttack = _CounterAttack;
	}

	void SetLifeDrain(int _LifeDrain)
	{
		LifeDrain = _LifeDrain;
	}


	void SetMoveSpeed(float _MoveSpeed)
	{
		MoveSpeed = _MoveSpeed;
	}

	int GetHP()
	{
		return HP;
	}

	int GetMaxHP()
	{
		return MaxHP;
	}

	int GetMinAttck()
	{
		return MinAttck;
	}

	int GetMaxAttck()
	{
		return MaxAttck;
	}

	int GetDefense()
	{
		return Defense;
	}

	int GetStamina()
	{
		return Stamina;
	}

	float GetAttackSpeed()
	{
		return AttackSpeed;
	}
	
	float GetAttackGauge()
	{
		return AttackGauge;
	}

	int GetHPRegen()
	{
		return HPRegen;
	}

	int GetEvasion()
	{
		return Evasion;
	}

	int GetCritical()
	{
		return Critical;
	}

	int GetCounterAttack()
	{
		return CounterAttack;
	}

	int GetLifeDrain()
	{
		return LifeDrain;
	}

	float GetMoveSpeed()
	{
		return MoveSpeed;
	}

	void StatusInit(int _HP, int _MaxHP, int _MinAttck, int MaxAttck, int _Defense, float _AttackSpeed, float _AttackGauge, int _HPRegen, int _Critical, int _CounterAttack, int _LifeDrain);
	void LevelUP()
	{
		Level += 1;
	}

protected:

private:
	int HP = 250;
	int MaxHP = 250;
	int MinAttck = 30; //4
	int MaxAttck = 60; //6
	int Defense = 0;
	float AttackSpeed = 1.0f;
	float AttackGauge = 0;
	int Stamina = 100;
	int HPRegen = 0;
	int Evasion = 0;
	int Critical = 0;
	int CounterAttack = 0;
	int LifeDrain = 0;
	int Level = 0;

	float MoveSpeed = 250.0f;

};

