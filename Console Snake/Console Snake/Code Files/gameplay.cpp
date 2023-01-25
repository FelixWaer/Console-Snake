#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "gameplay.h"
#include "snakeBody.h"
#include "Food.h"
#include "Rendering.h"

std::vector<snakeBody> bodyVector;
 
std::shared_ptr<Food> theFood = std::make_shared<Food>();

Food* testFood;

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
	runThroughConsole(bodyVector, testFood, foodSpawned, bodyLength);
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
	if (bodyVector[0].getX() == testFood->getX() && bodyVector[0].getY() == testFood->getY())
	{
		bodyVector.emplace_back(snakeBody(bodyVector[*p_snakeLenght].getX(), bodyVector[*p_snakeLenght].getY()));
		*p_snakeLenght += 1;
		foodSpawned = false;
		delete testFood;
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
	}
	//theFood->setPos(randX, randY);
	testFood = new Food(randX, randY);
	foodSpawned = true;
}