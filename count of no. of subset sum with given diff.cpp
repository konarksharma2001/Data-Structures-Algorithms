int countsubsetSum(int a[], int n, int sum)
{
    // Initializing the matrix
    int dp[n + 1][sum + 1];
    for (int i = 0; i <= sum; i++)
    {
        for (int j = 0; i <= n; i++)
        {

            if (i == 0)
                dp[i][j] = false;
            if (j == 0)
                dp[i][j] = true;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (a[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
}

int countWithGivenSum(int arr[], int n, int diff)
{
    int sumofarray = 0;
    for (int i = 0; i < n; i++)
    {
        sumofarray += arr[i];
    }

    int sum = (diff + sumofarray) / 2;
    return subsetSum(arr, nsum);
}

int main()
{

    int arr[4] = {1, 1, 2, 3};
    int diff = 1;

    int ans = countWithGivenSum(arr, 4, diff);

    cout << endl;
    cout << "Count of No. of Subsets with given Difference is " << ans;
    cout << endl;

    return 0;
}