//使用两个队列实现栈的push、pop操作

template <typename T> class CStack{
    public:
    CStack(void);
    ~CStack(void);

    void push(const T& element);
    T pop();

    private:
    queue<T> queue1;
    queue<T> queue2;
};

template <typename T>
void push(const T& element)
{
    if (queue2.empty()){
        queue1.push(element);
    }else{
        queue2.push(element);
    }
}

template <typename T>
T pop(){
    T tail;
    if(queue2.empty()){
        if (queue1.empty())
            throw new exception("queue is empty");
        tail = queue1.top();
        queue1.pop();
        while(!queue1.empty()){
            queue2.push(tail);
            tail = queue1.top();
            queue1.pop();
        }
        return tail;
    }else if(queue1.empty()){
        tail = queue2.top();
        queue1.pop();
        while(!queue1.empty()){
            queue1.push(tail);
            tail = queue2.top();
            queue1.pop();
        }
        return tail;
    }else{//!queue1.empty()&&!queue2.empty
        throw new exception("error");
        return;
    }
}

