//RearrangeSpecifiPattern.cxx

//https://www.geeksforgeeks.org/reorder-a-array-according-to-given-indexes/


#include <iostream>

using namespace std;

void printarray(int *arr,int size)
{

    for(int i = 0;i < size;i++)
        cout << arr[i] << " ";
    cout << endl;
}

void rearrangespecifically(int *a,int *b,int size)
{
    int curr = 0;
    int temp[2];
    while(curr < size)
    {
        if(curr == b[curr])
        {
            curr++;
            continue;
        }
        temp[0] = a[b[curr]];
        temp[1] = b[b[curr]];
        a[b[curr]] = a[curr];
        b[b[curr]] = b[curr];
        a[curr] = temp[0];
        b[curr] = temp[1];
    }
}


int main()
{
    int a[] = {10, 11, 12};
    int b[] = {1, 0, 2};

    int size = 3;
    printarray(a,size);
    printarray(b,size);
    rearrangespecifically(a,b,size);
    printarray(a,size);
    printarray(b,size);
}
