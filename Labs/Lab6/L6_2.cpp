
#include <bits/stdc++.h>
using namespace std;

void printarr(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int twoStacks(int maxSum, vector<int> a, vector<int> b)
{
    int nA = a.size();
    int nB = b.size();

    int i = 0, j = 0;
    int count = 0, sum = 0;

    // Take elements from stack a until the running sum exceeds maxSum
    while (i < nA && sum + a[i] <= maxSum)
    {
        sum += a[i];
        i++;
        count++;
    }

    // Take elements from stack b until the running sum exceeds maxSum, but remove elements from stack a as well
    while (j < nB && i >= 0)
    {
        sum += b[j];
        j++;
        while (sum > maxSum && i > 0)
        {
            i--;
            sum -= a[i];
        }
        if (sum <= maxSum && i + j > count)
        {
            count = i + j;
        }
    }

   return count;
}
int main()
{
    vector<int> a = {4,2,4,6,1};
    vector<int> b = {2,1,8,5};

    cout << twoStacks(10, a, b);

    return 0;
}