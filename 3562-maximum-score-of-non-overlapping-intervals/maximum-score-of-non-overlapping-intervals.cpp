class Solution {
public:
    struct Node{
        long long score=-1;
        vector<int> idxs;
    };
    int n;
    vector<int> nextIdx;
    vector<vector<Node>> dp;
    int findIdx(vector<vector<int>>& intervals,int endPoint){
        int lo=0;
        int hi=n-1;
        int ans=n;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(intervals[mid][0]>endPoint){
                ans=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return ans;
    }
    Node solve(vector<vector<int>>& intervals,int i,int k){
        if(k==0 || i>=n) return Node();
        if(dp[i][k].score!=-1) return dp[i][k];
        int weight=intervals[i][2];
        int idx=intervals[i][3];
        int j=nextIdx[i];

        Node skip=solve(intervals,i+1,k);


        Node temp=solve(intervals,j,k-1);

        Node take;
        take.score=weight+temp.score;
        take.idxs=temp.idxs;
        take.idxs.push_back(idx);
        sort(begin(take.idxs),end(take.idxs));
        Node result;
        if(take.score>skip.score){
            result=take;
        }else if(take.score<skip.score){
            result=skip;
        }else{
            result=(take.idxs<skip.idxs)?take:skip;
        }
        return dp[i][k]=result;
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n=intervals.size();
        // storing the index with each interval
        for(int i=0;i<n;i++){
            intervals[i].push_back(i);
        }
        sort(begin(intervals),end(intervals));
        nextIdx.resize(n);
        // filling the nextIndex
        for(int i=0;i<n;i++){
            int endPoint=intervals[i][1];
            nextIdx[i]=findIdx(intervals,endPoint);
        }
        int k=4;
        dp.assign(n+1,vector<Node>(k+1));
        return solve(intervals,0,k).idxs;
    }
};