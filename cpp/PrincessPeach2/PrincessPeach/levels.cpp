#include "levels.h"
#include "enemy.h"
#include "player.h"

int TileMapClass::getSpawnPoint(PLAYER& Princess, std::string axis)
{
	if (axis == "x")
	{
		switch (Princess.level)
		{
		case 1:
			return 5; break;
		case 2:
			return 6; break;
		case 3:
			return 6; break;
		}
	}
	if (axis == "y")
	{
		switch (Princess.level)
		{
		case 1:
			return 17; break;
		case 2:
			return 17; break;
		case 3:
			return 17; break;
		}
	}
};