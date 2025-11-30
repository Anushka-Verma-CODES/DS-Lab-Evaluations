// //one
// #include <iostream>
// using namespace std;

// #define MAX 100

// class Stack {
//     int arr[MAX];
//     int top;
// public:
//     Stack() { top = -1; }
//     bool isEmpty() { return top == -1; }
//     bool isFull() { return top == MAX - 1; }
//     void push(int x) {
//         if (isFull()) {
//             cout << "Stack Overflow!\n";
//             return;
//         }
//         arr[++top] = x;
//         cout << x << " pushed to stack.\n";
//     }
//     void pop() {
//         if (isEmpty()) {
//             cout << "Stack Underflow!\n";
//             return;
//         }
//         cout << arr[top--] << " popped from stack.\n";
//     }
//     void display() {
//         if (isEmpty()) {
//             cout << "Stack is empty.\n";
//             return;
//         }
//         cout << "Stack elements: ";
//         for (int i = top; i >= 0; i--)
//             cout << arr[i] << " ";
//         cout << "\n";
//     }
//     void peek() {
//         if (isEmpty()) {
//             cout << "Stack is empty.\n";
//             return;
//         }
//         cout << "Top element: " << arr[top] << "\n";
//     }
// };

// int main() {
//     Stack s;
//     int choice, val;
//     do {
//         cout << "\nMenu:\n";
//         cout << "1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;
//         switch (choice) {
//             case 1:
//                 cout << "Enter value to push: ";
//                 cin >> val;
//                 s.push(val);
//                 break;
//             case 2:
//                 s.pop();
//                 break;
//             case 3:
//                 cout << (s.isEmpty() ? "Stack is empty.\n" : "Stack is not empty.\n");
//                 break;
//             case 4:
//                 cout << (s.isFull() ? "Stack is full.\n" : "Stack is not full.\n");
//                 break;
//             case 5:
//                 s.display();
//                 break;
//             case 6:
//                 s.peek();
//                 break;
//             case 7:
//                 cout << "Exiting...\n";
//                 break;
//             default:
//                 cout << "Invalid choice!\n";
//         }
//     } while (choice != 7);
//     return 0;
// }



// //two
// #include <iostream>
// #include <string>
// using namespace std;

// #define MAX 1000

// class CharStack {
//     char arr[MAX];
//     int top;
// public:
//     CharStack() { top = -1; }
//     bool isEmpty() { return top == -1; }
//     bool isFull() { return top == MAX - 1; }
//     void push(char x) {
//         if (isFull()) return;
//         arr[++top] = x;
//     }
//     char pop() {
//         if (isEmpty()) return '\0';
//         return arr[top--];
//     }
// };

// int main() {
//     string input;
//     cout << "Enter a string: ";
//     getline(cin, input);
//     CharStack s;
//     for (char ch : input) {
//         s.push(ch);
//     }
//     cout << "Reversed string: ";
//     while (!s.isEmpty()) {
//         cout << s.pop();
//     }
//     cout << endl;
//     return 0;
// }


// //three
// #include <iostream>
// #include <string>
// using namespace std;

// #define MAX 1000

// class CharStack {
//     char arr[MAX];
//     int top;
// public:
//     CharStack() { top = -1; }
//     bool isEmpty() { return top == -1; }
//     bool isFull() { return top == MAX - 1; }
//     void push(char x) {
//         if (isFull()) return;
//         arr[++top] = x;
//     }
//     char pop() {
//         if (isEmpty()) return '\0';
//         return arr[top--];
//     }
//     char peek() {
//         if (isEmpty()) return '\0';
//         return arr[top];
//     }
// };

// bool isBalanced(const string& expr) {
//     CharStack s;
//     for (char ch : expr) {
//         if (ch == '(' || ch == '[' || ch == '{') {
//             s.push(ch);
//         } else if (ch == ')' || ch == ']' || ch == '}') {
//             if (s.isEmpty()) return false;
//             char top = s.pop();
//             if ((ch == ')' && top != '(') ||
//                 (ch == ']' && top != '[') ||
//                 (ch == '}' && top != '{')) {
//                 return false;
//             }
//         }
//     }
//     return s.isEmpty();
// }

