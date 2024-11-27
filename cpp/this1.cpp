// THIS POINTER
// Always remember, each object gets their own copy of data member.
// But there is only one copy created of member function.
// Then how, member functions are accessed by multiple objects without any type of confusion or mismatch value?
// The compiler supplies an implicit pointer along the names of the function as "this".

// First use of this Pointer: -
// when local variable name is same as member's name

#include<iostream>
using namespace std;

class this_point
{
    private:
        int xyz;
    
    public:
        void set_num(int xyz)
        {
            this->xyz = xyz;
        }

        void print() 
        { 
            cout << "xyz = " << xyz << endl; 
        }
};

int main()
{
    int xyz = 110;
    this_point P1;
    P1.set_num(77);
    P1.print();
    return 0;
}