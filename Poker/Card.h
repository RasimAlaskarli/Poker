//Card.h
#pragma once
#include <iostream>



using namespace std;
class Card {
private:
	string suit;
	string rank;
	int value;
	int svalue;
public:
	void SetSuit(string suit);
	void SetRank(string rank);
	void SetValue(int value);
	void SetSValue(int svalue);
	string GetSuit();
	string GetRank();
	int GetValue();
	int GetSValue();

};