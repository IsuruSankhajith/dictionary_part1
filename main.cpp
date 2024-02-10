
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// TASK 01
/////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Define the Word struct
struct Word {
    string name; // name of the word (data type string)
    string type; // type of the word (for instance noun, verb , adjective)
    string definition; // Definition of the word
};

/**
* Opens a dictionary file and loads its contents into a vector of Word structs
 * User can enter the name of the dictionary file or 'default', if the user needs the default dictionary file
* @param dictionary The vector of Word structs to load the dictionary into.
* @return void
*takes a reference to the vector of Word structs to store the words
* Written by: [Isuru Sankhajith - 10597808]
* Date: [By 21nd march]
*/

// function to open a file and load the dictionary
void Openthedictionary(vector<Word>& dictionary) {
    string directory_Name;
    cout << "Type 'default' to open the default file, or the name of the dictionary file : ";
    cin >> directory_Name;

    if (directory_Name == "default") {
        directory_Name = "dictionary_2023S1.txt";
    }

    ifstream file(directory_Name);
    if (!file.is_open()) {
        cout << "Dictionary file cannot be opened!" << endl;
        return;
    }

    std::string line;
    while (getline(file, line)) {
        if (line == "<word>") {
            Word word;
            getline(file, word.name); // read the next line after <word>
            getline(file, word.definition);
            getline(file, word.type);

            if (word.name.length() > 0) {
                dictionary.push_back(word);
            }
        }
    }

    file.close();

    cout << "Dictionary loaded successfully!" << endl;
}
/**
 * This function called "showallwords" it takes a 'word' object.
 *That function responsible for the show all words in dictionary such as words, type and definition
 *prologue comment block explaining the function and its input and output
 *
 * Written by: [Isuru Sankhajith - 10597808]
 * Date: [By 22nd march]
 */


void ShowAllWords(const vector<Word>& dict) {
    if (dict.empty()) {
        cout << "There is no dictionary loaded." << endl;
        return;
    }

    cout << "Word\t\tType\t\tDefinition" << endl;
    cout << "-----------------------------------------------" << endl;
    for (const auto& word : dict) {
        cout << word.name << "\t\t" << word.type << "\t\t" << word.definition << endl;
    }
}

/**
 *The vector of Word objects is passed to the searchWord function and finds a specified word that the user has input.
 *
 * Written by: [Isuru Sankhajith - 10597808]
 * Date: [By 22nd march]
 */


void searchWord(const vector<Word>& dictionary) {
    if (dictionary.empty()) {
        cout << "No dictionary loaded" << endl;
        return;
    }

    string find_name;
    cout << "Enter the word you want to look up here: ";
    cin >> find_name;

    bool detected = false;
    for (const auto& word : dictionary) {
        if (word.name == find_name) {
            cout << word.name << " (" << word.type << "): " << word.definition << endl;
            detected = true;
            break;
        }
    }

    if (!detected) {
        cout << "Unknown word according to the dictionary" << endl;
    }
}

/**
 * The vector of Word objects is passed to the search word function and finds a dictionary word count
 *
 *takes a reference to the vector of Word structs to display
 *prologue comment block explaining the function and its input and output
 *
 * Written by: [Isuru Sankhajith - 10597808]
 * Date: [By 22nd march]
 */

void ShowWordCount(const vector<Word>& dict) {
    if (dict.empty()) {
        cout << "No dictionary loaded" << endl;
        return;
    }

    cout << "It includes in the dictionary " << dict.size() << " words" << endl;
}

