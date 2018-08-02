#pragma once
#include <iostream>
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum EGuessStatus {
	OK,
    NOT_ISOGRAM,
	WRONG_LENGTH,
	NOT_LOWER,
	INVALID,
};

class FBullCowGame {
public:
	FBullCowGame();

	void PrintIntro();
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool isGameWon(FString) const;
	EGuessStatus CheckGuessValidity(FString) const;

	void Reset();
	FBullCowCount SubmitValidGuess(FString);
	FString GetValidPlayerGuess();

private:
	bool isIsogram(FString) const;
	bool isLowerCase(FString) const;
	int32 MyCurrentTry;
	int32 MyMaxTry;
	FString MyHiddenWord;
};

