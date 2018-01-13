#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a, b, max, local_max;
    int A[10] = {};
    cin >> a >> b;
    if (a.length() < b.length()){
        sort(a.begin(), a.end(), greater<char>());
        cout << a << endl;
    } else {
        for (int i = 0; i <= a.length(); i++){
            A[a[i] - '0'] += 1;
        }
        local_max = "";
        for (int i = 0; i < b.length(); i++){
            int j = 0;
            for (j = 0; j <= b[i] - '0'; j++){
                if (A[(b[i] - '0') - j] > 0){
                    local_max += to_string((b[i] - '0') - j);
                    A[(b[i] - '0') - j] -= 1;
                    break;
                }
            }
            if (j == (b[i] - '0') + 1){
                for (j = 0; j < 10; j++){
                    while (A[j] > 0) {
                        local_max += to_string(j);
                        A[j] -= 1;
                    }
                }
                break;
            }
        }
        max = local_max;
        if (local_max < b){
            while (next_permutation(local_max.begin(), local_max.end())){
                if (local_max <= b){
                    max = local_max;
                } else {
                    break;
                }
            }
            cout << max << endl;
        } else if (local_max > b){
            while (prev_permutation(local_max.begin(), local_max.end())){
                if (local_max <= b){
                    max = local_max;
                    break;
                }
            }
            cout << max << endl;
        } else {
            cout << local_max << endl;
        }
    }
    return 0;
}
