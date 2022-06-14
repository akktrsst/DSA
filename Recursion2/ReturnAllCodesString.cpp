// Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
// Note : The order of codes are not important. And input string does not contain 0s.
// Input format :
// A numeric string
// Constraints :
// 1 <= Length of String S <= 10
// Sample Input:
// 1123
// Sample Output:
// aabc
// kbc
// alc
// aaw
// kw

#include <iostream>
using namespace std;
#include <string.h>

int getCodes(string input,string output[10000]){
    if(input.size()==0){
        output[0]="";
        return 1; 
    }
    char c1=(input[0]-'0')+96; //consider inoput 123 now c1 is a
    string o1[1000];
    string o2[1000];
	int size1=getCodes(input.substr(1),o1); // 2 3 ke regarding yeh le ayega i.e bc and w
    int size2=0;
    int row=0;
    	for(int i=0;i<size1;i++)
        {
            output[row]=c1+o1[i];            //a+bc and a+w
            row++;                             
        }
      if(input[1]!='\0'){  
        int d=(input[0]-48)*10+(input[1]-48);
    	if(d>=10 && d<=26)
        {
            char d1=d+96;;
        size2=getCodes(input.substr(2),o2);
            for(int i=0;i<size2;i++)
            {
                output[row++]=d1+o2[i];
            }
        }
      }
    return row;
}

int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}