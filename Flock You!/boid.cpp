#include "boid.h"

/**************************************************************************************************************/

/*Constructs the Boid object*/
Boid::Boid(Texture * inTexture, Vec2 inPosition, Vec2 inScale)
{
	/*initialise the pointer to the texture*/
	texture = inTexture;
	/*initialise the position*/
	position = inPosition;
	/*initialise the scale*/
	scale = inScale;
}

/**************************************************************************************************************/

/*Destructs the Boid object*/
Boid::~Boid()
{
}

/**************************************************************************************************************/

/*sets the position*/
void Boid::setPosition(Vec2 inPosition)
{
	/*sets the new position*/
	position = inPosition;
}

/**************************************************************************************************************/

/*gets the position*/
Vec2 Boid::getPosition()
{
	/*returns the position*/
	return position;
}

/**************************************************************************************************************/

/*sets the scale*/
void Boid::setScale(Vec2 inScale)
{
	/*sets the new scale*/
	scale = inScale;
}

/**************************************************************************************************************/

/*gets the scale*/
Vec2 Boid::getScale()
{
	/*returns the scale*/
	return scale;
}

/**************************************************************************************************************/

/*displays the Boid*/
void Boid::display(SDL_Renderer* renderer)
{
	/*push the texture to the screen using the Boid information*/
	texture->pushToScreen(renderer, (int)position.x, (int)position.y, (int) scale.x, (int) scale.y);
}