#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


char getUserChoice_RPS() {
    char choice;
    cout << "Enter your choice (R for Rock, P for Paper, S for Scissors): ";
    cin >> choice;
    return toupper(choice);
}


char getComputerChoice_RPS() {
    srand(time(NULL)); 
    int randomNum = rand() % 3;
    char choices[] = {'R', 'P', 'S'};
    return choices[randomNum];
}


void determineWinner_RPS(char userChoice, char computerChoice) {
    if (userChoice == computerChoice) {
        cout << "It's a tie!\n";
    } else if ((userChoice == 'R' && computerChoice == 'S') ||
               (userChoice == 'P' && computerChoice == 'R') ||
               (userChoice == 'S' && computerChoice == 'P')) {
        cout << "You win!\n";
    } else {
        cout << "Computer wins!\n";
    }
}

int RPS() {
    char userChoice, computerChoice;
    char playAgain = 'Y';

    while (playAgain == 'Y') {
        userChoice = getUserChoice_RPS();
        computerChoice = getComputerChoice_RPS();

      
        cout << "Your choice: " << userChoice << endl;
        cout << "Computer's choice: " << computerChoice << endl;

       
        determineWinner_RPS(userChoice, computerChoice);

        
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;
        playAgain = toupper(playAgain); 
    }

    cout << "Thanks for playing!\n";

    return 0;
}

