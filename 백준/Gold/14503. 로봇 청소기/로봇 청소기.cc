#include <bits/stdc++.h>
using namespace std;

// 방향: 0=북, 1=동, 2=남, 3=서
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

inline bool inRange(int x, int y, int N, int M) {
    return (0 <= x && x < N && 0 <= y && y < M);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int r, c, d;
    cin >> r >> c >> d;

    vector<vector<int>> room(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> room[i][j];   // 0=빈칸, 1=벽
        }
    }

    vector<vector<bool>> cleaned(N, vector<bool>(M, false));
    int cleanedCount = 0;

    while (true) {
        // 1) 현재 칸 청소
        if (!cleaned[r][c]) {
            cleaned[r][c] = true;
            ++cleanedCount;
        }

        // 2) 주변 4칸 중 청소되지 않은 빈칸이 있는지 확인(반시계 회전하며 앞칸 탐색)
        bool moved = false;
        for (int t = 0; t < 4; ++t) {
            d = (d + 3) % 4; // 반시계 90도 회전
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (inRange(nr, nc, N, M) && room[nr][nc] == 0 && !cleaned[nr][nc]) {
                // 앞칸으로 전진
                r = nr;
                c = nc;
                moved = true;
                break;
            }
        }

        if (moved) continue; // 전진했으면 1번부터 반복

        // 3) 네 방향 모두 못 갔으면 뒤로 한 칸 후진 시도
        int backDir = (d + 2) % 4;
        int br = r + dr[backDir];
        int bc = c + dc[backDir];

        // 뒤가 벽이면 종료
        if (!inRange(br, bc, N, M) || room[br][bc] == 1) break;

        // 후진만 하고 방향은 유지
        r = br;
        c = bc;
    }

    cout << cleanedCount << "\n";
    return 0;
}
