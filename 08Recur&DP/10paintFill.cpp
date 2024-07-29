//https://godbolt.org/z/59xraeGxf


#include<bits/stdc++.h>

using namespace std;
  
void dfs(vector<vector<int>> &screen, int i, int j, int newcolor, int oldcolor){
        // if corss the border, or 相邻数字与原数字不一样 or 新颜色与旧颜色一样 都不用对原数组修改
        if(i <0 ||j<0 || i>=screen.size()|| j>=screen[0].size() ||  screen[i][j] != oldcolor || oldcolor == newcolor) return;
        screen[i][j] = newcolor;
        dfs(screen, i-1, j, newcolor,oldcolor);
        dfs(screen, i+1, j, newcolor,oldcolor);
        dfs(screen, i, j-1, newcolor,oldcolor);
        dfs(screen, i, j+1, newcolor,oldcolor);
        
}

vector<vector<int>> paintFill(vector<vector<int>> &screen,int x, int y, int newcolor) {
        
        int prevColor = screen[x][y];
        dfs(screen, x,y, newcolor,prevColor);
        return screen;  
}



int main() {
    vector<vector<int>> screen = {
        {1, 1, 1, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1},
        {0, 0, 1, 1, 1},
        {0, 0, 0, 1, 1}
    };

    vector<vector<int>> screen2 = {{1,1,1},
                                    {1,1,0},
                                    {1,0,1}
                                };

    
    int startX = 1, startY = 1;
    int newColor = 2;
    int oldColor = screen2[startX][startY];
    
    paintFill(screen2, startX, startY, newColor);

    // 输出结果
    for (const auto& row : screen2) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}

