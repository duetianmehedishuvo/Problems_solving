#include <bits/stdc++.h>
using namespace std;

// Global variables Start
int bitLength;
int bit;
int expectedDecimal;
// Global variables End

typedef struct node
{
	int bit;
	struct node *next;
} NODE;

NODE *createNode(int b)
{
	NODE *newNode = (NODE *)malloc(sizeof(NODE));
	newNode->bit = b;
	newNode->next = NULL;
	return newNode;
}

NODE *insertLast(NODE *head, int b)
{
	NODE *node = createNode(b);

	if (head == NULL)
		return node;

	NODE *currentNode = head;
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
	}
	currentNode->next = node;
	return head;
}
// Method 01
int convertBinTo(NODE *head)
{
	int r = 0;
	while (head)
	{
		r = r * 2 + head->bit;
		head = head->next;
	}
	return r;
}

// Method 02
int convertBinToDec(NODE *head)
{
	int dec = 0;
	int len = 0;
	NODE *cur = head;
	while (cur)
	{
		len++;
		cur = cur->next;
	}
	len--;
	//cout << "Length " << len << endl;
	cur = head;
	while (cur)
	{
		if (cur->bit == 1)
		{
			dec |= (1 << len);
		}
		cur = cur->next;
		len--;
	}
	return dec;
}

NODE *input()
{
	NODE *head = NULL;
	scanf("%d", &bitLength);
	//printf("bits size = %d\n", bitLength);
	int i;
	for (i = 0; i < bitLength; i++)
	{
		scanf("%d", &bit);
		//printf(" %d", bit);
		head = insertLast(head, bit);
	}
	//printf("\n");
	scanf("%d", &expectedDecimal);
	//printf("Expected result = %d\n", expectedDecimal);
	return head;
}

void freeList(NODE *head)
{
	NODE *cur = head;
	while (cur)
	{
		NODE *temp = cur;
		cur = cur->next;
		free(temp);
	}
}

int main()
{
	freopen("input_practice.txt", "r", stdin);
	int testCase;
	int Case = 0;
	scanf("%d", &testCase);
	while (testCase)
	{
		NODE *head = input();
		int result = convertBinToDec(head);
		printf("Case#%d: ", ++Case);
		if (result == expectedDecimal)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
		freeList(head);
		testCase--;
	}
	return 0;
}
