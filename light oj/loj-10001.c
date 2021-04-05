#include<stdio.h>
int main()
{
    int b,i,a,j,u;
    int ara[50]= {0};
    scanf("%d",&a);
    for(i=0; i<a; i++)
    {
        scanf("%d",&b);
        if(b==0) printf("0 0\n");
        else if(b==20) printf("10 10\n");
        else if(b<11)
        {
            printf("%d %d\n",ara[b],abs(b-ara[b]));
            ara[b]++;
        }
        else
        {
            u=u-ara[b];
            printf("%d %d\n",u,abs(b-u));
            ara[b]++;
        }
    }
}
