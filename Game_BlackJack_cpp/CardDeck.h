#pragma once

//#define DEBUG

#include<array>

#ifdef DEBUG
#include<iostream>
#endif // DEBUG

#include"Card.h"

const std::int16_t SIZE_DECK(52);

class CardDeck
{
public:
	////////////////////////////////////// Ctor
	CardDeck();

	////////////////////////////////////// Get & set
	Card& getFirstCard();

	////////////////////////////////////// Func
#ifdef DEBUG
	void printDeck();
#endif // DEBUG


private:
	////////////////////////////////////// Func
	void shuffleDeck();

	std::array<Card, SIZE_DECK>m_deck;
};
