#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* previous;
};

void push(Node ** head_ref,int new_data){
    Node* new_node=new Node();

    // put in the data
    new_node->data=new_data;

    // make next of new node as head and previously as NULL
    new_node->next=(*head_ref);
    new_node->previous=NULL;

    // Change Prev of head node to new node
    if((*head_ref) !=NULL){
        (*head_ref)->previous=new_node;
    }

    // Move the head to point to the new node
    (*head_ref)=new_node;
}


void insertBefore(Node** head_ref,Node* next_node,int new_data){
    //1. check if the given next_node is NULL
    if(next_node==NULL){
        cout<<"The Given Previous Node Cannot be NULL";
        return;
    }

    //2. allocate new node
    Node* new_node=new Node;

    //3. Put in the data
    new_node->data=new_data;

    //4. Make prev of new node as prev of next_node
    new_node->previous=next_node->previous;

    //5. Make the prev of next_node as new_node
    next_node->previous=new_node;

    //6. Make next_node as next of new_node
    new_node->next=next_node;

    //7. Change next of new_node's previous node 
    if(new_node->previous !=NULL){
        new_node->previous->next=new_node;
    }
    // 8. If the prev of new_node is NULL, it will be the new head node
    else{
        (*head_ref)=new_node;
    }
}

void insertAfter(Node* prev_node, int new_data)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL)
    {
        cout<<"the given previous node cannot be NULL";
        return;
    }
 
    /* 2. allocate new node */
    Node* new_node = new Node();
 
    /* 3. put in the data */
    new_node->data = new_data;
 
    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;
 
    /* 5. Make the next of prev_node as new_node */
    prev_node->next = new_node;
 
    /* 6. Make prev_node as previous of new_node */
    new_node->previous = prev_node;
 
    /* 7. Change previous of new_node's next node */
    if (new_node->next != NULL)
        new_node->next->previous = new_node;
}

void append(Node ** head_ref,int new_data){
    //1. Allocate node
    Node * new_node=new Node;
    Node* last=*head_ref;

    // put in the data
    new_node->data=new_data;

    // this new node is going to be the last node, sp make next of it as NULL
    new_node->next=NULL;

    // if the linked list is empty, then make the new node as head
    if(*head_ref==NULL){
        new_node->previous=NULL;
        *head_ref=new_node;
        return;
    }


    // else traverse till the last node
    while(last->next !=NULL)
        last=last->next;

    // change the next of last node
    last->next=new_node;

    // make last node as previous of new node
    new_node->previous=last;
    return;
}


void deleteNode(Node** head_ref,Node* del){
    //base case
    if(*head_ref==NULL || del==NULL) return;

    // if node to be deleted is head node
    if(*head_ref==del) *head_ref=del->next;

    // change next only if node to be deleted is not the last node
    if(del->next !=NULL) del->next->previous=del->previous;

    // change prev only if node to be deleted is not the first node
    if(del->previous!=NULL) del->previous->next=del->next;

    // finally free the memory occupied by delete
    free(del);
}


void deleteAllOccurofX(Node** head_ref,int x){
    //if list is empty
    if((*head_ref)==NULL) return;

    Node* current=*head_ref;
    Node* next;

    // traverse the list up to the end
    while (current !=NULL){
        // if node found with the value of X
        if(current->data==x){
            //save currents next node in the pointer next
            next=current->next;

            //delete the node pointer to by current
            deleteNode(head_ref,current);

            // update current
            current=next;
        }else{
            current=current->next;
        }
    }
}

int countList(Node* node)
{
    int count=0;
    Node* last;
    while (node != NULL)
    {
        last = node;
        node = node->next;
        count++;
    }
    return count;
}

void printList(Node* node)
{
    Node* last;
    cout<<"\nTraversal in forward direction \n";
    while (node != NULL)
    {
        cout<<" "<<node->data<<" ";
        last = node;
        node = node->next;
    }
 
    cout<<"\nTraversal in reverse direction \n";
    while (last != NULL)
    {
        cout<<" "<<last->data<<" ";
        last = last->previous;
    }
}


int main(){

Node *node=NULL;
push(&node,10);
push(&node,20);
push(&node,30);
push(&node,40);
push(&node,50);
push(&node,60);

insertBefore(&node,node->next->next,8);
insertAfter(node->next,9);
append(&node,90);
deleteAllOccurofX(&node,40);
cout<<"Count "<<countList(node)<<endl;
printList(node);

    return 0;
}