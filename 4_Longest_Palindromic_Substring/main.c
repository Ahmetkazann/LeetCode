#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
char* longestPalindrome(char* s) {

    bool oddpalindrom = false;
    bool evenpalindrom = false;

    int rightp = 1, leftp = 0; // right pointer goes to right from center of palindrom and left goes left.
    int longestrightp, longestleftp;
    int i = 1;
    while(i != strlen(s)){
        rightp = i + 1;
        leftp = i;
        if(s[rightp] == s[leftp]){
            oddpalindrom = true;
        }
        else{
            oddpalindrom = false;
            rightp++;
            if(rightp > strlen(s)){
                break;
            }
            if(s[rightp] == s[leftp]){
                evenpalindrom = true;
            }
            else{
                evenpalindrom = false;
            }
        }
        while(oddpalindrom){
            if(rightp > strlen(s) || leftp < 0){
                break;
            }
            if(s[--leftp] == s[++rightp]){
                oddpalindrom = true;
                // rightp++;
                // leftp--;
            }
            else{
                if((rightp - leftp) > (longestrightp - longestleftp)){
                    longestrightp = rightp;
                    longestleftp = leftp;
                }
                oddpalindrom = false;
            }

        }
        while(evenpalindrom){

            if(rightp > strlen(s) || leftp < 0){
                break;
            }
            if(s[--leftp] == s[++rightp]){
                evenpalindrom = true;
                // rightp++;
                // leftp--;
            }
            else{
                if((rightp - leftp) > (longestrightp - longestleftp)){
                    longestrightp = rightp;
                    longestleftp = leftp;
                }
                evenpalindrom = false;
            }

        }

        i++;
    }
    char longestpalindrom[1000];
    int counter = 0;
    printf("left : %d - right : %d",longestleftp, longestrightp);
    // for(int j = longestleftp; j < longestrightp; j++){
    //     longestpalindrom[counter] = s[j];
    //     counter++;
    // }
    // printf("%s", longestpalindrom);
    // return longestpalindrom;
    return "a";
}

int main()
{
    char s[7] = "abccbaa";
    char longest[1000];
    strcpy(longest, longestPalindrome(s));
    printf("\nlongest : %s",longest);
    return 0;
}
