// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct Node {
    T data;
    Node* next;
    explicit Node(const T& val, Node* nxt = nullptr) : data(val), next(nxt) {}
  };
  Node* head;

 public:
  TPQueue() : head(nullptr) {}

  ~TPQueue() {
    while (head) {
      Node* temp = head;
      head = head->next;
      delete temp;
    }
  }

  void push(const T& value) {
    Node* newNode = new Node(value);
    if (!head || head->data.prior < value.prior) {
      newNode->next = head;
      head = newNode;
    } else {
      Node* cur = head;
      while (cur->next && cur->next->data.prior >= value.prior) {
        cur = cur->next;
      }
      newNode->next = cur->next;
      cur->next = newNode;
    }
  }

  T pop() {
    if (!head) return T();
    Node* temp = head;
    T result = head->data;
    head = head->next;
    delete temp;
    return result;
  }

  bool isEmpty() const {
    return head == nullptr;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
