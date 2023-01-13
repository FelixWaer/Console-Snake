#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include "conio.h"

#include "gameplay.h"

char key = ' ';
int xSpeed = 1;
int ySpeed = 0;
int snakeLenght = 0;

void getKey()
{
	key = _getch();
	return getKey();
}

void gameRendering()
{
	auto next_period = std::chrono::steady_clock::now() + std::chrono::milliseconds(1);

	startUp(snakeLenght);
	addBody(&snakeLenght);
	movement(&key, &xSpeed, &ySpeed);
	move(snakeLenght, xSpeed, ySpeed);
	draw(snakeLenght);

	std::this_thread::sleep_until(next_period);
	std::cout << "\x1B[2J\x1B[H";

	return gameRendering();
}
