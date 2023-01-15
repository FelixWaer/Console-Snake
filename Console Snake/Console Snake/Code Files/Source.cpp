#include "Snake.h"

int main(){

	std::thread keyThread(getKey);
	gameRendering();

	keyThread.join();

	return 0;
}