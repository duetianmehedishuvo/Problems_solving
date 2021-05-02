#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    Node *nextNode;
} NODE;

NODE *createNode(int data)
{

    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->nextNode = NULL;
    return newNode;
}

NODE *insertAtFirst(Node *headNode, int data)
{
    Node *node = createNode(data);
    if (headNode == NULL)
    {
        return node;
    }
    node->nextNode = headNode;
    return node;
}

NODE *insertATLast(NODE *headNode, int data)
{
    if (headNode == NULL)
    {
        return insertAtFirst(headNode, data);
    }

    NODE *node = createNode(data);
    NODE *tempNode = headNode;
    while (tempNode->nextNode != NULL)
    {
        tempNode = tempNode->nextNode;
    }

    tempNode->nextNode = node;
    return headNode;
}

NODE *insertATPosition(NODE *headNode, int data, int position)
{
    if (position == 1)
    {
        return insertAtFirst(headNode, data);
    }

    NODE *node = createNode(data);
    NODE *currentNode = headNode;
    while (position > 2)
    {
        currentNode = currentNode->nextNode;
        position--;
    }
    node->nextNode = currentNode->nextNode;
    currentNode->nextNode = node;
    return headNode;
}

NODE *deleteAtFirst(NODE *headNode)
{
    if (!headNode)
    {
        return NULL;
    }

    NODE *temp = headNode;
    headNode = temp->nextNode;
    free(temp);
    return headNode;
}

NODE *deleteAtLast(NODE *headNode)
{
    if (!headNode)
    {
        return NULL;
    }

    if (headNode->nextNode == NULL)
    {
        free(headNode);
        return NULL;
    }
    NODE *currentNode = headNode;
    while (currentNode->nextNode->nextNode != NULL)
    {
        currentNode = currentNode->nextNode;
    }
    NODE *tempNode = currentNode->nextNode;
    currentNode->nextNode = NULL;
    free(tempNode);
    return headNode;
}

NODE *deleteAtPosition(NODE *headNode, int position)
{
    if (!headNode)
        return NULL;
    if (position == 1)
        deleteAtFirst(headNode);
    NODE *currentNode = headNode;
    while (position > 2)
    {
        currentNode = currentNode->nextNode;
        position--;
    }

    /* Method 01*/
    // NODE *temp = currentNode->nextNode->nextNode;
    // free(currentNode->nextNode);
    // currentNode->nextNode = temp;
    // return headNode;

    /* Method 02*/
    NODE *temp1 = currentNode->nextNode;
    currentNode->nextNode = temp1->nextNode;
    free(temp1);
    return headNode;
}

void printList(Node *headNode)
{
    while (headNode != NULL)
    {
        cout << " " << headNode->data;
        headNode = headNode->nextNode;
    }
}

int main()
{
    NODE *headNode = NULL;
    int input, data, pos;
    do
    {
        cout << "List Contains: \n";
        printList(headNode);

        cout << "\nEnter 0 for exit\n";
        cout << "Enter 1 for insert at first\n";
        cout << "Enter 2 for insert at Last\n";
        cout << "Enter 3 for insert at any Position\n";
        cout << "Enter 4 for Delete at first\n";
        cout << "Enter 5 for Delete at Last\n";
        cout << "Enter 6 for Delete at any Position\n";

        cout << "Enter your wish: ";
        cin >> input;

        switch (input)
        {
        case 1:
            cout << "Data: ";
            cin >> data;
            headNode = insertAtFirst(headNode, data);
            break;
        case 2:
            cout << "Data: ";
            cin >> data;
            headNode = insertATLast(headNode, data);
            break;
        case 3:
            cout << "Data: ";
            cin >> data;
            cout << "Position: ";
            cin >> pos;
            headNode = insertATPosition(headNode, data, pos);
            break;
        case 4:
            headNode = deleteAtFirst(headNode);
            break;
        case 5:
            headNode = deleteAtLast(headNode);
            break;
        case 6:
            cout << "Position: ";
            cin >> pos;
            headNode = deleteAtPosition(headNode, pos);
            break;
        }

    } while (input);

    return 0;
}