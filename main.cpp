#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    char userPlay = ' ';
    ifstream inputFile;
    ofstream outputFile;

    while (true)
    {
        cout << "Welcome to the madLib Game!" << endl;
        cout << "--------------------------------" << endl;
        cout << "Would you like to play? (y/n): ";
        cin >> userPlay;
        // cin.ignore();
        cout << endl;

        if (userPlay == 'Y' || userPlay == 'y')
        {
            cout << "Which MadLib would you like to play?" << endl;
            cout << "1. Zoo MadLib" << endl;
            cout << "2. Camping MadLib" << endl;
            int userChoice = 0;
            cin >> userChoice;

            if (userChoice == 1)
            {
                cout << "Great choice. Time to go to the zoo!" << endl;
                cout << "Loading file..." << endl;

                inputFile.open("madLibZoo.txt");
                if (!inputFile.is_open())
                {
                    cerr << "Failed to open madLibZoo.txt" << endl;
                    return 1;
                }

                outputFile.open("adjustMadLib.txt");
                if (!outputFile.is_open())
                {
                    cerr << "Failed to open adjustMadLib.txt" << endl;
                    return 1;
                }

                break;
            }
            else if (userChoice == 2)
            {
                cout << "Great choice. Time to go camping!" << endl;
                cout << "Loading file..." << endl;
                inputFile.open("madLibCamping.txt");

                if (!inputFile.is_open())
                {
                    cerr << "Failed to open madLibCamping.txt" << endl;
                    return 1;
                }

                outputFile.open("adjustMadLib.txt");
                if (!outputFile.is_open())
                {
                    cerr << "Failed to open adjustMadLib.txt" << endl;
                    return 1;
                }

                break;
            }
            else
            {
                cout << "Sorry please choose 1 or 2" << endl;
            }
        }
        else if (userPlay == 'N' || userPlay == 'n')
        {
            cout << "Sorry you didn't want to play" << endl;
            return 0;
        }
        else
        {
            cout << "Sorry please choose Y or N" << endl;
        }
    }

    regex pattern("\\(([^)]+)\\)"); // Regular expression to match text inside parentheses

    string line;
    while (getline(inputFile, line))
    {
        smatch matches;
        while (regex_search(line, matches, pattern))
        {
            for (size_t i = 1; i < matches.size(); i++)
            {
                string placeholder = matches[i];
                string replacement;

                // Ask the user to enter a word based on the placeholder
                if (placeholder == "noun")
                {
                    cout << "Please enter a noun: ";
                    cin >> replacement;
                    cin.ignore();
                }
                else if (placeholder == "verb")
                {
                    cout << "Please enter a verb: ";
                    cin >> replacement;
                    cin.ignore();
                }
                else if (placeholder == "adjective")
                {
                    cout << "Please enter an adjective: ";
                    cin >> replacement;
                    cin.ignore();
                }
                else if (placeholder == "proper_noun")
                {
                    cout << "Please enter a proper noun: ";
                    cin >> replacement;
                    cin.ignore();
                }
                else if (placeholder == "animal")
                {
                    cout << "Please enter an animal: ";
                    cin >> replacement;
                    cin.ignore();
                }
                else if (placeholder == "color")
                {
                    cout << "Please enter a color: ";
                    cin >> replacement;
                    cin.ignore();
                }
                else if (placeholder == "adverb")
                {
                    cout << "Please enter an adverb: ";
                    cin >> replacement;
                    cin.ignore();
                }
                else if (placeholder == "number")
                {
                    cout << "Please enter a number: ";
                    cin >> replacement;
                    cin.ignore();
                }
                else if (placeholder == "measure_of_time")
                {
                    cout << "Please enter a measure of time: ";
                    cin >> replacement;
                    cin.ignore();
                }
                else if (placeholder == "silly_word")
                {
                    cout << "Please enter a silly word: ";
                    cin >> replacement;
                    cin.ignore();
                }
                else if (placeholder == "noun_animal")
                {
                    cout << "Please enter an animal: ";
                    cin >> replacement;
                    cin.ignore();
                }
                else if (placeholder == "verb_past_tense")
                {
                    cout << "Please enter a verb, past tense: ";
                    cin >> replacement;
                    cin.ignore();
                }

                // Replace the placeholder with the user's input
                line = regex_replace(line, regex("\\(" + placeholder + "\\)"), replacement);
                line = regex_replace(line, regex("\\(\\)"), ""); // Remove any leftover parentheses
            }
        }

        outputFile << line << endl; // Write the modified line to the output file
    }
    inputFile.close();
    outputFile.close();

    cout << "MadLib completed." << endl;

    ifstream output("adjustMadLib.txt");
    if (output.is_open())
    {
        cout << "\nYour MadLib:\n";
        string outputLine;
        while (getline(output, outputLine))
        {
            cout << outputLine << endl;
        }
        output.close();
    }
    else
    {
        cerr << "Failed to open the output file for reading." << endl;
    }

    return 0;
}
