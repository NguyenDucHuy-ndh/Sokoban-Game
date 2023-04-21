#pragma once

#include "Game.h"

struct Vec
{
	int x;
	int y;
};

class Player
{
public:
	Player(class Game* g);
	void Move(int x, int y);
	void Draw(SDL_Renderer* renderer);
	

private:
	Vec pos;
	SDL_Texture* texture;
	SDL_Rect posRect, spriteRect;
	class Game* game;

};

