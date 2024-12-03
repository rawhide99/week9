#include<iostream>
using namespace std;

class Demo
{
    private:
        int a;
    public:
        Demo(int a = 0)
        {
            this->a = a;
        }

        void print()
        {
            cout << "x = " << a << endl;
        }
};


int main()
{
    Demo D1(5);
    Demo *ptr = new Demo(10);
    D1.print();
    return 0;
}