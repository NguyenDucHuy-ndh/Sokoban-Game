#include "Player.h"


Player::Player(Game* g)
{
	game = g;
	texture = game->LoadTexture("image/player.png");
	direction = 0;
	pos.x = 0;
	pos.y = 0;
	posRect = { pos.x, pos.y, TILE_SIZE, TILE_SIZE };
	spriteRect = { 0, 0, TILE_SIZE, TILE_SIZE };
}

void Player::Move(int x, int y)
{
	SetDirection(x, y);
	int newPlayerX = pos.x + x;
	int newPlayerY = pos.y + y;

	if (game->HitWall(newPlayerX, newPlayerY))
	{
		return;
	}


	if (!game->BoxUpdated(x, y, newPlayerX, newPlayerY)) {
		return;
	}

	pos.x = newPlayerX;
	pos.y = newPlayerY;

	posRect = { pos.x * TILE_SIZE, pos.y * TILE_SIZE, TILE_SIZE, TILE_SIZE };
//	posRect = pos.y * TILE_SIZE;
}


void Player::SetDirection(int x, int y)
{
	if (x > 0)
	{
		direction = 2;
	}
	if (x < 0)
	{
		direction = 1;
	}
	if (y > 0)
	{
		direction = 0;
	}
	if (y < 0)
	{
		direction = 3;
	}
	
	// spriteRect = 
	spriteRect = { direction * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE };
}

void Player::Draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, texture, &spriteRect, &posRect);
}
void Player::Reset(int x, int y)
{
	direction = 0;
	pos.x = x;
	pos.y = y;
	posRect = { pos.x * TILE_SIZE, pos.y * TILE_SIZE, TILE_SIZE, TILE_SIZE };
	spriteRect = { 0, 0, TILE_SIZE, TILE_SIZE };
}