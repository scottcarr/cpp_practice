#include <iostream>

using namespace std;

class YahooNode {
public:
    YahooNode* next = nullptr;
    int n;
    YahooNode() : n(42) {}
    YahooNode(int d) { n = d; next = nullptr; }
    void print() {
        cout << n << "->";
        if (next != nullptr) {
            next->print();
        } else {
            cout << "nullptr\n";
        }
    }
};

YahooNode* makeLinkedList() {
    YahooNode* head = new YahooNode(1);
    YahooNode* curr = head;
    for (int i = 0; i < 2; ++i) {
        curr->next = new YahooNode(i+2);
        curr = curr->next;
    }
    curr->next = nullptr;
    return head;
}

YahooNode* doReverse(YahooNode* curr, YahooNode* prev) {
    if (curr->next == nullptr) {
        curr->next = prev;
        return curr;
    } else {
        YahooNode* tail = doReverse(curr->next, curr);
        curr->next = prev;
        return tail;
    }
}

YahooNode* reverseList(YahooNode* head) {
   doReverse(head, nullptr);
}

void testLinkedListRev() {
    YahooNode* l = makeLinkedList();
    //YahooNode* l = new YahooNode(42);
    l->print();
    YahooNode* r = reverseList(l);
    r->print();
    //cout << "hello world\n";
}
