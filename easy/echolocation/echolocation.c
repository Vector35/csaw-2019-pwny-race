#include <stdio.h>
#include <stdlib.h>

void ask()
{
    char buffer[128];
    puts("Hello stranger, where are you?");
    fflush(stdout);
    gets(buffer);
    printf("So you're in %s? That sounds great!", buffer);
}

int main()
{
    ask();
    return 0;
}

void win()
{
    system("/bin/bash");
}
