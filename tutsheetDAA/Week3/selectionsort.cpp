#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int array[n];
    int i, j;
    int swaps = 0;
    for (i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    for (i = 0; i < n; i++)
    {
        int minidx = i;
        for (j = i + 1; j < n; j++)
        {
            if (array[minidx] > array[j])
            {
                minidx = j;
            }
        }
        int temp = array[minidx];
        array[minidx] = array[i];
        array[i] = temp;
        swaps++;
    }
    for (i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "swaps=" << swaps << endl;
    return 0;
}