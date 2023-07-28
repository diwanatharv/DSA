#include <iostream>
using namespace std;

struct deques {
    int front;
    int rear;
    int size;
    int *arr;
};

void enqueueback(deques *&q, int val) {
    if (q->rear + 1 == q->size) {
        cout << "Cannot insert from back. Deque is full." << endl;
        return;
    }
    if (q->front == -1 && q->rear == -1) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear++;
    }
    q->arr[q->rear] = val;
}

void enqueuefront(deques *&q, int val) {
    if ((q->front == 0 && q->rear == q->size - 1) || (q->front == q->rear + 1)) {
        cout << "Cannot insert from front. Deque is full." << endl;
        return;
    }

    if (q->front == -1 && q->rear == -1) {
        q->front = 0;
        q->rear = 0;
    } else if (q->front == 0) {
        q->front = q->size - 1;
    } else {
        q->front--;
    }

    q->arr[q->front] = val;
}

int dequeue_front(deques *&q) {
    if (q->front == -1 && q->rear == -1) {
        cout << "Cannot remove from front. Deque is empty." << endl;
        return -1; // You can return a specific value to indicate an error or handle it differently.
    }

    int temp = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else if (q->front == q->size - 1) {
        q->front = 0;
    } else {
        q->front++;
    }
    return temp;
}

int dequeue_back(deques *&q) {
    if (q->front == -1 && q->rear == -1) {
        cout << "Cannot remove from the back. Deque is empty." << endl;
        return -1; // You can return a specific value to indicate an error or handle it differently.
    }

    int temp = q->arr[q->rear];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else if (q->rear == 0) {
        q->rear = q->size - 1;
    } else {
        q->rear--;
    }
    return temp;
}

int main() {
    deques *d = new deques;
    d->front = -1;
    d->rear = -1;
    d->size = 4;
    d->arr = new int[d->size];

    enqueueback(d, 1);
    enqueueback(d, 2);
    enqueueback(d, 3);
    cout << dequeue_back(d) << endl;
    cout << dequeue_front(d) << endl;

    enqueuefront(d, 4);
    enqueuefront(d, 5);

    return 0;
}
