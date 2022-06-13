// Check whether a given String S is a palindrome using recursion. Return true or false.
// Input Format :
// String S
// Output Format :
// 'true' or 'false'
// Constraints :
// 0 <= |S| <= 1000
// where |S| represents length of string S.
// Sample Input 1 :
// racecar
// Sample Output 1:
// true
// Sample Input 2 :
// ninja
// Sample Output 2:
// false

#include <iostream>
using namespace std;

int length(char input[]) { 
    int len = 0;
    for(int i = 0; input[i] != '\0'; i++) { 
        len++; 
    }
    return len;
} 
bool checkPalindrome(char input[], int start, int end) {
    if(input[0] == '\0' || input[1] == '\0') {
        return true;
    }
    if(start >= end) {
        return true;
    }
    if(input[start] == input[end]) {
        return checkPalindrome(input, start + 1, end - 1); 
    } 
    else { 
        return false;
    }
}
bool checkPalindrome(char input[]) { 
    int len = length(input);
    return checkPalindrome(input, 0, len - 1);
}
int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
