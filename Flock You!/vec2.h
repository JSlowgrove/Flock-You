#pragma once

/**
@brief Creates an Vec2 structure with functions
Creates an Vec2 structure with overloaded operators to create a new variable type for use as a 2D vector.
*/
struct  Vec2
{
	/*position variables*/
	float x;
	float y;
	
	/**
	Constructs an Vec2
	Constructs the Vec2 setting the values to 0,0
	*/
	Vec2()
	{
		x = 0;
		y = 0;
	}

	/**
	Constructs a Vec2
	Constructs the Vec2 setting the values to the input coordinates
	@param float The inputed x position
	@param float The inputed y position
	*/
	Vec2(float inputX, float inputY)
	{
		x = inputX;
		y = inputY;
	}

	/**
	Overloads the += operator
	Overloads the += operator allowing a Vec2 variable to use +=
	@param Vec2 The input Vec2
	*/
	Vec2* operator += (Vec2 a)
	{
		x += a.x;
		y += a.y;
		return this;
	}

	/**
	Overloads the -= operator
	Overloads the -= operator allowing a Vec2 variable to use -=
	@param Vec2 The input Vec2
	*/
	Vec2* operator -= (Vec2 a)
	{
		x -= a.x;
		y -= a.y;
		return this;
	}

};

/**
Overloads the - operator
Overloads the - operator allowing a Vec2 to be inverted
@param Vec2 The input Vec2
*/
inline Vec2 operator - (Vec2 a)
{
	Vec2 b;
	b.x = -a.x;
	b.y = -a.y;
	return b;
}

/**
Overloads the + operator
Overloads the + operator allowing Vec2's to be added to each other
@param Vec2 One of the input Vec2's
@param Vec2 One of the input Vec2's
*/
inline Vec2 operator + (Vec2 a, Vec2 b)
{
	Vec2 c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return c;
}

/**
Overloads the - operator
Overloads the - operator allowing Vec2's to be subtracted from each other
@param Vec2 One of the input Vec2's
@param Vec2 One of the input Vec2's
*/
inline Vec2 operator - (Vec2 a, Vec2 b)
{
	Vec2 c;
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	return c;
}