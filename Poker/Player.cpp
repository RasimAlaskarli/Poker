//Player.cpp
#include "Player.h"
#include "Card.h"
#include <iostream>

using namespace std;



void Player::SetCards(Card _cards[52])
{
	for (int i = 0; i < 52; i++) {
		cards[i] = _cards[i];
	}
}
Card* Player::GetCards()
{
	return cards;
}
void Player::CardSetup() {
	int r = 0;
	int s = 0;
	for (int i = 0; i < 52; i++) {
		switch (r) {
		case 0:
			cards[i].SetRank("2");
			cards[i].SetValue(2);
			break;
		case 1:
			cards[i].SetRank("3");
			cards[i].SetValue(3);
			break;
		case 2:
			cards[i].SetRank("4");
			cards[i].SetValue(4);
			break;
		case 3:
			cards[i].SetRank("5");
			cards[i].SetValue(5);
			break;
		case 4:
			cards[i].SetRank("6");
			cards[i].SetValue(6);
			break;
		case 5:
			cards[i].SetRank("7");
			cards[i].SetValue(7);
			break;
		case 6:
			cards[i].SetRank("8");
			cards[i].SetValue(8);
			break;
		case 7:
			cards[i].SetRank("9");
			cards[i].SetValue(9);
			break;
		case 8:
			cards[i].SetRank("10");
			cards[i].SetValue(10);
			break;
		case 9:
			cards[i].SetRank("J");
			cards[i].SetValue(11);

			break;
		case 10:
			cards[i].SetRank("Q");
			cards[i].SetValue(12);
			break;
		case 11:
			cards[i].SetRank("K");
			cards[i].SetValue(13);
			break;
		case 12:
			cards[i].SetRank("A");
			cards[i].SetValue(14);
			break;
		default:
			break;

		}
		switch (s) {
		case 0:
			cards[i].SetSuit("H");
			cards[i].SetSValue(1);
			break;
		case 1:
			cards[i].SetSuit("D");
			cards[i].SetSValue(2);
			break;
		case 2:
			cards[i].SetSuit("C");
			cards[i].SetSValue(3);
			break;
		case 3:
			cards[i].SetSuit("S");
			cards[i].SetSValue(4);
			break;
		}
		r++;
		s++;
		if (r >= 13) {
			r = 0;
		}
		if (s >= 4) {
			s = 0;
		}
	}

}
void Player::SetHand(Card c[2]) {
	for (int i = 0; i < 2; i++) {
		hand[i] = c[i];
		allcards[i] = c[i];
	}
}
void Player::SetTable(Card c[5]) {
	for (int i = 0; i < 5; i++) {
		table[i] = c[i];
		allcards[i + 2] = c[i];
	}
}
Card* Player::GetHand() {
	return hand;
}
Card* Player::GetTable() {
	return table;
}
Card* Player::GetAll() {
	return allcards;
}
void Player::RandomizeHand() {
	for (int i = 0; i < 2; i++) {
		int tmp = rand() % 52 + 1;
		while (cards[tmp].GetRank() == "0") {
			tmp = rand() % 52 + 1;
		}
		hand[i] = cards[tmp];
		allcards[i] = hand[i];
		cards[tmp].SetRank("0");
		cards[tmp].SetSuit("0");
	}

}
void Player::RandomizeTable() {
	for (int i = 0; i < 5; i++) {
		int tmp = rand() % 52 + 1;
		while (cards[tmp].GetRank() == "0") {
			tmp = rand() % 52 + 1;
		}
		table[i] = cards[tmp];
		allcards[i + 2] = table[i];
		cards[tmp].SetRank("0");
		cards[tmp].SetSuit("0");
	}
}
void Player::PrintHand() {
	for (int i = 0; i < 2; i++) {
		cout << hand[i].GetRank() << hand[i].GetSuit() << " ";
	}
	cout << endl;
}

