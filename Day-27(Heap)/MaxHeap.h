class MaxHeap{
private:
    int *arr = new int[100];
    int n;
public:
    MaxHeap()
    {
        this->n = 0;
    }
    void push(int elem)
    {
        //find the index at which element is getting stored
        int i = this->n;
        this->arr[this->n] = elem;
        (this->n)++;

        //find the parent index
        int parentIndex = (i%2==0)?((i-1)/2):(i/2);
        //find the parent element
        int parentElem = this->arr[parentIndex];
        while(parentIndex >= 0)
        {
            if(parentElem < this->arr[i])
            {
                int temp = this->arr[parentIndex];
                this->arr[parentIndex] = this->arr[i];
                this->arr[i] = temp;
                i = parentIndex;
                parentIndex = (i%2==0)?((i-1)/2):(i/2);
                parentElem = this->arr[parentIndex];
            }
            else break;
        }
    }
    int top()
    {
        return this->n>0?this->arr[0]:-1;
    }
    int getSize()
    {
        return this->n;
    }
    int pop()
    {
        if(n<1) return -1;
        //remove and replace top element with last element in heap array
        int x = this->top();
        
        this->arr[0] = this->arr[n-1];
        this->arr[n-1] = x;
        (this->n)--;

        //down heapify
        int i = 0;
        int elem = this->arr[0];
        int rightChild = 2*i+2;
        int leftChild = 2*i+1;
        while(rightChild < n)
        {
            if(elem > this->arr[leftChild] && elem > this->arr[rightChild])
            {
                break;
            }
            //find out which of them is maximum
            bool leftMax = this->arr[leftChild] > this->arr[rightChild]?true:false;

            //now swap elem with max between left and right child
            if(leftMax)
            {
                int temp = this->arr[leftChild];
                this->arr[leftChild] = elem;
                this->arr[i] = temp;
                i = leftChild;
            }
            else
            {
                int temp = this->arr[rightChild];
                this->arr[rightChild] = elem;
                this->arr[i] = temp;
                i = rightChild;
            }

            //find left and right child
            leftChild = 2*i+1;
            rightChild = 2*i+2;
        }
        if(leftChild < n)
        {
            int temp = this->arr[leftChild];
            arr[leftChild] = elem;
            elem = temp;
        }
        return x;
    }
};