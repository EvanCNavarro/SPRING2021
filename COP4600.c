#include <stdio.h>
#include <unistd.h>
#include <limits.h>

//Default size for the History Array, if the file does NOT exist
#define DEFAULT_HISTORY_SIZE 100


void introduction();

int main(int argc, char** argv) {

    introduction();

    //Try to open History File (Read & Write, WILL NOT create if nonexistent)
    FILE* historyTextFile;
    historyTextFile = fopen("history.txt", "r+");

    //Set size of Array
    int historyArraySize;

    //File does NOT exist
    if (historyTextFile == NULL) {

        //Warn user, create file, set array size to default (100)
        printf("\n\t<< [WARNING] No previous History Text File was found.\n\t A new file has been created for all future sessions. >> \n");
        historyTextFile = fopen("history.txt", "w+");
        historyArraySize = DEFAULT_HISTORY_SIZE;
    }

    //File does exist
    else {

        char nextCharacter;
        int fileLineCount = 0;

        //Read and count number of lines in file
        while (!feof(historyTextFile)) {
            nextCharacter = fgetc(historyTextFile);
            if (nextCharacter == '\n') {
                fileLineCount++;
            }
        }

        //Set array size to be 3x the line count
        historyArraySize = 3 * fileLineCount;
    }

    //Create History Array
    char** historyArray = calloc(historyArraySize, sizeof(char*));

    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working dir: %s\n", cwd);
    }
    else {
        perror("getcwd() error");
        return 1;
    }
    return 0;
}

//Welcome text for the user
void introduction() {

    //Formatting line(s) for the intro text in the beginning of the program
    char* formatting = "---------------------------------------------";

    //Intro Text
    printf("\n%s\nHello, and welcome to the \'mysh\' C Program!\n( Created by Evan C. Navarro (UID: 3037941), for COP 4600's HW#3. )\nThis program acts as a replacement to the Unix Command Shell.\nEnter a command after the \'#\' below, like \'help\' to get started.\n%s\n", formatting, formatting);

}
