//ReaarangeAlternatePositiveNegative.cxx

//https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/


#include <iostream>

using namespace std;

int findnegpos(int *a,int curr,int size,bool negpos)
{
    for(int i = curr; i< size;i++)
    {
        if(a[i] < 0 && !negpos) return i;
        if(a[i] > 0 && negpos) return i;
    }
    return size;
}

void rightshift(int *a, int curr, int end)
{
    for(int i = end;i > curr;i--)
        a[i] = a[i-1];
}

void rearrange_array(int *a,int size)
{
    bool negpos = false;
    int curr = 0;
    int npos,ppos;
    int nposele,pposele;
    while(curr < size)
    {
        if(!negpos)
        {
            if(a[curr] < 0)
            {
                curr++;
                negpos = true;
                continue;
            }
            npos = findnegpos(a,curr,size,false);
            if(npos == size) return;

		    nposele = a[npos];
		    rightshift(a,curr,npos);
		    negpos = true;
		    a[curr] = nposele;
		    curr++;
		    continue;
        }
        else 
        {
            if(a[curr] > 0)
            {
		        curr++;
		        negpos = false;
		        continue;
            }

	        ppos = findnegpos(a,curr,size,true);
		    if(ppos == size) return;

		    pposele = a[ppos];
		    rightshift(a,curr,ppos);
		    negpos = false;
		    a[curr] = pposele;
		    curr++;
        }
    }
}

void printarray(int *arr,int size)
{

    for(int i = 0;i < size;i++)
        cout << arr[i] << " ";
    cout << endl;
}


int main()
{
    int arr[] = {-5, -3, -4, -5, -6, 2 , 8, 9, 1 , 4};

    int size = sizeof(arr)/sizeof(int);
    printarray(arr,size);

    rearrange_array(arr,sizeof(arr)/sizeof(int));

    printarray(arr,size);
}
