#include <bits/stdc++.h>
using namespace std;

/* ---------------------- 5) Linked List Loop Detection ---------------------- */

class Node {
public:
    int data;
    Node* next;
    Node(int d) : data(d), next(NULL) {}
};

bool hasCycle(Node* head) {
    unordered_set<Node*> visited;
    while(head) {
        if(visited.count(head)) return true;
        visited.insert(head);
        head = head->next;
    }
    return false;
}

/* ---------------------- 6) Binary Tree Duplicate Check ---------------------- */

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v): val(v), left(NULL), right(NULL) {}
};

bool containsDuplicate(TreeNode* root, unordered_set<int> &s) {
    if(!root) return false;
    if(s.count(root->val)) return true;
    s.insert(root->val);
    return containsDuplicate(root->left,s) || containsDuplicate(root->right,s);
}

int main() {

    /* ---------------------- 1) Check Duplicate in Array ---------------------- */
    vector<int> nums = {1,2,3,1};
    
    cout << "1) Contains Duplicate: ";
    unordered_set<int> s;
    bool found = false;
    for(int x : nums){
        if(s.count(x)){ found = true; break; }
        s.insert(x);
    }
    cout << (found ? "true" : "false") << endl;

    /* ---------------------- 2) Common Elements in Two Arrays ---------------------- */
    cout << "\n2) Common Elements: ";
    vector<int> A = {1,2,3,4}, B = {3,4,5,6};
    unordered_set<int> setA(A.begin(), A.end());
    for(int x : B) if(setA.count(x)) cout << x << " ";
    cout << endl;

    /* ---------------------- 3) Frequency Count ---------------------- */
    cout << "\n3) Frequency Count:\n";
    vector<int> arr = {2,3,2,4,3,2};
    unordered_map<int,int> freq;
    for(int x : arr) freq[x]++;
    for(auto &p : freq) {
        cout << p.first << " → " << p.second << " times\n";
    }

    /* ---------------------- 4) First Non-Repeating Element ---------------------- */
    cout << "\n4) First Non-Repeating: ";
    vector<int> arr2 = {4,5,1,2,0,4};
    unordered_map<int,int> mp;
    for(int x : arr2) mp[x]++;
    for(int x : arr2) {
        if(mp[x] == 1){
            cout << x << endl;
            break;
        }
    }

    /* ---------------------- 5) Linked List Cycle ---------------------- */
    cout << "\n5) Linked List Contains Loop: ";
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next; // loop

    cout << (hasCycle(head) ? "true" : "false") << endl;

    /* ---------------------- 6) Binary Tree Duplicate ---------------------- */
    cout << "\n6) Duplicate in Binary Tree: ";
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->right = new TreeNode(5); // duplicate

    unordered_set<int> st;
    cout << (containsDuplicate(root, st) ? "Duplicates Found" : "No Duplicates") << endl;

    return 0;
}
