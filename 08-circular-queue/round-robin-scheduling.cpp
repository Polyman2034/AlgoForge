#include <iomanip>
#include <iostream>

using namespace std;

const int MAX = 100;

class CircularQueue {
public:
    int q[MAX];
    int front, rear, count;

    CircularQueue();
    void enqueue(int x);
    int dequeue();
    bool isEmpty();
};

CircularQueue::CircularQueue() {
    front = 0;
    rear = -1;
    count = 0;
}

bool CircularQueue::isEmpty() { 
    return count == 0; 
}

void CircularQueue::enqueue(int x) {
    if (count == MAX) {
        cout << "Queue is full" << endl;
        return;
    }
    rear = (rear + 1) % MAX;
    q[rear] = x;
    count++;
}

int CircularQueue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    int x = q[front];
    front = (front + 1) % MAX;
    count--;
    return x;
}

class Schedular {
public:
    int n, qt;
    int at[MAX], ct[MAX], tat[MAX], bt[MAX], rem[MAX], wt[MAX];

    Schedular();
    void input();
    void display();
    void execute();
};

Schedular::Schedular() {
    n = 5;
    qt = 2;
    int arrival[] = {0, 1, 2, 3, 4};
    int burst[] = {5, 3, 1, 2, 3};

    for (int i = 0; i < n; i++) {
        at[i] = arrival[i];
        bt[i] = burst[i];
        rem[i] = bt[i];
        tat[i] = wt[i] = ct[i] = 0;
    }
}

void Schedular::input() {
    cout << "Enter the quantum time:" << endl;
    cin >> qt;
    if (qt <= 0) {
        cout << "Quantum time can't be negative or zero" << endl;
        qt = 2;
    }
}

void Schedular::display() {
    double TotalTat = 0, TotalWt = 0;
    cout << "Process\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        TotalTat += tat[i];
        TotalWt += wt[i];
        cout << "P" << i + 1 << "\t" << at[i] << "\t" << bt[i] << "\t" 
             << ct[i] << "\t" << tat[i] << "\t" << wt[i] << "\n";
    }
    cout << fixed << setprecision(2);
    cout << "Average Turn around time = " << TotalTat / n << endl;
    cout << "Average Waiting time = " << TotalWt / n << endl;
}

void Schedular::execute() {
    CircularQueue q;
    int time = 0, completed = 0, next = 0;

    cout << "\nGantt Chart:\n";
    while (completed < n) {
        while (next < n && at[next] <= time) {
            q.enqueue(next);
            next++;
        }

        if (q.isEmpty()) {
            time = at[next];
            continue;
        }

        int p = q.dequeue();
        int start = time;
        int run = (rem[p] < qt) ? rem[p] : qt;
        time += run;
        rem[p] -= run;

        cout << "| P" << p + 1 << " (" << start << "-" << time << ") ";

        while (next < n && at[next] <= time) {
            q.enqueue(next);
            next++;
        }

        if (rem[p] > 0) {
            q.enqueue(p);
        } else {
            ct[p] = time;
            completed++;
        }
    }
    cout << "|\n";
}

int main() {
    Schedular s;
    s.input();
    s.execute();
    s.display();
    return 0;
}
