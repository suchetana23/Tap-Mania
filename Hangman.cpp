#include <iostream>
#include <ctime>
#include <string>
#include <vector>

using namespace std;
string get_random_word(vector<string>& words);
int play();

vector<string> words = {"programming", "hangman", "games","alligator","audi","bear","deer","cheetah","cinderella","aerosmith","coldplay","dodgeball","foreigner",
};
string hangman_art[7] = {
    " +---+\n"
    " |   |\n"
    "     |\n"
    "     |\n"
    "     |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "     |\n"
    "     |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    " |   |\n"
    "     |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|   |\n"
    "     |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|\\  |\n"
    "     |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|\\  |\n"
    "/    |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|\\  |\n"
    "/ \\  |\n"
    "     |\n"
    "=========="
};

int main()
{
    int a=0,b=0;
    srand(time(0));
    int i=1,j;
    for(i=1;i<=2;i++)
    {
        cout << "Welcome to Hangman Player "<<i<<"!\n";
        j=play();
        if(i==1)
        {
            if(j==1)
                a++;
        }
        else if(i==2)
        {
            if(j==1)
                b++;
        }
    }
    cout<<"Scores:"<<endl;
    cout<<"Player 1: "<<a<<endl;
    cout<<"Player 2: "<<b<<endl;

    return 0;
}

int play()
{
    string secret_word = get_random_word(words);
    string guess_word = secret_word;
    for (int i = 0; i < secret_word.length(); ++i)
    {
        guess_word[i] = '_';
    }
    int try_no = 0;
    char guess;

    while (true)
    {
        cout << hangman_art[try_no] << "\n";
        cout << guess_word << "\n";
        cout << "Enter your guess:\n";
        cin >> guess;

        if (secret_word.find(guess) != string::npos)
            {
                for (int i = 0; i < guess_word.length(); ++i)
                {
                    if (secret_word[i] == guess)
                    {
                        guess_word[i] = guess;
                    }
                }
            if (secret_word == guess_word)
            {
                cout << hangman_art[try_no] << "\n";
                cout << guess_word << "\n";
                cout << "You win! The word was " << secret_word << "\n";
                return 1;
            }
        } else {
            ++try_no;
        }
        if (try_no >= 6)
        {
            cout << hangman_art[try_no] << "\n";
            cout << guess_word << "\n";
            cout << "You lost! The word was " << secret_word << "\n";
            return 0;
        }
    }
}

string get_random_word(vector<string>& words)
{
    return words[rand() % words.size()];
}


