class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int startX = -1, startY = -1;
        vector<pair<int, int>> litters;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    startX = i;
                    startY = j;
                } else if (classroom[i][j] == 'L') {
                    litters.push_back({i, j});
                }
            }
        }
        
        int numLitters = litters.size();
        int targetMask = (1 << numLitters) - 1;
        
        auto getLitterIndex = [&](int r, int c) -> int {
            for (int i = 0; i < numLitters; ++i) {
                if (litters[i].first == r && litters[i].second == c) return i;
            }
            return -1;
        };
        
        int initialMask = 0;
        int initIdx = getLitterIndex(startX, startY);
        if (initIdx != -1) initialMask |= (1 << initIdx);
        
        if (initialMask == targetMask) return 0;

        vector<vector<vector<int>>> maxEnergySeen(m, vector<vector<int>>(n, vector<int>(1 << numLitters, -1)));
        
        queue<tuple<int, int, int, int>> q;
        q.push({startX, startY, initialMask, energy});
        maxEnergySeen[startX][startY][initialMask] = energy;
        
        int moves = 0;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c, mask, currEnergy] = q.front();
                q.pop();
                
                if (mask == targetMask) return moves;
                if (currEnergy == 0) continue; 
                
                for (auto& d : dirs) {
                    int nr = r + d[0];
                    int nc = c + d[1];
                    
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && classroom[nr][nc] != 'X') {
                        int nextEnergy = currEnergy - 1;
                        int nextMask = mask;
                        
                        if (classroom[nr][nc] == 'L') {
                            int idx = getLitterIndex(nr, nc);
                            if (idx != -1) nextMask |= (1 << idx);
                        }
                        
                        if (classroom[nr][nc] == 'R') {
                            nextEnergy = energy;
                        }
                        
                        if (nextEnergy > maxEnergySeen[nr][nc][nextMask]) {
                            maxEnergySeen[nr][nc][nextMask] = nextEnergy;
                            q.push({nr, nc, nextMask, nextEnergy});
                        }
                    }
                }
            }
            moves++;
        }
        
        return -1;
    }
};