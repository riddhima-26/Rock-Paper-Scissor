#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to determine the winner of the game
int game(char player, char computer) {
    if (player == computer) {
        return 0; // It's a tie
    } else if ((player == 'r' && computer == 's') ||
               (player == 's' && computer == 'p') ||
               (player == 'p' && computer == 'r')) {
        return 1; // Player wins
    } else {
        return -1; // Computer wins
    }
}

int main() {
    char choices[] = {'r', 'p', 's'};
    char playerChoice, computerChoice;
    int result;
    srand(time(NULL));

    printf("Welcome to Rock, Paper, Scissors Game!\n");

    while (1) {
        // Get player's choice
        printf("Enter 'r' for Rock, 'p' for Paper, 's' for Scissors, or 'q' to quit: ");
        scanf(" %c", &playerChoice);


        if (playerChoice == 'q') {
            break;
        }

        if (playerChoice != 'r' && playerChoice != 'p' && playerChoice != 's') {
            printf("Invalid choice. Please enter 'r', 'p', 's', or 'q'.\n");
            continue;
        }

        // Generate computer's choice
        computerChoice = choices[rand() % 3];

        // Display choices
        printf("You chose: %c\n", playerChoice);
        printf("Computer chose: %c\n", computerChoice);

        
        result = game(playerChoice, computerChoice);

        if (result == 0) {
            printf("It's a tie!\n");
        } else if (result == 1) {
            printf("You win!\n");
        } else {
            printf("Computer wins!\n");
        }
    }

    printf("Thanks for playing!\n");

    return 0;
}