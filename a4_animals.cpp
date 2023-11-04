//------------------------------------------------------------------------------
// a4_animals.cpp 
//
// Animals game: computer asks questions to guess user's animal
//------------------------------------------------------------------------------
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
const string WELCOME = "\nWelcome to the Animals guessing game!\n";
const string NO_MORE_ANIMALS = "\nWe can play, but I can't learn more animals.\n";
const string IM_THINKING_OF = "\nThink of an animal, and I'll guess which one.\n";
const string ANIMAL_DOES = "\nDoes your animal ";
const string QUESTION = "? ";
const string EXCLAMATION = "! ";
const string ANIMAL_IS = "Your animal is a ";
const string I_WIN = "I guessed your animal!\n\n";
const string I_LOSE = "Aw, I couldn't guess!\n\n";
const string NEW_ANIMAL = "What was your animal? ";
const string NEW_SOUND = "What sound does your animal make? ";
const string ANIMAL_LEARNED = "Ok, now I can guess that animal too!\n\n";
const string PLAY_AGAIN = "Do you want to play again? ";
const string GOODBYE = "\nGoodbye!\n\n";


//------------------------------------------------------------------------------
// globals
//------------------------------------------------------------------------------
namespace g {

    constexpr int MAX_ANIMALS = 8;

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
}

//------------------------------------------------------------------------------
// local functions
//------------------------------------------------------------------------------
int get_first_empty_index();
inline void get_input_string(string&);
bool typed_yes();
bool guess_animals_loop(int&);
void learn_animal(int);

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    cout << WELCOME;

    int next_index = get_first_empty_index();

    do {

        // display message when we can't learn more animals
        if (next_index >= g::MAX_ANIMALS) {
            cout << NO_MORE_ANIMALS;
        }

        // guess user's animal
        cout << IM_THINKING_OF;

        int found_index { };
        if (guess_animals_loop(found_index)) {
            cout << ANIMAL_IS << g::animal_names[found_index] << EXCLAMATION;
            cout << I_WIN;
        }
        else {
            cout << I_LOSE;

            // if the arrays have room, learn the new animal
            if (next_index < g::MAX_ANIMALS) {
                learn_animal(next_index);
                next_index++;
            }
        }

        cout << PLAY_AGAIN;

    } while (typed_yes());

    cout << GOODBYE;
    return 0;
}

//------------------------------------------------------------------------------
// -returns true if there are unused elements in the array
// -puts index of the first unused array element in index parameter
//------------------------------------------------------------------------------
int get_first_empty_index() {

    int index = 0;
    while (index < g::MAX_ANIMALS && !g::animal_names[index].empty()) {

        index++;
    }

    return index;
}

//------------------------------------------------------------------------------
// cin macro
//------------------------------------------------------------------------------
inline void get_input_string(string& str) {

    //cin.clear();
    //cin.ignore(10000, '\n');

    getline(cin, str);
}

//------------------------------------------------------------------------------
// returns true when user types 'Y' or 'y', false otherwise
//------------------------------------------------------------------------------
bool typed_yes() {

    string str;
    get_input_string(str);

    if (!str.empty() && toupper(str.at(0)) == 'Y')
        return true;

    return false;
}

//------------------------------------------------------------------------------
// returns true when computer guesses the user's animal, false otherwise
//------------------------------------------------------------------------------
bool guess_animals_loop(int& found_index) {

    int i = 0;
    while (i < g::MAX_ANIMALS && !g::animal_names[i].empty()) {

        cout << ANIMAL_DOES << g::animal_sounds[i] << QUESTION;

        if (typed_yes()) {
            found_index = i;
            return true;
        }

        i++;    // bump loop index
    }

    return false;
}

//------------------------------------------------------------------------------
// -put a new animal and its sound in the arrays at passed next_index
// -update reference param next_index
//------------------------------------------------------------------------------
void learn_animal(int next_index) {

    cout << NEW_ANIMAL;
    get_input_string(g::animal_names[next_index]);

    cout << NEW_SOUND;
    get_input_string(g::animal_sounds[next_index]);

    cout << ANIMAL_LEARNED;
}
