#include<iostream>
#include<ctime>
#include<cstdint>
#include<thread>
#include<chrono>
#include<Windows.h>

#include"CardDeck.h"
#include"Actor.h"

enum Action
{
	Exit, Hit, Stand, MaxAction
};

enum WhoMove
{
	PlayerMove = 1, DeallerMove
};

std::int16_t checkInput(const std::string& output, const int min, const int max);
void printField(const Actor& dealer, const Actor& player, const std::int32_t bet = 0);

int main()
{
	srand(static_cast<size_t>(time(NULL)));

	Actor player("Player", 1000), dealer("Dealer", 10000);

	CardDeck deck;
	Card* ptr_currentCard = &deck.getFirstCard();

	const std::int16_t start_card = 2;
	for (int i = 0; i < start_card; ++i, ++ptr_currentCard)
	{
		dealer.addCard(ptr_currentCard);
	}

	for (int i = 0; i < start_card; ++i, ++ptr_currentCard)
	{
		player.addCard(ptr_currentCard);
	}

	WhoMove currentMove = PlayerMove;
	bool isWin(false);
	do
	{
		system("cls");

		std::cout << "Dialler have " << dealer[0].getName() << ", and one unknown.";
		std::cout << "\n\n" << getWhoMove(currentMove) << "\'s card is: ";
		
		printCard(player);
		
		if (player.getScore() > 21)
			break;
		if (player.getScore() == 21)
		{
			currentMove = DeallerMove;
			break;
		}
		
		int player_answer = checkInput("\n\n1 - to hit, 2 - to stand, 0 - to exit", 0, 2);
		switch (player_answer)
		{
		case Hit:
			player.addCard(ptr_currentCard);
			system("cls");
			break;
			break;
		case Stand:
			currentMove = DeallerMove;
			system("cls");
			break;
		}
	} while (currentMove == PlayerMove);

	std::cout << getWhoMove(PlayerMove) << "\'s card is: ";
	printCard(player);
	std::cout << "\n\n" << getWhoMove(currentMove) << "\'s card is: ";
	printCard(dealer);

	while (dealer.getScore() < 17)
	{
		std::cout << "\n\nDealer take card ";
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		std::cout << ptr_currentCard->getName();
		dealer.addCard(ptr_currentCard);
		std::cout << "\nScore is " << dealer.getScore();
	}
	if (dealer.getScore() > 21)return true;
	return (21 - player.getScore()) <= (21 - dealer.getScore());

	return 0;
}

std::int16_t checkInput(const std::string& output, const int min, const int max)
{
	std::int16_t answer;

	while (true)
	{
		std::cout << output;
		std::cout << "\nEnter: ";
		std::cin >> answer;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Error, try again!\n";
			continue;
		}
		std::cin.ignore(32767, '\n');
		if (std::cin.gcount() > 1)
		{
			std::cout << "Error, try again!\n";
			continue;
		}
		if (answer<min || answer>max)
		{
			std::cout << "Error, try again!\n";
			continue;
		}

		return answer;;
	}
}

void printCard(const Actor& actor)
{
	
	for (int i = 0; i < actor.getCardsCount(); ++i)
		std::cout << actor[i].getName() << ' ';
	std::cout << " Score is " << actor.getScore();
}

void printInfo(const Actor& actor)
{
	std::cout << actor.getName();
	printCard(actor);
	std::cout << actor.getMoney();
}

void printField(const Actor& dealer, const Actor& player, const std::int32_t bet = 0)
{
	printInfo(dealer);

	std::cout << "\n\n";
	std::cout << "Your bet is " << bet;
	std::cout << "\n\n";

	printInfo(player);
}