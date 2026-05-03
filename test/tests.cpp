// Copyright 2026 <Student Name>

#include <cassert>
#include "../include/tpqueue.h"

void testPriorityQueue() {
    TPQueue<SYM> pqueue;

    pqueue.push(SYM{'a', 4});
    pqueue.push(SYM{'b', 7});
    pqueue.push(SYM{'c', 1});
    pqueue.push(SYM{'d', 10});
    pqueue.push(SYM{'e', 5});

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
}

void testEmptyQueue() {
    TPQueue<SYM> pqueue;
    assert(pqueue.isEmpty());

    pqueue.push(SYM{'x', 3});
    assert(!pqueue.isEmpty());

    pqueue.pop();
    assert(pqueue.isEmpty());
}
