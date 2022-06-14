// Sort an array A using Quick Sort.
// Change in the input array itself. So no need to return or print anything.


// Input format :
// Line 1 : Integer n i.e. Array size
// Line 2 : Array elements (separated by space)
// Output format :
// Array elements in increasing order (separated by space)
// Constraints :
// 1 <= n <= 10^3

#include<iostream>
using namespace std;

int partition(int *input,int si,int ei){
    int pivot=input[si];
    int count=0;
    for(int i=si+1;i<=ei;i++)
    {
        if(input[i]<=pivot)
        {
            count++;
        }
        
    }
    int pivotindex=si+count;
    input[si]=input[pivotindex];
    input[pivotindex]=pivot;
    // ensure left half contains elements smaller than pivot 
    // and right half larger
    int i=si,j=ei;
    while(i<pivotindex && j>pivotindex)
    {
        if(input[i]<=pivot)
        {
            i++;
        }
        else if(input[j]>pivot)
        {
            j--;
        }
        else
        {
            int temp=input[i];
            input[i]=input[j];
            input[j]=temp;
            i++;
            j--;
        }
    }
    return pivotindex;
}
void qs(int* input, int si, int ei){
    // your code goes here 
    if(si>=ei)
    {
        return;
    }
    int pi= partition(input,si,ei);
    qs(input,si,pi-1);
    qs(input,pi+1,ei);
}
void quickSort(int *input, int n)
{
    qs(input,0,n-1);
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}