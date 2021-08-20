#ifndef USER_H
#define USER_H

#include <iostream>
#include <random>
#include <vector>
#include <cstdlib>
#include <ctime>

class Playerr
{
public:
	std::vector<int> currentHand;
	int amount = 500;
	int bet = 50;
	int input = 0;
	int turn = 0;
	int score = 0;

	void Deal();
	void Hit();
	int Split();
	int Double_();
	void CalculateScore();
	void PrintScore();
	void EndTurn();
};

#endif