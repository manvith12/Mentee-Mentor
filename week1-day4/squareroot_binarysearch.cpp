// week1-day4 binary search q2 , squareroot what??//

#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long l = 0;
    long long r = n;
    long long ans = -1;
    long long mid;

    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (mid * mid == n)
        {
            ans = mid;
            break;
        }
        else if (mid * mid < n)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}