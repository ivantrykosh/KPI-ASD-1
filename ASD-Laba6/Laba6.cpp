#include <iostream>
using namespace std;

double dif_y(int, double); // ��������� �������

int main()
{
    double a, d, an;   // ������ ����, ������ � n-�� ����
    int n;             // ʳ������ ����� ����������� �������
    cout << "Enter the first term of the arithmetic progression: ";
    cin >> a;
    cout << "Enter the difference of the arithmetic progression: ";
    cin >> d;
    cout << "Enter n > 0: ";
    cin >> n;
    an = a + dif_y(n, d);  // ���������� n-�� ����
    cout << n << "-term of the arithmetic progression = " << an;
}

double dif_y(int k, double d)
{
    if (k > 1)
    {
        return d + dif_y(k-1, d); // ��������� ������ � ��������� ������� 
    }
    return 0;
}
