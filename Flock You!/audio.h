#pragma once

#include <SDL_mixer.h>
#include <string>
#include <iostream>

/**
@brief Creates a Audio object to handle the SDL_Mixer.
*/
class Audio
{
private:
	Mix_Music * audio;
	Mix_Chunk * sound;
public:
	/**
	Constructs an Audio object
	Constructs the Audio object.
	@param std::string the file to be loaded
	@param bool is it a music file? if false its a sound file
	*/
	Audio(std::string, bool);

	/**
	De-constructs a Audio object
	De-constructs the Audio object
	*/
	~Audio();

	/**
	Starts the Audio playing
	Starts the Audio playing, also checks if not playing and starts again
	*/
	void startAudio();

	/**
	Plays the sound
	Plays the sound effect
	*/
	void playEffect();

	/**
	Stops the Audio playing
	*/
	void stopAudio();
};