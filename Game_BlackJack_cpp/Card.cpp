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

Card::Card()
	:m_value(0), m_rank{ 0 }, m_suit{ 0 } {};

Card::Card(const std::int16_t number)
	:m_value(0), m_rank{ 0 }, m_suit{ 0 }
{
	setCard(number);
}

const std::string& Card::getName() const
{
	return m_name;
}

void Card::setCard(const std::int16_t number)
{
	m_rank = number % SIZE_RANK;
	m_suit = number / SIZE_RANK;

	m_name += rankSymbols[m_rank];
	if (m_rank == Rank::TEN)
		m_name += static_cast<char>(48);
	m_name += ' ';
	m_name += suitSymbols[m_suit];
}

