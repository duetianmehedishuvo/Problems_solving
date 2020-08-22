#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char s[20];
    int i;
    gets(s);
    int k=0,j=0;
    int newa[30];
    for(i=strlen(s)-1;i>=0;i--)
    {
        if(j==3)
        {
            newa[k++]=',';
            newa[k++]=s[i];
            j=0;
        }
        else{
            newa[k++]=s[i];
        }

     j++;

    }

    for(i=k-1;i>=0;i--)
    {
        printf("%c",newa[i]);
    }
    return 0;
}