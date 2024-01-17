#include <bits/stdc++.h>
using namespace std;


void bubbleSort(vector<int> &arr, int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<(n-i-1); j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(arr[j], arr[j+1]);
			}
		}
	}
}

void insertionSort(vector<int> &arr, int n)
{
	for(int i=1; i<n; i++)
	{
		int j=i;
		while(j>0 && arr[j] < arr[j-1])
		{
			swap(arr[j], arr[j-1]);
			j--;
		}
	}
}

void selectionSort(vector<int> &arr, int n)
{
	
	int minIndex = 0;
	for(int i=0; i<n; i++)
	{
		minIndex = i;
		// go and find the min element in the array
		for(int j=i+1; j<n; j++)
		{
			if(arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		// and finally swap the min elem with the min place
		swap(arr[i], arr[minIndex]);
	}
}

void print(vector<int> &arr, int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}


int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
	int n;
	cin>>n;
	vector<int> arr(n, 0);
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	bubbleSort(arr, n);
	print(arr, n);
	insertionSort(arr, n);
	print(arr, n);
	selectionSort(arr, n);
	print(arr, n);
}