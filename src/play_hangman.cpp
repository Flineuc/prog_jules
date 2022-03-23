#include "play_hangman.hpp"
#include "random.hpp"
#include <array>
#include <iostream>
#include <string>
#include <string_view>

const std::string pick_a_random_word() {
  static std::array words = {
      "flavos", "sully", "solem", "yayelle", "theo", "tanguos", "jordy", "lisa",
  };
  std::string word;
  int index = rand(0, words.size() - 1);
  return word = words[index];
}

void show_nb_lives(int nb_lives) {
  std::cout << "\nTu as " << nb_lives << " vies." << std::endl;
}

void reduce_nb_lives(int &nb_lives) { nb_lives--; }

char get_letter_from_user() {
  char letter;
  std::cin >> letter;
  return letter;
}

bool word_contains(char letter, std::string word) {
  if (word.find(letter) != std::string::npos)
    return true;
  else
    return false;
}

void show_word_to_guess_with_missing_letters(
    std::string word, std::vector<bool> letters_guessed) {
  size_t i = 0;
  std::cout << "Il ressemble a ça : ";
  while (i < word.size()) {
    if (letters_guessed[i])
      std::cout << word[i];
    else
      std::cout << "_ ";
    i++;
  }
  std::cout << std::endl;
}

void mark_as_guessed(char guessed_letter, std::vector<bool> &letters_guessed,
                     std::string word) {
  size_t i = 0;
  while (i < word.size()) {
    if (word[i] == guessed_letter)
      letters_guessed[i] = true;
    i++;
  }
}

bool player_is_alive(int nb_lives) {
  if (nb_lives > 0)
    return true;
  else
    return false;
}

bool player_has_won(std::vector<bool> letters_guessed) {
  bool winner = false;
  size_t i = 0;
  while (i < letters_guessed.size()) {
    if (letters_guessed[i])
      winner = true;
    else
      winner = false;
    i++;
  }
  return winner;
}

void display_final_message(int nb_lives, std::vector<bool> letters_guessed,
                           std::string word_to_guess) {
  if (player_has_won(letters_guessed)) {
    std::cout << "\nBravo tu as trouvé, c'était bien le mot : " << word_to_guess
              << " !" << std::endl;
  }
  if (!player_is_alive(nb_lives)) {
    std::cout << "\nDeso, t'es mort, tu aurais du trouver le mot : "
              << word_to_guess << " !" << std::endl;
  }
}

void play_hangman() {
  std::string word_to_guess = pick_a_random_word();
  std::vector<bool> letters_guessed;
  for (size_t i = 0; i < word_to_guess.size(); i++) {
    letters_guessed.push_back(false);
  }
  int nb_lives = 8;

  std::cout << "J'ai choisi un mot. Trouve le !" << std::endl;

  while (player_is_alive(nb_lives) && !player_has_won(letters_guessed)) {
    show_nb_lives(nb_lives);
    show_word_to_guess_with_missing_letters(word_to_guess, letters_guessed);
    std::cout << "Essaie avec une lettre :\n";
    const auto test_letter = get_letter_from_user();
    if (word_contains(test_letter, word_to_guess)) {
      mark_as_guessed(test_letter, letters_guessed, word_to_guess);
      std::cout << "BG, Cette lettre est dedans !\n";
    } else {
      std::cout << "Aie, elle y est pas... Tu perds une vie !\n";
      reduce_nb_lives(nb_lives);
    }
  }
  display_final_message(nb_lives, letters_guessed, word_to_guess);
}