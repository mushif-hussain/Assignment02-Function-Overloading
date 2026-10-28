#include <iostream>
using namespace std;

// Answer 1: (c):  why do you have to write 0 for sms even though
//           its default value is already 0?
//            Kyunkeh C++ mein  arguments hamesha right side se shuru hotay hein
//              data pass karna ho to to  beech wala argument yani sms
//              skip nahi hoskta isliye wahan 0 likhna parta hai.

// Answer 2: What error does the call mobileBill(60, , 1.5) give, and why?
// syntax arrour ayega kukeh (, , ) iski help se c++ me koi argument skip nahi kiya jaskta
//           Yeh syntax error deta hai kyunki C++ mein arguments ke darmiyan khali comma (,,) 
//              chhod kar koi argument skip nahi kiya ja sakta.

double mobileBill(int minutes, int sms = 0, double data = 0.0);   
void printLine(char ch = '-', int n = 30);                  

int main()
{
    printLine();
    cout << "Bill 1: " << mobileBill(100) << endl;
    cout << "Bill 2: " << mobileBill(100, 50) << endl;
    cout << "Bill 3: " << mobileBill(100, 50, 2.5) << endl;
    printLine('*', 10);

    cout << "Bill 4: " << mobileBill(60, 0, 1.5) << endl;   // (c)
    printLine('=');
    return 0;
}

double mobileBill(int minutes, int sms, double data)
{    // (d)
    return (minutes * 2.0) + (sms * 1.0) + (data * 150.0); // (e)
}

void printLine(char ch, int n)
{                   // (f)
    for (int i = 0; i < n; i++) cout << ch;            // (g)
    cout << endl;
}