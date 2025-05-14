#include <iostream>
#include <cstdlib>   
#include <ctime>     
#include <string>

using namespace std;

// Function to get computer's choice
string getComputerChoice() {
    int choice = rand() % 3;  // 0, 1, or 2
    if (choice == 0)
        return "rock";
    else if (choice == 1)
        return "paper";
    else
        return "scissors";
}

// Function to determine the winner
string determineWinner(string user, string computer) {
    if (user == computer) {
        return "It's a tie!";
    }
    else if (
        (user == "rock" && computer == "scissors") ||
        (user == "paper" && computer == "rock") ||
        (user == "scissors" && computer == "paper")
    ) {
        return "You win!";
    }
    else {
        return "Computer wins!";
    }
}

int main() {
    srand(time(0));  

    string userChoice, computerChoice;
    char playAgain;

    do {
        cout << "====== Rock-Paper-Scissors Game ======\n";
        cout << "Enter your choice (rock, paper, scissors): ";
        cin >> userChoice;
        if (userChoice != "rock" && userChoice != "paper" && userChoice != "scissors") {
            cout << "Invalid choice! Please enter rock, paper, or scissors.\n";
            continue;
        }

        computerChoice = getComputerChoice();
        cout << "Computer chose: " << computerChoice << endl;

        // Determine winner
        string result = determineWinner(userChoice, computerChoice);
        cout << result << endl;

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! 👋\n";
    return 0;
}
