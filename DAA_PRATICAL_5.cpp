#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weight(n), profit(n);

    cout << "Enter weights of " << n << " items:\n";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    cout << "Enter profits of " << n << " items:\n";
    for (int i = 0; i < n; i++) {
        cin >> profit[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    // DP table
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Dynamic Programming
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {

            if (weight[i - 1] <= w) {
                dp[i][w] = max(
                    profit[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "\nMaximum Profit = " << dp[n][capacity] << endl;

    // Find selected items
    int w = capacity;

    cout << "Selected items: ";

    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << i << " ";
            w = w - weight[i - 1];
        }
    }

    cout << endl;

    return 0;
}
