#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <iostream>

/**
@brief Creates a Text Texture for use with a renderer
Creates a Text Texture from an image file, this can then be used with a renderer.
*/
class Text
{
private:
	/*font*/
	TTF_Font * font;
	/*font colour*/
	SDL_Color fontColour;
	/**The Texture data*/
	SDL_Texture* textureData;
public:

	/**
	Constructs a Text Texture
	Creates a Text Texture using an image location and a renderer.
	@param std::string The text to display
	@param std::string The location of the font file.
	@param int The size of the font.
	@param SDL_Renderer* The renderer.
	@param int The value of red.
	@param int The value of green.
	@param int The value of blue.
	*/
	Text(std::string, std::string, SDL_Renderer*, int, int, int);

	/**
	Destructs the Text Texture
	Destructs the Text Texture deleting the Texture from memory.
	*/
	~Text();

	/**
	Getter # Returns a pointer to the Texture
	Returns a pointer to the Texture data.
	*/
	SDL_Texture* getTexture();

	/**
	Pushes the image to the Renderer, to the XY Coordinates. This is scaled to the width and height
	inputed.
	@param SDL_Renderer* The renderer.
	@param int x coordinate of the image.
	@param int y coordinate of the image.
	@param int width of the scaled image.
	@param int height of the scaled image.
	*/
	void pushToScreen(SDL_Renderer*, int, int, int, int);
};