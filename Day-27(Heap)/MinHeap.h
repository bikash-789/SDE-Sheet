#include <vector>
class MinHeap
{
private:
    std::vector<int> arr;

public:
    MinHeap()
    {
    }

    void push(int elem)
    {
        arr.push_back(elem);
        int childIndex = arr.size() - 1;

        //up heapify
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (arr[childIndex] < arr[parentIndex])
            {
                int temp = arr[childIndex];
                arr[childIndex] = arr[parentIndex];
                arr[parentIndex] = temp;
            }
            else
                break;
            childIndex = parentIndex;
        }
    }

    int getSize()
    {
        return arr.size();
    }

    int top()
    {
        if (arr.size() == 0)
            return -1;
        return arr[0];
    }

    int pop()
    {
        if (arr.size() == 0)
            return -1;

        // pop out the top element
        int x = arr[0];

        // replace top element with last element
        int n = arr.size() - 1;
        arr[0] = arr[n];
        arr.pop_back();
        int parentIndex = 0;
        int lChildIndex = 2 * parentIndex + 1;
        int rChildIndex = 2 * parentIndex + 2;


        // down heapify
        while (rChildIndex < arr.size())
        {
            if(arr[parentIndex] < arr[lChildIndex] && arr[parentIndex] < arr[rChildIndex]) return x;
            
            bool lMin = arr[lChildIndex] < arr[rChildIndex] ? true : false;

            if (lMin)
            {
                // swap left child with parent
                int temp = arr[parentIndex];
                arr[parentIndex] = arr[lChildIndex];
                arr[lChildIndex] = temp;
                parentIndex = lChildIndex;
            }
            else
            {
                //swap right child with parent
                int temp = arr[parentIndex];
                arr[parentIndex] = arr[rChildIndex];
                arr[rChildIndex] = temp;
                parentIndex = rChildIndex;
            }
            //again find lChild and rChild for new parentIndex
            lChildIndex = 2 * parentIndex + 1;
            rChildIndex = 2 * parentIndex + 2;
        }

        //if there is only one child and that is left child, then
        if(lChildIndex < arr.size())
        {
            if(arr[lChildIndex] < arr[parentIndex])
            {
                int temp = arr[parentIndex];
                arr[parentIndex] = arr[lChildIndex];
                arr[lChildIndex] = temp;
            }
        }
        return x;
    }
};