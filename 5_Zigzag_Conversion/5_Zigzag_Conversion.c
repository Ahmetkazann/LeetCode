#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char* convert(char* s, int numRows)
{

    int lenghtofs = strlen(s);
    if (lenghtofs == 1 || numRows == 1){
        return s;
    }
    int COLUMNS;
    double formula; // COLUMNS PATTERN REPEAT ITSELF FOR EACH ARRAY ELEMENT (2N-2) N = numRows
    if(numRows > 2){
        formula = (lenghtofs / (2*numRows -2));
        formula = formula * (numRows - 1);
        formula = formula + numRows;
        COLUMNS = formula;
    }
    else if(numRows == 2){
        COLUMNS = lenghtofs / 2 + 1;
    }

    char zigzag[numRows][COLUMNS];

    for (int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < COLUMNS; j++)
        {
            zigzag[i][j] = ' ';
        }
    }

    int column = 0, row = 0, i = 0;
    while(i < lenghtofs)
    {
        while(row < numRows - 1&& i < lenghtofs && column < COLUMNS)
        {
            zigzag[row++][column] = s[i++];
        }

        while(row > 0 && i < lenghtofs && column < COLUMNS)
        {
            zigzag[row--][column++] = s[i++];
        }
    }
    char *mystring = malloc(sizeof(char) * (lenghtofs + 1));
    int counter2 = 0;
    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < COLUMNS; j++)
        {
            if(zigzag[i][j] != ' '){
                mystring[counter2] = zigzag[i][j];
                counter2++;
            }
        }
    }
    mystring[counter2] = '\0';
    return mystring;
}

int main()
{

    char s[42] = "PAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRING";
    char a[42];
    strcpy(a, convert(s, 9));
    printf("Hello world!\nstrng :%s",a);
    return 0;
}
