#include<iostream>
#include<ctime>

#include"CardDeck.h"

int main()
{
	srand(static_cast<size_t>(time(NULL)));

	CardDeck deck;

	for (int i = 0; i < SIZE_DECK; ++i)
		std::cout << deck.getCard(i).getName() << '\n';

	return 0;
}