#include <iostream>
#include <string>
#include <random>
#include <limits>

using namespace std;

string convert_to_word(char r_p_s)
{
    if (r_p_s == 'p')
    {
        return "Paper";
    }
    else if (r_p_s == 's')
    {
        return "Scissors";
    }
    else
    {
        return "Rock";
    }
}

int generate_rnd_value(void)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 3);

    return distrib(gen);
}

string num_to_word(int rnd)
{
    if (rnd == 1)
    {
        return "Paper";
    }
    else if (rnd == 2)
    {
        return "Scissors";
    }
    else
    {
        return "Rock";
    }
}

void compare(char user_input_2, int rnd)
{
    // rnd == 1 (paper)
    // rnd == 2 (scissors)
    // rnd == 3 (rock)

    if (rnd == 1 && user_input_2 == 'r')
    {
        cout << "You Lost!" << endl
             << "Better Luck Next Time." << endl;
    }
    else if (rnd == 1 && user_input_2 == 's')
    {
        cout << "You Won!" << endl;
    }
    else if (rnd == 1 && user_input_2 == 'p')
    {
        cout << "Its a Draw!" << endl;
    }
    else if (rnd == 2 && user_input_2 == 's')
    {
        cout << "Its a Draw!" << endl;
    }
    else if (rnd == 2 && user_input_2 == 'p')
    {
        cout << "You Lost!" << endl
             << "Better Luck Next Time." << endl;
    }
    else if (rnd == 2 && user_input_2 == 'r')
    {
        cout << "You Won!" << endl;
    }
    else if (rnd == 3 && user_input_2 == 's')
    {
        cout << "You Lost!" << endl
             << "Better Luck Next Time." << endl;
    }
    else if (rnd == 3 && user_input_2 == 'p')
    {
        cout << "You Won!" << endl;
    }
    else if (rnd == 3 && user_input_2 == 'r')
    {
        cout << "Its a Draw!" << endl;
    }
}

void runProgram()
{

    string user_input_1;
    cout << endl
         << "Press (Enter Key) to start the game." << endl;
    getline(cin, user_input_1);
    if (user_input_1.empty())
    {
        cout << "How to play :" << endl
             << "Press (r) for [ROCK]" << endl
             << "Press (p) for [PAPER]" << endl
             << "Press (s) for [SCISSORS]" << endl
             << endl;

        char user_input_2;
        cin >> user_input_2;

        if (user_input_2 == 'r' || user_input_2 == 'p' || user_input_2 == 's')
        {

            string r_p_s = convert_to_word(user_input_2);
            int rnd = generate_rnd_value();
            string num = num_to_word(rnd);
            cout << "You : " << r_p_s << endl;
            cout << "Computer : " << num << endl;
            compare(user_input_2, rnd);
        }
        else
        {
            cout << "Invalid Input!" << endl;
        }
    }
    else
    {
        cout << "ERROR : Please press only 'Enter' key to continue!" << endl;
    }
}

int main()
{
    char userInput = 'y';

    do
    {
        runProgram();

        cout << endl
             << "Play again? (y/n): ";
        cin >> userInput;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (userInput == 'y' || userInput == 'Y');

    cout << "Game has ended." << endl;

    return 0;
}