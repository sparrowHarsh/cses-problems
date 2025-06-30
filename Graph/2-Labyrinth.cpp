/**
*    Coded by :  Harsh vardhan 
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MODE 1000000007

/**
 * ShortestPath: BFS Algorithm
 * Constraints are high, so we use path tracking to reconstruct the path.
 */

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char dr[4] = {'R', 'L', 'D', 'U'};

bool isValidIndex(int x, int y, int n, int m) {
    return (x >= 0 && y >= 0 && x < n && y < m);
}

void harsh() {
    ll n, m;
    cin >> n >> m;

    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<vector<char>> path(n, vector<char>(m, '#'));

    queue<vector<int>> q;
    int sti = -1, stj = -1, eni = -1, enj = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '#') visited[i][j] = 1;
            if (v[i][j] == 'A') {
                sti = i;
                stj = j;
            }
            if (v[i][j] == 'B') {
                eni = i;
                enj = j;
            }
        }
    }

    q.push({sti, stj});
    visited[sti][stj] = 1;

    while (!q.empty()) {
        auto it = q.front();
        q.pop();

        int x = it[0], y = it[1];

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (isValidIndex(nx, ny, n, m) && !visited[nx][ny] && v[nx][ny] != '#') {
                visited[nx][ny] = 1;
                path[nx][ny] = dr[i];
                q.push({nx, ny});
            }
        }
    }

    if (path[eni][enj] == '#') {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    string ans = "";
    int x = eni, y = enj;

    while (x != sti || y != stj) {
        char dir = path[x][y];
        ans += dir;

        // Backtrack based on direction
        if (dir == 'R') y -= 1;
        else if (dir == 'L') y += 1;
        else if (dir == 'D') x -= 1;
        else if (dir == 'U') x += 1;
    }

    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    harsh();
    return 0;
}
