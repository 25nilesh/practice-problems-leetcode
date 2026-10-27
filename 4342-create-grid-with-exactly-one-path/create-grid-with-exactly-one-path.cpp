class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<vector<char>> grid(m,vector<char> (n,'#'));
        vector<string> result;
        for(int i=0;i<m;i++){
            grid[i][0]='.';
        }
        for(int i=0;i<n;i++){
            grid[m-1][i]='.';
        }
        for(int i=0;i<m;i++){
            string str="";
            for(int j=0;j<n;j++){
                str+=grid[i][j];
            }
            result.push_back(str);
        }
        return result;
    }
};