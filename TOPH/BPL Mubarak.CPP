#include <iostream>

using namespace std;

int main()
{
    int i,n,j,ball;
    char s[100];
    char ch;
    cin>>n;
    for(j=0; j<n; j++)
    {
        cin>>s;
        ball=0;
        i=0;
        while(s[i]!='\0')
        {
            ch=s[i];
            if(s[i]>='0' && s[i]<='6')
                ball++;
            if(s[i]=='O') ball++;

            i++;
        }
        if(ball<=6)
        {
            if(ball==1)
            {
                cout<<ball<<"1 BALL"<<endl;
            }
            else if(ball==6)
            {
                cout<<"1 OVER"<<endl;
            }
            else
            {
                cout<<ball<<" BALLS"<<endl;
            }
        }
        else
        {
            if(ball%6==0) cout<<ball/6<<" OVERS "<<endl;
            else
            {
                if(ball/6==1)
                {
                    if(ball%6==1) cout<<ball/6<<" OVER "<<"1 BALL"<<endl;
                    else cout<<ball/6<<" OVER "<<ball%6<<" BALLS"<<endl;

                }
                else cout<<ball/6<<" OVERS "<<ball%6<<" BALLS"<<endl;

            }
        }

    }

    return 0;
}
