// Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
// Return empty string for numbers 0 and 1.
// Note : 1. The order of strings are not important.
// 2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
// Input Format :
// Integer n
// Output Format :
// All possible strings in different lines
// Constraints :
// 1 <= n <= 10^6
// Sample Input:
// 23
// Sample Output:
// ad
// ae
// af
// bd
// be
// bf
// cd
// ce
// cf

#include <iostream>
#include <string>
using namespace std;

#include <string>
using namespace std;

int seq(int input, string output[]){
    if(input==0){
        output[0]="";
		return 1;
    }
    int s = input/10;
    int s1 = input%10;
    string input1;
    if(s1 == 1 or s1==0){
        output[0]="";
		return 1 ;
    }
    if(s1 == 2 ){
		input1 = "abc" ;
    }
    if(s1 == 3 ){
		input1 = "def"  ;
    }
    if(s1 == 4 ){
		input1 = "ghi"  ;
    }
    if(s1 == 5 ){
		input1 = "jkl" ;
    }
    if(s1 == 6 ){
		input1 = "mno" ;
    }
    if(s1 == 7 ){
		input1 = "pqrs" ;
    }
    if(s1 == 8 ){
		input1 = "tuv" ;
    }
    if(s1 == 9 ){
		input1 = "wxyz" ;
    }
    int size = seq(s,output);
    int n = input1.size();
    int o =n;
    while(n>0){
        for(int i=0 ; i <size ; i++){
            output[i + (n-1)*size]= output[i] + input1[n-1];
        }
        n--;
    }
    return o*size;
}

int keypad(int num, string output[]){
    seq(num,output);
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}