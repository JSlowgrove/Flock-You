#pragma once

#include <SDL.h>
#include "texture.h"
#include "vec2.h"

/**
@brief Creates an Boid object
Creates an Boid object that is to be used for each Boid.
*/
class Boid
{
private:
	/*A pointer to Texture of the Boid*/
	Texture * texture;
	/*The Boid position*/
	Vec2 position;
	/*The Boid scale*/
	Vec2 scale;
public:
	/**
	Constructs an Boid object
	@param Texture * a pointer to the Texture
	@param Vec2 the initial Boid position
	@param Vec2 the Boid scale
	*/
	Boid(Texture *, Vec2, Vec2);

	/**
	Destructs an Boid object
	*/
	~Boid();

	/**
	Setter # sets the position
	@param Vec2 the new position
	*/
	void setPosition(Vec2);

	/**
	Getter # gets the position
	@returns Vec2 the position
	*/
	Vec2 getPosition();

	/**
	Setter # sets the scale
	@param Vec2 the new scale
	*/
	void setScale(Vec2);

	/**
	Getter # gets the scale
	@returns Vec2 the scale
	*/
	Vec2 getScale();

	/**
	Displays the Boid
	@param SDL_Renderer * a pointer to the renderer
	*/
	void display(SDL_Renderer *);
};