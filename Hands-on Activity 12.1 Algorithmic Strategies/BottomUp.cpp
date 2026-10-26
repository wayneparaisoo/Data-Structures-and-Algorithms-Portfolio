#include <iostream>
#include <algorithm>
#include <vector>

int getMinSteps ( int n )
{
    std::vector<int> dp(n + 1, 0);
    dp[1] = 0; // trivial case

    for ( int i = 2; i <= n; i++ )
    {
        dp[i] = 1 + dp[i-1];                                  // '-1' step
        if ( i%2 == 0 ) dp[i] = std::min( dp[i], 1 + dp[i/2] ); // '/2' step
        if ( i%3 == 0 ) dp[i] = std::min( dp[i], 1 + dp[i/3] ); // '/3' step
    }
    return dp[n];
}

int main(){
    int tests[] = {1, 4, 7, 10, 15, 27, 100};

    for (int n : tests) {
        std::cout << "n = " << n << " -> "<< " Steps = " << getMinSteps(n) << std::endl;
    }

}