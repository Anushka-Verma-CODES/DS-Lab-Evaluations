#include <iostream>
#include <string>
using namespace std;

/* 
   1) MENU DRIVEN PROGRAM FOR CIRCULAR & DOUBLY LINKED LIST

------------------- CIRCULAR LINKED LIST -------------------
#include <iostream>
using namespace std;

struct CNode {
    int data;
    CNode* next;
};

CNode* chead = NULL;

void cinsertBegin(int x) {
    CNode* temp = new CNode();
    temp->data = x;

    if (chead == NULL) {
        chead = temp;
        temp->next = chead;
        return;
    }

    CNode* p = chead;
    while (p->next != chead) p = p->next;

    temp->next = chead;
    p->next = temp;
    chead = temp;
}

void cinsertEnd(int x) {
    CNode* temp = new CNode();
    temp->data = x;
    if (chead == NULL) {
        chead = temp;
        temp->next = chead;
        return;
    }

    CNode* p = chead;
    while (p->next != chead) p = p->next;

    p->next = temp;
    temp->next = chead;
}

void cinsertAfter(int key, int x) {
    if (chead == NULL) return;
    CNode* p = chead;
    do {
        if (p->data == key) {
            CNode* temp = new CNode();
            temp->data = x;
            temp->next = p->next;
            p->next = temp;
            return;
        }
        p = p->next;
    } while (p != chead);
}

void cinsertBefore(int key, int x) {
    if (chead == NULL) return;

    CNode* p = chead;
    CNode* prev = NULL;

    do {
        if (p->data == key) {
            if (prev == NULL) {
                cinsertBegin(x);
                return;
            }
            CNode* temp = new CNode();
            temp->data = x;
            temp->next = p;
            prev->next = temp;
            return;
        }
        prev = p;
        p = p->next;
    } while (p != chead);
}

void cdeleteNode(int key) {
    if (chead == NULL) return;

    CNode* p = chead;
    CNode* prev = NULL;

    do {
        if (p->data == key) {
            if (prev == NULL) {
                if (chead->next == chead) {
                    delete chead;
                    chead = NULL;
                    return;
                }
                CNode* last = chead;
                while (last->next != chead) last = last->next;
                last->next = chead->next;
                CNode* temp = chead;
                chead = chead->next;
                delete temp;
                return;
            }
            prev->next = p->next;
            delete p;
            return;
        }
        prev = p;
        p = p->next;
    } while (p != chead);
}

void csearchNode(int key) {
    if (chead == NULL) return;
    int pos = 1;
    CNode* p = chead;
    do {
        if (p->data == key) {
            cout << "Found at position " << pos << endl;
            return;
        }
        p = p->next;
        pos++;
    } while (p != chead);
    cout << "Not found" << endl;
}

void cdisplay() {
    if (chead == NULL) return;
    CNode* p = chead;
    do {
        cout << p->data << " ";
        p = p->next;
    } while (p != chead);
    cout << endl;
}

int main() {
    int ch, x, key;
    while (1) {
        cout << "\nCIRCULAR LL MENU\n";
        cout << "1 Insert Begin\n2 Insert End\n3 Insert After\n4 Insert Before\n";
        cout << "5 Delete\n6 Search\n7 Display\n8 Exit\n";
        cin >> ch;
        if (ch == 8) break;

        switch (ch) {
            case 1: cin >> x; cinsertBegin(x); break;
            case 2: cin >> x; cinsertEnd(x); break;
            case 3: cin >> key >> x; cinsertAfter(key, x); break;
            case 4: cin >> key >> x; cinsertBefore(key, x); break;
            case 5: cin >> key; cdeleteNode(key); break;
            case 6: cin >> key; csearchNode(key); break;
            case 7: cdisplay(); break;
        }
    }
}

------------------- DOUBLY LINKED LIST -------------------

#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* next;
    DNode* prev;
};

DNode* head = NULL;

void dinsertBegin(int x) {
    DNode* temp = new DNode();
    temp->data = x;
    temp->next = head;
    temp->prev = NULL;

    if (head) head->prev = temp;
    head = temp;
}

void dinsertEnd(int x) {
    DNode* temp = new DNode();
    temp->data = x;
    temp->next = NULL;

    if (head == NULL) {
        temp->prev = NULL;
        head = temp;
        return;
    }

    DNode* p = head;
    while (p->next != NULL) p = p->next;

    p->next = temp;
    temp->prev = p;
}

void dinsertAfter(int key, int x) {
    DNode* p = head;
    while (p && p->data != key) p = p->next;
    if (!p) return;

    DNode* temp = new DNode();
    temp->data = x;
    temp->next = p->next;
    temp->prev = p;

    if (p->next) p->next->prev = temp;
    p->next = temp;
}

void dinsertBefore(int key, int x) {
    if (head == NULL) return;

    if (head->data == key) {
        dinsertBegin(x);
        return;
    }

    DNode* p = head;
    while (p && p->data != key) p = p->next;
    if (!p) return;

    DNode* temp = new DNode();
    temp->data = x;
    temp->next = p;
    temp->prev = p->prev;

    p->prev->next = temp;
    p->prev = temp;
}

void ddeleteNode(int key) {
    if (head == NULL) return;

    DNode* p = head;
    while (p && p->data != key) p = p->next;
    if (!p) return;

    if (p->prev) p->prev->next = p->next;
    else head = p->next;

    if (p->next) p->next->prev = p->prev;

    delete p;
}

void dsearchNode(int key) {
    DNode* p = head;
    int pos = 1;
    while (p) {
        if (p->data == key) {
            cout << "Found at position " << pos << endl;
            return;
        }
        p = p->next;
        pos++;
    }
    cout << "Not found\n";
}

void ddisplay() {
    DNode* p = head;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    int ch, x, key;
    while (1) {
        cout << "\nDOUBLY LL MENU\n";
        cout << "1 Insert Begin\n2 Insert End\n3 Insert After\n4 Insert Before\n";
        cout << "5 Delete\n6 Search\n7 Display\n8 Exit\n";
        cin >> ch;
        if (ch == 8) break;

        switch (ch) {
            case 1: cin >> x; dinsertBegin(x); break;
            case 2: cin >> x; dinsertEnd(x); break;
            case 3: cin >> key >> x; dinsertAfter(key, x); break;
            case 4: cin >> key >> x; dinsertBefore(key, x); break;
            case 5: cin >> key; ddeleteNode(key); break;
            case 6: cin >> key; dsearchNode(key); break;
            case 7: ddisplay(); break;
        }
    }
}

*/

