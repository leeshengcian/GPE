#include <bits/stdc++.h>
using namespace std;

int main() {
    const double pi = M_PI;
    double n;

    while (cin >> n) {
        if (n == 0) break;

        double ans1, ans2, ans3;

        ans3 = ((n * n / 2.0) - (n * n * sqrt(3.0) / 8.0) - (n * n * pi / 12.0)) * 8;   // (一半正方形 - 一半正三角 - 30度扇形) * 8
        ans2 = ((n * n) - (n * n * pi / 4.0) - (ans3 / 2.0)) * 4;
        ans1 = n * n - ans2 - ans3;

        cout << fixed << setprecision(3) << ans1 << " " << ans2 << " " << ans3 << endl;
    }

    return 0;
}
