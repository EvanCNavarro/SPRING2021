#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
//#include <unistd.h>


//Default size for the History Array, if the file does NOT exist
#define DEFAULT_HISTORY_SIZE 100
#define MAX_COMMAND_SIZE 500


void introduction();
//void whereami();
void save(char** historyArray, int fileLineCount);

int fileLineCount = 0;
int main(int argc, char** argv) {

    introduction();

    //Try to open History File (Read & Write, WILL NOT create if nonexistent)
    FILE* historyTextFile;

    //Set size of Array
    int historyArraySize;
    char nextCharacter;
    int fileLineCount = 0;
    //File does NOT exist

    historyArraySize = DEFAULT_HISTORY_SIZE;

    if ((historyTextFile = fopen("history.txt", "r+")) == NULL) {

        //Warn user, create file, set array size to default (100)
        printf("\n\t<< [WARNING] No previous History Text File was found.\n\t A new file has been created for all future sessions. >> \n");
        historyTextFile = fopen("history.txt", "w+");
    }

    //File does exist
    else {
        //Read and count number of lines in file
        while (!feof(historyTextFile)) {
            nextCharacter = fgetc(historyTextFile);
            if (nextCharacter == '\n') {
                fileLineCount++;
            }
        }

        if (fileLineCount > DEFAULT_HISTORY_SIZE) {
            historyArraySize = ((fileLineCount / DEFAULT_HISTORY_SIZE) + 2) * DEFAULT_HISTORY_SIZE;
        }
    }

    printf("%d\n", historyArraySize);

    //Create History Array
    char** historyArray = (char **) calloc(historyArraySize, sizeof(char*));
    fseek(historyTextFile, 0, SEEK_SET);
    char buff[MAX_COMMAND_SIZE];
    for (int i = 0; i < fileLineCount; i++) {
        fgets(buff, MAX_COMMAND_SIZE, historyTextFile);
        printf("%d\n", sizeof(buff));
        historyArray[i] = (char*)calloc(historyArraySize, sizeof(buff+1));
        strcpy(historyArray[i], buff);
        printf("%s\n", historyArray[i]);
        printf("%d\n", sizeof(historyArray[i]));
        if (historyArray[i][4] == NULL) {
            printf("IT'S NULL\n");
        }
        if (historyArray[i+1] == NULL) {
            printf("%d FILELINECOUNT\n\n", i);

        }
    }
    printf("%d", fileLineCount);

    printf("\nHello\n");

    //while byebye != true
    //get input
    //parse
    //return token value
    //switch case
    //byebye 
    //clear
    //history
    //replay history
    //whereami
    //movetodir
    //start program
    //background program
    //dalek pid
    //repeat n command
    char userInput[20][MAX_COMMAND_SIZE] = { '\0' };



    do {

        printf("# ");
        scanf("%s", userInput);
        printf("check YOUR INPUT: %s", userInput);
        char userInput[MAX_COMMAND_SIZE] = { '\0' };
        printf("\n\n%s Userinput check>>", *userInput);
    } while (!feof(stdin));

    save(historyArray, fileLineCount);

    //whereami();

    return 0;
}

//Welcome text for the user
void introduction() {

    //Formatting line(s) for the intro text in the beginning of the program
    char* formatting = "---------------------------------------------";

    //Intro Text
    printf("\n%s\nHello, and welcome to the \'mysh\' C Program!\n( Created by Evan C. Navarro (UID: 3037941), for COP 4600's HW#3. )\nThis program acts as a replacement to the Unix Command Shell.\nEnter a command after the \'#\' below, like \'help\' to get started.\n%s\n", formatting, formatting);

}
/*
void whereami() {
    char currentdir[PATH_MAX];
    if (getcwd(currentdir, sizeof(currentdir)) != NULL) {
        printf("\nCurrent Directory: %s\n", currentdir);
    }
    else {
        perror("getcwd() error");
    }
}
*/
void save(char **historyArray, int fileLineCount) {
    FILE* historyTextFile = fopen("history.txt", "w+");
    for (int i = 0; i < fileLineCount; i++) {
        fputs(historyArray[i], historyTextFile);
    }
}
