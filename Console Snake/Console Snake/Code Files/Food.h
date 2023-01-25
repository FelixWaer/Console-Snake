#pragma once
class Food
{
	int xPos;
	int yPos;
public:
	Food(){}
	Food(int X, int Y) : xPos(X), yPos(Y) {}
	void setPos(int X, int Y);
	void eaten(int snake_xPos, int snake_yPos, bool* eaten);
	int getX() const { return xPos; }
	int getY() const { return yPos; }
};

