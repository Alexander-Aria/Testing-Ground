// This is where the C++ Standard Library is included. 
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
using namespace std;

// Basic Concepts
void Function();
int Add(int x, int y);
void IfElse();
void WhileLoop();
void ForLoop();
void ForeachLoop();
void Switch();
void References();
void Pointers();

// Advanced Concepts
void Vectors();
void Structure();
void FileInOut();
void DateTime();
void Classes();

// Backend functions
void Input(int &num);

// Class declaration
class car{
    // Variable and Functions inside the private domain cannot be accessed directly outside of the object.
    // This is called encapsulation. 
    private:
        string brand, color;
        int weight;

    // Variable and Functions inside the private domain can be accessed directly outside of the object.
    // The public domain acts as a bridge from the program to the object. 
    public:
        // This is the constructor. It is a function that runs everytime you create an object of this class.
        car(string b, string c, int w){
            brand = b;
            color = c;
            weight = w;
        }

        string GetCarBrand(){return brand;}
        string GetCarColor(){return color;}
        int GetCarWeight(){return weight;}
};