#pragma once

#include<cstdint>
#include<vector>

#include"Card.h"

const std::int16_t BLACKJACK(21);

class Actor
{
public:
	////////////////////////////////// Ctor
	Actor(const std::string name, std::int32_t money);

	////////////////////////////////// Get & set
	std::int16_t getScore()const;
	std::int16_t getCardsCount()const;
	const std::string& getName()const;

	std::int32_t getMoney()const;
	void incraseMoney(std::int32_t money);
	void decraseMoney(std::int32_t money);

	////////////////////////////////// Func
	void addCard(Card* const card);

	////////////////////////////////// Operator
	Card& operator[](const std::int16_t index);
	const Card& operator[](const std::int16_t index)const;

private:
	void incraseScore(const Card* card);

	std::vector<Card*>m_cards;
	std::int16_t m_score;
	std::int32_t m_money;
	std::string m_name;
};

