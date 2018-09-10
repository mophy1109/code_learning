#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    cin >> str;
    int a[256];
    memset(a, 0, sizeof a);
    int s = 0, e = 0;
    int maxval = 0;

    for(e = 0; e<str.length();e++){
        if(a[str[e]] == 0){
            a[str[e]]++;
            // cout << e <<endl;
        }else{
            maxval = max(maxval, e-s+1);
            // cout << s << "," << e <<endl;
            s = e;
            e--;
            memset(a, 0, sizeof a);
        }
    }
    // maxval = max(maxval, e-s+1);
    cout << maxval <<endl;
    return 0;
}
