/*
The game logic implementation
The game is a simple guess the word game based on Mastermind
*/

#pragma once
#include "FBullCowGame.h"
#include <map>
#define TMap std::map

// To make the syntax Unreal friendly
using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const
{
	TMap<int32, int32> WordLengthToMaxTries { {3, 4}, {4, 7}, {5, 10}, {6, 15}, {7, 20} };
	return WordLengthToMaxTries[MyHiddenWord.length()];;
}


void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "planet"; // This must be an isogram

	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;

	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	// If the guess isn't an isogram
	if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else if (!IsIsogram(Guess))
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess))
	{
		return EGuessStatus::Not_Lowercase;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

// Receives a valid gues, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;

	// Loop through all letters in the hidden word
	int32 WordLength = MyHiddenWord.length();

	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
	{
		// Compare letters against the guess
		for (int32 GChar = 0; GChar < WordLength; GChar++)
		{
			// If they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar])
			{
				// If they're in the same place
				if (MHWChar == GChar)
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			}
		}
	}

	bGameIsWon = (BullCowCount.Bulls == WordLength);
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	// Treat 0- and 1-letter words as isograms
	if (Word.length() <= 1) return true;

	TMap<char, bool> LetterSeen;

	// Range-based for loop
	for (auto Letter : Word)
	{
		Letter = tolower(Letter); // Handle mixed case

		// If a letter is already in the map
		if (LetterSeen[Letter])
		{
			return false; // Then it's not an isogram
		}
		else
		{
			LetterSeen[Letter] = true; // Add the letter to the map
		}
	}

	return true; // For example in cases where /0 is entered
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	for (auto Letter : Word)
	{
		// If not a lowercase letter
		if (!islower(Letter))
			return false;
	}

	return true;
}
