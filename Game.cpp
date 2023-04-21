#include "Game.h"

bool Game::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
	{
		cout << "SDL failed to initialize: " << SDL_GetError() << endl;
		return false;
	}

	if (IMG_Init(IMG_INIT_PNG) == 0)
	{
		cout << "SDL_Image failed to initialize: " << IMG_GetError << endl;
		return false;
	}

	window = SDL_CreateWindow("SOKOBAN", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	if (!window)
	{
		cout << "Window failed to initialize: " << SDL_GetError() << endl;
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (!renderer)
	{
		cout << "Renderer failed to initialize: " << SDL_GetError() << endl;
		return false;
	}

	levelManager = new LevelManager;
	levelManager->LoadLevel("Levels/level1.txt");

	wallTexture = LoadTexture("image/wall.png");
	groundTexture = LoadTexture("image/ground.png");

	player = new Player(this);
	   
	for (int r = 0; r < TILE_ROWS; r++)
	{
		for (int c = 0; c < TILE_COLS; c++)
		{
			if (levelManager->levelMap[c][r] == 'p')
			{
				player->Move(c, r);
			}
		}
	}

	return true;
}

void Game::GameLoop()
{
	while (isRunning)
	{
		HandleEvents();
		Update();
		Draw();
	}
}

void Game::HandleEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			isRunning = false;
		}
		
		if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_RIGHT:
				player->Move(1, 0);
				break;
			case SDLK_LEFT:
				player->Move(-1, 0);
				break;
			case SDLK_DOWN:
				player->Move(0, 1);
				break;
			case SDLK_UP:
				player->Move(0, -1);
				break;
			default:
				break;
			}
		}
	}


	const Uint8* keystates = SDL_GetKeyboardState(NULL);

	if (keystates[SDL_SCANCODE_ESCAPE])
	{
		isRunning = false;
	}
}

void Game::Update()
{

}

void Game::Draw()
{
	SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
	SDL_RenderClear(renderer);


	for (int r = 0; r < TILE_ROWS; r++)
	{
		for (int c = 0; c < TILE_COLS; c++)
		{
			SDL_Rect rect = { c * TILE_SIZE, r * TILE_SIZE, TILE_SIZE, TILE_SIZE };

			if (levelManager->levelMap[c][r] == 'x')
			{
				SDL_RenderCopy(renderer, wallTexture, NULL, &rect);
			}
			else
			{
				SDL_RenderCopy(renderer, groundTexture, NULL, &rect);
			}
		}
	}

	player->Draw(renderer);

	SDL_RenderPresent(renderer);
}

void Game::Shutdown()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_DestroyTexture(wallTexture);
	SDL_DestroyTexture(groundTexture);

	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* Game::LoadTexture(string path)
{
	SDL_Surface* tempSurface = IMG_Load(path.c_str());
	if (tempSurface == NULL)
	{
		cout << "Failed to load surface: " << IMG_GetError() << endl;
	}

	SDL_Texture* newTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	if (newTexture == NULL)
	{
		cout << "Failed to conver to Texture: " << SDL_GetError() << endl;
	}

	SDL_FreeSurface(tempSurface);

	return newTexture;
}

bool Game::HitWall(int x, int y)
{
	return levelManager->levelMap[x][y] == 'x';
}