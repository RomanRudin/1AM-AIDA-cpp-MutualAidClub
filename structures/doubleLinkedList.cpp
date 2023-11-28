#include <iostream>

struct Node {
    int val;
    Node* next;
    Node* previous;
};

struct doubleLinkedIntList {
    Node* root;


    void print() { //Ready
        if (isEmpty()) return;
        Node* current = root->next;
        while (current != root) {
            std::cout << current->val << "\t";
            current = current->next;
        }
        std::cout << std::endl;
        return;
    }


    int length() { //Ready
        if (isEmpty()) return 0;
        int counter = 0;
        Node* current = root->next;
        while (current != root) {
            counter++;
            current = current->next;
        }
        return counter;
    }


    bool isEmpty() { //Ready
        return root->next == nullptr;
    }


    void appendLeft(int value) { //Ready
        Node* elem = new Node();
        elem->val = value;
        if (isEmpty()) {
            elem->next = root;
            elem->previous = root;
            root->next = elem;
            root->previous = elem;
            return;
        }
        elem->previous = root;
        elem->next = root->next;
        root->next->previous = elem;
        root->next = elem;
        return;
    }


    void appendRight(int value) { //Ready
        Node* elem = new Node();
        elem->val = value;
        if (isEmpty()) {
            elem->next = root;
            elem->previous = root;
            root->next = elem;
            root->previous = elem;
            return;
        }
        elem->previous = root->previous;
        elem->next = root;
        root->previous->next = elem;
        root->previous = elem;
        return;
    }


    void pop(Node* elem) { //Ready
        if ((elem->next == root) || (elem->previous == root)) {
            elem->previous->next = root;
            elem->next->previous = root;
            return;
        }
        elem->previous->next = elem->next;
        elem->next->previous = elem->previous;
        return;
    }


    void duplicate(Node* element) { //Ready
        Node* duplicated = new Node();
        duplicated->val = element->val;
        duplicated->previous = element;
        duplicated->next = element->next;
        element->next->previous = duplicated;
        element->next = duplicated;
        return;
    }


    void swap(Node* elem1, Node* elem2) {
        int temp = elem1->val;
        elem1->val = elem2->val;
        elem2->val = temp;
        return;
    }
};