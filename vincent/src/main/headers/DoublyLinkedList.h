#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>

// Define the Node structure as a template
template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;

    Node(const T& data) : data(data), prev(nullptr), next(nullptr) {}
};

// Define the Doubly Linked List class as a template
template <typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void addFront(const T& data);
    void addBack(const T& data);
    void remove(Node<T>* node);
    Node<T>* getHead() const;
    Node<T>* getTail() const;

    void printForward() const;
    void printBackward() const;

private:
    Node<T>* head;
    Node<T>* tail;
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node<T>* current = head;
    while (current) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
void DoublyLinkedList<T>::addFront(const T& data) {
    Node<T>* newNode = new Node<T>(data);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

template <typename T>
void DoublyLinkedList<T>::addBack(const T& data) {
    Node<T>* newNode = new Node<T>(data);
    if (!tail) {
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

template <typename T>
void DoublyLinkedList<T>::remove(Node<T>* node) {
    if (!node) return;

    if (node->prev) {
        node->prev->next = node->next;
    } else {
        head = node->next;
    }

    if (node->next) {
        node->next->prev = node->prev;
    } else {
        tail = node->prev;
    }

    delete node;
}

template <typename T>
Node<T>* DoublyLinkedList<T>::getHead() const {
    return head;
}

template <typename T>
Node<T>* DoublyLinkedList<T>::getTail() const {
    return tail;
}

template <typename T>
void DoublyLinkedList<T>::printForward() const {
    Node<T>* current = head;
    while (current) {
        std::cout << "Data: " << current->data << std::endl;
        current = current->next;
    }
}

template <typename T>
void DoublyLinkedList<T>::printBackward() const {
    Node<T>* current = tail;
    while (current) {
        std::cout << "Data: " << current->data << std::endl;
        current = current->prev;
    }
}

#endif // DOUBLYLINKEDLIST_H
