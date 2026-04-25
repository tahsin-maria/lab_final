//Implement a circular queue with enqueue and dequeue operations

#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;      // dynamic array to hold queue elements
    int front;     // index of the front element
    int rear;      // index of the rear element
    int size;      // max capacity
    int count;     // current number of elements

public:
    // Constructor: initialize queue with given size
    CircularQueue(int size) {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = -1;
        count = 0;
    }

    // Destructor: free memory
    ~CircularQueue() {
        delete[] arr;
    }

    // Check if queue is full
    bool isFull() {
        return count == size;
    }

    // Check if queue is empty
    bool isEmpty() {
        return count == 0;
    }

    // Enqueue: add element to rear
    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue " << val << "\n";
            return;
        }
        // Move rear forward, wrap around using modulo
        rear = (rear + 1) % size;
        arr[rear] = val;
        count++;
        cout << "Enqueued: " << val << "\n";
    }

    // Dequeue: remove element from front
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue.\n";
            return -1;
        }
        int val = arr[front];
        // Move front forward, wrap around using modulo
        front = (front + 1) % size;
        count--;
        cout << "Dequeued: " << val << "\n";
        return val;
    }

    // Peek at front element without removing
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return arr[front];
    }

    // Display all elements from front to rear
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue: ";
        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % size] << " ";
        }
        cout << "\n";
    }
};

int main() {
    CircularQueue q(5);  // create queue with capacity 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);  // fills the gap left by dequeue
    q.display();

    q.enqueue(70);  // should say full

    return 0;
}
