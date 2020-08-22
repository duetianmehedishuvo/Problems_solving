#include <iostream>
#include<string.h>

using namespace std;

int main()
{

    char str1[30];
    char str2[30];
    cin>>str1;
    int i=0,len=0,j;
    while(str1[i]!='\0'){
        i++;
        len++;
    }
    for(j=0,i=len-1;i>=0;i--,j++){
        str2[j]=str1[i];
    }
    str2[j]='\0';

    if(strcmp(str1,str2)==0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}