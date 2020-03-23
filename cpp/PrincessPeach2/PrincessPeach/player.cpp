#include "enemy.h"
#include "player.h"
#include "levels.h"
#include "prototypes.h"
#include <iostream>

PLAYER::PLAYER() //конструктор класса
{
	image.loadFromFile("peach_png2.png");
	sprite.setTexture(image);
	sprite.setTextureRect(IntRect(0, 0, 24, 49));
	dx = dy = 0.2F;
	сurrentFrame = 0;
	life = 3; sumTime = 0;
	points = 0; sumPoints = 0;
	level = 1;
};

void PLAYER::set(int x, int y)
{
	rect = FloatRect(x * 32, y * 32, 24, 49);
	dx = dy = 0.2F;
	сurrentFrame = 0;
};

void PLAYER::update(float time, RenderWindow &window, Sprite &tile,
	PLAYER &princess, String TileMap[], std::list<ENEMY*>& enemies,
	std::list<ENEMY*>::iterator it, float& offsetX, float& offsetY, TileMapClass Map, Clock& clock)
{
	rect.left += dx * time; //перемещаем координату x на dx*time

	collision(0, window, tile, princess, TileMap, enemies, it, offsetX, offsetY, Map, clock);

	if (!onGround) dy = dy + 0.001F*time; //если не на земле, то двигается с ускорением
	rect.top += dy*time; //координата y
	onGround = false;

	collision(1, window, tile, princess, TileMap, enemies, it, offsetX, offsetY, Map, clock);

	сurrentFrame += 0.009F*time; //скорость анимации

	if (сurrentFrame > 8) сurrentFrame -= 8;

	if (inWater)
	{
		if (dx > 0) sprite.setTextureRect(IntRect(34 * int(сurrentFrame), 51, 34, 36)); //если движение вправо
		if (dx < 0) sprite.setTextureRect(IntRect(34 * int(сurrentFrame) + 34, 51, -34, 36)); //если движение влево
	}
	else
	{
		if (dx > 0) sprite.setTextureRect(IntRect(22.8 * int(сurrentFrame), 0, 22.9, 49)); //если движение вправо
		if (dx < 0) sprite.setTextureRect(IntRect(22.6 * int(сurrentFrame) + 22.6, 0, -22.6, 49)); //если движение влево
	}

	if (life == 0) sprite.setTextureRect(IntRect(111, 122, 28, 49));

	sprite.setPosition(rect.left - offsetX, rect.top - offsetY); //выводим спрайт на позицию (x,y)

	dx = 0;
};

void PLAYER::collision(int dir, RenderWindow& window, Sprite& tile,
	PLAYER& princess, String TileMap[], std::list<ENEMY*>& enemies,
	std::list<ENEMY*>::iterator it, float& offsetX, float& offsetY,
	TileMapClass Map, Clock& clock) //функция обработки столкновений
{
	for (int i = rect.top / 32; i < (rect.top + rect.height) / 32; i++)
	{
		for (int j = rect.left / 32; j < (rect.left + rect.width) / 32; j++)
		{
			switch (TileMap[i][j])
			{
			case 'B':
			{
				if ((dx > 0) && (dir == 0)) rect.left = j * 32.0F - rect.width;
				if ((dx < 0) && (dir == 0)) rect.left = j * 32.0F + 32.0F;
				if ((dy > 0) && (dir == 1)) { rect.top = i * 32.0F - rect.height; dy = 0; onGround = true; }
				if ((dy < 0) && (dir == 1)) { rect.top = i * 32.0F + 32.0F; dy = 0.0F; }
				break;
			}
			case 'W':
			{
				inWater = true;
				break;
			}
			case '0':
			{
				TileMap[i][j] = ' ';
				points++;
				std::cout << "Points: " << points << std::endl;
				break;
			}
			case 'S':
			{
				death(window, offsetX, offsetY);
				princess.set(Map.getSpawnPoint(princess, "x"), Map.getSpawnPoint(princess, "y"));
				clock.restart();
				drawScreen(window, tile, princess, enemies, it, TileMap, offsetX, offsetY);
				break;
			}
			case 'A':
			{
				if (points > 0)
				{
					TileMap[i][j] = ' ';
					drawScreen(window, tile, princess, enemies, it, TileMap, offsetX, offsetY);
					level++;
					levelGen(enemies, princess, TileMap, Map, offsetX, offsetY, 1);
					break;
				}
			}
			}
		}
	}
};

void PLAYER::death(RenderWindow& window, float& offsetX, float& offsetY)
{
	life--;
	std::cout << "Current life: " << life << std::endl;
	sprite.setColor(Color::Red);
	window.draw(sprite);
	if (life > 0)
	{
		over(window);
		sprite.setColor(Color::White);
		sleep(milliseconds(2000)); //добавить сюда финальную
	}
	dx = dy = 0.2F;
	offsetX = offsetY = 0;
};

void PLAYER::movement()
{
	if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
	{
		if (!inWater) dx = -0.2F;
		else dx = -0.1F;
	}
	if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
	{
		if (!inWater) dx = 0.2F;
		else dx = 0.1F;
	}
	if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up))
	{
		if (onGround) {
			if (!inWater) { dy = -0.55F; onGround = false; } //если мы на земле, то только тогда можно прыгнуть
			else { dy = -0.3F; onGround = false; }
		}
	}
};