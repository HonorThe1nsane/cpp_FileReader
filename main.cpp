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
        cout << endl;

        if (userPlay == 'Y' || userPlay == 'y')
        {
            cout << "Which MadLib would you like to play?" << endl;
            cout << "1. Zoo MadLib" << endl;
            cout << "2. Camping MadLib" << endl;
            int userChoice = 0;
            cin >> userChoice;
            cin.ignore();
            cout << endl;
            if (userChoice == 1)
            {
                cout << "Great choice. Time to go to the zoo!" << endl;
                cout << "Loading file..." << endl;
                {

                    inputFile.open("madLibZoo.txt");
                    outputFile.open("adjustMadLib.txt");
                    break;
                }
            }
            else if (userChoice == 2)
            {
                cout << "Great choice. Time to go camping!" << endl;
                cout << "Loading file..." << endl;
                {

                    inputFile.open("madLibCamping.txt");
                    outputFile.open("adjustMadLib.txt");
                    break;
                }
            }
            else
            {
                cout << "Sorry please choose 1 or 2" << endl;
            }
        } else if (userPlay == 'N' || userPlay == 'n')
        {
            cout << "Sorry you didn't want to play" << endl;
            return 0;
        }
        else
        {
            cout << "Sorry please choose Y or N" << endl;
        }
    }

    if (!inputFile.is_open() || !outputFile.is_open())
    {
        cerr << "Failed to open one or more files." << endl;
        return 1;
    }


    regex pattern("\\(.*?\\)");  // Regular expression to match text inside parentheses

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
                if (placeholder == "noun") {
                    cout << "Please enter a noun: ";
                } else if (placeholder == "verb") {
                    cout << "Please enter a verb: ";
                } else if (placeholder == "adjective") {
                    cout << "Please enter an adjective: ";
                } else if (placeholder == "proper noun") {
                    cout << "Please enter a proper noun: ";
                } else if (placeholder == "animal") {
                    cout << "Please enter an animal: ";
                } else if (placeholder == "color") {
                    cout << "Please enter a color: ";
                } else if (placeholder == "adverb") {
                    cout << "Please enter an adverb: ";
                } else if (placeholder == "number") {
                    cout << "Please enter a number: ";
                } else if (placeholder == "measure of time") {
                    cout << "Please enter a measure of time: ";
                } else if (placeholder == "silly word") {
                    cout << "Please enter a silly word: ";
                } else if (placeholder == "noun - animal"){
                    cout << "Please enter an animal: ";
                } else if (placeholder == "verb, past tense"){
                    cout << "Please enter a verb, past tense: ";
                }

                cin.ignore();
                getline(cin, replacement);

                // Replace the placeholder with the user's input
                line = regex_replace(line, regex(placeholder), replacement);
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