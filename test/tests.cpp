#include "../include/tpqueue.h"
#include <iostream>
#include <cassert>

void testPriorityQueue() {
    TPQueue<SYM> pqueue;

    // Тест 1: добавление и извлечение
    pqueue.push(SYM{'a', 4});
    pqueue.push(SYM{'b', 7});
    pqueue.push(SYM{'c', 1});
    pqueue.push(SYM{'d', 10});
    pqueue.push(SYM{'e', 5});

    // Ожидаемый порядок: d(10), b(7), e(5), a(4), c(1)
    SYM sym = pqueue.pop();
    assert(sym.ch == 'd' && sym.prior == 10);
    
    sym = pqueue.pop();
    assert(sym.ch == 'b' && sym.prior == 7);
    
    sym = pqueue.pop();
    assert(sym.ch == 'e' && sym.prior == 5);
    
    sym = pqueue.pop();
    assert(sym.ch == 'a' && sym.prior == 4);
    
    sym = pqueue.pop();
    assert(sym.ch == 'c' && sym.prior == 1);
    
    std::cout << "All tests passed!" << std::endl;
}

void testEmptyQueue() {
    TPQueue<SYM> pqueue;
    assert(pqueue.isEmpty());
    
    pqueue.push(SYM{'x', 3});
    assert(!pqueue.isEmpty());
    
    pqueue.pop();
    assert(pqueue.isEmpty());
    
    std::cout << "Empty queue test passed!" << std::endl;
}

int main() {
    testPriorityQueue();
    testEmptyQueue();
    return 0;
}
