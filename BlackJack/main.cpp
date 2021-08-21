//This program will allow the user to play a black jack game

#include <iostream>
#include <string>
#include <charconv>
#include <random>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Playerr.h"
#include <thread>
#include <chrono>

using namespace std;
using this_thread::sleep_for;
using namespace chrono_literals;

int main()
{
	Playerr player;
	int input;
	bool ready_to_play = false;


	//opening intro text
	cout << "Welcome to Black Jack! I recommend you read the rules:)\n";
	cout << "\n1 - Play \n2 - Rules \n3 - Exit" << endl << endl;

	//1 starts game, 2 gives rules, 3 exits
	while (1) {
		cin >> input;
		switch (input) {
		case 1:
			cout << endl;
			ready_to_play = true;
			break;
		case 2:
			cout << "\nYou will start with $1,000. Each round costs $50 to play. If you Black Jack your first round, you will earn 2x" <<
				"\nyour bet. However all you have to do is beat the dealer which will earn you 1.5x your bet. However, if you lose to the " <<
				"\ndealer then you lose your bet! If you reach $0 you lose. However, if you get to $1,500 you win a special prize!" << endl << endl;
			break;
		case 3:
			cout << "Have a nice day!\n";
			return 0;
		}
		if (ready_to_play == true) {
			break;
		}
	}

	//Button Legend
	cout << "1 - Hit\n2 - Stand \n3 - Double\n4 - Split\n5 - Exit" << endl << endl;

	//Start Game!

	while (1) {
		player.turn++;

		//First Turn
		if (player.turn == 1) {

			//gives dealer his hand
			//vector<int> dealerCards;
			//int dealerScore = 0;
			//int card = 0;
			//while (dealerScore < 16) {
			//	card = (rand() % 10) + 2;
			//	dealerCards.push_back();
			//	
			//}
			


			cout << "Total Winnings: $" << player.amount << endl;
			player.Deal();
			player.CalculateScore();
			player.PrintScore();
			if (player.score == 21) {
				cout << "Black Jack!" << endl << endl;
				player.amount += player.bet * 2.5;
				player.EndTurn();
				sleep_for(250ms);
				continue;
			}
		}

		//Any other turn
		cin >> player.input;
		cout << endl;
		switch (player.input) {
		//Hit
		case 1:
			player.Hit();
			player.CalculateScore();
			if (player.score > 21) {
				//Here I can add logic to make sure that aces can count as either 1 or 11
				player.PrintScore();
				cout << "BUST! Score: " << player.score << endl << endl;
				player.EndTurn();
				break;
			}
			if (player.score == 21) {
				cout << "You got 21!" << endl << endl;
				player.amount += player.bet * 2;
				player.EndTurn();
				break;
			}
			player.PrintScore();
			break;

		//Stand
		case 2:
			player.CalculateScore();
				cout << "Score: " << player.score << endl << endl;
				player.EndTurn();
			break;

		//Double
		case 3:
			break;

			//Split
		case 4:
			break;

		//Exit
		case 5:
			player.EndTurn();
			break;
		}
	}

	return 0;
}
