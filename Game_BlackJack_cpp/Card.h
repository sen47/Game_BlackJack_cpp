#pragma once

#include<string>
#include<cstdint>
#include<array>

enum Suit { HEARTS, DIAMONDS, SPIDERS, CLUBS, SIZE_SUIT };
enum Rank { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE, SIZE_RANK };

struct Card
{
public:
	Card();
	Card(const std::int16_t number);

	const std::string& getName()const;
	void setCard(const std::int16_t number);

private:
	std::int16_t m_suit, m_rank;

	std::string m_name;
	std::int16_t m_value;
};