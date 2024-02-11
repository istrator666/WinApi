#include "Player.h"
#include <EngineCore\EngineCore.h>
#include <EnginePlatform\EngineInput.h>
#include "Bullet.h"
#include <EngineBase\EngineTime.h>
#include <vector>
#include <list>

Player::Player()
{
}

Player::~Player()
{
}

void Player::BeginPlay()
{
	AActor::BeginPlay();


}

void Player::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

