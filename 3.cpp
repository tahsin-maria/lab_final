// Insert a node at the beginning, end, and at a given position in a singly linked list
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int v)
    {
        val = v;
        next = NULL;
    }
};

void insert_at_head(Node *&head, int val)
{
    Node *newNode = new Node(val);

    newNode->next = head;
    head = newNode;
}

void insert_at_position(Node *&head, int pos, int val)
{
    if (pos == 0)
    {
        insert_at_head(head, val);
        return;
    }
    Node *tmp = head;
    for (int i = 0; i < pos-1; i++)
    {
        if (tmp == NULL) // invalid position
        {
            return;
        }
        tmp = tmp->next;
    }

    if (tmp == NULL)
    {
        return;
    }

    Node *newNode = new Node(val);
    newNode->next = tmp->next;
    tmp->next = newNode;
}

void insert_at_tail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

void print(Node *head)
{
    Node *tmp = head;
    cout << "The SLL is : \n";
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    int size;
    cout << "enter the size of linked list:";
    cin >> size;
    while (size--)
    {
        int val;
        cin >> val;
        insert_at_tail(head, val);
    }
    int options;
    while (1)
    {
        cout << "enter options :- 1 for insert_at_head\n2 for insert_at_tail\n3 for insert_at_position:";
        cin >> options;

        if (options == 1)
        {
            int val;
            cout << "enter the value:";
            cin >> val;
            insert_at_head(head, val);
            print(head);
        }
        else if (options == 2)
        {
            int val;
            cout << "enter the value:";
            cin >> val;
            insert_at_tail(head, val);
            print(head);
        }
        else if (options == 3)
        {
            int pos, val;
            cout << "enter the position and value:";
            cin >> pos >> val;
            insert_at_position(head, pos, val);
            print(head);
        }
        else
        {
            print(head);
            break;
        }
    }
}