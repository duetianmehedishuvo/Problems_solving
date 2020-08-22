#include <iostream>
#include<string.h>

using namespace std;

int main()
{

    int i,n,j,count;
    char s[100];
    cin>>n;
    for(j=0;j<n;j++){
        cin>>s;
        count=0;
        for(i=0;i<strlen(s);i++){
            if(s[i]>='0' && s[i]<='6') count++;
            if(s[i]=='O') count++;
        }

        if(count==1)
            cout<<"1 BALL"<<endl;
        if(count<6)
            cout<<count<<" BALLS"<<endl;
        if(count==6)
            cout<<"1 OVER"<<endl;
        if(count>6){
            if(count%6==0){
                cout<<count/6<<" OVERS"<<endl;
            }else{
                if(count/6==1){
                    if(count%6==1){
                        cout<<count/6<<" OVER "<<count%6<<" BALL"<<endl;
                    }else{
                        cout<<count/6<<" OVER "<<count%6<<" BALL"<<endl;
                    }
                }else{
                    cout<<count/6<<" OVER "<<count%6<<" BALL"<<endl;
                }
            }
        }
    }

    return 0;
}
