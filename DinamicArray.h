#ifndef DINAMICARRAY_H
#define DINAMICARRAY_H

#include "stdafx.h"

template<typename T>
class DynamicArray {
private:
    T* data;        
    size_t capacity;   
    size_t length;     

    void resize(size_t new_capacity) {
        T* new_data = new T[new_capacity];
        
        for (size_t i = 0; i < length; i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        
        data = new_data;
        capacity = new_capacity;
    }

public:
    DynamicArray() : data(nullptr), capacity(0), length(0) {}
    
    DynamicArray(size_t initial_capacity) : capacity(initial_capacity), length(0) {
        data = new T[capacity];
    }
    
    DynamicArray(const DynamicArray& other) : capacity(other.capacity), length(other.length) {
        data = new T[capacity];
        for (size_t i = 0; i < length; i++) {
            data[i] = other.data[i];
        }
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] data;
            
            capacity = other.capacity;
            length = other.length;
            data = new T[capacity];

            for (size_t i = 0; i < length; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
    
    ~DynamicArray() {
        delete[] data;
    }

    void push_front(const T& value){
        if (length >= capacity) {
            size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
            resize(new_capacity);
        }
        for (size_t i = length; i > 0; i--) {
            data[i] = data[i - 1];
        }
        data[0] = value;
        length++;

    }
    
    void push_back(const T& value) {
        if (length >= capacity) {
            size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
            resize(new_capacity);
        }
        
        data[length] = value;
        length++;
    }
    
    void pop_back() {
        if (length == 0) {
            throw std::runtime_error("Cannot pop from empty array");
        }
        length--;
        
        if (length > 0 && length <= capacity / 4) {
            resize(capacity / 2);
        }
    }

    void pop_front() {
        if (length == 0) {
            throw std::runtime_error("Cannot pop from empty array");
        }

        for (size_t i = 0; i < length - 1; i++) {
            data[i] = data[i + 1];
        }
        
        length--;
        
        if (length > 0 && length <= capacity / 4) {
            resize(capacity / 2);
        }
    }

    void insert(size_t index, const T& value) {
        if (index > length) {
            throw std::out_of_range("Index out of range");
        }

        if (length >= capacity) {
            size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
            resize(new_capacity);
        }
        
        for (size_t i = length; i > index; i--) {
            data[i] = data[i - 1];
        }
        
        data[index] = value;
        length++;
    }
    
    void erase(size_t index) {
        if (index >= length) {
            throw std::out_of_range("Index out of range");
        }
        
        for (size_t i = index; i < length - 1; i++) {
            data[i] = data[i + 1];
        }
        
        length--;
        
        if (length > 0 && length <= capacity / 4) {
            resize(capacity / 2);
        }
    }

    T& operator[](size_t index) {
        if (index >= length){
            throw std::out_of_range("Position out of range");
        }
        return data[index];
    }
    
    const T& operator[](size_t index) const {
        if (index >= length){
            throw std::out_of_range("Position out of range");
        }
        return data[index];
    }

    T& front() {
        if (length == 0) {
            throw std::runtime_error("Array is empty");
        }
        return data[0];
    }
    
    const T& front() const {
        if (length == 0) {
            throw std::runtime_error("Array is empty");
        }
        return data[0];
    }

    T& back() {
        if (length == 0) {
            throw std::runtime_error("Array is empty");
        }
        return data[length - 1];
    }
    
    const T& back() const {
        if (length == 0) {
            throw std::runtime_error("Array is empty");
        }
        return data[length - 1];
    }

    size_t get_size() const {
        return length;
    }

    size_t get_capacity() const {
        return capacity;
    }

    bool empty() const {
        return length == 0;
    }

    void clear() {
        length = 0;
        if (capacity > 1) {
            resize(1);
        }
    }

    T& find(const T& value) const {
        for (size_t i = 0; i < length; i++) {
            if (data[i] == value) {
                return i;
            }
        }
        return -1; 
    }

    void print() const {
        std::cout << "Array (size: " << length << ", capacity: " << capacity << "): ";
        for (size_t i = 0; i < length; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
    
    void sort() {
        for (size_t i = 0; i < length - 1; i++) {
            for (size_t j = 0; j < length - i - 1; j++) {
                if (data[j] > data[j + 1]) {
                    std::swap(data[j], data[j + 1]);
                }
            }
        }
    }
};


#endif
