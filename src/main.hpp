// This is where the C++ Standard Library is included. 
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <limits>
using namespace std;
#define IGNORE cin.ignore(numeric_limits<streamsize>::max(), '\n')

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
void InheritancePolymorphism();
void Templates();

// Template definition
template <typename T>
T Multiplication(T x, T y);

// Backend functions
template <typename T>
void NumInput(T &num);
char Continue();

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

class device{
    // The protected domain can be accessed by child/inherited classes. 
    protected:
        string brand, model;
    public:
        device(string b, string m){
            brand = b;
            model = m;
        }

        string GetBrand(){return brand;}
        string GetModel(){return model;}

        // Device Specification function. A part of the Specification polymorphism.
        void Specification(){
            cout << "This is an unknown device. Specification : \n";
            cout << "Brand : " << GetBrand() << "\n";
            cout << "Model : " << GetModel() << "\n";
        }
};

// phone and PC is inherited from device. 
class phone : public device{
    private:
        string mobileOS;
    public:
        phone(string b, string m, string mOS) : device(b, m) {
            mobileOS = mOS;
        }

        string GetMobileOS(){return mobileOS;}

        // Phone Specification function. A part of the Specification polymorphism.
        void Specification(){
            cout << "This is an phone. Specification : \n";
            cout << "Brand : " << GetBrand() << "\n";
            cout << "Model : " << GetModel() << "\n";
            cout << "MobileOS : " << GetMobileOS() << "\n";
        }
};

class PC : public device{
    private:
        string OS;
    public:
        PC(string b, string m, string os) : device(b, m){
            OS = os;
        }

        string GetOS(){return OS;}

        // PC Specification function. A part of the Specification polymorphism.
        void Specification(){
            cout << "This is an PC. Specification : \n";
            cout << "Brand : " << GetBrand() << "\n";
            cout << "Model : " << GetModel() << "\n";
            cout << "OS : " << GetOS() << "\n";
        }
};