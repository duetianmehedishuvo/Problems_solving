#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

};

void printVehicalList(Node* n){
    while (n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
    
}

void pushStart( Node ** head_ref,int new_data){
     Node * new_one=new Node;
    new_one->data=new_data;
    new_one->next=(*head_ref);
    (*head_ref)=new_one;
}

void pushEnd( Node ** head_ref,int new_data){
     Node * new_vehical=new Node;
     Node * last=*head_ref;
    new_vehical->data=new_data;
    new_vehical->next=NULL;

    while (last->next!=NULL)
    {
        last=last->next;
    }
    last->next=new_vehical;
}

void pushAfter(Node* prev_vehical,int new_data){
    if(prev_vehical==NULL){
        cout<<"The Given Previously node cannot be NULL";
        return;
    }

    Node* new_node=new Node;
    new_node->data=new_data;
    new_node->next=prev_vehical->next;
    prev_vehical->next=new_node;
}


void deleteList(Node ** head_ref){
    Node* current=*head_ref;
    Node* next=NULL;
    while (current!=NULL)
    {
        next=current->next;
        free(current);
        current=next;
    }

*head_ref=NULL;
    
}

void deleteVehical(Node ** head_ref,int key){

    Node * temp=*head_ref;
    Node* prev=NULL; 

    if(temp!=NULL && temp->data==key){
        *head_ref=temp->next;
        delete temp;
        return;
    }else{
        while (temp!=NULL && temp->data !=key)
        {
            prev=temp;
            temp=temp->next;
        }

        if(temp==NULL) return;
        prev->next=temp->next;
        delete temp;
        
    }
}

int main(){

    Node* vehicalHead=NULL;
    Node* vehicalSecond=NULL;
    Node* vehicalThird=NULL;

    vehicalHead=new Node();
    vehicalSecond=new Node();
    vehicalThird=new Node();

// asign data in first node
    vehicalHead->data=1;
    vehicalHead->next=vehicalSecond;

// asign data in second node
    vehicalSecond->data=2;
    vehicalSecond->next=vehicalThird;

// asign data in third node
    vehicalThird->data=3;
    vehicalThird->next=NULL;

    printVehicalList(vehicalHead);

    cout<<endl;
    pushStart(&vehicalHead, 11);
    printVehicalList(vehicalHead);


    cout<<endl;
    pushEnd(&vehicalThird, 15);
    printVehicalList(vehicalHead);


    cout<<endl;
    pushAfter(vehicalSecond, 12);
    printVehicalList(vehicalHead);


    cout<<endl;
    deleteList(&vehicalHead);
    printVehicalList(vehicalHead);

    cout<<endl;
    Node * vehical=NULL;
    pushStart(&vehical,7);
    pushStart(&vehical,1);
    pushStart(&vehical,2);
    pushStart(&vehical,4);
    pushStart(&vehical,9);
    pushStart(&vehical,5);
    deleteVehical(&vehical,2);
    printVehicalList(vehical);

    return 0;
}