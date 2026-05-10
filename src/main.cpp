#include <iostream>
#include "main.hpp"
using namespace std;

// The "Function" function
void Function(){
    int x, y;
    cout << "Enter the first number : ";
    cin >> x;
    cout << "Enter the second number : ";
    cin >> y;
    cout << "\n" << x << "+" << y << "=" << Add(x, y) << "\n";
}

// The "If/Else" function
void IfElse(){
    int num;
    cout << "Enter a number : ";
    cin >> num;
    if(num < 5) cout << "Your number is lower than 5.\n";
    else if(num > 5) cout << "Your number is higher than 5.\n";
    else if(num == 5) cout << "Your number is 5.\n";
}

// The "While loop" function
void WhileLoop(){
    string key;
    while(key != "OPEN"){
        cout << "You are in a loop until you tell me the secret code (it's 'OPEN') : \n-";
        cin >> key;
    }
}

// The "For Loop" function
void ForLoop(){
    int amount;
    cout << "Tell me how many times I should say 'I love you' : \n-";
    cin >> amount;
    for(int i; i < amount; i++){
        cout << "I love you\n";
    }
}

// Main function
int main(){
    cout << "This is the main C++ testing source code. I recommend running the program while reading the source code. You can change the source code however you like. \n";
    while(1){
        cout << "_______________________________________________\n";
        cout << "0. Exit\n1. Function\n2. If/Else\n3. While Loop\n4. For Loop\n";
        cout << "- ";
        cin >> opt;
        if(opt == '0'){
            cout << "Exiting...\n";
            return 0;
        }
        else if(opt == '1'){
            Function();
        }
        else if(opt == '2'){
            IfElse();
        }
        else if(opt == '3'){
            WhileLoop();
        }
        else if(opt == '4'){
            ForLoop();
        }
    }
    return 0;
}