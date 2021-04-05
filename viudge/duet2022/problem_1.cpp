#include<bits/stdc++.h>
using namespace std;
int main(){

    int n,student,i,length,width,hight,min,max,minIndex=0,maxIndex=0;
    string name;
    vector<string> studentName;
    vector<int> cLength,cWidth,cHeight;
    cin>>n;
    for(int j=1;j<=n;j++){
        scanf("%d",&student);
      for(i=0;i<student;i++){
        cin>>name;
        studentName.push_back(name);
        scanf("%d%d%d",&length,&width,&hight);
        cLength.push_back(length);
        cWidth.push_back(width);
        cHeight.push_back(hight);
      }
      min=cLength[0]*cWidth[0]*cHeight[0];
      max=cLength[0]*cWidth[0]*cHeight[0];
      for(i=0;i<student;i++){
        int mul=cLength[i]*cWidth[i]*cHeight[i];
        if((mul==min ) || (mul==max )) continue;
        else if((mul<min )) {
            min=cLength[i]*cWidth[i]*cHeight[i];
            minIndex=i;
        }
        else if (mul>max) {
            max=cLength[i]*cWidth[i]*cHeight[i];
            maxIndex=i;
        }
      }
      if(min==max) cout<<"Case "<<j<<": no thief"<<endl;
      else cout<<"Case "<<j<<": "<<studentName[maxIndex]<<" took chocolate from "<<studentName[minIndex]<<endl;

        studentName.clear();
        cLength.clear();
        cHeight.clear();
        cWidth.clear();

        minIndex=0;
        maxIndex=0;
    }

return 0;
}
