//Implementation of a queue using an array
#include <iostream>
using namespace std;

class Queue {
private:
    static const int MAX_SIZE = 100;
    int data[MAX_SIZE];
    int frontIndex, rearIndex;

public:
    Queue() : frontIndex(0), rearIndex(0) {}

    void enqueue(int value) {
        if (rearIndex < MAX_SIZE) {
            data[rearIndex++] = value;
        } else {
            std::cout << "Queue is full!\n";
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            frontIndex++;
        } else {
            std::cout << "Queue is empty!\n";
        }
    }

    int front() {
        if (!isEmpty()) {
            return data[frontIndex];
        } else {
            std::cerr << "Queue is empty!\n";
            return -1;
        }
    }

    bool isEmpty() {
        return frontIndex == rearIndex;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.front() << "\n";
    q.dequeue();
    cout << "Front: " << q.front() << "\n";
    q.dequeue();
    cout << "Front: " << q.front() << "\n";
    q.dequeue();
    q.dequeue(); // Attempt to dequeue from empty queue

    return 0;
}
