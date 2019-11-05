#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char* helicopter = "\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"                       _____......----------\"\"\"\"\"\"\"\"\"\"------.._      _/\"/\n"
"         __...:::::;:::....                                   /___../  /\n"
"  _.--\"\"\"::::::::::::::::::::::....,o%%%%:...._.....-----\"\"\"\"\"\"____.._ \"\\\n"
" \"..____              __../-----\"\"\"\"\"\"\"\"\"\"        ___...---\"\"\"\"      \"\\__\\\n"
"        \"\"\"\"\"\"\"\"\"\"\"\"/\"---.   .--\"\":       ...--\"\"\"\n"
"               _./\"//    |   |     |     /akn       \n"
"              /\\__//_____|   `--\"\"\"     /\n"
"              \\                 .  ___/\"\n"
"               \"--.___/\"....---|\"\"\"  \n"
"                     /       ___\\....  \n"
"                \\\\..\"--:\"\"\"\"\"      \n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n";


char* ropl = "Incoming ROPLCOPTER!\n"
"\n"
"   ROPL:ROPL:ROPL:ROPL\n"
"    	 ___^___ _\n"
" P    __/      [] \\    \n"
"POP===__           \\ \n"
" P      \\___ ___ ___]\n"
"            I   I\n"
"	      ----------/\n";


void check(char* arg) {
    if (strcmp(arg, "/bin/sh") == 0) {
        exit(1);
    }
}

void chopper() {
    puts(helicopter);
}

void heli() {
    puts(ropl);
}

void ask() {

    char buffer[64];
    puts("WHISHWHISHWHISHWHISHWHISHWHISHWHISHWHISHWHISHWHISHWHISHWHISHWHISHWHISHWHISH");
    puts("1. WHOOSH\n2. WHOOOOSH\n3. WHIRRRRRR~~~~\n>");
    fflush(stdout);
    read(0, buffer, 256);
    
    check(buffer);

    if (buffer[0] == '1') {
        chopper();
    }
    else if (buffer[0] == '2') {
        heli();
    }
    else if (buffer[0] == '3') {
        for (unsigned int i = 0; i < 256; i+=4) {
            buffer[i] = 'R';
            buffer[i+1] = 'O';
            buffer[i+2] = 'P';
            buffer[i+3] = 'L';
        }
    }
}

int main()
{
    ask();
    
    return 0;
}
