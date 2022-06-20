// For a given singly linked list of integers, find and return the node present at the middle of the list.
// Note :
// If the length of the singly linked list is even, then return the first middle node.

// Example: Consider, 10 -> 20 -> 30 -> 40 is the given list, then the nodes present at the middle with respective data values are, 20 and 30. We return the first node with data 20.
//  Input format :
// The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

// The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space. 
// Remember/Consider :
// While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
//  Output Format :
// For each test case/query, print the data value of the node at the middle of the given list.

// Output for every test case will be printed in a seperate line.
// Constraints :
// 1 <= t <= 10^2
// 0 <= M <= 10^5 
// Where M is the size of the singly linked list.

// Time Limit: 1sec
// Sample Input 1 :
// 1
// 1 2 3 4 5 -1
// Sample Output 1 :
// 3
// Sample Input 2 :
// 2 
// -1
// 1 2 3 4 -1
// Sample Output 2 :
// 2

#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;
// Way-1
/*
int length(Node *head)
{
    //Write your code here
    int count=0;
    while(head)
    {
        head=head ->next;
        count++;
    }
    return count;
}
Node *midPoint(Node *head)
{
    // Write your code here
    int len=length(head);
    while(head!=NULL)
    {
        if(len%2!=0)
        {
            for(int i=0;i<len/2;i++)
            {
                head=head->next;
            }
            return head;
        }
        else
        {
            for(int i=0;i<(len-1)/2;i++)
            {
                head=head->next;
            }
            return head;
        }
    }
}
*/
// Way-2
Node *midPoint(Node *head)
{
    if(head==NULL) return head;
    Node *slow=head, *fast = head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		Node *mid = midPoint(head);
		if (mid != NULL)
		{
			cout << mid->data;
		}
		cout << endl;
	}
	return 0;
}