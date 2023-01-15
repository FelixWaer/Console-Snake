#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "gameplay.h"
#include "snakeBody.h"
#include "Food.h"

std::vector<snakeBody> bodyVector;

std::shared_ptr<Food> theFood = std::make_shared<Food>();

bool foodSpawned = false;

void startUp(int bodyLength)
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

void movement(char p_key, int& p_xSpeed, int& p_ySpeed)
{
	if (p_key == 'd' &&p_xSpeed >= 0)
	{
		p_xSpeed = 1;
		p_ySpeed = 0;
	}
	else if (p_key == 'a' && p_xSpeed <= 0)
	{
		p_xSpeed = -1;
		p_ySpeed = 0;
	}
	else if (p_key == 's' && p_ySpeed >= 0)
	{
		p_xSpeed = 0;
		p_ySpeed = 1;
	}
	else if (p_key == 'w' && p_ySpeed <= 0)
	{
		p_xSpeed = 0;
		p_ySpeed = -1;
	}
}

void draw(int bodyLength)
{
	std::vector <int> snake_yPos;

	for (int yPos = 0; yPos < 30; yPos++)
	{
		for (int v = 0; v <= bodyLength; v++)
		{
			if (bodyVector[v].getY() == yPos || theFood->getY() == yPos)
			{
				snake_yPos.push_back(yPos);
				break;
			}
		}
	}

	for (int i = 0; i < 29; i++)
	{
		for (int s = 0; s < snake_yPos.size(); s++)
		{
			if (snake_yPos[s] != i)
			{
				continue;
			}
			for (int xPos = 0; xPos < 120; xPos++)
			{
				for (int l = 0; l <= bodyLength; l++)
				{
					if (bodyVector[l].getX() == xPos && bodyVector[l].getY() == i)
					{
						std::cout << "X";
						break;
					}
					if (theFood->getX() == xPos && theFood->getY() == i && foodSpawned == true)
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
			break;
		}
		std::cout << "\n";
	}
}

void move(int bodyLength, int xSpeed, int ySpeed)
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

void spawnFood(int bodyLength)
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