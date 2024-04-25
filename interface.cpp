#include "Guess the number.cpp"
#include "Hangman.cpp"
#include "TicTacToe.cpp"
#include "quiz.cpp"
#include "rock paper scissors.cpp"
#include "Pacman.cpp"
#include "Snakegame.cpp"

#include <iostream>

int cog() {
  int choice{0};
  while (choice != 5) {
    cout
        << "1: To Play Guess The Number\n2: To Play Hangman\n3: To Participate "
           "In A Short Quiz\n4: To Play TicTacToe\n5: To play Rock Paper Scissors\n
           6: To play pacman\n7: To play Snake Game\n8: To Quit The Game\nEnter "
           "Your Choice: ";
    cin >> choice;
    switch (choice) {
    case 1:
      initiateGuessTheNumber();
      break;
    case 2:
      initiateHangman();
      break;
    case 3:
      Quiz_Game();
      break;
    case 4:
      initiateTicTacToe();
      break;
    case 5:
      RPS();
    case 6:
        initiatePacman();
    case 7:
        initiateSnakeGame();
    case 8:
        return 0;
    default:
      cout << "Invalid choice";
    }
  }

  return 1;
}

int main() {
  cout << "\t\tTap-Mania\nBy Anjana, Nicole, Prachi, Shalvi, Sohini and Suchetana\n";
  while (true) {
    if (cog() == 0)
      break;
  }
  cout << "Thank you for playing!" << endl;
  return 0;
}
