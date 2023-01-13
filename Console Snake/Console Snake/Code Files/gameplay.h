#pragma once

void startUp(const int& bodyLength);

void movement(const char* p_key, int* p_xSpeed, int* p_ySpeed);

void draw(const int& bodyLength);

void move(const int& bodyLength, const int& xSpeed, const int& ySpeed);

void addBody(int* p_snakeLenght);

void spawnFood(const int& bodylength);