#include<bits/stdc++.h>
using namespace std;

int main(){
    string title;
    int upperCaseNumber=0,lowerCaseNumber=0,i,asciiNumber;
    cin>>title;
    for(i=0;i<title.size();i++){
        asciiNumber=title[i];
        if(asciiNumber>=65 && asciiNumber<=90) upperCaseNumber++;
        else if(asciiNumber>=97 && asciiNumber<=122) lowerCaseNumber++;
    }
    if(lowerCaseNumber>=upperCaseNumber)
        transform(title.begin(),title.end(),title.begin(),::tolower);

    else 

        transform(title.begin(),title.end(),title.begin(),::toupper);
        
    cout<<title<<endl;
    return 0;
}