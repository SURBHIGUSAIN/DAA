#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int array[n];
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    int key;
    cout << "enter key";
    cin >> key;
    int count = 0;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (abs(array[i] - array[j]) == key)
            {
                count++;
            }
        }
    }
    cout << count << endl;
}