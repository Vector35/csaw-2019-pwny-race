#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* monster_names[99] = {
    "Roppy", "Poppy", "Hoppy", "Kablion", "Pyrion", "Frion",
    "Whalegun", "Whaletail", "Wailer", "Beezer", "Nutter",
    "Crawler", "Cock", "Clucker", "Chickling",
    "Windove", "Birdove", "Dovelett", "Rattichewy", "Rattitat",
    "Woofer", "Subhound", "Webadeth", "Spidra", "Drillboar",
    "Boghog", "Digpig", "Ramstine", "Sheepler", "Stingping",
    "Antler", "Harerazer", "Bunnybolt", "Wabbitwap", "Wascaly",
    "Ohkamel", "Kamelcase", "Glostar", "Costar", "Starem",
    "Stormikloud", "Electrikloud", "Hoverkloud", "Snowmo",
    "Snowblo", "Snowbro", "Krabber", "Shellkra", "Oktokore",
    "Snukinasnail", "Lazybug", "Turtlejet", "Turtlewet",
    "Gatorath", "Gatorate", "Chiptune", "Cowabusta",
    "Cowabucka", "Monkadoo", "Monkasee", "Unihorn",
    "Warpsteed", "Fasteed", "Leptear", "Kitear", "Kitease",
    "Jackfry", "Jackflare", "Shroomdoom", "Bonedread",
    "Skullker", "Spiriboo", "Impest", "Ogreat", "Ogrim",
    "Pilapoo", "Flaret", "Electret", "Pouret", "Freezet",
    "Pixet", "Eetee", "Flyver", "Wyrmton", "Phishy",
    "Bottabuzz", "Botto", "Ohdaze", "Sundaze", "Doomboom",
    "Kabomb", "Lyarkake", "Tacocat", "Tuxacool", "Panfoo",
    "Crystrike", "Burninator", "Slithaburn", "Slither"
};

struct monster
{
    int species;
    char nickname[16];
};

struct monster party[6];

void seed()
{
    FILE* fp = fopen("/dev/urandom", "rb");
    int start_seed = 0;
    fread(&start_seed, sizeof(start_seed), 1, fp);
    fclose(fp);
    srand(start_seed);
}

void show_party()
{
    printf("In your party:\n");
    for (int i = 0; i < 6; i++)
    {
        if (party[i].species == -1)
            continue;
        printf("#%d: %s\n", i + 1, party[i].nickname);
    }
    fflush(stdout);
}

void play()
{
    printf("\nWhich party member do you want to play with?\n");
    fflush(stdout);
    char line[32];
    if (!fgets(line, 31, stdin))
        return;
    int member = atoi(line) - 1;
    if (party[member].species == -1)
    {
        printf("There isn't such a party member\n");
        return;
    }
    printf("\nYou played with %s and had a great time!\n\n", party[member].nickname);
    fflush(stdout);
}

void grass()
{
    printf("\nYou walk around in the tall grass.\n\n");
    fflush(stdout);
    int species = rand() % 99;
    printf("A wild %s appears!\n\n", monster_names[species]);
    fflush(stdout);

    printf("What do you want to do?\n");
    printf("1) Throw a ball at it\n");
    printf("2) Run away\n\n");
    printf("Choice:\n");
    fflush(stdout);

    char line[32];
    if (!fgets(line, 31, stdin))
        return;
    if (atoi(line) != 1)
        return;

    if (rand() % 2)
    {
        printf("\nIt broke out! You almost had it.\n\n");
        return;
    }

    printf("\nYou caught it!\nWhich party slot do you want to keep it in?\n");
    fflush(stdout);
    if (!fgets(line, 31, stdin))
        return;
    int slot = atoi(line) - 1;
    
    printf("\nWhat would you like its nickname to be?\n");
    fflush(stdout);
    if (!fgets(line, 31, stdin))
        return;
    if ((strlen(line) != 0) && (line[strlen(line) - 1] == '\n'))
        line[strlen(line) - 1] = 0;
    if (strlen(line) == 0)
    {
        strcpy(party[slot].nickname, monster_names[species]);
        party[slot].species = species;
        printf("\nNot going to nickname it? %s it is.\n\n", monster_names[species]);
    }
    else
    {
        strcpy(party[slot].nickname, line);
        party[slot].species = species;
        if (slot != 0)
        {
            fputs(party[0].nickname, stdout);
            printf(" wants to play with %s.", party[slot].nickname);
        }
        printf("\n%s is happy to be part of your party!\n\n", line);
    }
    fflush(stdout);
}

int main_menu()
{
    show_party();

    printf("\nWhat do you want to do?\n");
    printf("1) Play with a party member\n");
    printf("2) Walk around in the tall grass\n");
    printf("3) Quit\n\n");
    printf("Choice:\n");
    fflush(stdout);

    char line[32];
    if (!fgets(line, 31, stdin))
        return 0;
    int choice = atoi(line);

    switch (choice)
    {
    case 1:
        play();
        break;
    case 2:
        grass();
        break;
    case 3:
        return 0;
    default:
        break;
    }
    return 1;
}

int main()
{
    seed();

    for (int i = 0; i < 6; i++)
        party[i].species = -1;

    static const int starters[3] = {2, 5, 8};
    party[0].species = starters[rand() % 3];
    strcpy(party[0].nickname, monster_names[party[0].species]);

    while (1)
    {
        if (!main_menu())
            break;
    }
    return 0;
}
