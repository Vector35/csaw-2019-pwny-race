#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

char* flag = 
"|* * * * * * * * * * OOOOOOOOOOOOOOOOOOOOOOOOO|\n"
"| * * * * * * * * *  :::::::::::::::::::::::::|\n"
"|* * * * * * * * * * OOOOOOOOOOOOOOOOOOOOOOOOO|\n"
"| * * * * * * * * *  :::::::::::::::::::::::::|\n"
"|* * * * * * * * * * OOOOOOOOOOOOOOOOOOOOOOOOO|\n"
"| * * * * * * * * *  ::::::::::::::::::::;::::|\n"
"|* * * * * * * * * * OOOOOOOOOOOOOOOOOOOOOOOOO|\n"
"|:::::::::::::::::::::::::::::::::::::::::::::|\n"
"|OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n"
"|:::::::::::::::::::::::::::::::::::::::::::::|\n"
"|OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n"
"|:::::::::::::::::::::::::::::::::::::::::::::|\n"
"|OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";


char* menu = 
"            ___----------___                                                                ___----------___           \n"
"         _--                ----__                    THE SIMS                        __----                --_        \n"
"        -                         ---_            AMERICAN EDITION                _---                         -       \n"
"       -___    ____---_              --_                                        _--              _---____    ___-      \n"
"   __---_ .-_--   _ O _-                -                                      -                -_ O _   --_-. _---__  \n"
"  -      -_-       ---                   -                                    -                   ---       -_-      - \n"
" -   __---------___                       -                                  -                       ___---------__   -\n"
" - _----                                  -                                  -                                  ----_ -\n"
"  -     -_                                 _      1. Change Name            _                                 _-     - \n"
"  `      _-                                 _     2. Pay Taxes             _                                 -_      ` \n"
"        _                           _-_  _-_ _    3. Go Bankrupt          _ _-_  _-_                           _       \n"
"       _-                   ____    -_  -   --    4. Watch Football       --   -  _-    ____                   -_      \n"
"       -   _-__   _    __---    -------       -   5. Print Stats         -       -------    ---__    _   __-_   -      \n"
"      _- _-   -_-- -_--                        _                        _                        --_- --_-   -_ -_     \n"
"      -_-                                       _                      _                                       -_-     \n"
"     _-                                          _                    _                                          -_    \n"
"     -                                                                                                            -    \n";

struct murican {
    char* name;
    uint32_t age;
    uint32_t money;
    uint32_t beer_consumed;
    uint32_t hours_of_football_watched;
    void (*pay_taxes)();
    void (*watch_football)();
};


void handle_taxes(struct murican* person) {
    person->money /= 2;
    person->age += 1;
}

void watch_football(struct murican* person) {
    person->hours_of_football_watched += 1;
    person->beer_consumed += 2;
}

void print_stats(struct murican* person) {
    printf("Stats for %s:\n", person->name);
    printf("- %u years old\n", person->age);
    printf("- Has $%u\n", person->money);
    printf("- Has consumed %u beers (what an amateur)\n", person->beer_consumed);
    printf("- Has watched %u hours of football\n", person->hours_of_football_watched);
}

struct murican* init_american(char* name) {
    struct murican* person = malloc(sizeof(struct murican));
    person->name = name;
    person->age = 0;
    person->money = &rand;
    person->beer_consumed = 0;
    person->hours_of_football_watched = 0;
    person->pay_taxes = handle_taxes;
    person->watch_football = watch_football;
    return person;
}

int main() {
    srand(time(NULL));
    
    int choice;
    
    char* name = malloc(28);
    puts("Name: ");
    fflush(stdout);
    scanf("%27s", name);
    struct murican* person = init_american(name);
    
    while(1) {
        puts(menu);
        fflush(stdout);
        scanf("%d", &choice);
        switch(choice){
            case 1:
                {
                    char* name = malloc(28);
                    puts("Name: ");
                    fflush(stdout);
                    scanf("%27s", name);
                    person->name = name;
                }
                break;
            case 2:
                person->pay_taxes(person);
                break;
            case 3:
                free(person);
                break;
            case 4:
                person->watch_football(person);
                break;
            case 5:
                print_stats(person);
                break;
        }
    }
    return 0;
}

