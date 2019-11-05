#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char toppings[8][256];

int main()
{
    printf("Welcome to Four Matts Burgers and Fries!\n\n");

    printf("What do you want on your burger?\n");
    fflush(stdout);
    int topping_count = 0;
    while (topping_count < 8)
    {
        char input[256];
        if (!fgets(input, 255, stdin))
            return 0;
        if ((strlen(input) != 0) && (input[strlen(input) - 1] == '\n'))
            input[strlen(input) - 1] = 0;
        if (strlen(input) == 0)
            break;

        strcpy(toppings[topping_count++], input);
    }

    while (1)
    {
        printf("\nYour order:\n");
        for (int i = 0; i < topping_count; i++)
            printf("%d) %s\n", i + 1, toppings[i]);

        printf("\nEdit topping using number, or blank for done:\n");
        fflush(stdout);
        char input[256];
        if (!fgets(input, 255, stdin))
            return 0;
        if (input[0] < '0')
            break;
        int number = atoi(input) - 1;
        if ((number < 0) || (number >= 8))
            continue;

        printf("\nCurrent topping:\n");
        printf(toppings[number]);

        printf("\nNew topping:\n");
        fflush(stdout);
        if (!fgets(input, 255, stdin))
            return 0;
        if ((strlen(input) != 0) && (input[strlen(input) - 1] == '\n'))
            input[strlen(input) - 1] = 0;
        if (strlen(input) == 0)
            continue;
        strcpy(toppings[number], input);
    }

    printf("\nYour order has been placed. Thank you for choosing Four Matts!\n");
    fflush(stdout);
    return 0;
}
