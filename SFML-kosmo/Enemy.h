#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
using namespace sf;
using namespace std;

class Enemy
{
private:
	unsigned pointCount;
	//CircleShape shape;
	Sprite sprite;
	Texture texture;
	int type;
	float speed;
	int hp;
	int hpMax;
	int damage;
	int points;
	
	void initVariables();
	void initTexture();
	void initShape();

public:
	Enemy(float pos_x, float pos_y);
	virtual ~Enemy();

	//Accessors
	const FloatRect getBounds() const;
	const int& getPoints() const;
	const int& getDamage() const;

	//Functions
	void update();
	void render(RenderTarget* target);
};

