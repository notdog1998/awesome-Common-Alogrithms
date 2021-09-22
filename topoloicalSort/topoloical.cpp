#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> bfs(vector<vector<int>>& edges)
{
    int n = edges.size();
    //入度
    vector<int> indeg(n, 0);
    vector<int> res;

    for (int i = 0; i < n; i++)
    {
        for(int x : edges[i])
        {
            indeg[x]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if(indeg[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        res.push_back(u);
        for(auto& v : edges[u])
        {
            indeg[v]--;
            if(indeg[v] == 0)
            {
                q.push(v);
            }
        }
    }
    
    if(res.size() != n)
    {
        return {};
    }
    return res;
}

void dfs(int u, vector<vector<int>>& edges, vector<int>& visited, bool& valid, vector<int>& ans)
{
    visited[u] = 1;
    for(auto v : edges[u])
    {
        if(visited[v] == 0)
        {
            dfs(v, edges, visited, valid, ans);
            if(!valid)
                return;
        }
        else if(visited[v] == 1)
        {
            valid = false;
            return;
        }
    }
    visited[u] = 2;
    ans.push_back(u);
}

int main()
{
    vector<vector<int>> graph = {{0, 1}, {0, 2}, {1, 3}, {2, 3}};
    //图转成邻接表
    int n = graph.size();
    vector<vector<int>> edges(n);
    for(auto& info : graph)
    {
        edges[info[0]].push_back(info[1]);
    }
    int vertexNum = edges.size();
    
    //bfs
    vector<int> resBfs = bfs(edges);

    //dfs
    // 0:未访问；1:正在访问；2：已访问
    vector<int> visited(vertexNum, 0);
    //有环判断
    //true无环；false有环
    bool valid = true;
    vector<int> resDfs;
    for (int i = 0; i < vertexNum; i++)
    {
        if(visited[i] == 0)
        {
            dfs(i, edges, visited, valid, resDfs);
        }
    }
    if(valid)
    {
        reverse(resDfs.begin(), resDfs.end());
    }
    else
    {
        cout << "有环" << endl;
    }
    return 0;
}