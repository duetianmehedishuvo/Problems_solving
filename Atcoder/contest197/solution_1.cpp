#include<stdio.h>
int main()
{

    char ch[3];


    for(int i=0;i<=2;i++){
        scanf("%c",&ch[i]);
    }
    char temp=ch[0];
    for(int i=0; i<=1; i++)
    {
        ch[i]=ch[i+1];
    }
    ch[2]=temp;
    for(int i=0; i<=2; i++) printf("%c",ch[i]);

    return 0;
}
