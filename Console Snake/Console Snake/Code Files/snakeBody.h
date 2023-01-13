#pragma once
class snakeBody
{
	int xPos;
	int yPos;
public:
	snakeBody(){}
	snakeBody(int xPos, int yPos);
	void setPos(int X, int Y);
	int getX() const { return xPos; }
	int getY() const { return yPos; }
};

