#define T1
#ifdef T1

#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vi;
vector<pair<int,int>> ans;
int out = 1;
vector<int> final;
int sum = 0;

vector<int> vis;
void DFS(vi & vec, int i){
    vis[i] = 1;
    for(int j = 0; j < vec[i].size(); j++){
        if (!vis[vec[i][j]])
            DFS(vec, vec[i][j]);
    }
    ans.push_back(pair<int,int>(out++, i));
}

void rev_DFS(vi & vec, int i){
    vis[i] = 1;
    final[i] = sum;
    for(int j = 0; j < vec[i].size(); j++){
        if (!vis[vec[i][j]])
            rev_DFS(vec, vec[i][j]);
    }
}

int main() {

    ios::sync_with_stdio(0);

    int n, e;
    cin >> n >> e;
    int a, b;
    char c;
    vector<vector<int>> vec(n), rev(n);
    vis.resize(n, 0);
    for (int i = 0; i < e; ++i) {
        cin >> a >> c >> b;
        vec[a].push_back(b);
        rev[b].push_back(a);
    }
    for(int i = 0; i < n; i++) {
        if (!vis[i])
            DFS(vec, i);
    }
    sort(ans.rbegin(), ans.rend());
    vis.clear();
    vis.resize(n, 0);
    final.resize(n);
    for(int i = 0; i < ans.size(); i++){
        if(!vis[ans[i].second]){
            rev_DFS(rev, ans[i].second);
            sum++;
        }
    }
    sum--;
    for(int i = 0; i < final.size() - 1; i++){
        cout << sum - final[i] << " ";
    }
    cout << sum - final[final.size() - 1] << endl;


    return 0;
}




#endif
