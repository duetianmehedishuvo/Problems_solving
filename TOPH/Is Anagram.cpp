#include <iostream>
#include<string.h>

using namespace std;

int main()
{

    char str1[30];
    char str2[30];
    cin>>str1>>str2;
    int i=0,j=0,flag=0;
    for(i=0;i<strlen(str1);i++){
        flag=0;
        for(j=0;j<strlen(str2);j++){
            if(str1[i]==str2[j]){
                flag=1;
                break;
            }
        }
        if(flag==0) break;
    }
    if(flag==1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}
