#include<iostream>
using namespace std;

template <typename T>
struct elem_q
{
    T inf;
    elem_q<T> * link;
};

template <typename T>
class Queue
{
public:
    Queue()
    {
        front = rear = NULL;
    }
    ~Queue()
    {
        deleteQueue();
    }
    Queue (const Queue &other)
    {
        copyQueue(other);
    }
    Queue &operator= (const Queue &other)
    {
        if(this != &other)
        {
            deleteQueue();
            copyQueue(other);
        }
        return *this;
    }

    bool empty() const
    {
        return rear == NULL;
    }
    void push(const T & x)
    {
        elem_q<T> *p = new elem_q<T>;
        p -> inf = x;
        p->link = NULL;
        if(rear)
            rear->link = p;
        else
            front = p;
        rear = p;
    }
    void pop(T & x)
    {
        if(!empty())
        {
            elem_q<T> *p = front;
            x = p->inf;
            if(p == rear)
            {
                rear = NULL;
                front = NULL;
            }
            else
                front = p->link;
            delete p;
        }
    }
    void head(T & x)const
    {
        if(!empty())
        {
            x = front->inf;
        }
    }
    void print()
    {
        T x;
        while(!empty())
        {
            pop(x);
            cout << x << " ";
        }
        cout << endl;
    }
    int length()
    {
        T x;
        int n = 0;
        while(!empty())
        {
            pop(x);
            n++;
        }
        return n;
    }
private:
    elem_q<T> *front,
              *rear;
    void copyQueue(const Queue &other)
    {
        front = rear = NULL;
        elem_q<T> *p = other.front;
        while(p)
        {
            push(p->inf);
            p = p->link;
        }
    }
    void deleteQueue()
    {
        T x;
        while(!empty())
            pop(x);
    }
};

int main()
{
    Queue<int> stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);
    stack1.push(6);
    Queue<int> stack2(stack1);
    int x;
    stack1.pop(x);
    stack1.print();
    cout << x << endl;
    stack2.head(x);
    cout << x << endl;
    cout << stack2.length() << endl;
    cin.sync();
    cin.get();
    return 0;
}
