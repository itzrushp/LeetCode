class Solution {
public:
    int largestAltitude(vector<int>& gain) {
     vector<int > pre(gain.size()+1, 0);
     for(int i=1 ; i< pre.size(); i++){
        pre[i] = pre[i-1] + gain[i-1];
     }
     int max_altitude = INT_MIN;
     for(int j =0 ;j<pre.size() ; j++){
        max_altitude = max(max_altitude, pre[j]);
     }
     return max_altitude;
    }
};
