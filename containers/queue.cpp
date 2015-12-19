#include<iostream>
using namespace std;

template <typename T>
struct elem_link1
{
    T inf;
    elem_link1<T> *link;
};

template <typename T>
class LList
{
public:
    LList()
    {
        start = end = NULL;
    }
    ~LList()
    {
        deleteList();
    }
    LList(const LList &other)
    {
        copyList(other);
    }
    LList &operator= (const LList &other)
    {
        if(this != &other)
        {
            deleteList();
            copyList(other);
        }
        return * this;
    }

    bool empty() const
    {
        return start == NULL;
    }
    void iterStart(elem_link1<T> *p = NULL) //
    {
        if(p)
            current = p;
        else
            current = start;
    }
    elem_link1<T> *iter() // I?aianoaa current-a ia neaaaauaoa iiceoey, ii a?uua oaeouaoa eooey
    {
        elem_link1<T> *p = current;
        if(current)
            current = current->link;
        return p;
    }
    void toEnd(const T &x)
    {
        elem_link1<T> *p = end;
        end = new elem_link1<T>;
        end->inf = x;
        end->link = NULL;
        if(p)
            p->link = end;
        else
            start = end;
    }
    void insertAfter(elem_link1<T> * p, const T& x)
    {
            elem_link1<T> *q = new elem_link1<T>;
            q->inf = x;
            q->link = p->link;
            if(p == end)
                end = q;
            p->link = q;
    }
    void insertBefore(elem_link1<T> *p, const T& x)
    {
        elem_link1<T> *q = new elem_link1<T>;
        *q = *p;
        if(p == end)
            end = q;
        p->inf = x;
        p->link = q;
    }
    void deleteAfter(elem_link1<T> *p, T& x)
    {
        if(p->link)
        {
            elem_link1<T> *q = p->link;
            x = q->inf;
            p->link = q->link;
            if(q == end)
                end = p;
            delete q;
        }
    }
    void deleteBefore(elem_link1<T> *p, T& x)
    {
        if(p != start)
        {
            elem_link1<T> *q = start;
            while(q->link != p)
                q = q->link;
            deleteElem(q,x);
        }
    }
    void deleteElem(elem_link1<T> *p, T& x)
    {
        if(p == start)
        {
            x = p->inf;
            if(start == end)
                start = end = NULL;
            else
                start = start ->link;
            delete p;
        }
        else
        {
            elem_link1<T> *q = start;
            while(q->link != p)
                q = q->link;
            deleteAfter(q,x);
        }
    }

    void print() const
    {
        elem_link1<T> *p = start;
        while(p)
        {
            cout << p->inf << " ";
            p = p->link;
        }
        cout << endl;
    }
    int length() const
    {
        elem_link1<T> *p = start;
        int n = 0;
        while(p)
        {
            n++;
            p = p->link;
        }
        return n;
    }
    void concat(const LList &r)
    {
        elem_link1<T> *p = r.start;
        while(p)
        {
            toEnd(p->inf);
            p = p->link;
        }
    }
private:
    elem_link1<T> *start,
                  *end,
                  *current; // Oeacaoaey ae eui oaeouey aeaiaio.
    void copyList(const LList & other)
    {
        start = end = current = NULL;
        elem_link1<T> *p = other.start;
        while(p)
        {
            toEnd(p->inf);
            p = p->link;
        }
    }
    void deleteList()
    {
        elem_link1<T> *p;
        while(start)
        {
            p = start;
            start = start->link;
            delete p;
        }
        end = NULL;
    }
};

int main()
{
    LList<int> list;
    list.toEnd(1);
    list.toEnd(2);
    list.toEnd(3);
    list.toEnd(4);
    list.toEnd(5);

    list.print();
    LList<int> list2(list);
    list2.concat(list);
    list2.print();
    list2.iterStart();
    cout << " Iter" << endl;
    elem_link1<int> *p = list2.iter();
    while(p != NULL)
    {
        cout << p->inf << " ";
        p = p->link;
    }
    cout << endl;
    cin.sync();
    cin.get();
    return 0;
}
