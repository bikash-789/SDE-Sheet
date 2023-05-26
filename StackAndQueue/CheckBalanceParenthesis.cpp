#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string exp)
{
    // Initialize a stack
    stack<char> st;
    int i=0; 
    while(i<exp.length())
    {
        if(exp[i] == 40 || exp[i] == 91 || exp[i] == 123)
        {
            st.push(exp[i]);
        }
        else if(exp[i] == 41 || exp[i] == 93 || exp[i] == 125)
        {
            if(st.empty())
            {
                return false;
            }
            char out = st.top();
            st.pop();
            if(out == 40 && exp[i] != 41 || out == 91 && exp[i] != 93 || out == 123 && exp[i]!= 125)
            {
                return false;
            }
        }
        i++;
    }
    return true;
}

int main()
{
    string exp;
    cin>>exp;

    if(isBalanced(exp)) cout<<"True";
    else cout<<"False";
}