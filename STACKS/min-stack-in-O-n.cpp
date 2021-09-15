stack<int> x;
void push(stack<int> &s, int a)
{
    // Your code goes here
    s.push(a);
    if (x.empty() || x.top() >= a)
    {
        x.push(a);
    }
}

bool isFull(stack<int> &s, int n)
{
    // Your code goes here
    return s.size() == n;
}

bool isEmpty(stack<int> &s)
{
    // Your code goes here
    return s.empty();
}

int pop(stack<int> &s)
{
    // Your code goes here
    if (!s.empty())
    {
        int a = s.top();
        s.pop();
        if (a == x.top())
        {
            x.pop();
        }
        return a;
    }
}

int getMin(stack<int> &s)
{
    if (x.size() == 0)
        return -1;
    return x.top();
}