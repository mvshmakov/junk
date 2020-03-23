#include "enemy.h"
#include "player.h"
#include "prototypes.h"

ENEMY::ENEMY(int x, int y)
{
	image.loadFromFile("Mario_tileset.png");
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	rect = FloatRect(x * 32.0F + 16.0F, y * 32.0F + 16.0F, 16.0F, 16.0F);

	dx = 0.05F;
	currentFrame = 0;
	life = true;
};

void ENEMY::set(int x, int y)
{
	rect = FloatRect(x * 32.0F + 16.0F, y * 32.0F + 16.0F, 16.0F, 16.0F);

	dx = 0.05F;
	currentFrame = 0;
	life = true;
};

void ENEMY::update(String TileMap[], float time, float offsetX, float offsetY)
{
	rect.left += dx * time;

	collision(TileMap);

	currentFrame += time * 0.005F;
	if (currentFrame > 2) currentFrame -= 2;

	sprite.setTextureRect(IntRect(18 * int(currentFrame), 0, 16, 16));
	if (!life) sprite.setTextureRect(IntRect(58, 0, 16, 16));

	sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
};

void ENEMY::collision(String TileMap[])
{
	for (int i = (int)rect.top / 32; i < (rect.top + rect.height) / 32; i++)
		for (int j = (int)rect.left / 32; j < (rect.left + rect.width) / 32; j++)
		{
			if ((TileMap[i][j] == 'B') || (TileMap[i][j] == '0'))
			{
				if (dx > 0) { rect.left = j * 32 - rect.width * 2 + 16; dx *= -1; }
				else if (dx < 0) { rect.left = j * 32 + rect.width * 2; dx *= -1; }
			}
			if (TileMap[i][j] == 'W')
			{
				sprite.setColor(Color(80, 80, 255, 180));
			}
		}
};