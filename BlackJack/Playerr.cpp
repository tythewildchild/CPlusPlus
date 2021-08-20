#include "Playerr.h"

void Playerr::Deal() {
	srand(time(0));
	currentHand.push_back((rand() % 10) + 2);
	currentHand.push_back((rand() % 10) + 2);
}
void Playerr::Hit() {
	srand(time(0));
	currentHand.push_back((rand() % 10) + 2);
}

int Playerr::Split() {
	return 0;
}

int Playerr::Double_() {
	return 0;
}

//Tallies the score
void Playerr::CalculateScore() {
	score = 0;
	for (int i = 0; i < currentHand.size(); i++) {
		score += currentHand.at(i);
	}
}

//Prints current hand (and ends turn if 21 or bust)
void Playerr::PrintScore() {
	score = 0;
	for (int i = 0; i < currentHand.size(); i++) {
		if (i == currentHand.size() - 1) {
			std::cout << currentHand.at(i) << std::endl << std::endl;
		}
		else {
			std::cout << currentHand.at(i) << ", ";
		}
		score += currentHand.at(i);
	}
}

void Playerr::EndTurn() {
	turn = 0;
	score = 0;
	currentHand.clear();
}

