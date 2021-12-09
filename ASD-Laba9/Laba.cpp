#include <iostream>
#include <stdlib.h>

using namespace std;

void Inp_Out_A(double*, int, int); // ���������� �� �������� ������ �����
void Solution(double*, int, int, double&, int&, int&, double&); // ���������� �����
void Out_answer(double*, int, int, double&, int&, int&, double&); // �������� ������� �����

int main()
{
    const int m = 5; // ʳ������ �����
    const int n = 5; // ʳ������ ��������
    double A[m][n];  // ��������� �����
    double x = 10.1; // ̳�������� �������
    // ������� ���������� ��������
    int row;
    int column;
    // ������������������� �������� ��������
    double sum = 0;
    
    Inp_Out_A(&A[0][0], m, n); // ���������� �� �������� ������ �����
    Solution(&A[0][0], m, n, x, row, column, sum); // ���������� �����
    Out_answer(&A[0][0], m, n, x, row, column, sum); // �������� ������� �����
}

void Inp_Out_A(double* p, int m, int n)
{
    srand(time(NULL));
    cout << "Array A:";
    for (int i = 0; i < m; i++)
    {
        cout << "\n";
        for (int j = 0; j < n; j++)
        {
            *(p + m * i + j) = (double)(rand()) / RAND_MAX * 10; // ��������� ����� ����� �� 0 �� 10
            printf("  %.2f", *(p + m * i + j)); //  �������� �������� ������
        }
    }
}

void Solution(double* p, int m, int n, double& x, int& row, int& column, double& sum)
{
    bool flag = false; // ��� ������ ������ �� ���������
    int a = 0; // ʳ������ �������� ��� �������� ���������
    
    // ��������� ������������������� �������� �������� � ��������� �������
    for (int i = 0; i < m; i++)
    {
        if (flag == false)
        {
            for (int j = 0; j < n; j++) // ��������� ����� ����
            {
                if (i > j)
                {
                    sum += *(p + n * j + i); // ���������� ����
                    a++; // �������� ������� ��������
                }
                if (*(p + n * j + i) < x) // ��������� ��������� �������
                {
                    x = *(p + n * j + i);
                    row = j;
                    column = i;
                }
            }
        }
        else
        {
            for (int j = n - 1; j >= 0; j--) // ��������� ����� �����
            {
                if (i > j)
                {
                    sum += *(p + n * j + i); // ���������� ����
                    a++; // �������� ������� ��������
                }
                if (*(p + n * j + i) < x) // ��������� ��������� �������
                {
                    x = *(p + n * j + i);
                    row = j;
                    column = i;
                }
            }
        }
        flag = !flag; // ������� �� ���������� ��������
    }
    
    sum = sum / a; // ������ ����������� ��������
    flag = false; // ������� �� ���������� ��������
    
    /* �������� ����� � ������� ������� ��� �������� ���������,
       �� ������ �� ������������������� ��������, �� ��������� �������*/
    for (int i = 0; i < m; i++)
    {
        if (flag == false)
        {
            for (int j = 0; j < n; j++)
            {
                if (j < i)
                {
                    if (*(p + n * j + i) > sum) // ���������� �������
                    {
                        *(p + n * j + i) = x; // ������� ����
                    }
                }
            }
        }
        else
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (j < i)
                {
                    if (*(p + n * j + i) > sum) // ���������� �������
                    {
                        *(p + n * j + i) = x; // ������� ����
                    }
                }
            }
        }
        flag = !flag; // ������� �� ���������� ��������
    }

}

void Out_answer(double* p, int m, int n, double& x, int& row, int& column, double& sum)
{
    printf("\n\nX = %.2f", x); // �������� ��������� �������
    cout << "   row = " << row + 1 << "  column = " << column + 1; // �������� ���� �������
    printf("\nSum = %.2f\n", sum); // �������� ������������������� ��������
    cout << "\nAnswer: ";
    // �������� �����
    for (int i = 0; i < m; i++)
    {
        cout << "\n";
        for (int j = 0; j < n; j++)
        {
            printf("  %.2f", *(p + m * i + j));
        }
    }
}