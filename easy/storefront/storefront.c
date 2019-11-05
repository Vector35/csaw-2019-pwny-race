#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void store()
{
    char buffer[128];
    int line_pos = rand();

    for (int i = 0; i < ((rand() % 120) + 8); i++) {
        buffer[i] = (char) (rand() % 256);
    }
    char* answer;
    printf("Hi, welcome to Sally's shop!\nWould you like to look at our special: %s?\nYou're number %u in line.\n", buffer, &line_pos);
    fflush(stdout);
    gets(buffer);
}

int main()
{
    srand(time(NULL));
    store();
    return 0;
}

