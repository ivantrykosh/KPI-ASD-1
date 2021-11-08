#include <iostream>

using namespace std;

double dif_y(int);
double a,d;
int n;

int main()
{
    double an;
    cout << "Enter the first term of the arithmetic progression: ";
    cin >> a;
    cout << "Enter the difference of the arithmetic progression: ";
    cin >> d;
    cout << "Enter n > 0: ";
    cin >> n;
    an = a + dif_y(n);
    cout << n << "-term of the arithmetic progression = " << an;
}

double dif_y(int k)
{
    if (k > 1)
    {
        return d + dif_y(k-1);
    }
    return 0;
}