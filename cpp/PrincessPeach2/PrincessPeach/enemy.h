#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class ENEMY {
public:
	//Переменные
	FloatRect rect;
	Texture texture;
	Sprite sprite;
	Image image;
	float dx, dy;
	float currentFrame;
	bool life;

	//Функции
	ENEMY(int x, int y);
	void set(int x, int y);
	void update(String TileMap[], float time, float offsetX, float offsetY);
	void collision(String TileMap[]);
};