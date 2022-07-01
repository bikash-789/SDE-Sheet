#include <iostream>
using namespace std;

//Problem 1
void printName(int n, string name)
{
    //base case
    if(n==0)
        return;

    //Do some work
    cout<<name<<endl;

    //recursive call (let recursion do the rest of work)
    printName(n-1, name);
}

//Problem 2
void printNum(int n)
{
    //base case
    if(n==0)
        return;
    
    //recursion call
    printNum(n-1);

    //small work
    cout<<n<<endl;
}

//Problem 3
void printNumRev(int n)
{
    //base case
    if(n==0)
    {
        return;
    }

    //small work
    cout<<n<<endl;

    //recursive call
    printNumRev(n-1);
}

//Problem 4
int sumOfFirstN(int n)
{
    //base case
    if(n==0)
        return 0;
    
    //recursive call
    int smallAns = sumOfFirstN(n-1);

    //small work
    return smallAns+n;
}

//Problem 5
int fact(int n)
{
    //base case
    if(n==0)
        return 1;
    
    //recursive call
    int smallAns = fact(n-1);

    //small work
    return smallAns * n;
}

//Problem 6
void reverseArray(int arr[], int l, int r)
{
    //base case
    if(l>=r) return;

    //small work
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;

    //recursive call
    reverseArray(arr, l+1, r-1);
}

//Problem 7
bool isPalindrome(string s, int l, int r)
{
    //base case
    if(l>=r) return true;

    //small work
    if(s[l]!=s[r]) return false;

    //recursive call
    return isPalindrome(s, l+1, r-1);

}

int main()
{

    /*

    string name="Bikash Chauhan";
    printName(10, name);

    printNum(5);

    printNumRev(5);

    cout<<sumOfFirstN(5)<<endl;

    cout<<fact(5)<<endl;


    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    reverseArray(arr, 0, n-1);


    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }


    string s;
    cin>>s;
    int n = s.length();
    cout<<isPalindrome(s, 0, n-1)<<endl;
    
    */
   
   
}