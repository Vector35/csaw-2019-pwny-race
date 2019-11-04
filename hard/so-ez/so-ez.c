#include <unistd.h>

int main() {
    char yay[16];
    read(0, yay, 0x500);
    return 0x50f;
}
