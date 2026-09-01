class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        int startX = -1, startY = -1;
        vector<pair<int, int>> litters;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') startX = i, startY = j;
                else if (classroom[i][j] == 'L') litters.push_back({i, j});
            }
        }

        int targetMask = (1 << litters.size()) - 1;
        if (targetMask == 0) return 0;

        // Map (r, c) of each litter cell to bit index
        auto getLitterIdx = [&](int r, int c) {
            for (int i = 0; i < litters.size(); ++i) {
                if (litters[i].first == r && litters[i].second == c) return i;
            }
            return -1;
        };

        // Stores maximum remaining energy reached for (row, col, mask)
        vector<vector<vector<int>>> maxEnergy(m, vector<vector<int>>(n, vector<int>(1 << litters.size(), -1)));
        
        // Queue stores {r, c, mask, current_energy, steps}
        queue<tuple<int, int, int, int, int>> q;

        int initMask = 0;
        int startLitter = getLitterIdx(startX, startY);
        if (startLitter != -1) initMask |= (1 << startLitter);

        q.push({startX, startY, initMask, energy, 0});
        maxEnergy[startX][startY][initMask] = energy;

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            auto [r, c, mask, e, steps] = q.front();
            q.pop();

            if (mask == targetMask) return steps;
            if (e == 0) continue;

            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n || classroom[nr][nc] == 'X') continue;

                int nextE = e - 1;
                int nextMask = mask;

                if (classroom[nr][nc] == 'R') {
                    nextE = energy;
                } else if (classroom[nr][nc] == 'L') {
                    int idx = getLitterIdx(nr, nc);
                    if (idx != -1) nextMask |= (1 << idx);
                }

                if (nextE > maxEnergy[nr][nc][nextMask]) {
                    maxEnergy[nr][nc][nextMask] = nextE;
                    q.push({nr, nc, nextMask, nextE, steps + 1});
                }
            }
        }

        return -1;
    }
};