#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int array[n];
    int i, j, swaps = 0;
    for (i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        int current = array[i];
        while (array[j] > current && j != 0)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = current;
        swaps++;
    }
    for (i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "swaps=" << swaps << endl;
}