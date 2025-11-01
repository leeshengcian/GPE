#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    while(cin >> num && num != 0){
        map<vector<int>, int> course_count;
        for(int i = 0; i < num; i++){
            vector<int> course(5);
            for(int j = 0; j < 5; j++){
                cin >> course[j];
            }
            sort(course.begin(), course.end());
            course_count[course]++;
        }
        
        int max_count = 0;
        int result = 0;

        for(const auto& pair : course_count){
            if(pair.second > max_count){
                max_count = pair.second;
                result = pair.second;
            }

            else if(pair.second == max_count){
                result += pair.second;
            }
        }

        cout << result << endl;
    }

    return 0;
}