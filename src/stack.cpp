#include <iostream>

using namespace std;

namespace Stack {

class StackNode {
public:
    StackNode* next = nullptr;
    int data;
    StackNode(int n) : data(n) {}
};

class LStackNodeIter {
public:
    StackNode* curr;
    LStackNodeIter(StackNode* head) : curr(head) {}
    bool operator!=(const LStackNodeIter& other) {
        return curr != other.curr;
    }
    StackNode* operator*() {
        return curr;
    }
    const LStackNodeIter& operator++() {
        curr = curr->next;
        return *this;
    }
};

class LStack {
    StackNode* head = nullptr;
public:
    void push(int n) {
        StackNode* node = new StackNode(n);
        if (head) {
            node->next = head;
            head = node;
        }
        head = node;
    }
    LStackNodeIter end() const {
        return LStackNodeIter(nullptr);
    }
    LStackNodeIter begin() const {
        return LStackNodeIter(head);
    }
    bool pop(int* rv) {
        if (head) {
           *rv = head->data;
           StackNode *dead = head;
           head = head->next;
           delete head;
           return true;
        } else {
            return false;
        }
    }
};

ostream& operator<< (ostream& os, const LStack& stack) {
    for (auto n : stack) {
        os << n->data;
        os << "->";
    }
    os << "nullptr";
    return os;
}

void testStack() {
    LStack s;
    int rv;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s << endl;
    if (s.pop(&rv)) {
        cout << "popped: " << rv << endl;
    } else {
        cout << "failed to pop" << endl;
    }
    cout << s << endl;
}

} // end namespace Stack
