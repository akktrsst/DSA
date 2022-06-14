// Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
// Note : The order of strings are not important. Just print different strings in new lines.
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

string getstring(int num){
  if(num==2){
      return "abc";
  }
    if(num==3){
        return "def";
    }
     if(num==4){
        return "ghi";
    }
     if(num==5){
        return "jkl";
    }
     if(num==6){
        return "mno";
    }
    if(num==7){
        return "pqrs";
    }
     if(num==8){
        return "tuv";
    }
     if(num==9){
        return "wxyz";
    }
    return " ";

}

void printKeypadhelper(int num, string outputsofar){
    if(num==0){
        cout<<outputsofar<<endl;
        return ;
    }
    int lastdigit=num%10;
    int smallno=num/10;
    string options= getstring(lastdigit);
    for(int i=0;i<options.size();i++){
        printKeypadhelper(smallno,options[i]+outputsofar);
    }
}


void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    printKeypadhelper(num," ");
}


int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}