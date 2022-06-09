#include <thread>
#include <mutex>
#include <iostream>
#include <deque>
#include <condition_variable>
using namespace std;

mutex mtx;
condition_variable cv;
const int maxDequeSize = 30;
// 共享资源（工厂）
struct item {
    deque<int> dq;
    int size;
    item() : size(0) {}
};
item* items = new item();

void produce() {
    unique_lock<mutex> lock(mtx);
    if (items->size >= maxDequeSize) {
        cv.notify_all();
        return;
    }
    // 生产
    items->dq.push_back(111);
    items->size++;
    cv.notify_all();
}
void consume() {
    unique_lock<mutex> lock(mtx);
    while (items->size == 0) {
        cv.wait(lock);
        // return;
    }
    // 消费
    items->dq.pop_front();
    items->size--;
}
int main() {

    return 0;
};