import java.util.*;

class Solution {
    public int removeCoveredIntervals(int[][] intervals) {

        Arrays.sort(intervals, (a, b) -> {
            if (a[0] == b[0]) return b[1] - a[1];
            return a[0] - b[0];
        });

        int ans = 0;
        int prevEnd = -1;

        for (int[] interval : intervals) {
            if (interval[1] > prevEnd) {
                ans++;
                prevEnd = interval[1];
            }
        }

        return ans;
    }
}