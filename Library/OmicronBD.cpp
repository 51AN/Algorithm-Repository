#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 100; // maximum size of the residential area

int n, m; // dimensions of the residential area
char grid[MAXN][MAXN]; // grid of the residential area
bool visited[MAXN][MAXN]; // visited buildings
int days[MAXN][MAXN]; // number of days it takes to infect each building

// checks if the given coordinates (i, j) are inside the grid
bool isInside(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

// BFS to infect neighboring buildings
void infect(int i, int j, int day, queue<pair<int, int>> &q) {
    visited[i][j] = true;
    days[i][j] = day;
    if (isInside(i-1, j) && grid[i-1][j] == 'Y' && !visited[i-1][j]) {
        grid[i-1][j] = 'X';
        q.push({i-1, j});
    }
    if (isInside(i+1, j) && grid[i+1][j] == 'Y' && !visited[i+1][j]) {
        grid[i+1][j] = 'X';
        q.push({i+1, j});
    }
    if (isInside(i, j-1) && grid[i][j-1] == 'Y' && !visited[i][j-1]) {
        grid[i][j-1] = 'X';
        q.push({i, j-1});
    }
    if (isInside(i, j+1) && grid[i][j+1] == 'Y' && !visited[i][j+1]) {
        grid[i][j+1] = 'X';
        q.push({i, j+1});
    }
}

// returns the number of days it takes to infect the whole residential area
int getInfectionDays() {
    queue<pair<int, int>> q;
    int day = 0;
    // add initially infected buildings to the queue
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'X') {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        int size = q.size();
        for (int k = 0; k < size; k++) {
            pair<int, int> p = q.front();
            q.pop();
            infect(p.first, p.second, day, q);
        }
        day++;
    }
    return day;
}

int main(){

    
    return 0;
}