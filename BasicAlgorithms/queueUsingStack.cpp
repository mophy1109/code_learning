//使用2个栈来实现队列的操作，包括插入（appendTail）、弹出（deleteHead）

#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class CQueue {
public:
    CQueue(void);
    ~CQueue(void);

    void appendTail(const T &node);
    T deleteHead();

private:
    stack<T> stack1;
    stack<T> stack2;
};

template <typename T>
void CQueue<T>::appendTail(const T &element)
{
    stack1.push(element);
}

template <typename T>
T CQueue<T>::deleteHead()
{
    if (stack2.empty()) {
        while (!stack1.empty()) {
            T tmp = stack1.top();
            stack2.push(tmp);
            stack1.pop();
        }
    }

    if (stack2.empty())
        throw new exception("queue is empty");
    result = stack2.top();
    stack2.pop();
    return result;
}

