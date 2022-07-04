#include <stdio.h>
#include <string.h>

void SuperPrinter(char* street, int number, int floor, char letter, float balance, int numberWidth, int floorWidth, int fillWithZero) {
    if (strlen(street) > 20) return;
    if (fillWithZero == 1) {
        printf("%-20s %0*d %0*d %c %15.*f\n", street, numberWidth, number, floorWidth, floor, letter, numberWidth, balance);
    }
    else printf("%-20s %*d %*d %c %15.*f\n", street, numberWidth, number, floorWidth, floor, letter, numberWidth, balance);
    return;

}

int main()
{
    // no testing main
    
    return 0;
}
