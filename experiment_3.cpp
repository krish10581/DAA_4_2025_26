#include<iostream>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    cin >> N;
    unordered_map<int,int>f;
    f[0]=-1;
    int sum=0,ans=0;
    for (int i=0;i<N;i++) {
        char c;
        cin>>c;

        if(c=='P'){
            sum++;
        }else if(c=='A'){
            sum--;
        }

        if(f.count(sum)){
            ans=max(ans,i-f[sum]);
        }else{
            f[sum]=i;
        }
    }
    cout << ans;
    return 0;
}
