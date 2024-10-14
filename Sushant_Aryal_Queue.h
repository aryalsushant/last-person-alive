#ifndef SUSHANT_ARYAL_QUEUE_H
#define SUSHANT_ARYAL_QUEUE_H

#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Queue {
protected:
    queue<T> q;

public:
    void Enqueue(T data) {
        q.push(data);
    }

    bool Dequeue(T &data) {
        if (!q.empty()) {
            data = q.front();
            q.pop();
            return true;
        }
        return false;
    }

    int GetCount() const {
        return q.size();
    }

    bool IsEmpty() const {
        return q.empty();
    }
};

#endif // SUSHANT_ARYAL_QUEUE_H
