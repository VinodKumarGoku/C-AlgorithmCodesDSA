//ArraySearchElementRotated.cxx

// https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/

#include <iostream>

using namespace std;



void searcharray(int *arr,int start,int end,int &result)
{
    if((end - start) == 1 && (arr[end] - arr[start]) < 0)
    {
        result = end;
        return;
    }

    if(result != -1 || (end-start) == 1)
        return;

    int mid = (start+end)/2; 

    // Left Array Check    
    if((end - start) % 2 == 0)
        searcharray(arr,start,mid-1,result);
    else searcharray(arr,start,mid,result);

    // Right Array Check
    searcharray(arr,mid+1,end,result);
    
}

void binarysearch(int *arr,int start,int end, int ele,bool &found)
{
    if(found)
        return;

    if(end == start && ele == arr[end])
    {
        found = true;
        return;
    }
    if(end == start)
        return;

    int mid = (start+end)/2;

    binarysearch(arr,start,mid,ele,found);
    binarysearch(arr,mid+1,end,ele,found);
}


int main()
{
    cout << "Starting Running Program" << endl;
    //int arr[] = {10,1,2,3,5,6,7,8,9};
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    //int arr[] = {5,1,2,3,4};
    int result = -1;
    int ele = 10;
    cin >> ele;
    searcharray(arr,0,sizeof(arr)/sizeof(int)-1,result);

    bool elepresent = false;

    binarysearch(arr,0,result-1,ele,elepresent);
    if(!elepresent)
        binarysearch(arr,result,sizeof(arr)/sizeof(int)-1,ele,elepresent);

    cout << "Element present: " << elepresent << endl;
    return 0;
}
