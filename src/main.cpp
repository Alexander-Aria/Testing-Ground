#include "main.hpp"
#include "class.hpp"

// The "Function" function
void Function(){
    int x, y;

    cout << "Enter the first number : ";
    NumInput<int>(x);
    cout << "Enter the second number : ";
    NumInput<int>(y);

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
    NumInput<int>(num);

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
    NumInput<int>(amount);

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
        NumInput<int>(amount[i]);
    }

    for(int i : amount){
        cout << num << ". " << i << "\n";
        num++;
    }
}

void Switch(){
    int num;

    cout << "Choose a number from 1-3 : ";
    NumInput<int>(num);

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
    NumInput<int>(num);

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
    if(data.is_open()){
        data << str;
        cout << "Data successfully inserted.\n";
    }
    data.close();

    // Data retrieval. ios::in is for reading/retrieval.
    data.open("data/data.txt", ios::in);
    if(data.is_open()){
        getline(data, filestr);
        cout << "Your data : " << filestr << "\n";
    }
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

void Classes(){
    vector<car> cars;
    string brand, color;
    int weight, num = 1;
    char opt;

    while(true){
        cout << "Enter your car specification : \n";
        cout << "Brand : ";
        getline(cin, brand);
        cout << "Color : ";
        getline(cin, color);
        cout << "Weight (kg): ";
        NumInput<int>(weight);
        IGNORE;
        cars.push_back(car(brand, color, weight));
        if(Continue() != 'Y') break;
    }
    cout << "Your car(s) : \n";
    for(auto &car : cars){
        cout << "Car no. " << num << "\n";
        cout << "Brand : " << car.GetCarBrand() << "\n";
        cout << "Color : " << car.GetCarColor() << "\n";
        cout << "Weight (kg): " << car.GetCarWeight() << "\n";
        num++;
    }
}

void InheritancePolymorphism(){
    vector <phone> phones;
    vector <PC> PCs;
    vector <device> misc;
    string brand, model, mobileOS, OS;

    while(true){
        cout << "Insert your phone specification here.\n";
        cout << "Brand : ";
        getline(cin, brand);
        cout << "Model : ";
        getline(cin, model);
        cout << "MobileOS : ";
        getline(cin, mobileOS);
        phones.push_back(phone(brand, model, mobileOS));
        if(Continue() != 'Y') break;
    }
    
    while(true){
        cout << "Insert your PC specification here.\n";
        cout << "Brand : ";
        getline(cin, brand);
        cout << "Model : ";
        getline(cin, model);
        cout << "OS : ";
        getline(cin, OS);
        PCs.push_back(PC(brand, model, OS));
        if(Continue() != 'Y') break;
    }

    while(true){
        cout << "Insert your other device specification here.\n";
        cout << "Brand : ";
        getline(cin, brand);
        cout << "Model : ";
        getline(cin, model);
        misc.push_back(device(brand, model));
        if(Continue() != 'Y') break;
    }

    cout << "Your Devices : \n";
    cout << "Phones : \n";
    for(phone &i : phones){
        i.Specification();
    }

    cout << "PCs : \n";
    for(PC &i : PCs){
        i.Specification();
    }

    cout << "Other Devices : ";
    for(device &i : misc){
        i.Specification();
    }
}

void Templates(){
    int x1, y1;
    double x2, y2;

    cout << "Enter an integer : ";
    NumInput<int>(x1);
    cout << "Enter another integer : ";
    NumInput<int>(y1);
    cout << x1 << "*" << y1 << " = " <<Multiplication<int>(x1, y1) << "(int)\n";

    cout << "Enter a double : ";
    NumInput<double>(x2);
    cout << "Enter another double : ";
    NumInput<double>(y2);
    cout << x1 << "*" << y1 << " = " << Multiplication<double>(x2, y2) << "(double)\n";
}

template <typename T>
T Multiplication(T x, T y){
    return x*y;
}

void Vectors(){
    vector<string> colors;
    string color;
    int num = 1, inputloop = 1;

    //This is the input loop. You can add as many values as you want here.
    cout << "Pick some colors for a house theme. You can add as many as you want.\n"; 
    while(inputloop == 1){
        cout << num << ". ";
        cin >> color;
        colors.push_back(color);
        if (Continue() == 'Y'){
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

void Lists(){
    list<int> numbers = {2, 4, 6, 8, 10};
    int opt = 0, num;
    bool n = true;

    cout << "Different from vectors, you can add and remove elements from the front and the back.\n";
    cout << "list does not support random access, meaning you cannot directly jump to a specific index, or access elements by index numbers.\n";
    while(n){
        int total = 0;
        cout << "The current list is : ";
        for(int &i : numbers){
            cout << i << " ";
            total += i;
        }
        cout << "\nThe series/sum is : " << total << "\n";
        cout << "Try manipulating the list! \n";
        cout << "0. Finish\n1. Push Front\n2. Push Back\n3. Clear\n\n- ";
        NumInput<int> (opt);
        switch(opt){
            case 1:
                cout << "Enter a number to push to the front : ";
                NumInput<int> (num);
                numbers.push_front(num);
                break;
            case 2:
                cout << "Enter a number to push to the back : ";
                NumInput<int> (num);
                numbers.push_back(num);
                break;
            case 3:
                numbers.clear();
                break;
            default:
                n = false;
        }
    }
}

void Stacks(){
    stack<int> numbers;
    int opt = 0, num;
    bool n = true;

    cout << "You can add and remove elements from the top of the stack.\n";
    cout << "Stack purposely hide the elements below the top element so you can't access the stack elements other than the top.\n";
    while(n){
        if(!numbers.empty()) cout << "The current element on the top is : " << numbers.top() << "\n";
        else cout << "The stack is currently empty.\n";
        cout << "Try manipulating the stack! \n";
        cout << "0. Finish\n1. Push\n2. Pop\n3. Clear\n\n- ";
        NumInput<int> (opt);
        switch(opt){
            case 1:
                cout << "Enter a number to push to the front : ";
                NumInput<int> (num);
                numbers.push(num);
                break;
            case 2:
                if(!numbers.empty()) numbers.pop();
                else cout << "The stack is already empty!\n";
                break;
            case 3:
                while(!numbers.empty()) numbers.pop();
                break;
            default:
                n = false;
        }
    }
}

void Queues(){}
void Deques(){}
void Sets(){}
void Maps(){}

//This is the Input function. It handles integer input errors.
template <typename T>
void NumInput(T &num){
    while(!(cin >> num)){
        cin.clear();
        IGNORE;
        cout << "Error! Try again : ";
    }
}

void BasicConcepts(){
    int opt;

    cout << "0. Back\n1. Functions\n2. If/Else\n3. While Loops\n4. For Loops\n5. Foreach Loop/Arrays\n6. Switches\n7. References\n8. Pointers\n\n- ";
    NumInput<int> (opt);

    switch(opt){
        case 1:
            Function();
            break;
        case 2:
            IfElse();
            break;
        case 3:
            WhileLoop();
            break;
        case 4:
            ForLoop();
            break;
        case 5:
            ForeachLoop();
            break;
        case 6:
            Switch();
            break;
        case 7:
            References();
            break;
        case 8:
            Pointers();
            break;
    }
}

void AdvancedConcepts(){
    int opt;

    cout << "0. Back\n1. Structures/getline\n2. File Input/Output\n3. Date/Time\n4. Classes/Objects\n5. Inheritance/Polymorphism\n6. Templates\n\n- ";
    NumInput<int> (opt);
    IGNORE;

    switch(opt){
        case 1:
            Structure();
            break;
        case 2:
            FileInOut();
            break;
        case 3:
            DateTime();
            break;
        case 4:
            Classes();
            break;
        case 5:
            InheritancePolymorphism();
            break;
        case 6:
            Templates();
            break;
    }
}

void STL(){
    int opt;

    cout << "0. Back\n1. Vectors\n2. Lists\n3. Stacks\n4. Queues\n5. Deques\n6. Sets\n7. Maps\n\n- ";
    NumInput<int> (opt);
    IGNORE;

    switch(opt){
        case 1:
            Vectors();
            break;
        case 2:
            Lists();
            break;
        case 3:
            Stacks();
            break;
        case 4:
            Queues();
            break;
        case 5:
            Deques();
            break;
        case 6:
            Sets();
            break;
        case 7:
            Maps();
            break;
    }
}

char Continue(){
    char opt;
    cout << "Data added!\nContinue? Y/n\n";
    cin >> opt;
    IGNORE;
    return opt;
}

// Main function
int main(){
    int opt;
    while(true){
        cout << "_______________________________________________\n";
        cout << "Welcome to the C++ testing ground. The purpose of this program is to be experimented and used as a cheat sheet.\n";
        cout << "It is recommended to run this program while having the source code open. Feel free to change the code however you like.\n";
        cout << "0. Exit\n1. Basic Concepts\n2. Advanced Concepts\n3. Standard Template Library (STL)\n\n- ";
        NumInput<int> (opt);
        IGNORE;
        switch(opt){
            case 0:
                cout << "Exiting...\n";
                return 0;
            case 1:
                BasicConcepts();
                break;
            case 2:
                AdvancedConcepts();
                break;
            case 3:
                STL();
                break;
        }
    }
    return 0;
}