#pragma once

#include "Utils.h"
#include <fstream>
#include <string>


class LevelManager
{
public:
	void LoadLevel();
	void UpdateLevel();
	char levelMap[TILE_ROWS][TILE_COLS] = { '0' };

private:
	ifstream levelFile;
	
	int currentLevel = 1;
};

