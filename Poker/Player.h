//Player.h
#pragma once
#include <iostream>
#include "Card.h"
using namespace std;



class Player {
private:
	Card hand[2];
	Card table[5];
	Card allcards[7];
	Card cards[52];

public:
	void CardSetup();
	void SetCards(Card _cards[52]);
	Card* GetCards();
	void SetHand(Card c[2]);
	void SetTable(Card c[5]);
	Card* GetHand();
	Card* GetTable();
	Card* GetAll();
	void RandomizeHand();

	void RandomizeTable();
	void PrintHand();
	void PrintAll();
	void PrintFlop();

	void PrintTurn();
	void PrintRiver();
	int HighCard();
	void Sort(Card c[7]);
	void SuitSort(Card c[7]);
	int Points();
};



