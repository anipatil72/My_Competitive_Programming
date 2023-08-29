// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> image(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> image[i];
    }

    // Create a prefix sum matrix
    std::vector<std::vector<int>> prefix_sum(n + 1, std::vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + (image[i - 1][j - 1] == '1');
        }
    }

    int result = INT_MAX;

    // Iterate through possible k values
    for (int k = 2; k <= std::max(n, m); k++)
    {
        // Determine the dimensions of the padded image
        int padded_n = (n + k - 1) / k * k;
        int padded_m = (m + k - 1) / k * k;

        int toggles = 0;

        // Iterate through the blocks of the image
        for (int i = 0; i < padded_n; i += k)
        {
            for (int j = 0; j < padded_m; j += k)
            {
                int block_sum = prefix_sum[std::min(i + k, n)][std::min(j + k, m)] - prefix_sum[i][std::min(j + k, m)] - prefix_sum[std::min(i + k, n)][j] + prefix_sum[i][j];
                int total_pixels = k * k;
                int zeros = total_pixels - block_sum;
                toggles += std::min(block_sum, zeros);
            }
        }

        // Update the result if this k value gives a better solution
        result = std::min(result, toggles);
    }

    std::cout << result << std::endl;

    return 0;
}
// ॥ जय श्री राम जय श्री कृष्ण ॥