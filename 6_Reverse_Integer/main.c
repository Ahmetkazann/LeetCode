#include <stdio.h>
#include <stdlib.h>

int reverse(int x){

    int reversex = 0;
    int lastdigit;
    int counter = 0;

    while(x != 0){
        if(counter == 1){
            reversex *= 10;
        }
        lastdigit = x % 10;
        reversex += lastdigit;
        x = x - lastdigit;
        x = x / 10;
        counter = 1;
    }

    return reversex;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
