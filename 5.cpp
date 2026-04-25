// Check if parentheses are balanced using a stack
#include <bits/stdc++.h>
using namespace std;

bool match(char open, char close)
{
    return ((open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']'));
}

int main()
{
    string s;
    bool flag = true;
    cout << "Enter a string:";
    cin >> s;
    stack<char> st;
    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        else
        {
            if (st.empty() || match(st.top(), c) == false)
            {
                flag = false;
                break;
            }
            st.pop();
        }
    }
    if (flag && st.empty())
        cout << "Balanced";
    else
        cout << "Not Balanced";
}