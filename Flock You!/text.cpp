#include "text.h"

/**************************************************************************************************************/

/*Constructs the texture*/
Text::Text(std::string text, std::string fontName, SDL_Renderer* renderer, int r, int g, int b)
{
	/*initialise font and font colour*/
	font = TTF_OpenFont(fontName.c_str(), 10);
	fontColour = { r, g, b };

	/*Declaring the surface*/
	SDL_Surface *surface;

	/*Creating the surface from the font*/
	surface = TTF_RenderText_Solid(font, text.c_str(), fontColour);

	/*Converts the surface into texture data*/
	textureData = SDL_CreateTextureFromSurface(renderer, surface);

	/*delete the surface from memory*/
	SDL_FreeSurface(surface);
}

/**************************************************************************************************************/

/*Destructs the Texture*/
Text::~Text()
{
	/*deletes the texture from memory*/
	SDL_DestroyTexture(textureData);
	/*delete font*/
	TTF_CloseFont(font);
	font = NULL;
}

/**************************************************************************************************************/

/*Getter # Texture*/
SDL_Texture* Text::getTexture()
{
	/*returns the texture data*/
	return textureData;
}

/**************************************************************************************************************/

/*Pushes the scaled texture to the Renderer*/
void Text::pushToScreen(SDL_Renderer* renderer, int x, int y, int width, int height)
{
	/*create the destination rectangle of the texture*/
	SDL_Rect destRect;
	destRect.x = x; /*destination x coordinate*/
	destRect.y = y; /*destination y coordinate*/
	destRect.w = width; /*destination width (scale along the x axis)*/
	destRect.h = height; /*destination height (scale along the y axis)*/

	/*Copy the texture to the renderer at the destination rectangle*/
	SDL_RenderCopy(renderer, textureData, NULL, &destRect);
}
