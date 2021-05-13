#include <iostream>
#include "ufo_functions.hpp"

void greet()
{
  std::cout << "==============\n";
  std::cout << "UFO: The Game\n";
  std::cout << "==============\n";
  std::cout << "Instructions: Save your friend from alien abduction by guessing the letters in the codeword.\n";
}

void display_status(std::vector<char> incorrect, std::string answer) {

   // Function 
    std::cout << "Incorrect Guesses: \n";
    for (int i = 0; i < incorrect.size(); i++)
    {
      std::cout << incorrect[i] << " ";
    }

    std::cout << "\nCodeword\n";
    for (int i = 0; i < answer.length(); i++)
    {
      std::cout << answer[i] << " ";
    }

}

int main() 
{
  // Introduction
  greet();
  // More...
  std::string codeword = "codecademy"; // what player is guessing
  std::string answer = "__________"; // guessed letters
  int misses = 0; 
  std::vector<char> incorrect;
  bool bGuess = false;
  char playerLetter;

  while (answer != codeword && misses < 7) 
  {

    // displays ASCII Art to show player status
    display_misses(misses);
    display_status(incorrect, answer);

    std::cout << "\n\nEnter a letter: ";
    std::cin >> playerLetter;
    for (int i = 0; i < codeword.length(); i++)
    {
        if (playerLetter == codeword[i]) {
          answer[i] = playerLetter;
          bGuess = true;
        }
    }

    // logic for additional player feedback
    if (bGuess)
    {
        std::cout << "\nGood!";
    }
    else{
      std::cout << "\nIncorrect! Their sucked further in.\n";
      incorrect.push_back(playerLetter);
      misses++;
    }
    bGuess = false;

  }
  end_game(answer, codeword);

    }

      void end_game(std::string answer, std::string     codeword) {
      // Moved the IF/ELSE function into end_game()
      if (answer == codeword)
        {
          std::cout << "Hooray! You saved the person and earned a medal of honor!";
        }
      else
        {
          std::cout << "Oh no! The UFO just flew away with another person.";
        }

}
