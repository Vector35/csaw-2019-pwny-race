#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_choice()
{
    char input[32];
    if (!fgets(input, 31, stdin))
        return 0;
    return atoi(input);
}

void set_title(char* movie, int len)
{
    printf("New title:\n");
    fflush(stdout);
    char input[512];
    if (!fgets(input, 511, stdin))
        return;
    if (input[0] == 0)
        return;
    input[strlen(input) - 1] = 0;
    strncpy(movie, input, len);
    printf("\nAccepted new title:\n");
    fflush(stdout);
    write(1, movie, strlen(input));
}

void menu()
{
    char movie[128] = "The Thing from the Deep C";
    char msg[128];
    while (1)
    {
        printf("\n1) Set movie title\n");
        printf("2) Show current movie\n");
        printf("3) Quit\n");
        fflush(stdout);
        int choice = get_choice();
        switch (choice)
        {
        case 1:
            set_title(movie, 128);
            break;
        case 2:
            sprintf(msg, "\nThe movie currently playing in the theater is '%s'", movie);
            puts(msg);
            break;
        case 3:
            return;
        default:
            break;
        }
    }
}

int main()
{
    printf("Kernel Panic!\n");
    printf("The Horror Theater popcorn stand.\n\n");
    printf("Management Console\n");
    menu();
    return 0;
}
