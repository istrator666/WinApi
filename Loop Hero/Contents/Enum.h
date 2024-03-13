#pragma once
#include <EngineBase\EngineMath.h>
#include <EngineCore\EngineCore.h>
#include <EngineCore\ImageRenderer.h>

enum class IntroState
{
	Idle,
	Next,
	Prev,
	Skip
};

enum class ECollision
{
	Map,
	Card,
	Equipment,
	ItemInventory,
};

enum class EStageState
{
	Talk1,
	Talk2,
	Talk3,
	Talk4,
	Talk5,
	Talk6,
	Talk7,
	Talk8,
	Talk9,
	Move,
	Fight,
	Pause,
};

enum class CharacterStatus
{
	Idle,
	Attack,
	Hurt,
	Death,

};

enum class MonsterType
{
	Slime,
	Ratwolf,
	Spider,
	Skeleton,
	CrackedSkeleton,
	SkeletonArcher,
	CrackedSkeletonArcher,
	Mimic,
	BloodClot,
	Harpy,
};

enum class BossType
{
	Lich,
	Priestess,
	PriestessAngel,
	Hunter,
	HunterPet,
	Omega,
};

/// <summary>
/// 0. Ȳ����
/// 1. ����
/// 2. ��Ǯ
/// 3. ���Ǳ�
/// 4. ����
/// 5. ��Ż�� ����
/// 6. ������ ����
/// 7. �й�
/// 8. ������� ��
/// 9. ����
/// 10. ��
/// 11. ����?
/// 12. �ٸ�
/// </summary>
enum class TileType
{
	WASTELAND = 0,
	CEMETERY,
	GROVE,
	BLOODPATH,
	VILLAGE,
	RANSACKEDVILLAGE,
	COUNTSLAND,
	WHEATFIELDS,
	OVERGROWNFIELD,
	RUINS,
	SWAMP,
	AVILLAGE,
	BRIDGE,

};

/// <summary>
/// 0. �Ǽ� ����
/// 1. �Ź� ��ġ
/// 2. ������ ����
/// 3. ����
/// 4. ���ļ�
/// 5. ���ε�
/// 6. ��� �߿���
/// 7. ��� ������
/// 8. ������ ���θ�
/// 9. �� ������
/// 10. ������ �� ������
/// 11. �������� ��Ǯ
/// 12. ���ָ� ��Ǯ
/// 13. ���� �߿���
/// 14. ���� ��
/// 15. ���� ����
/// 16. ���������� ���尣
/// 17. �ð��� ����
/// </summary>
enum class TileSideType
{
	NONE = 0,
	SPIDERCOCOON,
	VAMPIREMANSION,
	BATTLEFIELD,
	SHIPWRECK,
	ROADLANTERN,
	GOBLINCAMP,
	GOBLINLOOKOUT,
	WITCHHUT,
	BOOKERY,
	ABANDONEDBOOKERY,
	BLOODGROVE,
	HUNGRYGROVE,
	BANDITCAMP,
	REED,
	OUTPOST,
	SMITHSFORGE,
	CHRONOCRYSTALS,

};

/// <summary>
/// 0. �Ǽ� ����
/// 1. ����
/// 2. ��
/// 3. ����츮
/// 4. ������
/// 5. ������ ������
/// 6. �縷
/// 7. �籸
/// 8. ������Ʈ
/// 9. ��
/// 10. ���ƽý�
/// 11. ��
/// 12. ��� ��
/// 13. ��Ÿ���� ��
/// 14. ��Ű
/// 15. ����
/// 16. ����
/// </summary>
enum class TileSightType
{
	NONE = 0,
	ROCK,
	MOUNTAIN,
	MOUNTAINPEAK,
	MEADOW,
	BLOOMINGMEADOW,
	DESERT,
	SANDDUNES,
	ZIGGURAT,
	RIVER,
	OASIS,
	FOREST,
	THICKET,
	BURNEDFOREST,
	MAQUIS,
	SUBURBS,
	TOWNS,
};

/// <summary>
/// 0. �Ǽ� ����
/// 1. �ݰ�
/// 2. �ֺ� �ݰ�
/// 3. ��ǳ�� ���
/// 4. ���
/// 5. �ð��� ���
/// 6. ��ġ�� ����
/// </summary>
enum class TileSpecialType
{
	NONE = 0,
	TREASURY,
	BROKENTREASURY,
	STORMTEMPLE,
	BEACON,
	TEMPORALBEACON,
	LICHSPALACE,
};

