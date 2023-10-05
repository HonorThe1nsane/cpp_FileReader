#include <iostream>
#include <fstream>
#include <string>

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
    cout << "Loading..." << endl;

    string line;
    while (getline(inputFile, line))
    {
        string adjective;
        cout << "Please enter an adjective" << endl;
        cin >> adjective;
        size_t pos0 = line.find("(adjective)");
        while (pos0 != string::npos)
        {
            line.replace(pos0, adjective.length(), adjective);
            pos0 = line.find("(adjective)", pos0 + 1);
        }
        string noun;
        cout << "Please enter a noun" << endl;
        size_t pos1 = line.find("(noun)");
        while (pos1 != string::npos)
        {
            line.replace(pos1, noun.length(), noun);
            pos1 = line.find("(noun)", pos1 + 1);
        }
        string verbPT;
        cin >> verbPT;
        cout << "Please enter a noun" << endl;
        size_t pos2 = line.find("(verb, past tense)");
        while (pos2 != string::npos)
        {
            line.replace(pos2, adjective.length(), verbPT);
            pos2 = line.find("(verb, past tense)", pos2 + 1);
        }
        outputFile << line << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}