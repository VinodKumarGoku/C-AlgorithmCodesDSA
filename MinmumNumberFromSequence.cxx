//MinmumNumberFromSequence.cxx

//https://www.geeksforgeeks.org/form-minimum-number-from-given-sequence/

#include<iostream>
#include<vector>

using namespace std;


// D D I
// 213
// 231
// 321 



void startswappingelements(vector<int> &res, string &seq, int seqposition, int resultposition)
{
    for(int i = resultposition;i > 0;i--)
    {
        if((seq[i-1] == 'D' && res[i] > res[i-1]) || (seq[i-1] == 'I' && res[i] < res[i-1]))
        {
            int temp = res[i];
            res[i] = res[i-1];
            res[i-1] = temp;
            continue;
        }
        else break;
    }

}

void generate_sequence(string seq,int size)
{
    vector<int> result;
    int startnum = 1;

    if(seq[0] == 'D')
    {
        result.push_back(startnum+1);
        result.push_back(startnum);
    }
    else 
    {
        result.push_back(startnum);
        result.push_back(startnum+1);
        
    }
    startnum+=2;

    for(int i = 1;i < size;i++)
    {
        result.push_back(startnum);
        int size = result.size();
        if((seq[i] == 'D' && result[size-2] < result[size-1]) ||
             (seq[i] == 'I' && result[size-2] > result[size-1]) )
        {
            startswappingelements(result, seq, i, size-1);
        }
        startnum++;   
    }
    for(int i=0;i < result.size();i++)
        cout << result[i] << " ";
    cout << endl;
}




int main()
{
    string seq = "IDIDIDIDDDII";
    generate_sequence(seq,seq.size());

}
