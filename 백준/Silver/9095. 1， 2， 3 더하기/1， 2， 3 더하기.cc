#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // n <= 10 이므로 0..10까지 준비
    const int MAX_N = 10;
    long long dp[MAX_N + 1] = {0};

    // 기본값
    dp[0] = 1; // 편의를 위한 값 (아래 점화식 성립용)
    dp[1] = 1; // 1 -> (1)
    dp[2] = 2; // 2 -> (1+1, 2)
    dp[3] = 4; // 3 -> (1+1+1, 1+2, 2+1, 3)

    for (int i = 4; i <= MAX_N; ++i) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    int T; 
    cin >> T;
    while (T--) {
        int n; 
        cin >> n;          // 1 <= n <= 10 보장
        cout << dp[n] << "\n";
    }
    return 0;
}
