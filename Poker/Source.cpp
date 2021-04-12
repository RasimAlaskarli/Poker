//Source.cpp
#include <iostream>
#include <time.h>
#include "Card.h"
#include "Player.h"
using namespace std;


int playerpoints = 0;
int computerpoints = 0;

void main() {

	srand(time(NULL));
	Player player1;
	Player computer;
	int playerbalance = 1000;
	int stake;
	player1.CardSetup();
	player1.RandomizeHand();
	player1.RandomizeTable();
	computer.SetCards(player1.GetCards());
	computer.RandomizeHand();
	computer.SetTable(player1.GetTable());
	cout << "Enter the amount of money you want to put:";
	cin >> stake;
	int tmp = 5;
	int index = 0;
	while (tmp != 2) {

		cout << "Your Cards:" << endl;
		player1.PrintHand();
		cout << "-------------------------\n\n";
		cout << "1-Hit" <<"\n2-Fold" << endl;
		cin >> tmp;
		switch (tmp) {
		case 1:
			system("cls");
			cout << "Table Cards:" << endl;
			if (index == 0) {
				player1.PrintFlop();
				index++;
			}
			else if (index == 1) {
				player1.PrintTurn();
				index++;
			}
			else if (index == 2) {
				player1.PrintRiver();
				index++;
				playerpoints = player1.Points();
				computerpoints = computer.Points();
				cout << "Computer's Cards:";
				computer.PrintAll();
				cout << "Player's Cards:";
				player1.PrintAll();

				cout << endl << endl;
				cout << "Computer's points:" << computerpoints << endl;
				cout << "Player's points:" << playerpoints << endl;
				if (playerpoints > computerpoints) {
					cout << "You win!" << endl;
					playerbalance += stake;
				}
				else if (playerpoints < computerpoints) {
					cout << "You lost!" << endl;
					playerbalance -= stake;
				}
				else {
					if (player1.HighCard() > computer.HighCard()) {
						cout << "You win!" << endl;
						playerbalance += stake;
					}
					else {
						cout << "You lost!" << endl;
						playerbalance -= stake;
					}
				}
				cout << "Balance:" << playerbalance << endl;
				cout << "1-Play Again" << "\n2-Quit" << endl;
				cin >> tmp;
				index = 0;
				player1.CardSetup();
				computer.SetCards(player1.GetCards());
				player1.RandomizeHand();
				player1.RandomizeTable();
				computer.RandomizeHand();
				computer.SetTable(player1.GetTable());
				system("cls");
				break;
		case 2:
			cout << "You lose" << endl;
			playerbalance -= stake;
			break;
			}

		}
	}





}