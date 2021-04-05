#include<stdio.h>
#include<math.h>
int main()
{
    int n,sum=0;
    scanf("%d",&n);
    if(n>=1 && n<=10)
    {
        for(int i=1; i<=3; i++)
        {
            sum=sum+pow(n,i);
        }
        printf("%d",sum);
    }
    return 0;
}