// int main() {
//     string expr;
//     cout << "Enter an expression: ";
//     getline(cin, expr);
//     if (isBalanced(expr))
//         cout << "Balanced parentheses.\n";
//     else
//         cout << "Unbalanced parentheses.\n";
//     return 0;
// }

// //four
// #include <iostream>
// #include <string>
// #include <cctype>
// #include <cmath>
// using namespace std;

// #define MAX 1000

// class CharStack {
//     char arr[MAX];
//     int top;
// public:
//     CharStack() { top = -1; }
//     bool isEmpty() { return top == -1; }
//     bool isFull() { return top == MAX - 1; }
//     void push(char x) {
//         if (isFull()) return;
//         arr[++top] = x;
//     }
//     char pop() {
//         if (isEmpty()) return '\0';
//         return arr[top--];
//     }
//     char peek() {
//         if (isEmpty()) return '\0';
//         return arr[top];
//     }
// };

// int precedence(char op) {
//     if (op == '^') return 3;
//     if (op == '*' || op == '/') return 2;
//     if (op == '+' || op == '-') return 1;
//     return 0;
// }

// string infixToPostfix(const string& infix) {
//     CharStack s;
//     string postfix = "";
//     for (char ch : infix) {
//         if (isalnum(ch)) {
//             postfix += ch;
//         } else if (ch == '(') {
//             s.push(ch);
//         } else if (ch == ')') {
//             while (!s.isEmpty() && s.peek() != '(') {
//                 postfix += s.pop();
//             }
//             if (!s.isEmpty()) s.pop(); // Remove '('
//         } else { // Operator
//             while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch)) {
//                 postfix += s.pop();
//             }
//             s.push(ch);
//         }
//     }
//     while (!s.isEmpty()) {
//         postfix += s.pop();
//     }
//     return postfix;
// }

// class IntStack {
//     int arr[MAX];
//     int top;
// public:
//     IntStack() { top = -1; }
//     bool isEmpty() { return top == -1; }
//     bool isFull() { return top == MAX - 1; }
//     void push(int x) {
//         if (isFull()) return;
//         arr[++top] = x;
//     }
//     int pop() {
//         if (isEmpty()) return 0;
//         return arr[top--];
//     }
//     int peek() {
//         if (isEmpty()) return 0;
//         return arr[top];
//     }
// };

// int evaluatePostfix(const string& expr) {
//     IntStack s;
//     for (size_t i = 0; i < expr.length(); ++i) {
//         char ch = expr[i];
//         if (isspace(ch)) continue;
//         if (isdigit(ch)) {
//             int num = 0;
//             while (i < expr.length() && isdigit(expr[i])) {
//                 num = num * 10 + (expr[i] - '0');
//                 i++;
//             }
//             i--;
//             s.push(num);
//         } else {
//             int val2 = s.pop();
//             int val1 = s.pop();
//             switch (ch) {
//                 case '+': s.push(val1 + val2); break;
//                 case '-': s.push(val1 - val2); break;
//                 case '*': s.push(val1 * val2); break;
//                 case '/': s.push(val1 / val2); break;
//                 case '^': s.push((int)pow(val1, val2)); break;
//             }
//         }
//     }
//     return s.pop();
// }

// int main() {
//     string infix;
//     cout << "Enter infix expression: ";
//     getline(cin, infix);
//     string postfix = infixToPostfix(infix);
//     cout << "Postfix expression: " << postfix << endl;

//     int result = evaluatePostfix(postfix);
//     cout << "Result: " << result << endl;

//     return 0;
// }

//five
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#define MAX 1000

class IntStack {
    int arr[MAX];
    int top;
public:
    IntStack() { top = -1; }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }
    void push(int x) {
        if (isFull()) return;
        arr[++top] = x;
    }
    int pop() {
        if (isEmpty()) return 0;
        return arr[top--];
    }
};

int evaluatePostfix(const string& expr) {
    IntStack s;
    for (char ch : expr) {
        if (isdigit(ch)) {
            s.push(ch - '0');
        } else if (ch == ' ') {
            continue;
        } else {
            int val2 = s.pop();
            int val1 = s.pop();
            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }
    return s.pop();
}

int main() {
    string postfix;
    cout << "Enter postfix expression (single-digit operands, no spaces needed): ";
    getline(cin, postfix);
    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;
    return 0;
}