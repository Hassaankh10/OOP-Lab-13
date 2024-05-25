#include <iostream>
using namespace std;
template <class T>
class Array
{
    int size;
    T *arr;

public:
    Array()
    {
        arr = nullptr;
        size = 0;
    }

    ~Array()
    {
        delete[] arr;
    }

    void input()
    {
        cout << "Enter size of array: ";
        cin >> size;
        arr = new T[size];
        cout << "Enter array elements: ";
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
    }

    void sum()
    {
        T sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += arr[i];
        }
        cout << "Sum of array elements: " << sum << endl;
    }
};

int main()
{
    Array<char> a;
    a.input();
    a.sum();

    return 0;
}
