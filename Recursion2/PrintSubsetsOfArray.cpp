// Given an integer array (of length n), find and print all the subsets of input array.
// Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
// Note : The order of subsets are not important. Just print the subsets in different lines.
// Input format :
// Line 1 : Integer n, Size of array
// Line 2 : Array elements (separated by space)
// Constraints :
// 1 <= n <= 15
// Sample Input:
// 3
// 15 20 12
// Sample Output:
// [] (this just represents an empty array, don't worry about the square brackets)
// 12 
// 20 
// 20 12 
// 15 
// 15 12 
// 15 20 
// 15 20 12 

#include <iostream>
using namespace std;

void PrintOutputArray(int input[],int n,int output[],int m)
{
    if(n==0)
    {
        for(int i=0;i<m;i++)
        {
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return;
    }
    PrintOutputArray(input+1,n-1,output,m);
    int nOutput[1000];
    for(int i=0;i<m;i++)
    {
        nOutput[i]=output[i];
    }
    nOutput[m]=input[0];
    PrintOutputArray(input+1,n-1,nOutput,m+1);
}
void printSubsetsOfArray(int input[], int n) {
	// Write your code here
    int m=0;
    int output[1000];
    PrintOutputArray(input,n,output,m);
}

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}
