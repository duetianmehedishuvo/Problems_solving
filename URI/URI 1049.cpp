#include <bits/stdc++.h>

using namespace std;

int main()
{
    string firstName,middleName,lastName;
    cin>>firstName>>middleName>>lastName;

    if(firstName=="vertebrado"){
        if(middleName=="ave"){

            if(lastName=="carnivoro")
                cout<<"aguia"<<endl;
            else if(lastName=="onivoro")
                cout<<"pomba"<<endl;

        }else if(middleName=="mamifero"){

            if(lastName=="onivoro")
                cout<<"homem"<<endl;
            else if(lastName=="herbivoro")
                cout<<"vaca"<<endl;

        }
    }else if(firstName=="invertebrado"){

        if(middleName=="inseto"){

            if(lastName=="hematofago")
                cout<<"pulga"<<endl;
            else if(lastName=="herbivoro")
                cout<<"lagarta"<<endl;

        }else if(middleName=="anelideo"){

            if(lastName=="hematofago")
                cout<<"sanguessuga"<<endl;
            else if(lastName=="onivoro")
                cout<<"minhoca"<<endl;

        }

    }
    return 0;
}
