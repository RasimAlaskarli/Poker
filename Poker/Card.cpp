//Card.cpp
#include "Card.h"
#include "Player.h"
using namespace std;

void Card::SetSuit(string suit) {
	this->suit = suit;
}
void Card::SetRank(string rank) {
	this->rank = rank;
}
void Card::SetValue(int value) {
	this->value = value;
}
void Card::SetSValue(int svalue) {
	this->svalue = svalue;
}
string Card::GetSuit() {
	return suit;
}
string Card::GetRank() {
	return rank;
}
int Card::GetValue() {
	return value;
}
int Card::GetSValue() {
	return svalue;
}

