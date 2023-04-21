#include "Player.h"


Player::Player(Game* g)
{
	game = g;
	texture = game->LoadTexture("image/player.png");

	pos.x = 0;
	pos.y = 0;
	posRect = { pos.x, pos.y, TILE_SIZE, TILE_SIZE };
	spriteRect = { 0, 0, TILE_SIZE, TILE_SIZE };
}

void Player::Move(int x, int y)
{
	int newPlayerX = pos.x + x;
	int newPlayerY = pos.y + y;

	if (game->HitWall(newPlayerX, newPlayerY))
	{
		return;
	}

	pos.x = newPlayerX;
	pos.y = newPlayerY;

	posRect.x = pos.x * TILE_SIZE;
	posRect.y = pos.y * TILE_SIZE;
}

void Player::Draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, texture, &spriteRect, &posRect);
}
