#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace sf;
using namespace std;

class Bullet
{
	Sprite shape;

	Vector2f direction;
	float movementSpeed;

private:
	

public:
	Bullet();
	Bullet(Texture* texture, float pos_x, float pos_y, float dir_X, float dir_Y, float movement_speed);
	virtual ~Bullet();

	//Accessor
	const FloatRect getBounds() const;

	void update();
	void render(RenderTarget& target);
};

