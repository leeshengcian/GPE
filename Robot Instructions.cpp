#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string dummy;
        getline(cin, dummy); // consume endline after n

        vector<int> moves;
        moves.reserve(n);

        for (int i = 0; i < n; ++i) {
            string line;
            getline(cin, line);

            if(line == "LEFT"){
                moves.push_back(-1);
            }
            else if(line == "RIGHT"){
                moves.push_back(1);
            }
            else{
                string word1, word2;
                int k;

                // sscanf(line.c_str(), "SAME AS %d", &k)
                stringstream ss(line);
                ss >> word1 >> word2 >> k;
                moves.push_back(moves[k-1]);
            }
        }

        int pos = accumulate(moves.begin(), moves.end(), 0);
        cout << pos << "\n";
    }
    return 0;
}