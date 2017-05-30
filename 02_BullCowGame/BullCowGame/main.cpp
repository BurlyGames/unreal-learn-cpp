/*
This is the console executable that makes use of the BullCowClass
This acts as the View in an MVC pattern, and is responsible for all
user interaction.  For game logic, see the FBullCowGame class.
*/

#pragma once
#include <iostream>
#include <string>
#include "FBullCowGame.h"

// To make syntax Unreal friendly
using FText = std::string;
using int32 = int;

// Function prototypes as outside a class
void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
FText PrintGameSummary();

FBullCowGame BCGame; // Instantiate a new game

// Entrypoint for our application
int main()
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	}
	while (bPlayAgain);

	return 0;
}

void PrintIntro()
{
	std::cout << "\n\n";
	std::cout << "Welcome to Bulls and Cows!  A fun word game.\n";
	std::cout << std::endl;
	std::cout << "          }   {          ___             " << std::endl;
	std::cout << "          (o o)         (o o)            " << std::endl;
	std::cout << "   /-------\\ /           \\ /-------\\  " << std::endl;
	std::cout << "  / | BULL |o             o| COW  | \\   " << std::endl;
	std::cout << " *  |-,--- |               |------|  *   " << std::endl;
	std::cout << "    ^      ^               ^      ^      " << std::endl;
	std::cout << "                                         " << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n\n";
	std::cout << std::endl;

	return;
}

// Plays a single game to completion
void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// Loop asking for guesses while the game is NOT won
	// and there are still tries remaining
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess();

		// Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		// Print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}

	PrintGameSummary();

	return;
}

// Loop continually until the user gives a valid guess
FText GetValidGuess()
{
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText Guess = "";

	do
	{
		// Get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " (of " << BCGame.GetMaxTries() << "). Enter your guess: ";
		Guess = "";
		getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
			case EGuessStatus::Wrong_Length:
				std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
				break;

			case EGuessStatus::Not_Isogram:
				std::cout << "Please enter a word without repeating letters.\n\n";
				break;

			case EGuessStatus::Not_Lowercase:
				std::cout << "Please enter a lower-case word.\n\n";
				break;

			default:
				// Assuming the guess is valid
				break;
		}

	} while (Status != EGuessStatus::OK); // Keep looping until we get no errors

	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same hidden word (y/n)?";
	FText Response = "";
	getline(std::cin, Response);
	return (Response[0] == 'y');
}

FText PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "Congratulations!  You've won the game.\n\n";
	}
	else
	{
		std::cout << "Better luck next time!\n\n";
	}

	return "";
}
