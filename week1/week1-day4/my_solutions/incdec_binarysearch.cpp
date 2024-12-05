// week1-day4 binary search , highest from array of increasing and decreasing //

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0 ; i <n ; ++i){
        cin >> arr[i];
    }

    int l = 0;
    int r = n-1;
    int mid = l + abs((r-l)/2);

    while (l < r)
    {
        mid = l + abs((r-l)/2);
        if (arr[mid] > arr[mid+1])
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l;
    return 0;


}