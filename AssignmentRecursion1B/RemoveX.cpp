// Given a string, compute recursively a new string where all 'x' chars have been removed.
// Input format :
// String S
// Output format :
// Modified String
// Constraints :
// 1 <= |S| <= 10^3
// where |S| represents the length of string S. 
// Sample Input 1 :
// xaxb
// Sample Output 1:
// ab
// Sample Input 2 :
// abc
// Sample Output 2:
// abc
// Sample Input 3 :
// xx
// Sample Output 3:

#include <iostream>
using namespace std;

#include <cstring>
using namespace std;
void removeX(char input[]) {
    // Write your code here
    if(input[0]=='\0')
    {
        return;
    }
    
    removeX(input+1);

    
    if(input[0]=='x')
    {
        int len=strlen(input);
        // cout<<len<<endl;
        for(int i=1;i<len;i++)
        {
            input[i-1]=input[i];
        }
        input[len-1]='\0';
    }
    
}


int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}