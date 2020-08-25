#include <iostream>
#include "ufo_functions.hpp"

int main() {

  std::string codeword = "codecademy";
  std::string answer = "__________";
  int misses = 0;
  std::vector<char> incorrect; // stores incorrect guesses
  bool guess = false; // whether or not the guess is correct
  char letter; // current letter guess

  greet();

  while (answer != codeword && misses < 7) {

    display_misses(misses);

    display_status(incorrect, answer);


    std::cout << "Please enter your guess: ";
    std::cin >> letter;
    // check codeword for letter and replace it in the answer if it is
    for(int k=0; k<codeword.size(); k++) {
      if (letter == codeword[k]) {
        answer[k] = letter;
        guess = true;
      }
    }
    // if they guessed one of the letters, don't add to the misses
    if (guess == true) {
      std::cout << "Correct!\n";
    }
    // if they guessed incorrectly, add that letter to the list of incorrect guesses and increment misses
    else {
      std::cout << "Incorrect! The tractor beam pulls the person in further.\n";
      incorrect.push_back(letter);
      misses++;
    }

    // reset guess to false for the next round of guessing
    guess = false;

  }

  end_game(answer, codeword);

}
