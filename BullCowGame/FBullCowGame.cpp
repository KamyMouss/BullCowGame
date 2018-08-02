#include "FBullCowGame.h"
#include <string>
#include <map>
#define TMap std::map

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTry = MAX_TRIES;

	const FString HIDDEN_WORD = "ant";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

void FBullCowGame::PrintIntro()
{
	std::cout << "Welcome to Bulls and Cows. Guess a " << MyHiddenWord.length() << " letter word." << std::endl;
}

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTry;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

bool FBullCowGame::isGameWon(FString Guess) const
{
	return MyHiddenWord.compare(Guess) == 0;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::WRONG_LENGTH;
	}
	else if (!isLowerCase(Guess)) 
	{
		return EGuessStatus::NOT_LOWER;
	}
	else if (!isIsogram(Guess)) 
	{
		return EGuessStatus::NOT_ISOGRAM;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLength; i++) 
	{
		for (int32 j = 0; j < HiddenWordLength; j++) 
		{
			if (Guess[i] == MyHiddenWord[j])
			{
				if (i == j) {
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++;
				}
			}
		}
	}

	return BullCowCount;
}

FString FBullCowGame::GetValidPlayerGuess()
{
	FString Guess = "";
	EGuessStatus Status = EGuessStatus::INVALID;

	do {
		std::cout << "Try " << GetCurrentTry() << ". Enter your guess: ";
		std::getline(std::cin, Guess);
		Status = CheckGuessValidity(Guess);
		
		switch (Status) {
		case EGuessStatus::WRONG_LENGTH:
			std::cout << "Please enter a " << GetHiddenWordLength() << " letter word." << std::endl << std::endl;
			break;
		case EGuessStatus::NOT_LOWER:
			std::cout << "Please enter a lower case word." << std::endl << std::endl;
			break;
		case EGuessStatus::NOT_ISOGRAM:
			std::cout << "Please enter a word without repeating letters." << std::endl << std::endl;
			break;
		}

	} while (Status != EGuessStatus::OK);

	return Guess;
}

bool FBullCowGame::isIsogram(FString Guess) const
{
	TMap<char, bool> LetterSeen;
	for (auto Letter: Guess) 
	{
		if (LetterSeen[Letter]) 
		{
			return false;
		}
		else 
		{
			LetterSeen[Letter] = true;
		}
	}
	return true;
}

bool FBullCowGame::isLowerCase(FString Guess) const
{
	for (char Letter: Guess) {
		if (!islower(Letter))
		{
			return false;
		}
	}

	return true;
}
