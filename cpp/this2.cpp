// Second use of this pointer: -
// To return reference to the calling object.

#include<iostream>
using namespace std;

class Test
{
    private:
        int x;
        int y;
    public:
        Test(int x = 0, int y = 0)
        {
            this->x = x;
            this->y = y;
        }

        Test &setX(int a)
        {
            x = a;
            return *this;
        }

        Test &setY(int b)
        {
            y = b;
            return *this;
        }

        void print() 
        { 
            cout << "x = " << x << " y = " << y << endl; 
        }
};


int main()
{
    Test obj1(10,10);
    obj1.setX(25);
    obj1.setY(50);
    obj1.print();
    return 0;
}