#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

/* 
   1) SIMPLE QUEUE OPERATIONS – MENU DRIVEN PROGRAM

#include <iostream>
using namespace std;

#define SIZE 100
class SimpleQueue {
    int arr[SIZE];
    int front, rear;
public:
    SimpleQueue() { front = -1; rear = -1; }

    bool isEmpty() { return front == -1; }

    bool isFull() { return rear == SIZE - 1; }

    void enqueue(int x) {
        if (isFull()) { cout << "Queue Full\n"; return; }
        if (front == -1) front = 0;
        arr[++rear] = x;
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue Empty\n"; return; }
        cout << "Dequeued: " << arr[front] << endl;
        if (front == rear) front = rear = -1;
        else front++;
    }

    void peek() {
        if (isEmpty()) cout << "Queue Empty\n";
        else cout << "Front: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) { cout << "Queue Empty\n"; return; }
        for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    SimpleQueue q;
    int ch, x;
    while (1) {
        cout << "\n1 Enqueue\n2 Dequeue\n3 Peek\n4 Display\n5 Exit\n";
        cin >> ch;
        if (ch == 5) break;
        switch (ch) {
            case 1: cin >> x; q.enqueue(x); break;
            case 2: q.dequeue(); break;
            case 3: q.peek(); break;
            case 4: q.display(); break;
        }
    }
}
*/

/* 
   2) CIRCULAR QUEUE OPERATIONS – MENU DRIVEN PROGRAM

#include <iostream>
using namespace std;

#define SIZE 100

class CircularQueue {
    int arr[SIZE];
    int front, rear, count;
public:
    CircularQueue() { front = 0; rear = -1; count = 0; }

    bool isEmpty() { return count == 0; }

    bool isFull() { return count == SIZE; }

    void enqueue(int x) {
        if (isFull()) { cout << "Queue Full\n"; return; }
        rear = (rear + 1) % SIZE;
        arr[rear] = x;
        count++;
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue Empty\n"; return; }
        cout << "Dequeued: " << arr[front] << endl;
        front = (front + 1) % SIZE;
        count--;
    }

    void peek() {
        if (isEmpty()) cout << "Queue Empty\n";
        else cout << "Front: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) { cout << "Queue Empty\n"; return; }
        int idx = front;
        for (int i = 0; i < count; i++) {
            cout << arr[idx] << " ";
            idx = (idx + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int ch, x;
    while (1) {
        cout << "\n1 Enqueue\n2 Dequeue\n3 Peek\n4 Display\n5 Exit\n";
        cin >> ch;
        if (ch == 5) break;
        switch (ch) {
            case 1: cin >> x; q.enqueue(x); break;
            case 2: q.dequeue(); break;
            case 3: q.peek(); break;
            case 4: q.display(); break;
        }
    }
}
*/

/* 
   3) INTERLEAVE FIRST HALF OF QUEUE WITH SECOND HALF
    #include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    int x;
    while (cin >> x) q.push(x);

    int n = q.size();
    queue<int> first;

    for (int i = 0; i < n/2; i++) {
        first.push(q.front());
        q.pop();
    }

    while (!first.empty()) {
        cout << first.front() << " ";
        first.pop();

        cout << q.front() << " ";
        q.pop();
    }
}
*/

/* 
   4) FIRST NON-REPEATING CHARACTER IN STREAM

#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<char> q;
    int freq[26] = {0};
    char ch;

    while (cin >> ch) {
        q.push(ch);
        freq[ch - 'a']++;

        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        if (q.empty()) cout << -1 << " ";
        else cout << q.front() << " ";
    }
}
*/

/*
   5) STACK USING QUEUES

   (a) Using TWO QUEUES
*/

class StackTwoQ {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    void pop() {
        if (q1.empty()) return;
        q1.pop();
    }
    int top() {
        return q1.empty() ? -1 : q1.front();
    }
    bool empty() { return q1.empty(); }
};

/*
   (b) Using ONE QUEUE
*/

class StackOneQ {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        int size = q.size();
        while (size > 1) {
            q.push(q.front());
            q.pop();
            size--;
        }
    }
    void pop() {
        if (!q.empty()) q.pop();
    }
    int top() { return q.empty() ? -1 : q.front(); }
    bool empty() { return q.empty(); }
};

int main() {
    StackTwoQ s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    cout << s1.top() << endl;  
    s1.pop();
    cout << s1.top() << endl;  

    StackOneQ s2;
    s2.push(5);
    s2.push(7);
    s2.push(9);
    cout << s2.top() << endl;
    s2.pop();
    cout << s2.top() << endl;
}
