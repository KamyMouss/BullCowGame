#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;
FBullCowGame BCGame;
void PlayGame();
bool PlayAgain();

int main()
{
	bool playAgain = false;
	do {
		PlayGame();
		playAgain = PlayAgain();
	} while (playAgain);
}

void PlayGame() 
{
	BCGame.PrintIntro();
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	FText Guess = "";

	while (!BCGame.isGameWon(Guess) && BCGame.GetCurrentTry() <= MaxTries) {

		Guess = BCGame.GetValidPlayerGuess();

		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess); 

		std::cout << "Bulls = " << BullCowCount.Bulls << ". ";
		std::cout << "Cows = " << BullCowCount.Cows;
		std::cout << std::endl << std::endl;
		
	}
	if (BCGame.GetCurrentTry() >= MaxTries) 
	{
		std::cout << "Sucker, you lost!" << std::endl;
	} 
	else 
	{
		std::cout << "Congrats, you won!" << std::endl;
		std::cout << "Number of tries: " << BCGame.GetCurrentTry() << std::endl;
	}
	

}

bool PlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";
	std::string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}
