#include <iostream>
using namespace std;

int main()
{
    int arr[20], n;
    cout << "\nEnter the size of array : ";
    cin >> n;

    cout << "\nEnter elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {

            if (arr[i] == arr[j])
            {
                for (int k = j; k < n - 1; k++)
                {

                    arr[k] = arr[k + 1];
                }

                n--;
                j--;
            }
        }
    }

    cout << "\nArray after removing redundant elements : ";
    for (int i = 0; i < n; i++)

        cout << arr[i] << " ";
    return 0;
}