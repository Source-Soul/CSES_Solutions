#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> desired(n);
    for (int i = 0; i < n; i++)
    {
        cin >> desired[i];
    }

    vector<int> available(m);
    for (int i = 0; i < m; i++)
    {
        cin >> available[i];
    }

    sort(desired.begin(), desired.end());
    sort(available.begin(), available.end());

    int i = 0, j = 0, count = 0;
    while (i < n && j < m)
    {
        if (abs(desired[i] - available[j]) <= k)
        {
            count++;
            i++;
            j++;
        }
        else if (desired[i] < available[j] - k)
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    cout << count << endl;

    return 0;
}