// Main function
int main() {
    vector<Word> dictionary;

    int User_choice;
    do {
        cout << "***Hi users! this is the menu bar that you can search below mentioned, any information.***" << endl;
        cout << "1. Firstly load the dictionary :" << endl;
        cout << "2. Show all words :" << endl;
        cout << "3. Enter a word to find :" << endl;
        cout << "4. Show word count :" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice number: ";
        cin >> User_choice;

        switch (User_choice) {
            case 1:
                Openthedictionary(dictionary);
                break;
            case 2:
                ShowAllWords(dictionary);
                break;
            case 3:
                searchWord(dictionary);
                break;
            case 4:
                ShowWordCount(dictionary);
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (User_choice != 5);

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// TASK 02
////////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * This program allows users to look up words in a dictionary.
 *
 *Users can enter a search term and the program will display any matching words and their definitions.
 *This programme successfully displays that use inputs lower and upper case words
 *prologue comment block explaining the function and its input and output
 *
 * Written by: [Isuru Sankhajith - 10597808]
 * Date: [By 23rd march]
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include<algorithm>
using namespace std;


class Word {
public:
    string name; //name of the word (data type string)
    string type; // type of the word(for instance noun, verb , adjective)
    string meaning; // meaning for the word

    Word(string name = "", string type = "", string meaning = "") : name(name), type(type), meaning(meaning) {}
};

/**
 *Returns the word type in a format
 */

string get_Word_Type(string type) {
    if (type == "noun") {
        return "[noun]";
    } else if (type == "verb") {
        return "[verb]";
    } else if (type == "adverb") {
        return "[adverb]";
    } else if (type == "adjective") {
        return "[adjective]";
    } else if (type == "preposition") {
        return "[preposition]";
    } else if (type == "miscellaneous") {
        return "[miscellaneous]";
    } else if (type == "proper noun") {
        return "[proper noun]";
    } else if (type == "noun and verb") {
        return "[noun and verb]";
    } else {
        return "";
    }
}

/**
 * Show the details of word
 *This function grabs the 'word' object and displays the name, type and meaning
 *get_word_Type' is important for the that shows the word type and other details
 *prologue comment block explaining the function and its input and output
 */

void ShowWord(const Word& word) {
    cout << word.name << endl;
    cout << "Word format: " << get_Word_Type(word.type) << endl;
    cout << word.meaning << endl;
}
/**
 *This function is taking a vector of a 'word' object as input because it main purpose if the input vector is whether
 * empty or not
 * takes a reference to the vector of Word structs to display
 */

void lookupWord(vector<Word>& dictionary) {
    if (dictionary.empty()) {
        cout << "Nothing is in the dictionary." << endl;
        return;
    }

/**
 *This mainly doing the user enters the word to search for in the dictionary
 *Afterwards, that part performs a search through the vector of the object and searches for a matching word.
 */

    string search_word;
    cout << "*************** Hi users! *************** "<<endl;
    cout << "Enter a search word: ";
    cin >> search_word;

    bool detected = false;
    for (const auto& word : dictionary) {
        string lowercase_word = word.name;
        transform(lowercase_word.begin(), lowercase_word.end(), lowercase_word.begin(), ::tolower);
        string lowercase_search_word = search_word;
        transform(lowercase_search_word.begin(), lowercase_search_word.end(), lowercase_search_word.begin(), ::tolower);
        if (lowercase_word == lowercase_search_word) {
            ShowWord(word);
            detected = true;
            break;
        }
    }

    if (!detected) {
        cout << "Word not found." << endl;
    }
}
/**
 * Technically, this function load dictionary file after that returns it functions as a vector of Word objects.
 * If the dictionary successfully opened,that function reads the dictionaries include details via while loop
 * Every iteration it reads dictionary word,type and meaning
 */

vector<Word> loadDictionary(string dictionary_File_Name) {
    vector<Word> dictionary;
    ifstream dictionaryFile(dictionary_File_Name);
    if (!dictionaryFile) {
        cout << "Unable to open dictionary file: " << dictionary_File_Name << endl;
        return dictionary;
    }

    string word_Name, word_Type, word_Meaning;
    while (dictionaryFile >> word_Name >> word_Type) {
        getline(dictionaryFile, word_Meaning);
        dictionary.emplace_back(word_Name, word_Type, word_Meaning);
    }

    dictionaryFile.close();
    return dictionary;
}

/**
 * The main function load the dictionary from a file and searches for a word
 *takes a reference to the vector of Word structs to display
 */

int main() {
    string dictionaryFileName = "dictionary_2023S1.txt";
    vector<Word> dictionary = loadDictionary(dictionaryFileName);

    lookupWord(dictionary);

    return 0;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Task 03
//////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
/**
 * A boolean value is returned by this function after taking a string as input.
 * Afterwards,find words with more than three "z" characters by doing a word search Otherwise, the function returns
 * false.
 * @param the word that will be examined for the letter "z"
 * @return If a term has more than three "z" characters, it is true; otherwise, it is false.
 * Written by: [Isuru Sankhajith - 10597808]
 * Date: [By 27nd march]
 */

bool search(string word) {
    int count = 0;
    for (int i = 0; i < word.size(); i++) {
        if (word[i] == 'z') {
            count++;
        }
    }
    return count > 3;
}
/**
 * Display words from that dictionary forur or more than letter of"z" has words.
 * @param the word that will be examined for the letter "z"
 * @return If a term has more than three "z" characters, it is true; otherwise, it is false.
 */

void Showword(string fileName) {
    string word;
    ifstream dictionaryFile(fileName);
    if (dictionaryFile.is_open()) {
        while (getline(dictionaryFile, word)) {
            if (search(word)) {
                cout << word << endl;
            }
        }
        dictionaryFile.close();
    } else {
        cout << "Unable to open file: " << fileName << endl;
    }
}

/**

 * Main function to run the program
 * @return the program's exit status, int
 */

int main() {
    string dictionaryFileName = "dictionary_2023S1.txt";
    Showword(dictionaryFileName);

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//Task 04
//////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

/**
 * prologue comment block explaining the function and its input and output
 * In this program reads a user load dictionary file
 * Stores the words in a vector of Word structures together with their kind and definition.
 * Afterwards,The words and their information are displayed after alphabetical sorting of the vector.
 *
 * Input - In this program reads a dictionary file that loaded "dictionary_2023S1.txt"
 *
 *Output - That program part shows the words, their type, definition
 * Written by: [Isuru Sankhajith - 10597808]
 * Date: [By 28th march]
 */

using namespace std;
const string FILENAME = "dictionary_2023S1.txt";
struct Word {
    string name;
    string type;
    string definition;
};

/**
 * The first function print_word takes words to object print information for instance - name, type and definition
 * Afterwards, the second function takes a vector of object and string name as input and returns true if there
 * exists a word in the vector with given name
 */

void print_dic_word(const Word& w) {
    cout << "Name: " << w.name << "\n";
    cout << "Type: " << w.type << "\n";
    cout << "Definition: " << w.definition << "\n";
}

bool existing_word(const std::vector<Word>& dictionary, const std::string& name) {
    return std::any_of(dictionary.begin(), dictionary.end(), [&](const Word& w) {
        return w.name == name;
    });
}

/**
 * prologue comment block explaining the function and its input and output
 *
 * The function adds to new information to the dictionary which needs to enter the word's name, type and definition
 */

void add_new_word(std::vector<Word>& dictionary) {
    Word w;
    cout << "Type the word name here : ";
    cin >> w.name;
    if (existing_word(dictionary, w.name)) {
        cout << "Error: word exists, Editing existing words requires advanced privileges..\n";
        return;
    }
    cout << "Enter word type: ";
    cin >> w.type;
    cout << "Type word definition here: ";
    cin.ignore(); // disregard any remaining newline characters in the input stream.
    getline(std::cin, w.definition);
    dictionary.push_back(w);
    cout << "Word added to the dictionary:\n";
    print_dic_word(w);
}

/**
 *This function saves the dictionary file it takes two arguments such as a vector of words and
 *saves the vector's content to the file with the given name.
 */

void store_dictionary(const std::vector<Word>& dictionary, const std::string& filename) {
    ofstream file(filename);
    if (!file.is_open()) { // check to see if the failbit flag is set.
        cout << "Error: unable not open the file " << filename << " to write.\n";
        return;
    }
    for (const auto& w : dictionary) {
        file << w.name << "," << w.type << "," << w.definition << "\n";
    }
    cout << "Dictionary stored in a document " << filename << ".\n";
}

/**
 * prologue comment block explaining the function and its input and output
 *A dictionary is read into and stored in a vector of the word objects by this program part
 */

int main() {
    vector<Word> dictionary;
    string file_name = "dictionary_2023S1.txt";
    ifstream file(file_name);
    if (file.is_open()) {
        string line;
        while (std::getline(file, line)) {
            auto pos1 = line.find(",");
            auto pos2 = line.find(",", pos1 + 1);
            if (pos1 != std::string::npos && pos2 != std::string::npos) {
                Word w;
                w.name = line.substr(0, pos1);
                w.type = line.substr(pos1 + 1, pos2 - pos1 - 1);
                w.definition = line.substr(pos2 + 1);
                dictionary.push_back(w);
            }
        }
        file.close();
        cout<<"********************************* Hi users *********************************"<<".\n";
        cout << "Dictionary loaded from file " << file_name << ".\n";
    } else {
        std::cout << "Error: could not open file " << file_name << " for reading.\n";
        return 1;
    }

/**
 * prologue comment block explaining the function and its input and output
 *This part is the final part of the program's main function that function is called to add a new word to the dictionary
 *Afterwards store_dictionary() function is called to save the updated dictionary file that the user mentioned.
 */

    add_new_word(dictionary);
    cout << "To save dictionaries, enter a file name.: ";
    cin >> file_name;
    store_dictionary(dictionary, file_name);
    return 0;
}





