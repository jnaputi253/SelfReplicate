#include <stdio.h>
#include <stdlib.h>

static int count = 1;

void systemCommands();
FILE* openFile();
void readData(FILE *file);
void cleanup(FILE *file);

int main(int argc, char **argv) {
    systemCommands();
    
    FILE *file = openFile();
    readData(file);
    cleanup(file);
    
    return 0;
}

void systemCommands() {
    char command[100];
    
    // Unsure of this command.  Will look into it further since it is considered "safer"
    snprintf(command, sizeof(command), "gcc %s", __FILE__);
    system(command);
    system("./a.out");
}

FILE* openFile() {
    FILE *file = fopen("main.c", "r");
    
    return file;
}

void readData(FILE *file) {
    char *line;
    char buffer[100];
    
    system("touch main1.c");
    FILE *outputFile = fopen("main1c", "w");
    count++;
    
    while((line = fgets(buffer, 100, file)) != NULL) {
        printf("%s", line);
        fputs(line, outputFile);
    }
    
    cleanup(outputFile);
}

void cleanup(FILE *file) {
    if(file != NULL) {
        fclose(file);
    }
}
