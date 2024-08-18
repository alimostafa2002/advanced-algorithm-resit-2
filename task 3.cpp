#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* header;
    Node* trailer;

    DoublyLinkedList() {
        header = new Node();
        trailer = new Node();
        header->next = trailer;
        trailer->prev = header;
    }

    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->prev = header;
        newNode->next = trailer;
        header->next = newNode;
        trailer->prev = newNode;
    }

    Node* findMiddle() {
        Node* slow = header->next; // Start from the first real node
        Node* fast = header->next; // Start from the first real node

        while (fast != trailer && fast->next != trailer) {
            slow = slow->next;       // Move slow by one
            fast = fast->next->next; // Move fast by two
        }
        return slow; // Return the middle node
    }
};

int main() {
    DoublyLinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    Node* middle = list.findMiddle();
    std::cout << "Middle Node: " << middle->data << std::endl;

    return 0;
}