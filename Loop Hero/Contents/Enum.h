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
/// 0. 황무지
/// 1. 묘지
/// 2. 수풀
/// 3. 피의길
/// 4. 마을
/// 5. 약탈된 마을
/// 6. 백작의 영지
/// 7. 밀밭
/// 8. 과성장된 밭
/// 9. 유적
/// 10. 늪
/// 11. 마을?
/// 12. 다리
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
/// 0. 건설 가능
/// 1. 거미 고치
/// 2. 흡혈귀 저택
/// 3. 전장
/// 4. 난파선
/// 5. 가로등
/// 6. 고블린 야영지
/// 7. 고블린 전망대
/// 8. 마녀의 오두막
/// 9. 고서 보관소
/// 10. 버려진 고서 보관소
/// 11. 피투성이 수풀
/// 12. 굶주린 수풀
/// 13. 도적 야영지
/// 14. 갈대 숲
/// 15. 전초 기지
/// 16. 대장장이의 대장간
/// 17. 시간의 수정
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
/// 0. 건설 가능
/// 1. 바위
/// 2. 산
/// 3. 산봉우리
/// 4. 목초지
/// 5. 만개한 목초지
/// 6. 사막
/// 7. 사구
/// 8. 지구라트
/// 9. 강
/// 10. 오아시스
/// 11. 숲
/// 12. 잡목 숲
/// 13. 불타버린 숲
/// 14. 마키
/// 15. 교외
/// 16. 도시
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
/// 0. 건설 가능
/// 1. 금고
/// 2. 텅빈 금고
/// 3. 폭풍의 사원
/// 4. 등대
/// 5. 시간의 등대
/// 6. 리치의 궁전
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

