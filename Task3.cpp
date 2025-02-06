#include <iostream>

using namespace std;

char space[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
int row, column;
char token = 'x';
bool tie = false;
string n1, n2;

void functionOne() {
    // Structure of the Tic-Tac-Toe game
    cout << "    |      |    \n";
    cout << " " << space[0][0] << "  |  " << space[0][1] << "   | " << space[0][2] << "  \n";
    cout << "____|______|____\n";
    cout << "    |      |    \n";
    cout << " " << space[1][0] << "  |  " << space[1][1] << "   | " << space[1][2] << "  \n";
    cout << "____|______|____\n";
    cout << "    |      |    \n";
    cout << " " << space[2][0] << "  |  " << space[2][1] << "   | " << space[2][2] << "  \n";
    cout << "    |      |    \n";
}

void functionTwo() {
    int digit;
    while (true) {  // Use a loop instead of recursion to avoid stack overflow
        if (token == 'x') {
            cout << n1 << ", please enter: ";
        } else {
            cout << n2 << ", please enter: ";
        }
        cin >> digit;

        if (digit < 1 || digit > 9) {
            cout << "Invalid input! Please enter a number between 1 and 9." << endl;
            continue;
        }

        row = (digit - 1) / 3;
        column = (digit - 1) % 3;

        if (space[row][column] != 'x' && space[row][column] != '0') {
            space[row][column] = token;
            token = (token == 'x') ? '0' : 'x'; // Switch token
            break;
        } else {
            cout << "The spot is already taken! Choose another." << endl;
        }
    }
}

bool functionThree() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (space[i][0] == space[i][1] && space[i][0] == space[i][2])
            return true;
        if (space[0][i] == space[1][i] && space[0][i] == space[2][i])
            return true;
    }

    // Check diagonals
    if (space[0][0] == space[1][1] && space[0][0] == space[2][2])
        return true;
    if (space[0][2] == space[1][1] && space[0][2] == space[2][0])
        return true;

    // Check for tie
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'x' && space[i][j] != '0') {
                return false;
            }
        }
    }

    tie = true;
    return false;
}

int main() {
    cout << "Enter the name of player 1: ";
    getline(cin, n1);
    cout << "Enter the name of player 2: ";
    getline(cin, n2);

    cout << n1 << " (x) will play first.\n";
    cout << n2 << " (0) will play second.\n";

    while (!functionThree()) {
        functionOne();
        functionTwo();
    }

    functionOne();  // Show the final state of the game

    if (tie) {
        cout << "It's a draw!" << endl;
    } else {
        // Determine winner based on last token change
        if (token == '0') {
            cout << n1 << " wins!" << endl;
        } else {
            cout << n2 << " wins!" << endl;
        }
    }

    return 0;
}
