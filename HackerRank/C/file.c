/***

            Bismillahir Rahmanir Rahim
            Read in the name of Allah, who created you!!!
            Author : Mehedi Hasan Shuvo,
            Department of CSE, Dhaka University of Engineering & Technology,DUET.

***/

#include <stdio.h>
#include <ctype.h>
#define ebar_khela_jombe_besh int main(void)
#define jitsen_bhai return 0

ebar_khela_jombe_besh
{

    /* Pointer to the file */
    FILE *fp1;
    /* Character variable to read the content of file */
    char c;

    /* Opening a file in r mode*/
    fp1 = fopen("input.txt", "r");
    /* Infinite loop –I have used break to come out of the loop*/
    while (1)
    {
        c = fgetc(fp1);
        if (c == EOF)
            break;
        else
        {

            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            {
                if (c >= 'a' && c <= 'z')
                {
                    c = toupper(c);
                }
                printf("%c\n", c);
            }
        }
    }
    fclose(fp1);

    jitsen_bhai;
}