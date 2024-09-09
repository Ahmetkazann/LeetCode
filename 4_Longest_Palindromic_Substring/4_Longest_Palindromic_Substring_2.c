#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestPalindrome(char* s) {
    int n = strlen(s);

    if (n == 0) {
        return "";
    }

    int longestleftp = 0, longestrightp = 0;

    for (int i = 0; i < n; i++) { // odd case

        int leftp = i, rightp = i;
        while (leftp >= 0 && rightp < n && s[leftp] == s[rightp]) {
            if (rightp - leftp > longestrightp - longestleftp) {
                longestleftp = leftp;
                longestrightp = rightp;
            }
            leftp--;
            rightp++;
        }
        leftp = i, rightp = i + 1; // even case
        while (leftp >= 0 && rightp < n && s[leftp] == s[rightp]) {
            if (rightp - leftp > longestrightp - longestleftp) {
                longestleftp = leftp;
                longestrightp = rightp;
            }
            leftp--;
            rightp++;
        }
    }

    int length = longestrightp - longestleftp + 1;
    char* longestpalindrom = (char*)malloc((length + 1) * sizeof(char));
    strncpy(longestpalindrom, s + longestleftp, length);
    longestpalindrom[length] = '\0';

    return longestpalindrom;
}

int main()
{
    char s[] = "abccb";
    char* longest = longestPalindrome(s);
    printf("Longest Palindrome: %s\n", longest);

    free(longest);
    return 0;
}
