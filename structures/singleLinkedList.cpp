#include <iostream>

struct Node {
    int val;
    Node* next;
};

struct singleLinkedIntList {
    Node* first;
    Node* last;


    Node* getElementByIndex(int index) {
        if (isEmpty()) throw;
        if (length() <= index) throw;
        if (index < 0) index += length();
        Node* current = first;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current;
    }


    int elem(int index) {
        return getElementByIndex(index)->val;
    }


    void print() {
        if (isEmpty()) return;
        Node* current = first;
        while (current) {
            std::cout << current->val << "\t";
            current = current->next;
        }
        std::cout << std::endl;
    }


    int length() {
        if (isEmpty()) return 0;
        int counter = 1;
        Node* current = first;
        while (current != last) {
            counter++;
            current = current->next;
        }
        return counter;
    }


    bool isEmpty() {
        return first == nullptr;
    }


    void append(int value) {
        Node* elem = new Node();
        elem->val = value;
        if (isEmpty()) {
            first = elem;
            last = elem;
            return;
        }
        last->next = elem;
        last = elem;
    }


    void pop(int index) {
        if ((index == 0) && (length() == 1)) {
            first = nullptr;
            return;
        }
        if (index == 0) {
            first = getElementByIndex(1);
            return;
        }
        if (index == length() - 1) {
            last = getElementByIndex(index - 1);
            last->next = nullptr;
            return;
        }
        getElementByIndex(index - 1)->next = getElementByIndex(index + 1);
        return;
    }


    void duplicate(int index) {
        Node* elem = getElementByIndex(index);
        Node* duplicated = new Node();
        duplicated->val = elem->val;
        duplicated->next = elem->next;
        elem->next = duplicated;
    }


    void swap(int index1, int index2) {
        if (index1 < 0) throw;
        if (index2 < 0) throw;
        if (index1 == index2) return;
        if (index2 < index1) {
            int swap = index2;
            index2 = index1;
            index1 = swap;
        }

        Node* swap1 = getElementByIndex(index1);
        Node* swap2 = getElementByIndex(index2);

        int temp = swap1->val;
        swap1->val = swap2->val;
        swap2->val = temp;
    }
};