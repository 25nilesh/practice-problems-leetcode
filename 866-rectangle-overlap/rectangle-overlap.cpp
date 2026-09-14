class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        bool ans=true;
        int x1=rec1[0],y1=rec1[1],x2=rec1[2],y2=rec1[3];
        if(rec2[0]>=x2 || rec2[1]>=y2 || rec2[3]<=y1 || rec2[2]<=x1) ans=false;
        return ans;
    }
};