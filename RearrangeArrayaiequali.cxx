//RearrangeArrayaiequali.cxx

//https://www.geeksforgeeks.org/rearrange-array-arri/

#include <iostream>

using namespace std;


void swapele(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void rearrange(int *arr,int count)
{
    int i = 0;
    int temp;
    int total = 0;
    while(i < count)
    {
        total++;
        if(arr[i] == -1 || arr[i] == i)
        { 
            i++;
            continue;
        }
        
        swapele(arr[arr[i]],arr[i]);
    }

    cout << "The Total numbe rof iterations are " << total << endl;
}

void printarray(int *arr,int size)
{

    for(int i = 0;i < size;i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    //int arr[] = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
    int arr[] = {19, 7, 0, 3, 18, 15, 12, 6, 1, 8,
              11, 10, 9, 5, 13, 16, 2, 14, 17, 4};

    printarray(arr,sizeof(arr)/sizeof(int));
    rearrange(arr,sizeof(arr)/sizeof(int));
    printarray(arr,sizeof(arr)/sizeof(int));

}
