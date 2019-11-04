#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char a[27] = {85, 178, 135, 153, 154, 103, 106, 112, 113, 157, 143, 125,
    99, 97, 158, 173, 73, 102, 152, 142, 165, 131, 122, 94, 86, 102, 151};
char b[27] = {47, 29, 14, 25, 67, 104, 15, 103, 115, 84, 41, 86,
    39, 10, 20, 52, 63, 102, 99, 82, 9, 81, 98, 75, 72, 60, 25};

int check(const char* pass)
{
    char buffer[27];
    if (strlen(pass) != sizeof(buffer))
        return 0;
    memcpy(buffer, pass, sizeof(buffer));
    for (int i = 0; i < sizeof(buffer); i++)
        buffer[i] ^= a[i];
    for (int i = 0; i < sizeof(buffer); i++)
        buffer[i] -= b[i];
    for (int i = 0; i < sizeof(buffer); i++)
        buffer[i] += b[sizeof(buffer) - (i + 1)];
    int sum = 0;
    for (int i = 0; i < sizeof(buffer); i++)
        sum += (int)(unsigned char)buffer[i];
    if (sum == 0)
        return 1;
    return 0;
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Password required\n");
        return 1;
    }

    if (check(argv[1]))
    {
        printf("Password accepted!\n");
        return 0;
    }
    else
    {
        printf("Wrong.\n");
        return 1;
    }
}
