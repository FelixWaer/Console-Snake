#include "gameplay.h"
#include "iostream"
#include  "vector"
#include "cstdlib"
#include "ctime"

#include "snakeBody.h"
#include "Food.h"

std::vector<snakeBody> bodyVector;

std::shared_ptr<Food> theFood = std::make_shared<Food>();

bool foodSpawned = false;

void startUp(const int& bodyLength)
{
	static bool start = true;
	if (start)
	{
		srand(time(NULL));
		bodyVector.emplace_back(snakeBody(0, 0));
		spawnFood(bodyLength);
		 start = false;
	}
}

void movement(const char* p_key, int* p_xSpeed, int* p_ySpeed)
{
	if (*p_key == 'd' && *p_xSpeed >= 0)
	{
		*p_xSpeed = 1;
		*p_ySpeed = 0;
	}
	else if (*p_key == 'a' && *p_xSpeed <= 0)
	{
		*p_xSpeed = -1;
		*p_ySpeed = 0;
	}
	else if (*p_key == 's' && *p_ySpeed >= 0)
	{
		*p_xSpeed = 0;
		*p_ySpeed = 1;
	}
	else if (*p_key == 'w' && *p_ySpeed <= 0)
	{
		*p_xSpeed = 0;
		*p_ySpeed = -1;
	}
}

void draw(const int& bodyLength)
{
	for (int i = 0; i < 29; i++)
	{
		for (int j = 0; j < 120; j++)
		{
			for (int l = 0; l <= bodyLength; l++)
			{
				if (bodyVector[l].getX() == j && bodyVector[l].getY() == i)
				{
					std::cout << "X";
					break;
				}
				if (theFood->getX() == j && theFood->getY() == i && foodSpawned == true)
				{
					std::cout << "F";
					break;
				}
				if (l == bodyLength)
				{
					std::cout << " ";
				}
			}
		}
	}
}

void move(const int& bodyLength, const int& xSpeed, const int& ySpeed)
{
	int X = bodyVector[0].getX() + xSpeed;
	int Y = bodyVector[0].getY() + ySpeed;
	for (int i = bodyLength; i > 0; i--)
	{
		bodyVector[i].setPos(bodyVector[i - 1].getX(), bodyVector[i - 1].getY());
	}
	bodyVector[0].setPos(X, Y);
}

void addBody(int* p_snakeLenght)
{
	if (bodyVector[0].getX() == theFood->getX() && bodyVector[0].getY() == theFood->getY())
	{
		bodyVector.emplace_back(snakeBody(bodyVector[*p_snakeLenght].getX(), bodyVector[*p_snakeLenght].getY()));
		*p_snakeLenght += 1;
		foodSpawned = false;
		return spawnFood(*p_snakeLenght);
	}
}

void spawnFood(const int& bodyLength)
{
	int randX = rand() % 119;
	int randY = rand() % 28;

	for (int i = 0; i <= bodyLength; i++)
	{
		if (randX == bodyVector[i].getX() && randY == bodyVector[i].getY())
		{
			return spawnFood(bodyLength);
		}
		if (i == bodyLength)
		{
			theFood->setPos(randX, randY);
			foodSpawned = true;
		}
	}
}