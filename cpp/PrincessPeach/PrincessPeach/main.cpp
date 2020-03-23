#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include <list>
#include "enemy.h"
#include "player.h"
#include "prototypes.h"
#include "levels.h"

int main()
{
	RenderWindow window(VideoMode(1280, 720), "Princess Peach"); //для работы FullScreen прописать 1920*1080
	while (menuFirst(window))
	{
		bool inGameMenuCheck(0);
		gameRunning(window, inGameMenuCheck);
	}
	return 0;
}

bool menuFirst(RenderWindow& window)
{
	Font font;
	font.loadFromFile("font.ttf");

	Text newGameText("NEW GAME", font, 100), authorsText("AUTHORS", font, 100), exitText("EXIT", font, 100);
	Text about("DEVELOPERS\nEGOR SHIROBOKOV\nMAXIM SHMAKOV\nEKATERINA SALTYKOVA\n\nPRESS ESC", font, 100);

	newGameText.setPosition(460, 180); authorsText.setPosition(460, 280); exitText.setPosition(460, 380);
	about.setColor(Color::Black); about.setPosition(window.getSize().x / 5.0F, window.getSize().y / 10.0F);

	Texture background1;
	background1.loadFromFile("background.jpg");
	Sprite background_1(background1);
	background_1.setPosition(0, 0);

	bool Menu = true;

	while (Menu)
	{
		int MenuNum = 0;

		Event event;
		while (window.pollEvent(event)) { if (event.type == Event::Closed) window.close(); }

		newGameText.setColor(Color::Black);
		authorsText.setColor(Color::Black);
		exitText.setColor(Color::Black);

		window.draw(background_1);

		//зеленый по наведению курсора
		if (IntRect(460, 180, 430, 100).contains(Mouse::getPosition(window))) { newGameText.setColor(Color::Red); MenuNum = 1; }
		if (IntRect(460, 280, 340, 100).contains(Mouse::getPosition(window))) { authorsText.setColor(Color::Red); MenuNum = 2; }
		if (IntRect(460, 380, 170, 100).contains(Mouse::getPosition(window))) { exitText.setColor(Color::Red); MenuNum = 3; }

		//действие по нажатию
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (MenuNum == 1) { Menu = false; }
			if (MenuNum == 2) { window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
			if (MenuNum == 3) { window.close(); Menu = false; return false; }
		}

		window.draw(newGameText);
		window.draw(authorsText);
		window.draw(exitText);
		window.display();
	}
};

int menuSecond(RenderWindow& window, PLAYER& Princess)
{
	Font font;
	font.loadFromFile("font.ttf");

	Text continueText("CONTINUE", font, 100), newGameText("NEW GAME", font, 100), restartLevelText("RESTART LEVEL", font, 100), mainMenuText("MAIN MENU", font, 100);

	continueText.setPosition(460, 180);
	newGameText.setPosition(460, 280);
	restartLevelText.setPosition(460, 380);
	mainMenuText.setPosition(460, 480);

	Texture background1;
	background1.loadFromFile("background.jpg");
	Sprite background_1(background1);
	background_1.setPosition(0, 0);

	bool Menu = true;

	while (Menu)
	{
		int MenuNum = 0;

		Event event;
		while (window.pollEvent(event)) { if (event.type == Event::Closed) window.close(); }

		continueText.setColor(Color::Black);
		newGameText.setColor(Color::Black);
		restartLevelText.setColor(Color::Black);
		mainMenuText.setColor(Color::Black);

		background_1.setColor(Color(255, 255, 255, 5));
		window.draw(background_1);

		//зеленый по наведению курсора
		if (IntRect(460, 180, 350, 100).contains(Mouse::getPosition(window))) { continueText.setColor(Color::Red); MenuNum = 1; }
		if (IntRect(460, 280, 430, 100).contains(Mouse::getPosition(window))) { newGameText.setColor(Color::Red); MenuNum = 2; }
		if (IntRect(460, 380, 500, 100).contains(Mouse::getPosition(window))) { restartLevelText.setColor(Color::Red); MenuNum = 3; }
		if (IntRect(460, 480, 450, 100).contains(Mouse::getPosition(window))) { mainMenuText.setColor(Color::Red); MenuNum = 4; }

		//действие по нажатию
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (MenuNum == 1) { Menu = false; return 2; }
			if (MenuNum == 2) { Princess.level = 1; Menu = false; return 1; }
			if (MenuNum == 3) { Menu = false; return 3; }
			if (MenuNum == 4) { Menu = false; return 0; }
		}

		window.draw(continueText);
		window.draw(newGameText);
		window.draw(restartLevelText);
		window.draw(mainMenuText);
		window.display();
	}
};

