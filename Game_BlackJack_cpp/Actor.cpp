#include "Actor.h"

/////////////////////////////////////////////////// Public
////////////////////////////////////////// Ctor
Actor::Actor()
	:m_score(0)
{
}

////////////////////////////////////////// Get & set
std::int16_t Actor::getScore()const
{
	return m_score;
}

std::int16_t Actor::getCardsCount()const
{
	return m_cards.size();
}

const Card& Actor::getCard(const std::int16_t index)const
{
	return *m_cards.at(index);
}

////////////////////////////////////////// Func
void Actor::addCard(Card* const card)
{
	m_cards.push_back(card);
	
	incraseScore(card);
}

////////////////////////////////////////// Operator
Card& Actor::operator[](const std::int16_t index)
{
	return *m_cards.at(index);
}

/////////////////////////////////////////////////// Private
////////////////////////////////////////// Func
void Actor::incraseScore(const Card* card)
{
	if (card->getRank() == Rank::ACE)
		if (m_score > 10)
			m_score += 1;
		else
			m_score += 11;
	else
		if (card->getRank() == Rank::JACK ||
			card->getRank() == Rank::QUEEN ||
			card->getRank() == Rank::KING)
			m_score += 10;
		else
			m_score += card->getRank() + 2;
}
