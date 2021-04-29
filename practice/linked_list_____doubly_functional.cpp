#include<bits/stdc++.h>
using namespace std;

class Vehical
{
public:
    int id;
    string model;
    double price;
    string type;
    Vehical* previous;
    Vehical* next;
};

void push(Vehical ** head_ref,int new_id,string new_model,string new_type,double new_price)
{
    Vehical* new_vehical=new Vehical();

    // put in the data
    new_vehical->id=new_id;
    new_vehical->model=new_model;
    new_vehical->price=new_price;
    new_vehical->type=new_type;

    // make next of new node as head and previously as NULL
    new_vehical->next=(*head_ref);
    new_vehical->previous=NULL;

    // Change Prev of head node to new node
    if((*head_ref) !=NULL)
    {
        (*head_ref)->previous=new_vehical;
    }

    // Move the head to point to the new node
    (*head_ref)=new_vehical;
}

void append(Vehical ** head_ref,int new_id,string new_model,string new_type,double new_price)
{
    //1. Allocate node
    Vehical* new_vehical=new Vehical();
    Vehical* last=*head_ref;

    // put in the data
    new_vehical->id=new_id;
    new_vehical->model=new_model;
    new_vehical->price=new_price;
    new_vehical->type=new_type;

    // this new node is going to be the last node, sp make next of it as NULL
    new_vehical->next=NULL;

    // if the linked list is empty, then make the new node as head
    if(*head_ref==NULL)
    {
        new_vehical->previous=NULL;
        *head_ref=new_vehical;
        return;
    }


    // else traverse till the last node
    while(last->next !=NULL)
        last=last->next;

    // change the next of last node
    last->next=new_vehical;

    // make last node as previous of new node
    new_vehical->previous=last;
    return;
}

void addAVehical(Vehical **vehial,bool isAddBeganning,bool isAddEnd)
{
    int id;
    string model;
    double price;
    string type;
    cout<<"\nEnter ID: ";
    cin>>id;
    cout<<"Enter Vehical Model: ";
    cin>>model;
    cout<<"Enter Vehical Type: ";
    cin>>type;
    cout<<"Enter Vehical Price: ";
    cin>>price;
    cout<<endl;
    if(isAddBeganning==true)
        push(vehial,id,model,type,price);

    if(isAddEnd==true)
        append(vehial,id,model,type,price);

}

void deleteNode(Vehical** head_ref,Vehical* del)
{
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


void deleteAllOccurofX(Vehical** head_ref,int x)
{
    //if list is empty
    if((*head_ref)==NULL) return;

    Vehical* current=*head_ref;
    Vehical* next;

    // traverse the list up to the end
    while (current !=NULL)
    {
        // if node found with the value of X
        if(current->id==x)
        {
            //save currents next node in the pointer next
            next=current->next;

            //delete the node pointer to by current
            deleteNode(head_ref,current);

            // update current
            current=next;
        }
        else
        {
            current=current->next;
        }
    }

    cout<<x<<" is successfully deleted form vehical list";
}


int countVehicalList(Vehical* vehical)
{
    int count=0;
    Vehical* last;
    while (vehical != NULL)
    {
        last = vehical;
        vehical = vehical->next;
        count++;
    }
    return count;
}


void printVehicalList(Vehical* vehical)
{
    Vehical* last=NULL;
    while (vehical != NULL)
    {
        last = vehical;
        vehical = vehical->next;
    }

    cout<<"\nID-> Type-> Model-> Price\n";
    while (last != NULL)
    {
        cout<<last->id<<" "<<last->type<<" "<<last->model<<" "<<last->price<<" \n";
        last = last->previous;
    }
}



int main()
{

    Vehical *head_vehial=NULL;
    char choose;
    int query;

    while (choose!='Q' || choose!='q')
    {
        printf("============================================\n");
        printf("DOUBLY LINKED LIST PROGRAM\n");
        printf("============================================\n");
        printf("[A]: Add a vehicle at beginning\n");
        printf("[B]: Add a vehicle at end\n");
        printf("[D]: Delete a vehicle with ID\n");
        printf("[S]: Show all vehicles from end\n");
        printf("[N]: Number of vehicles\n");
        printf("[Q]: Quit\n");
        printf("--------------------------------------------\n");
        printf("Enter your choose : ");

        cin>>choose;

        switch (choose)
        {
        case 'a':
        case 'A':
            addAVehical(&head_vehial,true,false);
            break;

        case 'b':
        case 'B':
            addAVehical(&head_vehial,false,true);
            break;

        case 'd':
        case 'D':
            cout<<"Enter Vehical ID: ";
            cin>>query;
            deleteAllOccurofX(&head_vehial,query);
            break;

        case 's':
        case 'S':
            printVehicalList(head_vehial);
            break;

        case 'n':
        case 'N':
            cout<<"Length of Vehical list is: "<<countVehicalList(head_vehial);
            break;

        case 'q':
        case 'Q':
            return 0;

        default:
            cout<<"Error! Invalid choice. Please choose between 0-5";

        }

        printf("\n\n");
    }

    return 0;

}
