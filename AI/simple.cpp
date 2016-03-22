/*
 * Simple.cpp
 *
 *  Created on: Mar 21, 2016
 *      Author: rogshotz
 */

#include <iostream>
#include <chrono>
#include <cstdlib>
#include <thread>

int main() {

	int answer;
	int t = 0; //trash variable
	int guess;
	int prevGuess = -5;
	std::string task;
	bool bTask = true;
	bool win = false;

	while (task != "exit" || task != "restart") {

		while (bTask == true) {
			srand(time(NULL));
			answer = rand() % 100 + 1;
			std::cout << "Loading Number" << std::flush;

			while (t <= 3) {
				std::cout << "." << std::flush;
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
				t++;
			}
			std::cout << std::endl << "Enter a number: ";
			bTask = false;
		}
		while (win == false) {
			std::cin >> guess;
			guess = abs(guess - answer);

			if (prevGuess == -5) {
				std::cout << "Guess another number " << std::endl;
				prevGuess = guess;
			} else if (guess == 0) {
				std::cout << "You win";
			} else if (prevGuess > guess) {
				std::cout << "Closer";
				prevGuess = guess;
			} else if (prevGuess < guess) {
				std::cout << "Farther";
			}

		}
	}

	return 0;
}

