#pragma once

#include <SFML/Audio.hpp>
#include "player.h"
#include "enemy.h"
#include <list>

using namespace sf;

void levelGen(std::list<ENEMY*>& enemies, PLAYER& princess, String TileMap[], TileMapClass Map, float& offsetX, float& offsetY, bool levelCompleted);
void drawScreen(RenderWindow& window, Sprite& tile, PLAYER& princess, std::list<ENEMY*>& enemies, std::list<ENEMY*>::iterator it, String TileMap[], float offsetX, float offsetY);
void gameRunning(RenderWindow& window, bool& inGameMenuCheck);
void guiStream(RenderWindow& window, PLAYER& princess, Text& point_text);
void playMusic(Music& music, int state);
void over(RenderWindow& window);
void gameOver(RenderWindow& window);
bool startGame(RenderWindow& window);
bool menuFirst(RenderWindow& window);
int menuSecond(RenderWindow& window, PLAYER& princess);