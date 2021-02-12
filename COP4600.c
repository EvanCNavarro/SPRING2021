#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
//#include <unistd.h>


//Default size for the History Array, if the file does NOT exist
#define DEFAULT_HISTORY_SIZE 100
#define MAX_COMMAND_SIZE 500

static char* acceptedCommands[] = {
    "byebye", "clear", "history", "replay",
    "whereami", "movetodir", "start", "background",
    "dalek", "repeat", "dalekall", "help"
};

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

    char userInput[MAX_COMMAND_SIZE];

    while (!feof(stdin)) {
        fgets(userInput, MAX_COMMAND_SIZE, stdin);
        historyArray[fileLineCount] = (char*)calloc(historyArraySize, sizeof(userInput + 1));
        strcpy(historyArray[fileLineCount], userInput);
        fileLineCount++;

        printf("\nHistory:\n");
        for (int i = 1; i <= fileLineCount; i++) {
            printf("Entry #%d:\t%s", i, historyArray[fileLineCount - i]);
        }

        char* args[70];
        char** arg;
        arg = args;
        *arg++ = strtok(userInput, " \n");
        while ((*arg++ = strtok(NULL, " \n")));

        /*
        static char* acceptedCommands[] = {
            "byebye", "clear", "history", "replay",
            "whereami", "movetodir", "start", "background",
            "dalek", "repeat", "dalekall", "help"
        };
        */

        int commandNumber = 20;

        for (int i = 0; i < sizeof(acceptedCommands); i++) {
            if (!strcmp(args[0], acceptedCommands[i])) {
                commandNumber = i;
                printf("%d", i);
                break;
            }
        }

        switch (commandNumber) {
            case 0: {
                break;
            }

            case 1: {
                printf("clear");
            }
            
            case 2: {
                printf("clear");
            }

            case 3: {
                printf("clear");
            }

            case 4: {
                printf("clear");
            }

            case 5: {
                printf("clear");
            }

            case 6: {
                printf("clear");
            }

            case 7: {
                printf("clear");
            }

            case 8: {
                printf("clear");
            }

            case 9: {
                printf("clear");
            }

            case 10: {
                printf("clear");
            }

            case 11: {
                printf("clear");
            }

            case 12: {
                printf("clear");
            }

            default: {
                printf("DEFAULT -----\n\n");
            }
        }

        printf("Should not print...\n");

    }

    printf("\n\nEXITED\n\n");

    save(historyArray, fileLineCount);

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
