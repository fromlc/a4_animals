// -----------------------------------------------------------------------------
// A Student
//
// Assignment 4: Animals Game
//------------------------------------------------------------------------------

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
// LRC constexpr int MAX_ANIMALS = 10;
constexpr int MAX_ANIMALS = 3;
// LRC don't hard-coded this constexpr int STARTING_ANIMAL_COUNT = 5;

const string IM_THINKING_OF = "\nThink of an animal, and I'll guess which one.\n";
const string ANIMAL_DOES = "\nDoes your animal ";
const string QUESTION = "? ";
const string ANIMAL_IS = "Your animal is a ";
const string I_WIN = "I guessed your animal!\n\n";
const string I_LOSE = "Aw, I couldn't guess!\n\n";
const string WHAT_ANIMAL = "What animal were you thinking of? ";
const string WHAT_SOUND = "\nWhat sound does it make? ";
const string PLAY_AGAIN = "\nWant to play again (y/n)? ";
const string LEARNED_ANIMAL_OK = "Ok! Got it.\n";
const string MAX_ANIMALS_REACHED = "I don't have room for more animals...";

//------------------------------------------------------------------------------
// globals
//------------------------------------------------------------------------------
string animal_names[MAX_ANIMALS] = {
    "horse",
    "dog",
    // LRC "kitty cat",
    // LRC "pig",
    // LRC "lion",
};

string animal_sounds[MAX_ANIMALS] = {
    "whinny",
    "bark",
    // LRC "meow",
    // LRC "oink",
    // LRC "roar",
};

//------------------------------------------------------------------------------
// local functions
//------------------------------------------------------------------------------
bool typed_yes();
// LRC bool guess_animals_loop();
bool guess_animals_loop(int);
// LRC void learn_animal();
void learn_animal(int);
inline int count_empty_elements(int&, int&);
// LRC #TODO void animals_game_loop();

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    // LRC set max number of animals we can add to the array
    int first_empty_index { }, num_animals { };
    int num_can_learn = count_empty_elements(num_animals, first_empty_index);

    do {
        cout << IM_THINKING_OF;

        if (guess_animals_loop(num_animals)) {
            cout << I_WIN;
        }

        else {
            cout << I_LOSE;
            if (num_can_learn > 0) {
                learn_animal(first_empty_index);
                first_empty_index++;
                num_can_learn--;
            }
            else {
                cout << MAX_ANIMALS_REACHED;
            }
        }

        // play until user quits
        cout << PLAY_AGAIN;

    } while (typed_yes());

    return 0;
}

//------------------------------------------------------------------------------
// returns the maximum number of animals this app can learn
//------------------------------------------------------------------------------
inline int count_empty_elements(int& max_animals, int& first_empty) {

    max_animals = sizeof(animal_names) / sizeof(string);
    int i = 0;

    while (i < max_animals && !animal_names[i].empty()) {
        i++;
    }

    // return data
    first_empty = i;
    return max_animals - i;
}

//------------------------------------------------------------------------------
// returns true when user types 'Y' or 'y', false otherwise
//------------------------------------------------------------------------------
bool typed_yes() {

    char ch;
    cin >> ch;
    cin.clear();
    cin.ignore(10000, '\n');

    return toupper(ch) == 'Y' ? true : false;
}

//------------------------------------------------------------------------------
// returns true when computer guesses the user's animal, false otherwise
//------------------------------------------------------------------------------
// LRC bool guess_animals_loop() {
bool guess_animals_loop(const int max_animals) {

    int i = 0;
    //while (animal_names[i] != "") { // same as
    while (i < max_animals && !animal_names[i].empty()) {

        cout << ANIMAL_DOES << animal_sounds[i] << QUESTION;

        if (typed_yes()) {
            cout << ANIMAL_IS << animal_names[i] << "!\n";
            return true;
        }

        i++;    // bump loop index
    }

    return false;
}

//------------------------------------------------------------------------------
// Ask what animal you were thinking
//------------------------------------------------------------------------------
void learn_animal(int use_index) {

    cout << WHAT_ANIMAL;
    cin >> animal_names[use_index];

    cout << WHAT_SOUND;
    cin >> animal_sounds[use_index];

    cout << LEARNED_ANIMAL_OK;
}