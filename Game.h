#pragma once

#include "Utils.h"
#include "LevelManager.h"
#include "Player.h"
#include "Box.h"

#include <vector>

class Game
{
public:
	bool Init();
	void GameLoop();
	void Shutdown();

	SDL_Texture* LoadTexture(string path);
	bool HitWall(int x, int y);
	
	bool BoxUpdated(int moveX, int moveY, int pX, int pY);
	

private:
	void HandleEvents();
	void Update();
	void Draw();

	bool isRunning = true;

	bool HitGoal(int x, int y);
	bool AllGoalsComplete();
	void DestroyBoxes();
	void InitLevel();
	void GoToNextLevel();
	bool CanPushBox(Box* box, int x, int y);

	void DrawMenu();
	void DrawMenu_2();

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* wallTexture = nullptr;
	SDL_Texture* groundTexture = nullptr;
	SDL_Texture* boxTexture = nullptr;
	SDL_Texture* goalTexture = nullptr;
	SDL_Texture* playTexture = nullptr;
	SDL_Texture* exitTexture = nullptr;
	SDL_Texture* levelcompleteTexture = nullptr;
	SDL_Texture* nextTexture = nullptr;
	SDL_Texture* quitTexture = nullptr;

	TTF_Font* font = nullptr;
	SDL_Surface* textSurface = nullptr;
	SDL_Texture* textTexture = nullptr;
	SDL_Color textColor;

	int upLevel = 0;

	SDL_Texture* startTexture = nullptr;

	class LevelManager* levelManager;

	class Player* player;
	vector<Box*> boxes;
};


