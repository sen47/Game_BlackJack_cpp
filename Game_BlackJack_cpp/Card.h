#pragma once

#include<string>
#include<cstdint>
#include<array>

enum Suit { HEARTS, DIAMONDS, SPIDERS, CLUBS, SIZE_SUIT };
enum Rank { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE, SIZE_RANK };

struct Card
{
public:
	////////////////////////////////////// Ctor
	Card();

	////////////////////////////////////// Get & set
	const std::string& getName()const;
	const Rank& getRank()const;
	void setCard(const Suit& suit, const Rank& rank);

private:
	void setName();

	Suit m_suit;
	Rank m_rank;
	std::string m_name;
};