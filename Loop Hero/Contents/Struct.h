#pragma once
#include <EngineBase/EngineMath.h>
#include "Enum.h"

struct CoordinateKey
{
	__int64 Key;

	CoordinateKey(int x, int y)
	{
		Key = MakeKey(x, y);
	}

	static __int64 MakeKey(int x, int y)
	{
		return ((__int64)x << 32) | ((unsigned int)y & 0xFFFFFFFF);
	}
};

struct TileInfo
{
	static const int Rows = 13;
	static const int Cols = 21;
	static const int Size = 50;
};

struct SpawnTileData {
	FVector TileLocation;
	FVector SpawnLocation;
	TileType Tile;
};