#include<bits/stdc++.h>
using namespace std;

int countSolved(string s, int n){
    int count=0;
    unordered_map<char, int> mp;
    for(int i=0;i<n;i++)
        mp[s[i]]++;
    for(auto it:mp)
    {
        if(it.second>=(it.first-'A'+1))
            count++;
    }
    return count;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        cout<<countSolved(s, n)<<endl;
    }  
    
    return 0;
}