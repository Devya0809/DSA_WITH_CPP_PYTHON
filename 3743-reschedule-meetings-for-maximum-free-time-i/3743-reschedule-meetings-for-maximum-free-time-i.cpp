class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        int meetingTimeSum = 0;
        for(int i=0; i<k; i++){
            meetingTimeSum += (endTime[i] - startTime[i]);
        }
        if(k == n) return eventTime - meetingTimeSum;

        int maxFreeTime = startTime[k] - 0 - meetingTimeSum;
        for(int i = k; i<n; i++){ 
            meetingTimeSum -= endTime[i-k] - 0 - startTime[i-k];
            meetingTimeSum += endTime[i] - startTime[i];

            int left = endTime[i-k], right = ((i+1 == n) ? eventTime : startTime[i+1]);
            maxFreeTime = max(maxFreeTime, right - left - meetingTimeSum);

        }
        return maxFreeTime;
        
    }
};