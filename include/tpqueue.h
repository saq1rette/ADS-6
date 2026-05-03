// Copyright 2026 <Student Name>

#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <stdexcept>

struct SYM {
    char ch;
    int prior;
};

template<typename T>
class TPQueue {
 private:
    struct Node {
        T data;
        Node* next;
        explicit Node(const T& item, Node* n = nullptr)
            : data(item), next(n) {}
    };

    Node* head;

 public:
    TPQueue() : head(nullptr) {}

    ~TPQueue() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void push(const T& item) {
        Node* newNode = new Node(item);
        if (isEmpty() || item.prior > head->data.prior) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr &&
               current->next->data.prior >= item.prior) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    T pop() {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty");
        }

        Node* temp = head;
        T result = head->data;
        head = head->next;
        delete temp;
        return result;
    }
};

#endif  // INCLUDE_TPQUEUE_H_