bool startGame(RenderWindow& window)
{
	std::cout << "NEW GAME";

	Texture tileSet, peachSad;
	tileSet.loadFromFile("terrain_atlas.png"); peachSad.loadFromFile("peach_sad.png");

	Sprite tile(tileSet), sad(peachSad);

	PLAYER princess;
	princess.set(6, 15);

	Font font;
	font.loadFromFile("font.ttf");

	Text point_text("", font, 30), pointTextFinal("", font, 50), totalPoints("", font, 50), totalTime("", font, 50),
		gameOver("PRESS ESC AND\nRESTART GAME", font, 150);

	totalPoints.setColor(Color::Red); totalPoints.setPosition(500, 100);
	totalTime.setColor(Color::Red); totalTime.setPosition(500, 150);
	gameOver.setColor(Color::Red); gameOver.setPosition(200, 170);
	point_text.setColor(Color::Black); point_text.setStyle(Text::Bold);

	sad.setPosition(800, window.getSize().y - 201 * 1.5F); sad.setScale(1.5, 1.5);

	//музыка
	Music music;
	music.openFromFile("Mario_Theme.ogg");
	playMusic(music, 1);

	float offsetX(0), offsetY(0);
	String TileMap[H];
	TileMapClass Map;
	std::list<ENEMY*> enemies;
	std::list<ENEMY*>::iterator it;

	//часы
	Clock clock, gameTimeClock; //игровое время
	int timeCorrection(0);

	//ОСНОВНОЙ ЦИКЛ
	levelGen(enemies, princess, TileMap, Map, offsetX, offsetY, 0);

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		if (princess.life > 0) princess.gameTime = gameTimeClock.getElapsedTime().asSeconds() - timeCorrection;

		clock.restart();
		time /= 800; //регулировать скорость игры

		Event event;
		while (window.pollEvent(event)) { if (event.type == Event::Closed) window.close(); }

		if (princess.life > 0) { princess.movement(); princess.inWater = false; } //движение Принцессы

		//обновление информации об объектах
		princess.update(time, window, tile, princess, TileMap, enemies, it, offsetX, offsetY, Map, clock);

		clock.restart();

		for (it = enemies.begin(); it != enemies.end(); )
		{
			ENEMY *enemy = *it;
			enemy->update(TileMap, time, offsetX, offsetY);
			if (!(enemy->life)) { it = enemies.erase(it); delete enemy; }
			else it++;
		}

		//пересечение с врагом
		for (it = enemies.begin(); it != enemies.end(); it++)
		{
			if (princess.rect.intersects((*it)->rect))
			{
				if ((*it)->life)
				{
					if (princess.dy > 0) { (*it)->dx = 0; princess.dy = -0.2F; (*it)->life = false; std::cout << "-1 ENEMY" << std::endl; }
					else {
						princess.death(window, offsetX, offsetY);
						princess.set(Map.getSpawnPoint(princess, "x"), Map.getSpawnPoint(princess, "y"));
						clock.restart();
						drawScreen(window, tile, princess, enemies, it, TileMap, offsetX, offsetY);
					}
				}
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			playMusic(music, 2);
			switch (menuSecond(window, princess))
			{
			case 0:
				return false; break;
			case 1:
				clock.restart(); return true; break;
			case 2:
				clock.restart(); break;
			case 3:
				playMusic(music, 0); clock.restart(); levelGen(enemies, princess, TileMap, Map, offsetX, offsetY, 0);  break;
			}
			playMusic(music, 1);
		}

		//камера
		if (princess.rect.left > 640) offsetX = princess.rect.left - 640; //отнимаем половину ширины экрана, чтобы персонаж попал в середину экрана
		if (princess.rect.top > 560) offsetY = princess.rect.top - 550;

		timeCorrection = gameTimeClock.getElapsedTime().asSeconds() - princess.gameTime;

		drawScreen(window, tile, princess, enemies, it, TileMap, offsetX, offsetY);
		guiStream(window, princess, point_text);

		if (princess.life < 1) { window.draw(gameOver); window.draw(sad); }

		window.display();
	}
}

void gameRunning(RenderWindow& window, bool& inGameMenuCheck)
{
	if (startGame(window)) { gameRunning(window, inGameMenuCheck); }
}

