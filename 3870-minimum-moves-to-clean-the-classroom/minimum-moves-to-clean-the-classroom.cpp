class Solution {
public:
    using VB = vector<bool>;
    using VVB = vector<VB>;
    using VVVB = vector<VVB>;
    using VVVVB = vector<VVVB>;

    vector<vector<int>> directions ={{-1,0},{1,0},{0,-1},{0,1}};

    struct State{
        int row;
        int col;
        int energyLeft;
        int collectedMask;
    };

    int minMoves(vector<string>& classroom, int energy) {
        int m=classroom.size();
        int n=classroom[0].size();
        int maxEnergy=energy;

        int litterBit[20][20]; 
        int litterCount=0;
        int startRow=0;
        int startCol=0;

        for(int x=0;x<m;x++){
            for(int y=0;y<n;y++){
                litterBit[x][y]=-1;
                if(classroom[x][y]=='S'){
                    startRow=x;
                    startCol=y;
                }else if(classroom[x][y]=='L') {
                    litterBit[x][y]=litterCount;
                    litterCount++;
                }
            }
        }
        if(litterCount==0) return 0;
        int allAllocated=(1<<litterCount)-1;

        VVVVB seen(m, VVVB(n, VVB(maxEnergy + 1, VB(1 << litterCount, false))));

        queue<State> que;
        que.push({startRow,startCol,maxEnergy,0});
        seen[startRow][startCol][maxEnergy][0]=true;
        int moves=0;
        while(!que.empty()){
            int currSize=que.size();
            while(currSize--){
                State curr=que.front();
                que.pop();

                if(curr.collectedMask==allAllocated){
                    return moves;
                }
                if(curr.energyLeft==0) continue;

                for(auto& dir:directions){
                    int nextRow=curr.row+dir[0];
                    int nextCol=curr.col+dir[1];

                    if(nextRow<0 || nextRow>=m || nextCol<0 || nextCol>=n){
                        continue;
                    }
                    char cell=classroom[nextRow][nextCol];
                    if(cell=='X') continue;
                    int nextEnergy=curr.energyLeft-1;
                    int nextMask=curr.collectedMask;

                    if(cell=='R'){
                        nextEnergy=maxEnergy;
                    }else if(cell=='L'){
                        nextMask|=(1<<litterBit[nextRow][nextCol]);
                    }

                    if(!seen[nextRow][nextCol][nextEnergy][nextMask]){
                        seen[nextRow][nextCol][nextEnergy][nextMask]=true;
                        que.push({nextRow,nextCol,nextEnergy,nextMask});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};