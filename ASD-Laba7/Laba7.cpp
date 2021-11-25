#include <iostream>

using namespace std;

void Input_array(char*, char*, char*, int);   // ���������� ������
int Output_array(char*, char*, char*, int);   // �������� ������
void Solution(char*, int);                    // ������������ ����� �����
void Browse(char*, int);                      // �������� ������� �����

int main()
{
    const int n = 10; // ����� ������
    int m;            // �����, �� ������� ������ ������
    char array1[n];   // ������ �����
    char array2[n];   // ������ �����
    char array3[n];   // ����� �����
    
    Input_array(array1, array2, array3, n);
    m = Output_array(array1, array2, array3, n);
    Solution(array3, m);
    Browse(array3, m);
    
    return 0;
}

void Input_array(char *p, char *g, char *s, int n)
{
	// ���������� ������ � ������ ������
    for (int i = 0; i < n; i++) 
    {
        *p = 120 - i;
        *g = 110 + i;
        p++;
        g++;
    }
    
    // ���������� ����� �����
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (*(p - n + i) == *(g - n + j))
            {
                *s = *(g - n + j);
            }
        }
        s++;
    }
}

int Output_array(char *p, char *g, char *s, int m)
{
	// �������� ������
    cout << "Array1: ";
    for (int i = 0; i < m; i++)
    {
        cout << *(p + i) << " ";
    }
    cout << "\nArray2: ";
    for (int i = 0; i < m; i++)
    {
        cout << *(g + i) << " ";
    }
    cout << "\nArray3: ";
    for (int i = 0; i < m; i++)
    {
        if (*(s+i) == 0) // ��������� �������� � �������� ���������
        {
            m = m-1;
            for (int k = 0; k < m; k++)
            {
                *(s + k) = *(s + k + 1);
            }
        }
        cout << *(s + i) << " ";
    }
    return m;
}

void Solution(char* s, int m)
{
    int a, b;     // a - ������ ����������� ������, b - ������ ������������� ��������
    int sum = 0;  // ���� �������� ������
    char max = 0; // ������������ ������� ������
    
    for (int i = 0; i < m; i++)
    {
        sum += *(s + i);    // ��������� ���� ��������
        
        // ��������� ����������� �������� ������
        if (*(s + i) > max)
        {
            max = *(s + i); 
            b = i;
        }
    }
    
    a = sum/m;     // ������ ����������� �������� ������
    *(s + b) = a; // �������� ������������ ������� ��������������������
}

void Browse(char* s, int m)
{
    // �������� ������� �����
    cout << "\nAnswer: ";
    for (int i = 0; i < m; i++)
    {
        cout << *(s+i) << " ";
    }
}