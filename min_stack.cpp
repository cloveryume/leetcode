#include <stack>

struct MinusElem
{
    int count;
    int data;
};

class MinStack
{
public:
    void push(int x)
    {
        s.push(x);
        if (!minus.empty() && x >= minus.top().data)
            ++(minus.top().count);
        else
        {
            MinusElem e = {1, x};
            minus.push(e);
        }
    }

    void pop()
    {
        s.pop();

        MinusElem &e = minus.top();
        if (--e.count == 0)
            minus.pop();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return minus.top().data;
    }

private:
    std::stack<int> s;
    std::stack<MinusElem> minus;
};
