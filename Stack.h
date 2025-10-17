#ifndef STACK_H
#define STACK_H

#include "stdafx.h"
#include "LinkedList.h"

template<typename T>
class Stack {
    private: 
        LinkedList<T> stack;
    public:
        Stack() = default;

    void push(const T& value) {
        stack.push_back(value);
    }

    void pop() {
        if (empty()) throw std::runtime_error("Stack is empty");
        stack.pop_back();
    }

    T& top() {
        if (empty()) throw std::runtime_error("Stack is empty");
        return stack.back();
    }

    const T& top() const {
        if (empty()) throw std::runtime_error("Stack is empty");
        return stack.back();
    }

    bool empty() const { return stack.empty(); }
    size_t size() const { return stack.get_size(); }

    void clear() {
        stack.clear();
    }
};

#endif