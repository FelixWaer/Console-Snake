#pragma once

void startUp(int bodyLength);

void movement(char p_key, int& ref_xSpeed, int& ref_ySpeed);

void draw(int bodyLength);

void move(int bodyLength, int xSpeed, int ySpeed);

void addBody(int* p_snakeLenght);

void spawnFood(int bodylength);