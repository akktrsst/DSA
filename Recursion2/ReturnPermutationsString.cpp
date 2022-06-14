// Given a string S, find and return all the possible permutations of the input string.
// Note 1 : The order of permutations is not important.
// Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
// Input Format :
// String S
// Output Format :
// All permutations (in different lines)
// Sample Input :
// abc
// Sample Output :
// abc
// acb
// bac
// bca
// cab
// cba

#include <iostream>
#include <string>
using namespace std;


int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    
    if(input.length()==1)
    {
        output[0]=input[0];
        return 1;
    }
    int p=0;
    for(int i=0;i<input.length();i++) 
    {
        string temp=input.substr(0,i)+input.substr(i+1);
        string small[10000];
        int ans=returnPermutations(temp, small);
        for(int j=0;j<ans;j++)
        {
            output[p]=input[i]+small[j];
            p++;
        }
    }
    return p;
}

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}