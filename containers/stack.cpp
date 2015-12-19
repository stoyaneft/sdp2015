#include<iostream>
using namespace std;

template <typename T>
struct elem
{
    T inf;
    elem *link;
};

template <typename T = int>
class Stack
{
public:
    Stack()
    {
        start = NULL;
    }
    ~Stack()
    {
        deleteStack();
    }
    Stack(const Stack &other)
    {
        copyStack(other);
    }
    Stack &operator= (const Stack &other)
    {
        if(this != &other)
        {
            deleteStack();
            copyStack(other);
        }
        return *this;
    }

    bool empty() const
    {
        return start == NULL;
    }
    void push(const T& s)
    {
        elem<T> *p = start;
        start = new elem<T>;
        start->inf = s;
        start->link = p;
    }
    void pop(T& s)
    {
        if(start)
        {
            s = start -> inf;
            elem<T> *p = start;
            start = start -> link;
            delete p;
        }
    }
    void top(T& s) const
    {
        if(start)
        {
            s = start -> inf;
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
        int n = 0;
        T x;
        while(!empty())
        {
                       pop(x);
                       n++;
        }
        return n;
    }
private:
    elem<T> *start;
    void copyStack(const Stack& other)
    {
        if(other.start)
        {
            elem<T> *p = other.start,
                    *q = NULL,
                    *s = NULL;

            start = new elem<T>;
            assert(start != NULL);
            start->inf = p->inf;
            start->link =q;
            q = start;
            p = p -> link;
            while(p)
            {
                s = new elem<T>;
                s->inf = p -> inf;
                q->link = s;
                q = s;
                p = p->link;
            }
            q->link = NULL;
        }
        else
            start = NULL;
    }
    void deleteStack()
    {
        elem<T> *p;
        while(start)
        {
            p = start;
            start = start -> link;
            delete p;
        }
    }
};


//Example usage
int main()
{
    Stack<int> stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);
    stack1.push(6);
    Stack<int> stack2(stack1);
    int x;
    stack1.pop(x);
    stack1.print();
    cout << x << endl;
    stack2.top(x);
    cout << x << endl;
    cout << stack2.length() << endl;
    cin.sync();
    cin.get();
    return 0;
}
