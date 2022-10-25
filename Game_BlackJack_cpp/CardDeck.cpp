#include "CardDeck.h"

CardDeck::CardDeck()
{
	for (int i = 0; i < SIZE_DECK; ++i)
		m_deck[i].setCard(i);

	shuffleDeck();
	shuffleDeck();
	shuffleDeck();
}

const Card& CardDeck::getCard(const std::int16_t index) const
{
	return m_deck[index];
}

void CardDeck::shuffleDeck()
{
	for (int i = 0; i < SIZE_DECK; ++i)
	{
		std::int16_t randomCard{ rand() % SIZE_DECK };
		std::swap(m_deck[i], m_deck[randomCard]);
	}
}
