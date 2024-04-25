//DEVELOPED  BY SHALVI ATUL SURVE (23BCE0088)
//VIT VELLORE

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <vector>

#define MAXSNAKESIZE 100

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y) {
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}

class Point {
private:
    int x;
    int y;
    char symbol;

public:
    Point() {
        x = y = 10;
        symbol = 'O'; // Default symbol for snake
    }
    Point(int x, int y, char symbol) {
        this->x = x;
        this->y = y;
        this->symbol = symbol;
    }
    void SetPoint(int x, int y) {
        this->x = x;
        this->y = y;
    }
    int GetX() {
        return x;
    }
    int GetY() {
        return y;
    }
    void MoveUp() {
        y--;
    }
    void MoveDown() {
        y++;
    }
    void MoveLeft() {
        x--;
    }
    void MoveRight() {
        x++;
    }
    void Draw() { // Function to draw point
        gotoxy(x, y);
        cout << symbol;
    }
    void Erase() {
        gotoxy(x, y);
        cout << " ";
    }
    void Debug() {
        cout << "(" << x << "," << y << ") ";
    }
};

class Snake {
private:
    Point* cell[MAXSNAKESIZE]; // array of points to represent snake
    int size; // current size of snake
    char dir; // current direction of snake
    Point fruit;
    int level; // level number
    int fruitsToSpawn; // Number of fruits to spawn for the current level
    vector<Point*> obstacles; // Vector to store obstacles
public:
    Snake() {
        size = 1; // default size
        cell[0] = new Point(20, 20, '*'); // 20,20 is default position
        for (int i = 1; i < MAXSNAKESIZE; i++) {
            cell[i] = NULL;
        }
        fruit.SetPoint(rand() % 48 + 2, rand() % 21 + 2); // Random position for fruit
        level = 1; // starting level
        dir = 'l'; // default direction
        fruitsToSpawn = 1; // starting with 1 fruit
    }
    void AddCell(int x, int y) {
        cell[size++] = new Point(x, y, '*');
    }
    void TurnUp() {
        if (dir != 'd') // Prevent turning back on itself
            dir = 'u'; // w is control key for turning upward
    }
    void TurnDown() {
        if (dir != 'u')
            dir = 'd'; // w is control key for turning downward
    }
    void TurnLeft() {
        if (dir != 'r')
            dir = 'l'; // w is control key for turning left
    }
    void TurnRight() {
        if (dir != 'l')
            dir = 'r'; // w is control key for turning right
    }

    void Move() {
    // Clear screen
    system("cls");

    // Display developer name and current level
    gotoxy(0, 0);
    cout << "Developer: Shalvi Surve | Level: " << level;

    // Draw boundaries
    for (int i = 0; i < 52; i++) {
        gotoxy(i, 1);
        cout << "/";
        gotoxy(i, 23);
        cout << "/";
    }
    for (int i = 0; i < 24; i++) {
        gotoxy(0, i);
        cout << "/";
        gotoxy(51, i);
        cout << "/";
    }

    // Check collision with obstacles
    for (Point* obstacle : obstacles) {
        if (cell[0]->GetX() == obstacle->GetX() && cell[0]->GetY() == obstacle->GetY()) {
            // Display message and terminate the game
            gotoxy(20, 10);
            cout << "Game Over - Snake Hit an Obstacle!";
            exit(0);
        }
    }

    // making snake body follow its head
    for (int i = size - 1; i > 0; i--) {
        cell[i]->SetPoint(cell[i - 1]->GetX(), cell[i - 1]->GetY());
    }

    // turning snake's head
    switch (dir) {
    case 'u':
        cell[0]->MoveUp();
        break;
    case 'd':
        cell[0]->MoveDown();
        break;
    case 'l':
        cell[0]->MoveLeft();
        break;
    case 'r':
        cell[0]->MoveRight();
        break;
    }

    // Collision with walls
    if (cell[0]->GetX() <= 0 || cell[0]->GetX() >= 50 || cell[0]->GetY() <= 1 || cell[0]->GetY() >= 23) {
        // Display message and terminate the game
        gotoxy(20, 10);
        cout << "Game Over - Snake Hit the Wall!";
        exit(0);
    }

    // Collision with itself
    for (int i = 1; i < size; i++) {
        if (cell[0]->GetX() == cell[i]->GetX() && cell[0]->GetY() == cell[i]->GetY()) {
            // Display message and terminate the game
            gotoxy(20, 10);
            cout << "Game Over - Snake Bit Itself!";
            exit(0);
        }
    }

    // Collision with fruit
    if (fruit.GetX() == cell[0]->GetX() && fruit.GetY() == cell[0]->GetY()) {
        AddCell(fruit.GetX(), fruit.GetY());
        fruitsToSpawn--;
        if (fruitsToSpawn == 0) {
            // Spawn new fruits according to the level
            fruitsToSpawn = 1;
            if (level % 5 == 0) { // Increase fruits every 5 levels
                fruitsToSpawn++;
            }
            for (int i = 0; i < fruitsToSpawn; ++i) {
                fruit.SetPoint(rand() % 48 + 2, rand() % 21 + 2); // New position for fruit
                fruit.Draw(); // Draw the Fruit
            }
        }
        level++; // Increment level
    }

    // Drawing obstacles
    for (Point* obstacle : obstacles) {
        obstacle->Draw();
    }

    // Drawing snake
    for (int i = 0; i < size; i++)
        cell[i]->Draw(); // Draw the Snake
    fruit.Draw(); // Draw the Fruit

    // Debug();

    Sleep(150); // slower speed
}

    void Debug() {
        for (int i = 0; i < size; i++) {
            cell[i]->Debug();
        }
    }
    void GenerateObstacles() {
        // Clear existing obstacles
        for (Point* obstacle : obstacles) {
            delete obstacle;
        }
        obstacles.clear();

        // Generate new obstacles according to the level
        for (int i = 0; i < level; ++i) {
            Point* obstacle = new Point(rand() % 48 + 2, rand() % 21 + 2, '#');
            obstacles.push_back(obstacle);
        }
    }
};

int initiateSnakeGame() {
    // Random number generation
    srand((unsigned)time(NULL));

    // Testing snake
    Snake snake;
    snake.GenerateObstacles(); // Generate initial obstacles
    char op = 'l';
    do {
        // Check for arrow key input
        if (_kbhit()) {
            int key = _getch();
            switch (key) {
            case 72: // Up arrow
                snake.TurnUp();
                break;
            case 80: // Down arrow
                snake.TurnDown();
                break;
            case 75: // Left arrow
                snake.TurnLeft();
                break;
            case 77: // Right arrow
                snake.TurnRight();
                break;
            }
        }
        snake.Move();
    } while (op != 'e');

    return 0;
}
