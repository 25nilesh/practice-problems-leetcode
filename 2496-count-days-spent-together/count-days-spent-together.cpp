class Solution {
public:
    int dayCount(string &s){
        int days[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month=stoi(s.substr(0,2));
        int date=stoi(s.substr(3,2));
        for(int i=0;i<month-1;i++){
            date+=days[i];
        }
        return date;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arriveA = dayCount(arriveAlice);
        int leaveA = dayCount(leaveAlice);
        int arriveB = dayCount(arriveBob);
        int leaveB = dayCount(leaveBob);

        int l=max(arriveA,arriveB);
        int r=min(leaveA,leaveB);

        return max(0,r-l+1);
    }
};