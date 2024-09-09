#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char* longestPalindrome(char* s) {
    bool oddpalindrom = false;
    bool evenpalindrom = false;

    int rightp, leftp;
    int longestrightp = 0, longestleftp = 0;
    int i = 0;
    int len = strlen(s);

    while (i < len) {
        rightp = i + 1;
        leftp = i;

        if (s[rightp] == s[leftp]) {
            oddpalindrom = true;
        } else {
            oddpalindrom = false;
            rightp++;
            if (rightp >= len) {
                break;
            }
            if (s[rightp] == s[leftp]) {
                evenpalindrom = true;
            } else {
                evenpalindrom = false;
            }
        }

        while (oddpalindrom) {
            if (rightp >= len || leftp < 0) {
                break;
            }
            if (s[--leftp] == s[++rightp]) {
                oddpalindrom = true;
            } else {
                if ((rightp - leftp) > (longestrightp - longestleftp)) {
                    longestrightp = rightp;
                    longestleftp = leftp;
                }
                oddpalindrom = false;
            }
        }

        while (evenpalindrom) {
            if (rightp >= len || leftp < 0) {
                break;
            }
            if (s[--leftp] == s[++rightp]) {
                evenpalindrom = true;
            } else {
                if ((rightp - leftp) > (longestrightp - longestleftp)) {
                    longestrightp = rightp;
                    longestleftp = leftp;
                }
                evenpalindrom = false;
            }
        }

        if (longestleftp < 0) {
            longestleftp = 0;
        }
        if (longestrightp >= len) {
            longestrightp = len - 1;
        }

        i++;
    }

    int palin_len = longestrightp - longestleftp;
    char* longestpalindrom = (char*)malloc(palin_len + 1);
    strncpy(longestpalindrom, s + longestleftp + 1, palin_len);
    longestpalindrom[palin_len] = '\0';

    return longestpalindrom;
}


int main() {
    char s[] = "abccba";
    char* longest = longestPalindrome(s);
    printf("Longest Palindrome: %s\n", longest);

    free(longest);

    return 0;
}
