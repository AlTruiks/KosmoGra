#pragma once

#include <map>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include <string>
#include <sstream>

class Game
{
private:
	//Window
	RenderWindow* window;

	//Resources
	map<string, Texture*> textures;
	vector<Bullet*> bullets;

	//GUI
	Font font;
	Text pointText;

	Text gameOverText;

	//World
	Texture worldTexture;
	Sprite worldBackground;

	//Systems
	unsigned points;

	//Player
	Player* player;

	//Player GUI
	RectangleShape playerHpBar;
	RectangleShape playerHpBarBack;

	//Enemies
	float spawnTimer;
	float spawnTimerMax;
	vector<Enemy*> enemies;

	//Private functions
	void initWindow();
	void initTextures();
	void initGUI();
	void initWorld();
	void initSystems();

	void initPlayer();
	void initEnemies();

public:
	Game();
	virtual ~Game();

	//Functions
	void run();

	void updatePollEvents();
	void updateInput();
	void updateGUI();
	void updateWorld();
	void updateCollision();
	void updateBullets();
	void updateEnemies();
	void updateCombat();
	void update();
	void renderGUI();
	void renderWorld();
	void render();
};

