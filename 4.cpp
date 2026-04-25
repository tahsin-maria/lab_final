// Delete a node by value in a singly linked list.
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

void insert_at_tail(Node *&head, int val) // create a sll
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

void print(Node *head) // print
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

void del_by_val(Node *&head, int val)
{
    if (head == NULL)
        return;

    while (head != NULL && head->val == val) // Multiple deletions at head
    {
        Node *delNode = head;
        head = head->next;
        delete delNode;
    }

    Node *tmp = head;
    while (tmp != NULL && tmp->next != NULL)
    {
        if (tmp->next->val == val) // it can even delete multiple occurences of that value
        {
            Node *delNode = tmp->next;
            tmp->next = delNode->next;
            delete delNode;
        }
        else
        {
            tmp = tmp->next;
        }
    }
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
    int val;
    cout << "enter val:";
    cin >> val;
    del_by_val(head, val);
    print(head);
}