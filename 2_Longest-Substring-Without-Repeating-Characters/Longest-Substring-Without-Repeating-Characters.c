#include <stdio.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char* s) {

    int lenghtof_s = strlen(s);

    int counter;
    char longest[5000];
    char longestsub[5000];
    bool add;
    memset(longest, '\0', 256); // looks like useless but handling nonsense ram error
    memset(longestsub, '\0', 256);
    int i = 0;
    while(i != lenghtof_s){
        counter = 0;
        add = true;
        while(longest[counter] != '\0'){
            if(longest[counter] == s[i]){
                add = false;
                break;
            }
            counter++;
        }
        if(add){
            longest[counter] = s[i];
        }
        else{
            i = i - strlen(longest);
            if(strlen(longest) > strlen(longestsub)){
                strcpy(longestsub, longest);
            }
            memset(longest, '\0', 256);
        }
        i++;
    }
    if(strlen(longest) > strlen(longestsub)){
        strcpy(longestsub, longest);
    }
    printf("longest temp : %s\n", longest);
    printf("longestsub : %s\n", longestsub);
    return strlen(longestsub);
}

int main()
{
}