/* 
   2) DISPLAY CIRCULAR LIST WITH HEAD REPEATED

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

int main() {
    int x;
    while (cin >> x && x != -1) {
        Node* t = new Node();
        t->data = x;
        if (head == NULL) {
            head = t;
            t->next = head;
        } else {
            Node* p = head;
            while (p->next != head) p = p->next;
            p->next = t;
            t->next = head;
        }
    }

    Node* p = head;
    do {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
    cout << head->data;
}

*/

/* 
   3) SIZE OF DOUBLY AND CIRCULAR LINKED LIST

#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* next;
    DNode* prev;
};

struct CNode {
    int data;
    CNode* next;
};

int sizeDLL(DNode* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

int sizeCLL(CNode* head) {
    if (head == NULL) return 0;
    int count = 0;
    CNode* p = head;
    do {
        count++;
        p = p->next;
    } while (p != head);
    return count;
}

int main() {
    // just logic, no main test needed
    return 0;
}

*/

/* 
   4) PALINDROME CHECK IN DOUBLY LINKED LIST

#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};

Node* head = NULL;

int main() {
    char c;
    while (cin >> c && c != '#') {
        Node* t = new Node();
        t->data = c;
        t->next = NULL;
        t->prev = NULL;

        if (head == NULL) head = t;
        else {
            Node* p = head;
            while (p->next) p = p->next;
            p->next = t;
            t->prev = p;
        }
    }

    Node* left = head;
    Node* right = head;

    while (right->next) right = right->next;

    while (left && right && left != right && right->next != left) {
        if (left->data != right->data) {
            cout << "Not Palindrome";
            return 0;
        }
        left = left->next;
        right = right->prev;
    }

    cout << "Palindrome";
}

*/

int main() { return 0; }
