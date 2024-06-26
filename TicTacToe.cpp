#include <iostream>
#include <ctime>
#define checkcells(box1, box2, box3) ((board[box1] == board[box2]) && (board[box2] == board[box3]) && (board[box1] != 0))
#define xando(x) ((x > 0) ? (x == 1) ? 'X' : 'O' : ' ')

using namespace std;
int checkwin(int board[9]) {

	int winner = 0;
	for (int x = 0; x < 3; x++) {
		if (checkcells(3*x, 3*x+1, 3*x+2)) {
			winner = board[3*x];
			break;
		} else if (checkcells(x, x+3, x+6)) {
			winner = board[x];
			break;

		} else if (checkcells(2*x, 4, 8-2*x) && (x < 2)) {
			winner = board[4];
			break;
		}
	}
	return winner;
}
bool endofgame(int board[9]){
	int winner = checkwin(board);
	if (winner > 0) {
	    if(xando(winner)=='O'){
		cout << "Bot wins!"<< endl;
	    }
	    else{
            cout<<"Player wins!"<<endl;
            }
		return true;
	}
	for (int x = 0; x < 9; x++) {
		if (board[x] == 0) return false;
	}
	cout << "It's a tie!\n\n";
	return true;
}

int willWin(int board[9], int player) {

	for (int x = 0; x < 9; x++) {
		int tempBoard[9];
		memcpy(tempBoard, board, 36);
		if (board[x] > 0) continue;
		tempBoard[x] = player;
		if(checkwin(tempBoard) == player) return x;
	}
	return -1;
}

int case1(int board[9]) {

	int cases[2][9] = {{1,0,0,0,2,0,0,0,1}, {0,1,0,1,2,0,0,0,0}};
	int answers[2][4] = {{3,3,3,3}, {2,8,6,0}};
	int rotatedBoard[9] = {6,3,0,7,4,1,8,5,2};
	int newBoard[9];
	int tempBoard[9];
	for(int x = 0; x < 9; x++) {
		newBoard[x] = board[x];
	}
	for (int caseIndex = 0; caseIndex < 2; caseIndex++) {
		for(int rotation = 0; rotation < 4; rotation++) {
			for (int x = 0; x < 9; x++)
				tempBoard[x] = newBoard[x];

			int match = 0;
			for (int box = 0; box < 9; box++) {
				newBoard[box] = tempBoard[rotatedBoard[box]];
			}

			for (int x = 0; x < 9; x++) {
				if (newBoard[x] == cases[caseIndex][x]) match++;
				else break;
			}
			if (match == 9) return answers[caseIndex][rotation];
		}
	}
	return -1;
}

int checkspace(int board[9], int spaces[4]) {
	bool isSpaceEmpty = false;
	int y;
	for (int x = 0; x < 4; x++) {
		if (board[spaces[x]] == 0) {
			isSpaceEmpty = true;
			break;
		}
	}
	if (isSpaceEmpty) {
		do {
			y = rand() % 4;
		} while (board[spaces[y]] != 0);
		return spaces[y];
	}
	return -1;
}

void newboard(int board[9]) {
	for(int line = 0; line < 3; line++){
		for (int box = 0; box < 3; box++) {
			cout << xando(board[3*line+box]) << ((box < 2) ? '|' : '\n');
		}
		cout << ((line < 2) ? "-----\n" : "\n");
	}
}

int initiateTicTacToe(){
    cout<<"-------Welcome to a game of tic-tac-toe--------------"<<endl<<"Player vs bot"<<endl;
    cout<<"The following are the positions of the cells"<<endl<<"Press a number between(1-9):"<<endl;

	int board[9] = {0,0,0,0,0,0,0,0,0};
	int case2;
	int move;
	bool isInvalid;
	string moveString;
	srand((int) time(0));
	int corners[4] = {0,2,6,8};
	int sides[4] = {1,3,5,7};

	cout << "1|2|3\n-----\n4|5|6\n-----\n7|8|9\n\n";

	while (true) {
		do {
			cout << "X: ";
			getline(cin, moveString);
			move = moveString[0] - '1';
			if (move > 8 || move < 0 || board[move] != 0) {
				cout << "Invalid input" << endl<<"Enter a number between 1 to 9"<<endl;
				isInvalid = true;
			} else {
				board[move] = 1;
				isInvalid = false;
				cout << endl;
			}
		} while (isInvalid);
		if (endofgame(board) > 0) {
			newboard(board);
			break;
		}

		bool good = false;
		for (int x = 2; x > 0; x--){
			case2 = willWin(board, x);
			if (case2 != -1) {
				board[case2] = 2;
				good = true;
				break;
			}
		}
		if (good);
		else if (board[4] == 0) board[4] = 2;
		else if (case1(board) > -1) board[case1(board)] = 2;
		else if (checkspace(board, corners) != -1) board[checkspace(board, corners)] = 2;
		else board[checkspace(board, sides)] = 2;

		newboard(board);
		if(endofgame(board)) break;

	}
	return 0;
}

