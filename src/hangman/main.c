#include <stdio.h> 
#include <libhangman/GameS.h>

int main() { 
    srand(time(NULL)); 
 
    printf("Choose a topic: work, study, tableware\n"); 
    char topic[MAX_WORD_LENGTH]; 
    scanf("%s", topic); 
 
    hangman(topic); 
 
    return 0; 
}
