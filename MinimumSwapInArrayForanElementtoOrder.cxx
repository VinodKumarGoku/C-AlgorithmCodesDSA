//MinimumSwapInArrayForanElementtoOrder.cxx

//https://www.geeksforgeeks.org/minimum-swaps-required-bring-elements-less-equal-k-together/


#include <iostream>

using namespace std;


// Sliding window approach to find minimum swap required in a window


int findlessthanorequalnumelements(int *arr,int size,int ele)
{
    int count = 0;
    for(int i = 0;i<size;i++)
        if(arr[i] <= ele)count++;

    return count;
}

int minswaprequiredfunction(int *arr,int size, int window_size,int ele)
{
    int mincount = -1;
    //First window analysis
    for(int i = 0;i<=window_size;i++)
        if(arr[i] > ele)mincount++;

    //Search in all other windows past first windows
    int lastmin = mincount;
    for(int i = window_size;i<size;i++)
    {
        if(arr[i-window_size] > ele)mincount--;
        if(arr[i] > ele)mincount++;
        if(mincount > lastmin)mincount = lastmin;
    }

    return mincount;

}

int main()
{
    int arr[] = {2, 7, 9, 5, 8, 7, 4};
    int size = sizeof(arr)/sizeof(int);

    int elementtosearch = 5;
    int lessthanorequalelem = findlessthanorequalnumelements(arr,size,elementtosearch);

    // Sliding window approach to find min swap required
    int minswaprequired = minswaprequiredfunction(arr,size,lessthanorequalelem,elementtosearch);

    cout << "Minimum swap required is " << minswaprequired << endl;
}



















