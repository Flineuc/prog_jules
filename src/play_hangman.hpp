#include <array>
#include <iostream>
#include <random>

const std::string *pick_a_random_word() {
  static constexpr std::array words = {
      "flavos", "sully", "solem", "yayelle", "theo", "tanguos", "jordy", "lisa",
  };
  std::string word;
  return word = words(rand(0, 7));
}

int rand(int min, int max) {
  static std::default_random_engine generator{std::random_device{}()};
  std::uniform_int_distribution<int> distribution{min, max};
  return distribution(generator);
}

void show_nb_lives(int nb_lives) {
  if (nb_lives == 0)
    std::cout << "Dsl, t'es mort !" << std::endl;
  else
    std::cout << "Il te reste :" << nb_lives << std::endl;
}

void reduce_nb_lives(int nb_lives) { return nb_lives - 1; }

char get_letter_from_user() {
  char letter;
  std::cin >> letter;
  return letter;
}

void test_letter_(char letter, std::string word) {}

bool word_contains(char letter, std::string_view word) {
  // TODO
}

void play_hangman() {

  pick_a_word_to_guess();
  while (player_is_alive() && !player_has_won()) {
    show_number_of_lives();
    show_word_to_guess_with_missing_letters();
    const auto guess = get_char_from_user();
    if (word_to_guess_contains(guess)) {
      mark_as_guessed(guess);
    } else {
      remove_one_life();
    }
  }
  if (player_has_won()) {
    show_congrats_message();
  } else {
    show_defeat_message();
  }

  std::cout << "J'ai choisi un mot. Trouve le !" << std::endl;
  std::cout << "Essaie :\n";
  int valueTested = get_int_from_user();
  while (value != valueTested) {
    if (valueTested < value)
      std::cout << "Trop petit !";
    else
      std::cout << "Trop grand !";
    std::cout << " Ressaie :\n";
    valueTested = get_int_from_user();
  }
  std::cout << "Bravo, tu as trouvé ! C'était bien le nombre " << value << " !"
            << std::endl;
}