//------------------------------------------------------------------------------
// a4_animals.cpp 
//
// Animals game: computer asks questions to guess user's animal
//------------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
constexpr int MAX_ANIMALS = 10;

const string IM_THINKING_OF = "\nThink of an animal, and I'll guess which one.\n";
const string ANIMAL_DOES = "\nDoes your animal ";
const string QUESTION = "? ";
const string ANIMAL_IS = "Your animal is a ";
const string I_WIN = "I guessed your animal!\n\n";
const string I_LOSE = "Aw, I couldn't guess!\n\n";

//------------------------------------------------------------------------------
// globals
//------------------------------------------------------------------------------
string animal_names[MAX_ANIMALS] = {
    "horse",
    "dog",
    "kitty cat",
    "pig",
    "lion",
};

string animal_sounds[MAX_ANIMALS] = {
    "whinny",
    "bark",
    "meow",
    "oink",
    "roar",
};

//------------------------------------------------------------------------------
// local functions
//------------------------------------------------------------------------------
bool typed_yes();
bool guess_animals_loop();

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    cout << IM_THINKING_OF;

    if (guess_animals_loop())
        cout << I_WIN;
    else
        cout << I_LOSE;

    return 0;
}

//------------------------------------------------------------------------------
// returns true when user types 'Y' or 'y', false otherwise
//------------------------------------------------------------------------------
bool typed_yes() {

    char ch;
    cin >> ch;
    ch = toupper(ch);

    return ch == 'Y' ? true : false;
}

//------------------------------------------------------------------------------
// returns true when computer guesses the user's animal, false otherwise
//------------------------------------------------------------------------------
bool guess_animals_loop() {

    int i = 0;
    //while (animal_names[i] != "") { // same as
    while (!animal_names[i].empty()) {

        cout << ANIMAL_DOES << animal_sounds[i] << QUESTION;

        if (typed_yes()) {
            cout << ANIMAL_IS << animal_names[i] << "!\n";
            return true;
        }

        i++;    // bump loop index
    }

    return false;
}
