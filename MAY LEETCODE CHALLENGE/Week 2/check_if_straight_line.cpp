
/*
1232. Check If It Is a Straight Line

You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

Example 1:

Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
Example 2:

Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
*/
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int y_diff=(coordinates[1][1]-coordinates[0][1]);
        int x_diff=(coordinates[1][0]-coordinates[0][0]);
        
        for(int i=2;i<coordinates.size()-1;i++)
        {
            int curr_xdiff=coordinates[i][0]-coordinates[i-1][0];
            int curr_ydiff=coordinates[i][1]-coordinates[i-1][1];
            if(y_diff*curr_xdiff!=x_diff*curr_ydiff)
                return false;
        }
        return true;
    }
};