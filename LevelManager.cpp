#include "LevelManager.h"


void LevelManager::LoadLevel(string file)
{
	int rowCount = 0;
	int colCount = 0;

	levelFile.open(file);
	if (levelFile.is_open())
	{
		char inChar;
		while (levelFile.get(inChar))
		{
			if (inChar == '\n')
			{
				colCount = 0;
				rowCount++;
			}
			else
			{
				levelMap[colCount][rowCount] = inChar;
				colCount++;
			}
		}
	}


}
