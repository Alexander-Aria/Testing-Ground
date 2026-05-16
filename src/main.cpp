#include "main.hpp"

// The "Function" function
void Function(){
    int x, y;

    cout << "Enter the first number : ";
    Input(x);
    cout << "Enter the second number : ";
    Input(y);

    // This outputs the addition of the two numbers (the Add function is in main.hpp)
    cout << "\n" << x << "+" << y << "=" << Add(x, y) << "\n";
}

// the Add function to demonstrate functions.
int Add(int x, int y){

    //This returns the x+y to the "Function" function
    return x+y;
}

void IfElse(){
    int num;

    cout << "Enter a number : ";
    Input(num);

    // This Inputs if your number is lower, higher, or is 5 using if, else, and if else
    if(num < 5) cout << "Your number is lower than 5.\n";
    else if(num > 5) cout << "Your number is higher than 5.\n";
    else cout << "Your number is 5.\n";
}

void WhileLoop(){
    string key;

    // This is the loop. As long as the variable key does not contain the string "OPEN", it will not stop looping
    while(key != "OPEN"){
        cout << "You are in a loop until you tell me the secret code (it's 'OPEN') : \n-";
        cin >> key;
    }
}

void ForLoop(){
    int amount;

    cout << "Tell me how many times I should say 'I love you' : \n-";
    Input(amount);

    // This is the loop
    for(int i = 0; i < amount; i++){
        cout << "I love you\n";
    }
}

void ForeachLoop(){
    int num = 0;
    // You can try changing the array size.
    int amount[5];

    cout << "This is an integer array. It has a size of " << sizeof(amount)/sizeof(amount[0]) << ". Can you fill this array? : \n-";
    for(int i = 0; i < 5; i++){
        cout << "Array no. " << i << " : ";
        Input(amount[i]);
    }

    for(int i : amount){
        cout << num << ". " << i << "\n";
        num++;
    }
}

void Vectors(){
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

    for(string str : colors){
        cout << "Color no. " << num << " : " << str << "\n";
        num++;
    }
    cout << "Total colors you picked : " << colors.size() << "\n";
}

void Switch(){
    int num;

    cout << "Choose a number from 1-3 : ";
    Input(num);

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

void Structure(){
    string temp;
    struct{
        string title, author;
        int date;
    } book;

    cout << "What book are you reading right now? ";
    getline(cin, book.title);
    cout << "Who is the author? ";
    getline(cin, book.author);
    cout << "When was this book published? ";
    getline(cin, temp);
    book.date = stoi(temp);

    cout << "Title : " << book.title << "\n";
    cout << "Author : " << book.author << "\n";
    cout << "Date Published : " << book.date << "\n";
}

void References(){
    string food;
    string &ref = food;

    //Notice that the getline function inputs to ref. Your input will still be stored in the food variable.
    cout << "Enter your favourite food : ";
    getline(cin, ref);

    // This is the output.
    cout << "Your favourite food is : " << food << "\n";
}

void Pointers(){
    // Variable declaration/initialization. The "&" sign means the variable address.
    int num;
    int* pointer = &num;

    cout << "Enter a random number : ";
    Input(num);

    cout << "Variable : num\n";
    cout << "Address of num: " << pointer << "\n";
    cout << "Value stored in num: " << num << "\n";
    cout << "Dereference (*pointer) : " << *pointer << "\n\n";
    cout << "Value(" << num << ") <--- Address(" << pointer << ") <--- Variable(num)\n";
}

void FileInOut(){
    fstream data;
    string str, filestr;

    cout << "Introduce yourself in a single line : \n";
    getline(cin, str);

    // ios::out is for inserting data and ios::trunc is for truncing/erasing the content before the insertion. 
    // Your line will be inserted in the data.txt file.
    data.open("data/data.txt", ios::out|ios::trunc);
    data << str;
    cout << "Data successfully inserted.\n";
    data.close();

    // Data retrieval. ios::in is for reading/retrieval.
    data.open("data/data.txt", ios::in);
    getline(data, filestr);
    cout << "Your data : " << filestr << "\n";
    data.close();
}

void DateTime(){
    time_t date = time(nullptr);
    struct tm datetime = *localtime(&date);

    cout << "Current date (localtime): " << ctime(&date) << "\n";
    cout << "Seconds since 1 January 1970 00:00:00 UTC : " << date << "\n\n";

    // Pay attention to the datetime struct. Some of the outputs have been modified to be more readable.
    cout << "____________________________________________\n";
    cout << "Year : " << datetime.tm_year+1900 << "\n";
    cout << "Month : " << datetime.tm_mon+1 << "\n";
    cout << "Month Day : " << datetime.tm_mday << "\n";
    cout << "Week Day (Sunday = 1 --> Saturday = 7) : " << datetime.tm_wday+1 << "\n";
    cout << "Hour : " << datetime.tm_hour << "\n";
    cout << "Minute : " << datetime.tm_min << "\n";
    cout << "Second : " << datetime.tm_sec << "\n";
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
            cout << "0. Back\n1. Functions\n2. If/Else\n3. While Loops\n4. For Loops\n5. Foreach Loop/Arrays\n6. Switches\n7. References\n8. Pointers\n\n- ";
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
            else if(opt == "8"){
                Pointers();
            }
        }
        else if(opt == "2"){
            cout << "0. Back\n1. Vectors\n2. Structures/getline\n3. File Input/Output\n4. Date/Time\n\n- ";
            cin >> opt;
            cin.ignore();
            if(opt == "1"){
                Vectors();
            }
            else if(opt == "2"){
                Structure();
            }
            else if(opt == "3"){
                FileInOut();
            }
            else if(opt == "4"){
                DateTime();
            }
        }
    }
    return 0;
}