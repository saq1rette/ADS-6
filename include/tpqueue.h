#ifndef TPQUEUE_H
#define TPQUEUE_H

#include <stdexcept> // для std::runtime_error

// Структура SYM (может быть передана как шаблонный параметр T)
struct SYM {
    char ch;
    int prior;
};

template<typename T>
class TPQueue {
private:
    // Узел односвязного списка
    struct Node {
        T data;
        Node* next;
        Node(const T& item, Node* n = nullptr) : data(item), next(n) {}
    };

    Node* head; // указатель на начало очереди (элемент с наибольшим приоритетом)

public:
    // Конструктор
    TPQueue() : head(nullptr) {}

    // Деструктор (освобождаем память)
    ~TPQueue() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Проверка на пустоту
    bool isEmpty() const {
        return head == nullptr;
    }

    // Добавление элемента с учетом приоритета (O(n))
    void push(const T& item) {
        Node* newNode = new Node(item);

        // Если очередь пуста или новый элемент имеет приоритет выше первого
        if (isEmpty() || item.prior > head->data.prior) {
            newNode->next = head;
            head = newNode;
            return;
        }

        // Ищем место для вставки (список отсортирован по убыванию prior)
        Node* current = head;
        while (current->next != nullptr && current->next->data.prior >= item.prior) {
            current = current->next;
        }

        // Вставляем после current
        newNode->next = current->next;
        current->next = newNode;
    }

    // Извлечение элемента из головы (O(1))
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

#endif // TPQUEUE_H
