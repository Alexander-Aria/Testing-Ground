#include "main.hpp"

// The "Function" function
void Function(){
    // Variable declaration
    int x, y;

    // You input the two numbers here
    cout << "Enter the first number : ";
    Input(x);
    cout << "Enter the second number : ";
    Input(y);

    // This outputs the addition of the two numbers (the Add function is in main.hpp)
    cout << "\n" << x << "+" << y << "=" << Add(x, y) << "\n";
}

// the Add function to demonstrate functions
int Add(int x, int y){

    //This returns the x+y to the "Function" function
    return x+y;
}

// The "If/Else" function
void IfElse(){
    // Variable declaration
    int num;

    // You input a number here
    cout << "Enter a number : ";
    Input(num);

    // This Inputs if your number is lower, higher, or is 5 using if, else, and if else
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
    Input(amount);

    // This is the loop
    for(int i = 0; i < amount; i++){
        cout << "I love you\n";
    }
}

// The "Foreach Loop/Arrays" function
void ForeachLoop(){
    // Variable initialitazion/declaration
    int num = 0;
    int amount[5];

    // You input the array values here
    cout << "This is an integer array. It has a size of 5. Can you fill this array? : \n-";
    for(int i = 0; i < 5; i++){
        cout << "Array no. " << i << " : ";
        Input(amount[i]);
    }

    // This is the output loop
    for(int i : amount){
        cout << num << ". " << i << "\n";
        num++;
    }
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

// This is the Switch Function
void Switch(){
    // Variable initialization
    int num;

    // You input a number between 1-3 here
    cout << "Choose a number from 1-3 : ";
    Input(num);

    // This is the switch
    switch(num){
        case 1:
            cout << "You won a fridge!\n";
            break;
        case 2:
            cout << "You won a car!\n";
            break;
        case 3:
            cout << "You won nothing!\n";
            break;
        default:
            cout << "Uhm... what?\n";
    }
}

// This is the Structure function
void Structure(){
    // Variable Initialization
    string temp;
    struct{
        string title, author;
        int date;
    } book;

    // You input the values to the variables inside the book structure here
    cout << "What book are you reading right now? ";
    getline(cin, book.title);
    cout << "Who is the author? ";
    getline(cin, book.author);
    cout << "When was this book published? ";
    getline(cin, temp);
    book.date = stoi(temp);

    // This is the output
    cout << "Title : " << book.title << "\n";
    cout << "Author : " << book.author << "\n";
    cout << "Date Published : " << book.date << "\n";
}

// This is the References function
void References(){
    // Variable declaration/initialization
    string food;
    string &ref = food;

    // You input your favourite food here. 
    //Notice that the getline function inputs to ref. Your input will still be stored in the food variable.
    cout << "Enter your favourite food : ";
    getline(cin, ref);

    // This is the output.
    cout << "Your favourite food is : " << food << "\n";
}

//This is the Input function. It handles integer input errors.
void Input(int &num){
    while(!(cin >> num)){
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "Error! Try again : ";
    }
}

// Main function
int main(){
    string opt;
    cout << "This is the main C++ testing source code. I recommend running the program while reading the source code. You can change the source code however you like. \n";
    while(true){
        cout << "_______________________________________________\n";
        cout << "0. Exit\n1. Basic Concepts\n2. Advanced Concepts\n\n- ";
        cin >> opt;
        cin.ignore();
        if(opt == "0"){
            cout << "Exiting...\n";
            return 0;
        }
        else if(opt == "1"){
            cout << "0. Back\n1. Functions\n2. If/Else\n3. While Loops\n4. For Loops\n5. Foreach Loop/Arrays\n6. Switches\n7. References\n\n- ";
            cin >> opt;
            cin.ignore();
            if(opt == "1"){
                Function();
            }
            else if(opt == "2"){
                IfElse();
            }
            else if(opt == "3"){
                WhileLoop();
            }
            else if(opt == "4"){
                ForLoop();
            }
            else if(opt == "5"){
                ForeachLoop();
            }
            else if(opt == "6"){
                Switch();
            }
            else if(opt == "7"){
                References();
            }
        }
        else if(opt == "2"){
            cout << "0. Back\n1. Vectors\n2. Structures/getline\n\n- ";
            cin >> opt;
            cin.ignore();
            if(opt == "1"){
                Vectors();
            }
            else if(opt == "2"){
                Structure();
            }
        }
    }
    return 0;
}