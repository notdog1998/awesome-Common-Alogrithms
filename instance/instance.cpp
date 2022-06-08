#include <thread>
#include <mutex>
// 懒汉模式
class single1 {
private:
    // 私有静态指针变量指向唯一实例
    static single1 *p;
    // 静态锁，是由于静态函数只能访问静态成员
    static std::mutex mtx;

    // 私有化构造函数，单例模式的设计思路
    single1() {}
    ~single1() {}
public:
    // 公有静态方法获取实例
    static single1 *getInstance();
};
// 静态成员声明
std::mutex single1::mtx;

single1* single1::p = NULL;
single1* single1::getInstance() {
    // 双锁检测
    // 核心思想是在 new时一定是要上锁的， 防止两个线程同时getInstance 生成两个实例
    if (p == NULL) {
        std::unique_lock<std::mutex> lock(mtx);
        if (p == NULL) {
            p = new single1();
        }
    }
    return p;
};


// C++11 线程安全的懒汉模式
class single2 {
private:
    // 类内不在需要指向单例的指针 也不要锁
    // static single2 *p;

    // 私有化构造函数，单例模式的设计思路
    single2() {}
    ~single2() {}
public:
    // 公有静态方法获取实例
    static single2 *getInstance();
};
single2* single2::getInstance() {
    // 静态变量保证此变量在程序生命周期只有一份，且在第一次调用时初始化
    static single2 obj;
    return &obj;
}

// 饿汉模式
class single3 {
private:
    // 私有静态指针变量指向唯一实例
    static single3 *p;

    // 私有化构造函数，单例模式的设计思路
    single3() {}
    ~single3() {}
public:
    // 公有静态方法获取实例
    static single3 *getInstance();
};
// 在main函数之前就new出来
single3* single3::p = new single3();
single3* single3::getInstance() { 
        return p; 
}