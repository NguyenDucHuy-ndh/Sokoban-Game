#pragma once

#include "Utils.h"
#include "LevelManager.h"
#include "Player.h"

class Game
{
public:
	bool Init();
	void GameLoop();
	void Shutdown();

	SDL_Texture* LoadTexture(string path);
	bool HitWall(int x, int y);

private:
	void HandleEvents();
	void Update();
	void Draw();

	bool isRunning = true;

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* wallTexture = nullptr;
	SDL_Texture* groundTexture = nullptr;

	class LevelManager* levelManager;

	class Player* player;
};


