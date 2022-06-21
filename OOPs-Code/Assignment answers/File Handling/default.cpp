#include <iostream>
using namespace std;
// This function can only throw ints, chars, and doubles.
void Xhandler(int test) throw(int)
{
/* The following statements no longer work. Instead,
they will cause an abnormal program termination. */
if(test==0) throw test;
if(test==1) throw 'a';
if(test==2) throw 123.23;
}

int main()
{
    cout << "start\n";
    try
    {
        Xhandler(0); // also, try passing 1 and 2 to Xhandler()
    }
    catch (int i)
    {
        cout << "Caught an integer\n";
    }
    catch (char c)
    {
        cout << "Caught char\n";
    }
    catch (double d)
    {
        cout << "Caught double\n";
    }
    cout << "end";
    return 0;
}