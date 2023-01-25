#include "Rendering.h"

void checkYpos(std::vector<snakeBody>* bodyVector, int bodyLength)
{
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
}