void Player::PrintAll() {
	for (int i = 0; i < 7; i++) {
		cout << allcards[i].GetRank() << allcards[i].GetSuit() << " ";
	}
	cout << endl;
}
void Player::PrintFlop() {
	for (int i = 0; i < 3; i++) {
		cout << table[i].GetRank() << table[i].GetSuit() << " ";

	}
	cout << endl << endl;;
}
void Player::PrintTurn() {
	for (int i = 0; i < 4; i++) {
		cout << table[i].GetRank() << table[i].GetSuit() << " ";
	}
	cout << endl << endl;
}
void Player::PrintRiver() {
	for (int i = 0; i < 5; i++) {
		cout << table[i].GetRank() << table[i].GetSuit() << " ";
	}
	cout << endl << endl;
}
void Player::Sort(Card c[7]) {
	Card tmp;
	for (int i = 0; i < 7; i++) {
		for (int j = i + 1; j < 7; j++) {
			if (c[j].GetValue() < c[i].GetValue()) {
				tmp = c[i];
				c[i] = c[j];
				c[j] = tmp;
			}
		}
	}
}
int Player::HighCard() {
	Sort(hand);
	return hand[1].GetValue();
}
void Player::SuitSort(Card c[7]) {
	Card tmp;
	for (int i = 0; i < 7; i++) {
		for (int j = i + 1; j < 7; j++) {
			if (c[j].GetSValue() < c[i].GetSValue()) {
				tmp = c[i];
				c[i] = c[j];
				c[j] = tmp;
			}
		}
	}
}
int Player::Points() {
	int points = 0;
	int flush = 0;
	Sort(allcards);
	int pair = 0;
	for (int i = 0; i < 6; i++) {
		if (allcards[i].GetRank() == allcards[i + 1].GetRank()) {
			pair++;
			points += allcards[i].GetValue();
		}
	}
	int three = 0;
	for (int i = 0; i < 5; i++) {
		if (allcards[i].GetRank() == allcards[i + 1].GetRank() && allcards[i + 1].GetRank() == allcards[i + 2].GetRank()) {
			pair -= 2;
			three++;
			points += allcards[i].GetValue();
		}
	}
	int straight = 0;
	for (int i = 0; i < 3; i++) {
		if (allcards[i].GetValue() == allcards[i + 1].GetValue() - 1 == allcards[i + 2].GetValue() - 2 == allcards[i + 3].GetValue() - 3 == allcards[i + 4].GetValue() - 4) {
			straight++;
			points += allcards[i].GetValue();
		}
	}
	int fullhouse = 0;
	if (pair == 1 && three == 1) {
		fullhouse++;
		pair--;
		three--;
	}
	int four = 0;
	for (int i = 0; i < 4; i++) {
		if (allcards[i].GetRank() == allcards[i + 1].GetRank() && allcards[i + 1].GetRank() == allcards[i + 2].GetRank() && allcards[i + 2].GetRank() == allcards[i + 3].GetRank()) {
			four++;
			three--;
			pair -= 3;
			points += allcards[i].GetValue();
		}
	}
	int royalflush = 0;
	for (int i = 0; i < 3; i++) {
		if (allcards[i].GetSuit() == "10" && allcards[i + 1].GetSuit() == "J" && allcards[i + 2].GetSuit() == "Q" && allcards[i + 3].GetSuit() == "K" && allcards[i + 4].GetSuit() == "A" && flush == 1) {
			royalflush++;
			flush--;
			points += allcards[i].GetValue();
		}
	}
	SuitSort(allcards);


	for (int i = 0; i < 3; i++) {
		if (allcards[i].GetSuit() == allcards[i + 1].GetSuit() && allcards[i + 1].GetSuit() == allcards[i + 2].GetSuit() && allcards[i + 2].GetSuit() == allcards[i + 3].GetSuit() && allcards[i + 3].GetSuit() == allcards[i + 4].GetSuit()) {
			flush++;
			points += allcards[i].GetValue();
		}
	}
	int straightflush = 0;
	if (flush == 1 && straight == 1) {
		straightflush++;
		flush--;
		straight--;
	}
	if (pair > 0) {
		points += pair * 500;
	}
	if (three > 0) {
		points += three * 1500;
	}
	if (straight > 0) {
		points += straight * 2000;
	}
	if (flush > 0) {
		points += flush * 2500;
	}
	if (fullhouse > 0) {
		points += fullhouse * 3000;
	}
	if (four > 0) {
		points += four * 3500;
	}
	if (straightflush > 0) {
		points += straightflush * 5000;
	}
	if (royalflush > 0) {
		points += royalflush * 100000;
	}
	points += HighCard();
	return points;
}
