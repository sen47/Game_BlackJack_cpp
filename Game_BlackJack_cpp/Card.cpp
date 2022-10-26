#include "Card.h"

std::array<char, SIZE_SUIT>suitSymbols
{
	static_cast<char>(3),
	static_cast<char>(4),
	static_cast<char>(5),
	static_cast<char>(6)
};
std::array<char, SIZE_RANK>rankSymbols
{
	static_cast<char>(50),
	static_cast<char>(51),
	static_cast<char>(52),
	static_cast<char>(53),
	static_cast<char>(54),
	static_cast<char>(55),
	static_cast<char>(56),
	static_cast<char>(57),
	static_cast<char>(49),
	static_cast<char>(74),
	static_cast<char>(81),
	static_cast<char>(75),
	static_cast<char>(65)
};

//////////////////////////////////////////////////////////////////////////////////// Public
////////////////////////////////////////////////////////////// Ctor
Card::Card()
	:m_rank{ static_cast<Rank>(0) }, m_suit{ static_cast<Suit>(0) } {};


////////////////////////////////////////////////////////////// Get & set
const std::string& Card::getName() const
{
	return m_name;
}

const Rank& Card::getRank() const
{
	return m_rank;
}

void Card::setCard(const Suit& suit, const Rank& rank)
{
	m_suit = suit;
	m_rank = rank;

	setName();
}

//////////////////////////////////////////////////////////////////////////////////// Private
////////////////////////////////////////////////////////////// Get & set
void Card::setName()
{
	m_name += rankSymbols[m_rank];
	if (m_rank == Rank::TEN)
		m_name += static_cast<char>(48);
	//m_name += ' ';
	m_name += suitSymbols[m_suit];
}