void drawScreen(RenderWindow& window, Sprite& tile, PLAYER& princess, std::list<ENEMY*>& enemies, std::list<ENEMY*>::iterator it, String TileMap[], float offsetX, float offsetY)
{
	window.clear(Color(127, 199, 255)); //делаем заливку

	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
		{
			if (TileMap[i][j] == 'C')
			{
				if ((princess.level == 1) || (princess.level == 3)) tile.setTextureRect(IntRect(960, 0, 64, 156));
				else tile.setTextureRect(IntRect(354, 442, 48, 64));
			}
			if (TileMap[i][j] == 'B')
			{
				if (princess.level == 1) tile.setTextureRect(IntRect(864, 320, 32, 32));
				else tile.setTextureRect(IntRect(672, 704, 32, 32));
			}
			if (TileMap[i][j] == '0') tile.setTextureRect(IntRect(386, 777, 25, 20));
			if (TileMap[i][j] == 'A') tile.setTextureRect(IntRect(288, 448, 32, 32));
			if (TileMap[i][j] == 'S') tile.setTextureRect(IntRect(32, 250, 32, 32));
			if (TileMap[i][j] == 'W') tile.setTextureRect(IntRect(672, 544, 32, 32));
			if (TileMap[i][j] == ' ') continue;
			tile.setPosition(j * 32 - offsetX, i * 32 - offsetY);
			window.draw(tile);
		}

	window.draw(princess.sprite);

	for (it = enemies.begin(); it != enemies.end(); it++)
	{
		window.draw((*it)->sprite);
	}
}

void levelGen(std::list<ENEMY*>& enemies, PLAYER& princess, String TileMap[], TileMapClass Map, float& offsetX, float& offsetY, bool levelCompleted)
{
	if (levelCompleted) { princess.sumPoints += princess.points; princess.sumTime += princess.gameTime; princess.points = 0; }
	princess.gameTime = 0;

	offsetX = 0; offsetY = 0;

	switch (princess.level)
	{
	case 1:
	{
		for (int h = 0; h < H; h++)
			TileMap[h] = Map.TileMap1[h];
		princess.set(Map.getSpawnPoint(princess, "x"), Map.getSpawnPoint(princess, "y"));
		enemies.clear();
		enemies.push_back(new ENEMY(25, 19));
		enemies.push_back(new ENEMY(29, 19));
		enemies.push_back(new ENEMY(15, 8));
		enemies.push_back(new ENEMY(55, 15));
		enemies.push_back(new ENEMY(72, 19));
		break;
	}
	case 2:
	{
		for (int h = 0; h < H; h++)
			TileMap[h] = Map.TileMap2[h];
		princess.set(Map.getSpawnPoint(princess, "x"), Map.getSpawnPoint(princess, "y"));
		enemies.clear();
		enemies.push_back(new ENEMY(35, 19));
		enemies.push_back(new ENEMY(91, 12));
		enemies.push_back(new ENEMY(89, 16));
		break;
	}
	case 3:
	{
		for (int h = 0; h < H; h++)
			TileMap[h] = Map.TileMap3[h];
		princess.set(Map.getSpawnPoint(princess, "x"), Map.getSpawnPoint(princess, "y"));
		enemies.clear();
		enemies.push_back(new ENEMY(2, 5));
		enemies.push_back(new ENEMY(15, 5));
		enemies.push_back(new ENEMY(24, 13));
		enemies.push_back(new ENEMY(54, 8));
		enemies.push_back(new ENEMY(91, 8));
		break;
	}
	}
}

void guiStream(RenderWindow& window, PLAYER& princess, Text& point_text)
{
	std::ostringstream playerScoreString, gameTimeString;
	playerScoreString << princess.points; gameTimeString << princess.gameTime;
	point_text.setString("Number of points " + playerScoreString.str() + "\nGame time " + gameTimeString.str());
	point_text.setPosition(70, 20);
	window.draw(point_text);
}

void playMusic(Music& music, int state)
{
	switch (state)
	{
	case 0:
		music.stop(); break;
	case 1:
		music.setVolume(30);
		music.play();
		music.setLoop(true);
		break;
	case 2:
		music.pause();
	}
}

void over(RenderWindow& window)
{
	Font font; font.loadFromFile("font.ttf");

	Text over("\tOOPS\n TRY AGAIN", font, 200);  over.setColor(Color::Red); over.setPosition(190, 170);

	window.draw(over); window.display();
}

void gameOver(RenderWindow& window)
{
	Font font; font.loadFromFile("font.ttf");
	Text gameOver("PRESS ESC AND\nRESTART GAME", font, 150); gameOver.setColor(Color::Red); gameOver.setPosition(200, 170);

	Texture peachSad;  peachSad.loadFromFile("peach_sad.png");
	Sprite sad(peachSad); sad.setPosition(800, window.getSize().y - 201 * 1.5F); sad.setScale(1.5, 1.5);

	window.draw(gameOver); window.draw(sad); window.display();
}