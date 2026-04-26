// Implement a circular queue with enqueue and dequeue operations

#include <bits/stdc++.h>
using namespace std;

class QUEUE
{
public:
    int *arr;
    int front;
    int rear;
    int size;
    int count;

    QUEUE(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = -1;
        count = 0;
    }
    
    ~QUEUE()
    {
        delete[] arr;
    }

    bool isFull()
    {
        return count == size;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "queue is full\n";
            return;
        }
        rear = (rear + 1) % size;
        arr[rear] = val;
        count++;
        cout << "val " << val << " enqueued !" << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "queue is empty\n";
            return;
        }
        int delvalue = arr[front];
        front = (front + 1) % size;
        count--;
        cout << "val " << delvalue << " dequeued !\n";
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "queue is empty\n";
            return;
        }
        cout << "the queue is : ";
        for (int i = 0; i < count; i++)
        {
            cout << arr[(front + i) % size] << " ";
        }
    }
};

int main()
{
    QUEUE q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.dequeue();
    q.display();
}
