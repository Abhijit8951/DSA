//Implementation of a stack using a vector
#include <iostream>
#include <vector>

class Queue {
private:
    std::vector<int> data;
    int frontIndex;

public:
    Queue() : frontIndex(0) {}

    void enqueue(int value) {
        data.push_back(value);
    }

    void dequeue() {
        if (!isEmpty()) {
            frontIndex++;
            if (frontIndex > data.size() / 2) {
                // Optimize by removing processed elements
                data.erase(data.begin(), data.begin() + frontIndex);
                frontIndex = 0;
            }
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
        return frontIndex >= data.size();
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Front: " << q.front() << "\n";
    q.dequeue();
    std::cout << "Front: " << q.front() << "\n";
    q.dequeue();
    std::cout << "Front: " << q.front() << "\n";
    q.dequeue();
    q.dequeue(); // Attempt to dequeue from empty queue

    return 0;
}