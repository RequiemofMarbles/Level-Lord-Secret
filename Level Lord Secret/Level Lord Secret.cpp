#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool promptForPassword(const string& correctPassword);
void displayFile(const string& filename);

int main() {
    
    const string level_LordPassword = "DukeNukem_3D";
    const string cheat_Codes = "dnclip.txt"; 

    char choice;
    cout << "Would you like to view the Cheat Codes for Duke Nukem 3D? (Y/N): ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y') {
        
        bool accessGranted = promptForPassword(level_LordPassword);

        if (accessGranted) {
            
            displayFile(cheat_Codes);
        }
        else {
            cout << "\nYou must be the alien bastards that busted up my ride\n";
            return 1; 
        }
    }
    else {
        cout << "Its time to kick ass and chew bubble gum. Damn, I'm all outta gum.\n";
    }

    return 0;
}

bool promptForPassword(const string& correctPassword) {
    string userInput;
    const int max_Tries = 3;

    for (int trys = 1; trys <= max_Tries; ++trys) {
        cout << "Enter password (Attempt " << trys << " of " << max_Tries << "): ";
        cin >> userInput;

        if (userInput == correctPassword) {
            cout << "\n Lets Rock!\n";
            return true;
        }
        else {
            cout << "Eat shit and die\n";
        }
    }

    return false; 
}

void displayFile(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "What is this?! '" << filename << "'. Make it so!\n";
        return;
    }

    cout << "--- Duke Nukem 3D Cheat Codes ---\n";
    string line;
    while (getline(file, line)) {
        cout << line << "\n";
    }
    cout << "-------------------------\n";

    file.close();
}