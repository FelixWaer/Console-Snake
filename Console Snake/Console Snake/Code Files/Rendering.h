#pragma once
#include <iostream>
#include <vector>

class snakeBody;
class Food;

void check_yPos(std::vector<snakeBody>& bodyVector, Food* theFood, int bodyLength);

void drawing(std::vector<snakeBody>& bodyVector, Food* theFood, bool foodSpawned, int bodyLength, int xPos, int yPos);

void runThroughConsole(std::vector<snakeBody>& bodyVector, Food* theFood, bool foodSpawned, int bodyLength);