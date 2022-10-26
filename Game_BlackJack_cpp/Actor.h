#pragma once

#include<cstdint>
#include<vector>

#include"Card.h"

const std::int16_t BLACKJACK(21);

class Actor
{
public:
	////////////////////////////////// Ctor
	Actor();

	////////////////////////////////// Get & set
	std::int16_t getScore()const;
	std::int16_t getCardsCount()const;
	const Card& getCard(const std::int16_t index)const;

	////////////////////////////////// Func
	void addCard(Card* const card);

	////////////////////////////////// Operator
	Card& operator[](const std::int16_t index);

private:
	void incraseScore(const Card* card);

	std::vector<Card*>m_cards;
	std::int16_t m_score;
};

