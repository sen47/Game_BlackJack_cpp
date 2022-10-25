#pragma once

#include<array>

#include"Card.h"

const std::int16_t SIZE_DECK(52);

class CardDeck
{
public:
	CardDeck();

	const Card& getCard(const std::int16_t index)const;

private:
	void shuffleDeck();

	std::array<Card, SIZE_DECK>m_deck;
};
