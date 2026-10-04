#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void pickRandomWord(char dictionary[][20], int size, char word[]);
void initHiddenWord(char word[], char hidden[]);
void displayHangman(int wrongGuesses);
void displayGameState(char hidden[], int attemptsLeft, char guessed[], int guessedCount);
int ValidInput(char guess, char guessed[], int guessedCount);
int revealLetter(char word[], char hidden[], char guess);
int WordGuessed(char hidden[]);
void playGame(char dictionary[][20], int size);

int main(void)
{
    char dictionary[20][20] = {"strengths", "rhythm", "syzygy", "glyph",
                               "nymph", "cryptography", "cryptologist", "rhythmless",
                               "mythmaker", "skyward", "flyweight", "gyroscope",
                               "hypnotism", "lymphatic", "mystifying", "mythology",
                               "lynchings", "symphony", "synthesis", "synchronicity"};
    srand((unsigned int)time(NULL));

    int choice;
    do
    {
        printf("\n=====================================\n");
        printf("        TERMINAL HANGMAN GAME\n");
        printf("=====================================\n");
        printf("1. Play Game\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");

        while (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ;
            printf("Invalid menu choice. Please try again.\n");
            printf("Enter your choice: ");
        }

        if (choice == 1)
        {
            playGame(dictionary, 20);
        }
        else if (choice != 2)
        {
            printf("Invalid menu choice. Please try again.\n");
        }

    } while (choice != 2);

    printf("Thanks for playing! Goodbye.\n");
    return 0;
}

void playGame(char dictionary[][20], int size)
{
    char word[20];
    char hidden[20];
    char guessed[26];
    int guessedCount = 0;
    int attemptsLeft = 6;
    int wrongGuesses = 0;

    pickRandomWord(dictionary, size, word);
    initHiddenWord(word, hidden);

    printf("\nA new word has been chosen. Start guessing!\n");

    while (attemptsLeft > 0 && !WordGuessed(hidden))
    {

        displayHangman(wrongGuesses);
        displayGameState(hidden, attemptsLeft, guessed, guessedCount);

        char input[10];
        char guess;

        printf("Enter your guess (a single letter): ");
        scanf("%9s", input);

        if (strlen(input) != 1 ||
            !((input[0] >= 'a' && input[0] <= 'z') ||
              (input[0] >= 'A' && input[0] <= 'Z')))
        {
            printf(">> Invalid input! Please enter a single alphabet letter.\n");
            continue;
        }

        if (input[0] >= 'A' && input[0] <= 'Z')
        {
            guess = input[0] + ('a' - 'A');
            guess = input[0];
        }

        if (!ValidInput(guess, guessed, guessedCount))
        {
            printf(">> You already guessed '%c'. Try a different letter.\n", guess);
            continue;
        }

        guessed[guessedCount++] = guess;

        if (revealLetter(word, hidden, guess))
        {
            printf(">> Good guess! '%c' is in the word.\n", guess);
        }
        else
        {
            printf(">> Wrong guess! '%c' is not in the word.\n", guess);
            wrongGuesses++;
            attemptsLeft--;
        }
    }

    displayHangman(wrongGuesses);
    displayGameState(hidden, attemptsLeft, guessed, guessedCount);

    printf("=====================================\n");
    if (WordGuessed(hidden))
    {
        printf("YOU WIN! The word was: %s\n", word);
    }
    else
    {
        printf("YOU LOSE! The word was: %s\n", word);
    }
    printf("=====================================\n");
}

void pickRandomWord(char dictionary[][20], int size, char word[])
{
    int index = rand() % size;
    strcpy(word, dictionary[index]);
}

void initHiddenWord(char word[], char hidden[])
{
    int len = (int)strlen(word);
    int i;
    for (i = 0; i < len; i++)
    {
        hidden[i] = '_';
    }
    hidden[len] = '\0';
}

int ValidInput(char guess, char guessed[], int guessedCount)
{
    int i;
    for (i = 0; i < guessedCount; i++)
    {
        if (guessed[i] == guess)
        {
            return 0;
        }
    }

    return 1;
}

int revealLetter(char word[], char hidden[], char guess)
{
    int len = (int)strlen(word);
    int found = 0;
    int i;
    for (i = 0; i < len; i++)
    {
        if (word[i] == guess)
        {
            hidden[i] = guess;
            found = 1;
        }
    }
    return found;
}

int WordGuessed(char hidden[])
{
    int len = (int)strlen(hidden);
    int i;
    for (i = 0; i < len; i++)
    {
        if (hidden[i] == '_')
        {
            return 0;
        }
    }
    return 1;
}

void displayGameState(char hidden[], int attemptsLeft, char guessed[], int guessedCount)
{
    int i;

    printf("\nWord: ");
    for (i = 0; i < (int)strlen(hidden); i++)
    {
        printf("%c ", hidden[i]);
    }
    printf("\n");

    printf("Attempts Left: %d\n", attemptsLeft);

    printf("Guessed Letters: ");
    if (guessedCount == 0)
    {
        printf("(none yet)");
    }
    else
    {
        for (i = 0; i < guessedCount; i++)
        {
            printf("%c ", guessed[i]);
        }
    }
    printf("\n");
}

void displayHangman(int wrongGuesses)
{
    char head = (wrongGuesses >= 1) ? 'O' : ' ';
    char body = (wrongGuesses >= 2) ? '|' : ' ';
    char leftArm = (wrongGuesses >= 3) ? '/' : ' ';
    char rightArm = (wrongGuesses >= 4) ? '\\' : ' ';
    char leftLeg = (wrongGuesses >= 5) ? '/' : ' ';
    char rightLeg = (wrongGuesses >= 6) ? '\\' : ' ';

    printf("\n");
    printf("Attempts Used: %d / 6\n", wrongGuesses);
    printf("     +---+\n");
    printf("     |   |\n");
    printf("     %c   |\n", head);
    printf("    %c%c%c  |\n", leftArm, body, rightArm);
    printf("    %c %c  |\n", leftLeg, rightLeg);
    printf("         |\n");
    printf("    =========\n");
}
