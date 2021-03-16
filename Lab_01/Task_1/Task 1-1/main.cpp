#define _USE_MATH_DEFINES // for C++

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const auto x = 0.29;
    const auto y = 3.7;
    const auto z = -1.0;

    const auto a = 3.0 * pow(x, y) * log(y) + exp(z * x);
    const auto b = abs(2.0 * y * z) / (sin(x) * sin(x)) - x * x / 3.0;

    cout << "x = " << x << ", y =  "<< y << ", z = " << z << "\n";
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}