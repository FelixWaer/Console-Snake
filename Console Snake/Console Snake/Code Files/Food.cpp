#include "Food.h"

void Food::setPos(int X, int Y)
{
	xPos = X;
	yPos = Y;
}

void Food::eaten(int snake_xPos,int snake_yPos, bool* Eaten)
{
	if (xPos == snake_xPos && yPos == snake_yPos)
	{
		*Eaten = true;
	}
}

