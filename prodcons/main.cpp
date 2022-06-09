#include <thread>
#include <mutex>
#include <iostream>
#include <deque>
#include <condition_variable>
using namespace std;

mutex mtx;
condition_variable cv;
condition_variable notFullCv;
condition_variable notEmptyCv;
const int maxDequeSize = 30;
// 共享资源（工厂）
struct item {
    deque<int> dq;
    int size;
    item() : size(0) {}
};
item* items = new item();

void produce() {
    while (1) {    
        unique_lock<mutex> lock(mtx);
        // if (items->size >= maxDequeSize) {
        //     cv.notify_all();
        //     return;
        // }

        // items->size < maxDequeSize 继续执行； 否则（items->size >= maxDequeSize），被wait住
        notFullCv.wait(lock, []()
                    { return items->size < maxDequeSize; });
        // 生产
        items->dq.push_back(111);
        items->size++;
        // cv.notify_all();
        // 通知消费者线程消费
        notEmptyCv.notify_all();
    }
}
void consume() {
    while (1) {
        unique_lock<mutex> lock(mtx);
        // while (items->size == 0) {
        //     cv.wait(lock);
        //     // return;
        // }

        // items->size > 0 继续执行； 否则(items->size <= 0)， 被wait住
        notEmptyCv.wait(lock, []()
                        { return items->size > 0; });
        // 消费
        items->dq.pop_front();
        items->size--;
        // 通知生产者线程生产
        notFullCv.notify_all();
    }
}
int main() {

    return 0;
};