#include "CardDeck.h"

//////////////////////////////////////////////////////////////////////////////////// Public
////////////////////////////////////////////////////////////// Ctor
CardDeck::CardDeck()
{
	for (int i = 0, current = 0; i < SIZE_SUIT; ++i)
		for (int j = 0; j < SIZE_RANK; ++j)
		{
			m_deck[current].setCard(static_cast<Suit>(i), static_cast<Rank>(j));
			++current;
		}

	shuffleDeck();
	shuffleDeck();
	shuffleDeck();
}

////////////////////////////////////////////////////////////// Get & set
Card& CardDeck::getFirstCard()
{
	return m_deck.at(0);
}

////////////////////////////////////////////////////////////// Func
#ifdef DEBUG
void CardDeck::printDeck()
{
	for (const Card& el : m_deck)
		std::cout << el.getName() << '\n';
}
#endif // DEBUG

//////////////////////////////////////////////////////////////////////////////////// Private
////////////////////////////////////////////////////////////// Func
void CardDeck::shuffleDeck()
{
	for (int i = 0; i < SIZE_DECK; ++i)
	{
		std::int16_t randomCard{ rand() % SIZE_DECK };
		std::swap(m_deck[i], m_deck[randomCard]);
	}
}
