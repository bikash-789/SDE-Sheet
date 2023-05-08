#include <iostream>
using namespace std;

int sumOfDigits(int num)
{
    // BASE CASE
    if(num < 10)
    {
        return num;
    }

    // ASSUME THAT IT WORKS FOR (N-1)th TERM - hypothesis
    int leftSum = sumOfDigits(num/10);

    // DO THE WORK FOR N-th TERM
    return leftSum + num%10;
}

int main()
{
    int n;
    cin>>n;
    cout<<sumOfDigits(n)<<endl;
}