#include "GameS.h"
#include "checks.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGTH 100

char* workWords[] = {"computer", "keyboard", "monitor", "printer", "software"};
char* studyWords[]
        = {"mathematics", "history", "science", "literature", "language"};
char* tablewareWords[] = {"spoon", "fork", "knife", "plate", "cup"};

int getRandomIndex(int size)
{
    return rand() % size;
}

char* getRandomWord(char* topic)
{
    int index;
    if (strcmp(topic, "work") == 0) {
        index = getRandomIndex(sizeof(workWords) / sizeof(workWords[0]));
        return workWords[index];
    } else if (strcmp(topic, "study") == 0) {
        index = getRandomIndex(sizeof(studyWords) / sizeof(studyWords[0]));
        return studyWords[index];
    } else if (strcmp(topic, "tableware") == 0) {
        index = getRandomIndex(
                sizeof(tablewareWords) / sizeof(tablewareWords[0]));
        return tablewareWords[index];
    } else {
        return "";
    }
}

int isValidInput(char input)
{
    return ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z'));
}

int isEnglishLetter(char input)
{
    return ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z'));
}

void hangman(char* topic)
{
    char* word = getRandomWord(topic);
    if (strcmp(word, "") == 0) {
        printf("Invalid topic!\n");
        return;
    }

    int wordLength = strlen(word);
    char guessedLetters[MAX_WORD_LENGTH];
    for (int i = 0; i < wordLength; i++) {
        guessedLetters[i] = '_';
    }
    guessedLetters[wordLength] = '\0';

    int attempts = 6;

    printf("Welcome to Hangman!\n");
    printf("Topic: %s\n", topic);
    printf("Guess the word by entering one letter at a time.\n");

    while (attempts > 0) {
        printf("Word: %s\n", guessedLetters);
        printf("Attempts left: %d\n", attempts);
        printf("Enter a letter: ");

        char input[2];
        scanf("%1s", input);

        char letter = input[0];

        if (!isValidInput(letter)) {
            printf("Invalid input! Please enter a single letter.\n");
            attempts--;
            continue;
        }

        if (!isEnglishLetter(letter)) {
            printf("Invalid input language! Please enter an English letter.\n");
            attempts--;
            continue;
        }

        int found = 0;
        for (int i = 0; i < wordLength; i++) {
            if (word[i] == letter) {
                guessedLetters[i] = letter;
                found = 1;
            }
        }

        if (found) {
            printf("Correct guess!\n");

            if (strcmp(word, guessedLetters) == 0) {
                printf("Congratulations! You guessed the word: %s\n", word);
                break;
            }
        } else {
            printf("Incorrect guess!\n");
            attempts--;

            if (attempts == 0) {
                printf("You lost! The word was: %s\n", word);
                break;
            }
        }
    }
    printf("Thank you for playing!\n");
}