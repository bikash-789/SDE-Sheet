#include <iostream>
#include <vector>
using namespace std;

//Find the median of two sorted arrays
#define INT_MIN -9999999
#define INT_MAX 9999999
double findMedian(vector<int> &a, vector<int> &b)
{
    if(b.size() < a.size())
    {
        return findMedian(b, a);
    }
    int n1 = a.size();
    int n2 = b.size();
    int low = 0, high = n1;
    while(low <= high)
    {
        int cut1 = (low+high)/2;
        int cut2 = (n1+n2+1)/2 - cut1;
        
        int left1 = cut1 == 0?INT_MIN:a[cut1-1];
        int left2 = cut2 == 0?INT_MIN:b[cut2-1];
        
        int right1 = cut1==n1?INT_MAX:a[cut1];
        int right2 = cut2==n2?INT_MAX:b[cut2];
        
        if(left1<=right2 && left2<=right1)
        {
            if((n1+n2)%2==0)
            {
                return (max(left1, left2)+min(right1, right2))/2.0;
            }
            else return max(left1, left2);
        }
        else if(left1 > right2)
        {
            high = cut1-1;
        }
        else low = cut1+1;
    }
    return 0.0;
}

double median(vector<int> a, vector<int> b)
{
    // Write your code here.
    return findMedian(a,b);
    
}

int main()
{
    int n1,n2;
    cin>>n1;
    vector<int> nums1, nums2;
    for(int i=0; i<n1; i++)
    {
        int temp1;
        cin>>temp1;
        nums1.push_back(temp1);
    }
    cin>>n2;
    for(int i=0; i<n2; i++)
    {
        int temp2;
        cin>>temp2;
        nums2.push_back(temp2);
    }
    cout<<median(nums1, nums2)<<endl;
}