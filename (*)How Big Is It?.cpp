#include <bits/stdc++.h>
using namespace std;

double minWidth(const vector<double>& radius){
    int size = radius.size();
    vector<int> perm(size);
    iota(perm.begin(), perm.end(), 0);
    double result = 1e9;

    do{
        vector<double> x(size);
        x[0] = 0;

        for(int i = 1; i < size; i++){
            x[i] = 1e9;
            for(int j = 0; j < i; j++){
                double dx = sqrt((radius[perm[i]] + radius[perm[j]]) * (radius[perm[i]] + radius[perm[j]]) - (radius[perm[i]] - radius[perm[j]]) * (radius[perm[i]] - radius[perm[j]]));
                x[i] = max(x[i], x[j] + dx);
            }
        }

        double left = 1e9;
        double right = -1e9;

        for(int i = 0; i < size; i++){
            left = min(left, x[i] - radius[perm[i]]);
            right = max(right, x[i] + radius[perm[i]]);
        }
        result = min(result, right - left);

    } while (next_permutation(perm.begin(), perm.end()));

    return result;
}

int main(){
    int n;
    cin >> n;

    while(n--){
        int num;
        cin >> num;
        
        vector<double> radius_set(num);
        for(int i = 0; i < num; i++){
            cin >> radius_set[i];
        }
        cout << fixed << setprecision(3) << minWidth(radius_set) << endl;
    }
}