#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include "conio.h"

#include "gameplay.h"

char key;
int xSpeed = 1;
int ySpeed = 0;
int bodyLenght = 0;

void getKey()
{
	key = _getch();
	return getKey();
}

void gameRendering()
{
	auto next_period = std::chrono::steady_clock::now() + std::chrono::milliseconds(100);

	startUp(bodyLenght);
	addBody(&bodyLenght);
	movement(key, xSpeed, ySpeed);
	move(bodyLenght, xSpeed, ySpeed);
	draw(bodyLenght);

	std::this_thread::sleep_until(next_period);
	std::cout << "\x1B[3J\x1B[H\x1B[2J";

	return gameRendering();
}
