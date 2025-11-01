#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    while(cin >> num){
        vector<int> arr(num);
        for(int i = 0; i < num; i++){
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        if(num % 2 == 1){
            int medium = arr[num / 2];
            int count = 0;
            for (int j = 0; j < arr.size(); j++){
                if(medium == arr[j])
                    count++;
            }
            cout << medium << " " << count << " " << "1\n";
        }
        else{
            int med1 = arr[num / 2 - 1];
            int med2 = arr[num / 2];
            
            int count = 0;
            for (int j = 0; j < arr.size(); j++){
                if(med1 <= arr[j] && arr[j] <= med2){
                    count++;
                }
            }
            cout << med1 << " " << count << " " << med2 - med1 + 1 << endl;
        }
    }
}