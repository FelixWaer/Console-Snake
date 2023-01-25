#include "Rendering.h"
#include "snakeBody.h"
#include "Food.h"

void check_yPos(std::vector<snakeBody>& bodyVector, std::vector<int>& snake_yPos, Food* theFood, int bodyLength)
{
	for (int yPos = 0; yPos < 30; yPos++)
	{
		for (int v = 0; v <= bodyLength; v++)
		{
			if (bodyVector[v].getY() == yPos || theFood->getY() == yPos)
			{
				snake_yPos.emplace_back(yPos);
				break;
			}
		}
	}
}

void drawing(std::vector<snakeBody>& bodyVector, Food* theFood, bool foodSpawned, int bodyLength, int xPos, int yPos)
{
	for (int lengthNumber = 0; lengthNumber <= bodyLength; lengthNumber++)
	{
		if (bodyVector[lengthNumber].getX() == xPos && bodyVector[lengthNumber].getY() == yPos)
		{
			std::cout << "X";
			break;
		}
		if (theFood->getX() == xPos && theFood->getY() == yPos && foodSpawned == true)
		{
			std::cout << "F";
			break;
		}
		if (lengthNumber == bodyLength)
		{
			std::cout << " ";
		}
	}
}

void runThroughConsole(std::vector<snakeBody>& bodyVector, Food* theFood, bool foodSpawned, int bodyLength)
{
	std::vector <int> snake_yPos;
	snake_yPos.reserve(bodyLength);

	check_yPos(bodyVector, snake_yPos, theFood, bodyLength);

	for (int yPos = 0; yPos < 29; yPos++)
	{
		for (int s = 0; s < snake_yPos.size(); s++)
		{
			if (snake_yPos[s] != yPos)
			{
				continue;
			}
			for (int xPos = 0; xPos < 120; xPos++)
			{
				drawing(bodyVector, theFood, foodSpawned, bodyLength, xPos, yPos);
			}
			break;
		}
		std::cout << std::endl;
	}
}
