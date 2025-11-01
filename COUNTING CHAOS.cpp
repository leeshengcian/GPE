#include <iostream>
#include <iomanip>
using namespace std;
 
int main() {
    int T, hh, mm;
    string s;
    cin >> T;
    while (T--){
        cin >> s;
        int minute = (s[0] - '0') * 600 + (s[1] - '0') * 60 + (s[3] - '0') * 10 + (s[4] - '0');
        while (1){
            minute++;
            if (minute >= 1440) minute = 0;
            hh = minute / 60;
            mm = minute % 60;
            if (hh == 0){
                if (mm < 10 || (mm / 10 == mm % 10)){
                    break;
                }
            } 
            else if (hh < 10){
                if (hh == mm % 10){
                    break;
                }
            } 
            else {
                if ((hh/10 == mm%10) && (hh%10 == mm/10)){
                    break;
                }
            }
        }
        cout << setw(2) << setfill('0') << hh << ":" << setw(2) << setfill('0') << mm << "\n";
    }
}