/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> points;
        int cnt=2;
        ListNode* temp=head;
        int prevVal=temp->val;
        temp=temp->next;
        while(temp->next != NULL){
            if(temp->val>prevVal && temp->val>temp->next->val){
                points.push_back(cnt);
            }
            if(temp->val<prevVal && temp->val<temp->next->val){
                points.push_back(cnt);
            }
            cnt++;
            prevVal=temp->val;
            temp=temp->next;
        }
        if(points.size()==0) return {-1,-1};
        int maxDistance=points.back()-points.front();
        int minDistance=INT_MAX;
        for(int i=0;i<points.size()-1;i++){
            minDistance=min(minDistance,points[i+1]-points[i]);
        }
        if(minDistance==INT_MAX) return {-1,-1};
        return {minDistance,maxDistance};
    }
};