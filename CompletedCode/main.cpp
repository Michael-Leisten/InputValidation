#include <ctype.h>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

char get_char_from_user();
string get_word_from_user();
string get_sentence_from_user();
int get_int_from_user();
double get_float_from_user();

int main() {
    char letter = get_char_from_user();
    cout << "You entered the character " << letter << endl;
    string word = get_word_from_user();
    cout << "You entered the word " << word << endl;
    string sentence = get_sentence_from_user();
    cout << "You entered the sentence: " << sentence << endl;
    int num = get_int_from_user();
    cout << "You entered the number " << num << endl;
    double flo = get_float_from_user();
    cout << "You entered the floating-point number " << flo << endl;
    return 0;
}

char get_char_from_user() {
    // NOTE: a char is not restricted to an alphabet letter
    string input;
    char character;
    cout << "Enter a single character: ";
    getline(cin, input);
    // Checks if the user input is not equal to 1 character
    while (input.length() != 1) {
        // If the input is several characters long
        if (input.length() > 1) {
            cout << "Invalid input. Enter a single character: ";
            getline(cin, input);
        }
        // Checks for no input
        else {
            cout << "No input. Enter a single character: ";
            getline(cin, input);
        }
    }
    character = input[0];
    return character;
}

string get_word_from_user() {
    string word;
    cout << "Enter a single word: ";
    getline(cin, word);

    bool valid = false;
    // loop to check for the cases and recheck after a new input
    while (!valid) {
        valid = true;
        // Ensures the user makes an input
        while (word.length() == 0) {
            cout << "No input. Enter a single word: ";
            getline(cin, word);
        }
        for (int i = 0; i < word.length(); i++) {
            // Checks if there are any numbers in the word
            if (!isalpha(word[i])) {
                cout << "Invalid input. Enter a single word: ";
                getline(cin, word);
                valid = false;
                break;
            }
            // Checks if there are any spaces between words
            if (word[i] == ' ') {
                cout << "Invalid input. Enter a single word: ";
                getline(cin, word);
                valid = false;
                break;
            }
        }
    }
    return word;
}

string get_sentence_from_user() {
    // NOTE: a sentence does NOT need punctuation or syntax validation
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    bool valid = false;
    // loop to check for the cases and recheck after a new input
    while (!valid) {
        valid = true;
        // Ensures the user makes an input
        while (sentence.length() == 0) {
            cout << "No input. Enter a sentence: ";
            getline(cin, sentence);
        }
        for (int i = 0; i < sentence.length(); i++) {
            // Checks if there are any numbers in the word
            if (isdigit(sentence[i])) {
                cout << "Invalid input. Enter a sentence: ";
                getline(cin, sentence);
                valid = false;
                break;
            }
        }
    }
    return sentence;
}

int get_int_from_user() {
    // TODO: Complete the function
    string stringNumber;
    int number;
    stringstream ss;
    cout << "Enter a number: ";
    getline(cin, stringNumber);

    bool valid = false;
    // loop to check for the cases and recheck after a new input
    while (!valid) {
        valid = true;
        // Checks to make sure there is an input
        while (stringNumber.length() == 0) {
            cout << "No input. Enter a number: ";
            getline(cin, stringNumber);
            valid = false;
        }
        // Loop for if the first character is a negative sign
        if (stringNumber[0] == '-') {
            for (int i = 1; i < stringNumber.length(); i++) {
                // Checks to make sure only integers are used
                if (!isdigit(stringNumber[i])) {
                    cout << "Invalid input. Enter a number: ";
                    getline(cin, stringNumber);
                    valid = false;
                    break;
                }
            }
        }
        // loop for positive numbers
        else {
            for (int i = 0; i < stringNumber.length(); i++) {
                if (!isdigit(stringNumber[i])) {
                    cout << "Invalid input. Enter a number: ";
                    getline(cin, stringNumber);
                    valid = false;
                    break;
                }
            }
        }
    }
    // converts string to stringstream
    ss << stringNumber;
    // converts stringstream to int
    ss >> number;
    return number;
}

double get_float_from_user() {
    // TODO: Complete the function
    // NOTE: a float does not need to have a decimal part (meaning an integer is a valid float)
    string stringFloat;
    double numberFloat;
    stringstream ss;
    cout << "Enter a floating-point number: ";
    getline(cin, stringFloat);

    bool valid = false;
    // used to check if a decimal is present
    bool floatDecimal = false;
    // loop to check for the cases and recheck after a new input
    while (!valid) {
        valid = true;
        // ensures there is an input
        while (stringFloat.length() == 0) {
            cout << "No input. Enter a floating-point number: ";
            getline(cin, stringFloat);
            valid = false;
        }
        // Loop for if the first character is a negative sign
        if (stringFloat[0] == '-') {
            for (int i = 1; i < stringFloat.length(); i++) {
                // Checks for a decimal point
                if (stringFloat[i] == '.') {
                    // if there is a second decimal point found, makes sure the input is invalid
                    if (floatDecimal == true) {
                        cout << "Invalid input. Enter a floating-point number: ";
                        getline(cin, stringFloat);
                        valid = false;
                        break;
                    }
                    floatDecimal = true;
                }
                // checks to make sure any other characters are integers
                else if (!isdigit(stringFloat[i])) {
                    cout << "Invalid input. Enter a floating-point number: ";
                    getline(cin, stringFloat);
                    valid = false;
                    break;
                }
            }
        }
        // same as the first for loop except for positive numbers
        else {
            for (int i = 0; i < stringFloat.length(); i++) {
                if (stringFloat[i] == '.') {
                    if (floatDecimal == true) {
                        cout << "Invalid input. Enter a floating-point number: ";
                        getline(cin, stringFloat);
                        valid = false;
                        break;
                    }
                    floatDecimal = true;
                }
                else if (!isdigit(stringFloat[i])) {
                    cout << "Invalid input. Enter a floating-point number: ";
                    getline(cin, stringFloat);
                    valid = false;
                    break;
                }
            }
        }
    }
    // converts string to stringstream
    ss << stringFloat;
    // converts stringstream to double
    ss >> numberFloat;
    return numberFloat;
}