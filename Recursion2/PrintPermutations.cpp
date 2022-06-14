// Given an input string (STR), print all possible permutations of the input string.
// Note:
// The input string may contain the same characters, so there will also be the same permutations.
// The order of permutations doesn’t matter.
// Input Format:
// The only input line contains a string (STR) of alphabets in lower case
// Output Format:
// Print each permutations in a new line
// Note:
// You do not need to print anything, it has already been taken care of. Just implement the function.  
// Constraint:
// 1<=length of STR<=8
// Time Limit: 1sec
// Sample Input 1:
// cba
// Sample Output 1:
// abc
// acb
// bac
// bca
// cab
// cba

#include <iostream>
#include <string>
using namespace std;

void print(string input,string output)
{    
    if(input.length()==0)
    {
        cout<<output<<endl;
        return;
    } 
    
    string op = output;
    
    for(int i=0;i<input.length();i++) 
    {
        string temp=input.substr(0,i)+input.substr(i+1);
        char output1=input[i];
        print(temp, output+output1);
    }
}
void printPermutations(string input){

    string output="";
    print(input,output);
}


int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}