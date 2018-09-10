#include <bits/stdc++.h>

using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    vector<int> res;
    for(int i = m; i<=n; i++){
    	int a = i/100;
        int b = i/10 - a*10;
        int c = i%10;
        if (a*a*a + b*b*b + c*c*c == i) res.push_back(i);
    }
    
    if(res.empty()) cout << "no" << endl;
    else {
    	for(int i = 0; i<res.size(); i++){
        	cout << res[i];
            if (i != res.size()-1) cout << " ";
        }
    }
    cout << endl;
    return 0;
}