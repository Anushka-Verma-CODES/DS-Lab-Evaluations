#include <iostream>
using namespace std;

/* 
   1) MENU DRIVEN PROGRAM – SINGLY LINKED LIST OPERATIONS

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertBegin(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
}

void insertEnd(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if (head == NULL) { head = temp; return; }

    Node* p = head;
    while (p->next != NULL) p = p->next;
    p->next = temp;
}

void insertBefore(int key, int x) {
    if (head == NULL) return;

    if (head->data == key) {
        insertBegin(x);
        return;
    }

    Node* p = head;
    while (p->next && p->next->data != key) p = p->next;

    if (p->next == NULL) return;

    Node* temp = new Node();
    temp->data = x;
    temp->next = p->next;
    p->next = temp;
}

void insertAfter(int key, int x) {
    Node* p = head;
    while (p && p->data != key) p = p->next;
    if (!p) return;

    Node* temp = new Node();
    temp->data = x;
    temp->next = p->next;
    p->next = temp;
}

void deleteBegin() {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteEnd() {
    if (head == NULL) return;
    if (head->next == NULL) { delete head; head = NULL; return; }

    Node* p = head;
    while (p->next->next != NULL) p = p->next;

    delete p->next;
    p->next = NULL;
}

void deleteKey(int key) {
    if (head == NULL) return;
    if (head->data == key) {
        deleteBegin();
        return;
    }

    Node* p = head;
    while (p->next && p->next->data != key) p = p->next;

    if (p->next == NULL) return;

    Node* temp = p->next;
    p->next = temp->next;
    delete temp;
}

void searchNode(int key) {
    Node* p = head;
    int pos = 1;
    while (p) {
        if (p->data == key) {
            cout << "Found at position: " << pos << endl;
            return;
        }
        p = p->next;
        pos++;
    }
    cout << "Not found\n";
}

void display() {
    Node* p = head;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    int ch, x, key;
    while (1) {
        cout << "\n1 Insert Begin\n2 Insert End\n3 Insert Before\n4 Insert After";
        cout << "\n5 Delete Begin\n6 Delete End\n7 Delete Key\n8 Search\n9 Display\n10 Exit\n";

        cin >> ch;
        if (ch == 10) break;

        switch (ch) {
            case 1: cin >> x; insertBegin(x); break;
            case 2: cin >> x; insertEnd(x); break;
            case 3: cin >> key >> x; insertBefore(key, x); break;
            case 4: cin >> key >> x; insertAfter(key, x); break;
            case 5: deleteBegin(); break;
            case 6: deleteEnd(); break;
            case 7: cin >> key; deleteKey(key); break;
            case 8: cin >> key; searchNode(key); break;
            case 9: display(); break;
        }
    }
}
*/

/* 
   2) COUNT OCCURRENCES OF KEY AND DELETE ALL

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void push(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
}

int main() {
    int x;
    while (cin >> x && x != -1) push(x);

    int key;
    cin >> key;

    int count = 0;
    Node* curr = head;
    Node* prev = NULL;

    while (curr) {
        if (curr->data == key) {
            count++;
            if (prev == NULL) {
                head = curr->next;
                delete curr;
                curr = head;
            } else {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    cout << "Count: " << count << "\nUpdated Linked List: ";
    Node* p = head;
    while (p) { cout << p->data << " "; p = p->next; }
}
*/

/* 
   3) FIND MIDDLE OF LINKED LIST

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void push(int x) {
    Node* t = new Node();
    t->data = x;
    t->next = head;
    head = t;
}

int main() {
    int x;
    while (cin >> x) push(x);

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << slow->data;
}
*/

/* 
   4) REVERSE A LINKED LIST

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void push(int x) {
    Node* t = new Node();
    t->data = x;
    t->next = head;
    head = t;
}

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main() {
    int x;
    while (cin >> x) push(x);

    head = reverse(head);

    Node* p = head;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
}
*/

int main() { return 0; }
