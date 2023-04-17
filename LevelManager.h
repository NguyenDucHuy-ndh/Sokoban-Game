#pragma once

#include "Utils.h"
#include <fstream>


class LevelManager
{
public:
	void LoadLevel(string file);
	char levelMap[TILE_ROWS][TILE_COLS] = { '0' };

private:
	ifstream levelFile;

};

