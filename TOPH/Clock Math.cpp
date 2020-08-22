#include <iostream>
#include<math.h>

using namespace std;

int min(int x,int y){
    return (x<y)?x:y;
}


double calculateAngle(double h,double m){

        if(h<0||m<0||h>12||m>60)
            cout<<"Wrong Input"<<endl;
        if(h==12) h=0;
        if(m==60){
            m=0;
            h+=1;
            if(h>12){
                h=h-12;
            }
        }
        double hour_angle=0.5*(h*60+m);
        double minute_angle=6*m;
        double angle=abs(hour_angle-minute_angle);
        return min(360-angle,angle);
    }

int main()
{
    double m,h;
    cin>>m>>h;
    cout<<calculateAngle(m,h)<<endl;
    return 0;
}
