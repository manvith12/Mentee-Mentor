//week1-day4-binarysearch q1//

#include <iostream>


using namespace std;


int main()
{   
    int n,q;
    cin >> n >> q;
    int arr[n];

    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    while(q--)
    {
        int x;
        cin >> x;
        int l=0, r=n-1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(arr[mid] == x)
            {
                cout << mid << endl;
                break;
            }
            else if(arr[mid] < x)
            {
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
        if(l>r)
        {
            cout << "-1" << endl;
        }
    }

    return 0;
}