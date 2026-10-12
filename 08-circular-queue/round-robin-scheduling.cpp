#include <iostream>
using namespace std;

#define MAX 100

class Process {
public:
    string name;
    int arrivalTime;
    int burstTime;
    int remainingTime;

    Process(string n, int at, int bt) {
        name = n;
        arrivalTime = at;
        burstTime = bt;
        remainingTime = bt;
    }
};

class CircularQueue {
    int queue[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int index) {
        if (front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }

        queue[rear] = index;
    }

    int dequeue() {
        int index = queue[front];

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }

        return index;
    }
};

int main() {
    Process p[] = {
        Process("P1", 0, 5),
        Process("P2", 1, 3),
        Process("P3", 2, 1),
        Process("P4", 3, 2),
        Process("P5", 4, 3)
    };

    int n = 5;
    int timeQuantum = 2;
    int currentTime = 0;
    int completed = 0;

    CircularQueue q;
    bool added[MAX] = {false};

    cout << "Gantt Chart:\n";

    while (completed < n) {

        // Add newly arrived processes
        for (int i = 0; i < n; i++) {
            if (!added[i] && p[i].arrivalTime <= currentTime) {
                q.enqueue(i);
                added[i] = true;
            }
        }

        // If queue is empty, move to next time
        if (q.isEmpty()) {
            currentTime++;
            continue;
        }

        int index = q.dequeue();

        cout << "| " << p[index].name << " ";

        // Execute process for one time quantum
        int executionTime = min(timeQuantum, p[index].remainingTime);

        for (int t = 0; t < executionTime; t++) {
            currentTime++;

            // Check for newly arrived processes
            for (int i = 0; i < n; i++) {
                if (!added[i] && p[i].arrivalTime <= currentTime) {
                    q.enqueue(i);
                    added[i] = true;
                }
            }
        }

        p[index].remainingTime -= executionTime;

        if (p[index].remainingTime > 0) {
            q.enqueue(index);
        } else {
            completed++;
        }
    }

    cout << "|\n";

    return 0;
}
