#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<char>> matrix(N, vector<char>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> matrix[i][j];

    vector<int> x(K);
    vector<int> y(K);
    for (int i = 0; i < K; i++)
    {
        cin >> x[i] >> y[i];
        --x[i]; --y[i];
    }

    vector<vector<int>> dist(N, vector<int>(M));
    vector<vector<bool>> visited(N, vector<bool>(M));
    queue<pair<int, int>> q;
    for (int s = 0; s < K; s++)
    {
        pair<int, int> start = {x[s], y[s]};
        q.push(start);
        visited[start.first][start.second] = true;
        dist[start.first][start.second] = 0;
    }

    while (!q.empty())
    {
        pair<int, int> node = q.front();
        q.pop();

        if (node.first > 0 && matrix[node.first - 1][node.second] == '.' && !visited[node.first - 1][node.second])
        {
            pair<int, int> to = {node.first - 1, node.second};
            q.push(to);
            visited[to.first][to.second] = true;
            dist[to.first][to.second] = dist[node.first][node.second] + 1;
        }
        if (node.first < N - 1 && matrix[node.first + 1][node.second] == '.' && !visited[node.first + 1][node.second])
        {
            pair<int, int> to = {node.first + 1, node.second};
            q.push(to);
            visited[to.first][to.second] = true;
            dist[to.first][to.second] = dist[node.first][node.second] + 1;
        }
        if (node.second > 0 && matrix[node.first][node.second - 1] == '.' && !visited[node.first][node.second - 1])
        {
            pair<int, int> to = {node.first, node.second - 1};
            q.push(to);
            visited[to.first][to.second] = true;
            dist[to.first][to.second] = dist[node.first][node.second] + 1;
        }
        if (node.second < M - 1 && matrix[node.first][node.second + 1] == '.' && !visited[node.first][node.second + 1])
        {
            pair<int, int> to = {node.first, node.second + 1};
            q.push(to);
            visited[to.first][to.second] = true;
            dist[to.first][to.second] = dist[node.first][node.second] + 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            ans += dist[i][j];
    cout << ans << '\n';
}