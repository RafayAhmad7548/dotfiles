#include <iostream>
using namespace std;

class A
{
public:
    A(int ii = 0) : i(ii) {}
    A(const A &abc)
    {
        this->i = abc.i;
        cout << "Out Of " << i - 1 << endl;
    }
    A magic(A abc)
    {
        this->i = i + 1;
        A bcd(this->i);
        return bcd;
    }
    ~A() { cout << "Out A " << i << endl; }

private:
    int i;
};

int main()
{
    A b(3), a(4);
    a = b.magic(a).magic(b);
}