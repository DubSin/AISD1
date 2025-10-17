#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "stdafx.h"

template<typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        
        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };
    
    Node* head;    
    Node* tail;    
    size_t size;   

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}
    
    ~LinkedList() {
        clear();
    }

    LinkedList(const LinkedList& other) : head(nullptr), tail(nullptr), size(0) {
        Node* current = other.head;
        while (current != nullptr) {
            push_back(current->data);
            current = current->next;
        }
    }

    LinkedList& operator=(const LinkedList& other) {
        if (this != &other) {
            clear();
            Node* current = other.head;
            while (current != nullptr) {
                push_back(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    void push_back(const T& value) {
        Node* newNode = new Node(value);
        
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void push_front(const T& value) {
        Node* newNode = new Node(value);
        
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void pop_back() {
        if (tail == nullptr) {
            throw std::runtime_error("Cannot pop from empty list");
        }
        
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        size--;
    }

    void pop_front() {
        if (head == nullptr) {
            throw std::runtime_error("Cannot pop from empty list");
        }
        
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        size--;
    }

    void insert(size_t position, const T& value) {
        if (position > size) {
            throw std::out_of_range("Position out of range");
        }
        
        if (position == 0) {
            push_front(value);
            return;
        }
        
        if (position == size) {
            push_back(value);
            return;
        }
        
        Node* current = head;
        for (size_t i = 0; i < position; i++) {
            current = current->next;
        }
        
        Node* newNode = new Node(value);
        newNode->prev = current->prev;
        newNode->next = current;
        current->prev->next = newNode;
        current->prev = newNode;
        
        size++;
    }

    void erase(size_t position) {
        if (position >= size) {
            throw std::out_of_range("Position out of range");
        }
        
        if (position == 0) {
            pop_front();
            return;
        }
        
        if (position == size - 1) {
            pop_back();
            return;
        }
        
        Node* current = head;
        for (size_t i = 0; i < position; i++) {
            current = current->next;
        }
        
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        size--;
    }

    bool remove(const T& value) {
        Node* current = head;
        size_t position = 0;
        
        while (current != nullptr) {
            if (current->data == value) {
                erase(position);
                return true;
            }
            current = current->next;
            position++;
        }
        return false;
    }

    bool contains(const T& value) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    T& at(size_t position) {
        if (position >= size) {
            throw std::out_of_range("Position out of range");
        }
        
        Node* current = head;
        for (size_t i = 0; i < position; i++) {
            current = current->next;
        }
        return current->data;
    }
    
    const T& at(size_t position) const {
        if (position >= size) {
            throw std::out_of_range("Position out of range");
        }
        
        Node* current = head;
        for (size_t i = 0; i < position; i++) {
            current = current->next;
        }
        return current->data;
    }

    T& operator[](size_t position) {
        return at(position);
    }
    
    const T& operator[](size_t position) const {
        return at(position);
    }

    size_t get_size() const {
        return size;
    }

    bool empty() const {
        return size == 0;
    }

    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    T& front() {
        if (size == 0) {
            throw std::runtime_error("Array is empty");
        }
        return at(0);
    }
    
    const T& front() const {
        if (size == 0) {
            throw std::runtime_error("Array is empty");
        }
        return at(0);
    }

    T& back() {
        if (size == 0) {
            throw std::runtime_error("Array is empty");
        }
        return at(size - 1);
    }
    
    const T& back() const {
        if (size == 0) {
            throw std::runtime_error("Array is empty");
        }
        return at(size - 1);
    }

    void print() const {
        Node* current = head;
        std::cout << "List: ";
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};


#endif