#include "Enemy.h"

void Enemy::initVariables()
{
	this->pointCount = rand() % 8 + 3; //min = 3  max = 10
	this->type = 0;
	this->speed = static_cast<float>(16/this->pointCount);
	this->hpMax = static_cast<int>(this->pointCount);
	this->hp = this->hpMax;
	this->damage = this->pointCount;
	this->points = this->pointCount;
}

void Enemy::initTexture()
{
	//Load a texture from file
	if (!this->texture.loadFromFile("Textures/vinox.png"))
	{
		cout << "ERROR::ENEMY::INITTEXTURE::Could not load texture file" << endl;
	}
}

void Enemy::initShape()
{
	//this->shape.setRadius(this->pointCount*5);
	//this->shape.setPointCount(this->pointCount);
	//this->shape.setFillColor(Color(rand() % 254 + 1, rand() % 254 + 1, rand() % 254 + 1, 255));

	//Set the texture to the sprite
	this->sprite.setTexture(this->texture);

	//Resize the sprite
	this->sprite.scale((float)(this->pointCount)/100, (float)(this->pointCount) / 100);
}

Enemy::Enemy(float pos_x, float pos_y)
{
	this->initVariables();
	this->initTexture();
	this->initShape();

	this->sprite.setPosition(pos_x, pos_y);
}

Enemy::~Enemy()
{
}

const FloatRect Enemy::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int& Enemy::getPoints() const
{
	return this->points;
}

const int& Enemy::getDamage() const
{
	return this->damage;
}


//Functions
void Enemy::update()
{
	this->sprite.move(0.f, this->speed);
}


void Enemy::render(RenderTarget* target)
{
	target->draw(this->sprite);
}
