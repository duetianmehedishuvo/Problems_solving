#include<bits/stdc++.h>
using namespace std;


int cycleLength=0;

struct Node{
int data;
Node *next;
};

void push(Node *& headRef,int new_data){
    // create  a new linked list node from the heap
    Node * newNode=new Node;
    newNode->data=new_data;
    newNode->next=headRef;
    headRef=newNode;
}

// finding to detect a cycle in a linked list using Flod's Cycle detection algorithm
bool detectCycle(Node * head){
    
    // take two pointer - 'slow', 'fast'
    Node* slow=head,*fast=head;

    while (fast && fast->next)
    {
        cycleLength++;

        // Move slow by One Pointer
        slow=slow->next;

        // Move  fast by two  pointer
        fast=fast->next->next;

        // if they meet any node, the linked list contains a cycle
        if(slow==fast) return true;
    }

    //we reach here if the slow and fast pointer does not meet
    return false;
    

}


int main(){

// input keys
int keys[]={1,2,3,4,5};
int n=sizeof(keys)/sizeof(keys[0]);

Node * headNode=nullptr;
for(int i=n-1;i>=0;i--){
    push(headNode,keys[i]);
}

//insert cycle
headNode->next->next->next->next->next=headNode->next->next;

if(detectCycle(headNode)){
    cout<<"Cycle Found Length is: "<<cycleLength<<endl;
}else{
    cout<<"No Cycle Found";
}

    return 0;
}