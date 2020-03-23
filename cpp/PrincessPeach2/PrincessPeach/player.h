#pragma once

#include <SFML/Graphics.hpp>
#include <list>

using namespace sf;

class ENEMY;
class TileMapClass;

class PLAYER
{
public:
	//����������
	Sprite sprite;
	FloatRect rect;
	Texture image;
	float dx, dy; //��������
	float �urrentFrame; //������� ����
	bool onGround, inWater;
	int life, points, sumPoints, sumTime, gameTime;
	int level;

	//�������
	PLAYER(); //����������� ������
	void set(int x, int y);
	void update(float time, RenderWindow &window, Sprite &tile, PLAYER &princess,
		String TileMap[], std::list<ENEMY*>& enemies, std::list<ENEMY*>::iterator it,
		float& offsetX, float& offsetY, TileMapClass Map, Clock& clock);
	void collision(int dir, RenderWindow& window, Sprite& tile, PLAYER& princess,
		String TileMap[], std::list<ENEMY*>& enemies, std::list<ENEMY*>::iterator it,
		float& offsetX, float& offsetY, TileMapClass Map, Clock& clock);
	void death(RenderWindow& window, float& offsetX, float& offsetY);
	void movement();
};