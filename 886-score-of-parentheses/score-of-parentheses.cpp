class Solution {
public:
    int scoreOfParentheses(string s) {
        // approach-1 using T.C= O(n) and S.C=O(1)
        // int n=s.size();
        // int score=0;
        // int depth=0;
        // for(int i=0;i<n;i++){
        //     if(s[i]=='('){
        //         depth++;
        //     }else{
        //         if(s[i-1]=='('){
        //             depth--;
        //             score+=(1<<depth);
        //         }else{
        //             depth--;
        //         }
        //     }
        // }
        // return score;

        // approach-2 using T.C=O(n) and S.C=O(n)
        int n=s.size();
        vector<int> vec;
        int score=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                vec.push_back(score);
                score=0;
            }else{
                if(s[i-1]=='('){
                    score=1+vec.back();
                }else{
                    score=vec.back()+2*score;
                }
                vec.pop_back();
            }
        }
        return score;
    }
};