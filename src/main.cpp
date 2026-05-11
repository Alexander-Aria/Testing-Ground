#include <iostream>
#include <vector>
#include "main.hpp"
using namespace std;

// The "Function" function
void Function(){
    // Variable declaration
    int x, y;

    // You input the two numbers here
    cout << "Enter the first number : ";
    cin >> x;
    cout << "Enter the second number : ";
    cin >> y;

    // This outputs the addition of the two numbers (the Add function is in main.hpp)
    cout << "\n" << x << "+" << y << "=" << Add(x, y) << "\n";
}

// The "If/Else" function
void IfElse(){
    // Variable declaration
    int num;

    // You input a number here
    cout << "Enter a number : ";
    cin >> num;

    // This checks if your number is lower, higher, or is 5 using if, else, and if else
    if(num < 5) cout << "Your number is lower than 5.\n";
    else if(num > 5) cout << "Your number is higher than 5.\n";
    else cout << "Your number is 5.\n";
}

// The "While loop" function
void WhileLoop(){
    // Variable declaration
    string key;

    // This is the loop. As long as the variable key does not contain the string "OPEN", it will not stop looping
    while(key != "OPEN"){
        cout << "You are in a loop until you tell me the secret code (it's 'OPEN') : \n-";
        cin >> key;
    }
}

// The "For Loop" function
void ForLoop(){
    // Variable declaration
    int amount;

    // You input the amount of loops here
    cout << "Tell me how many times I should say 'I love you' : \n-";
    cin >> amount;

    // This is the loop
    for(int i; i < amount; i++){
        cout << "I love you\n";
    }
}

// The "Foreach Loop/Arrays" function
void ForeachLoop(){
    // Variable initialitazion/declaration
    int n, num = 0;

    // You input the array size here
    cout << "How big do you want the array to be? (This is an int array) : \n-";
    cin >> n;
    int amount[n];

    // You input the array values here
    for(int i = 0; i < n; i++){
        cout << "Array no. " << i << " : ";
        cin >> amount[i];
    }

    // This is the output loop
    for(int i : amount){
        cout << num << ". " << i << "\n";
        num++;
    }
    cout << "Array size : " << n << "\n";
}

// The Vectors function
void Vectors(){
    // Variable Declaration
    vector<string> colors;
    string color;
    char opt;
    int num = 1, inputloop = 1;

    //This is the input loop. You can add as many values as you want here.
    cout << "Pick some colors for a house theme. You can add as many as you want.\n"; 
    while(inputloop == 1){
        cout << num << ". ";
        cin >> color;
        colors.push_back(color);
        cout << "Continue? Y/n : ";
        cin >> opt;
        if (opt == 'Y'){
            num++;
        }
        else{
            inputloop = 0;
        }
    }
    num = 1;

    // This is the output loop
    for(string str : colors){
        cout << "Color no. " << num << " : " << str << "\n";
        num++;
    }
    cout << "Total colors you picked : " << num-1 << "\n";
}

// Main function
int main(){
    cout << "This is the main C++ testing source code. I recommend running the program while reading the source code. You can change the source code however you like. \n";
    while(1){
        cout << "_______________________________________________\n";
        cout << "0. Exit\n1. Function\n2. If/Else\n3. While Loop\n4. For Loop\n5. Foreach Loop/Arrays\n6. Vectors\n\n";
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
        else if(opt == '5'){
            ForeachLoop();
        }
        else if(opt == '6'){
            Vectors();
        }
    }
    return 0;
}