class Solution {
    public int numOfStrings(String[] arr, String word) {

        int n = word.length();
        int size = arr.length;
        int count = 0;
        for (int i = 0; i < size; i++) {
            int m = arr[i].length();
            if (m > n)
                continue;

            // Try every possible starting position
            for (int start = 0; start <= n - m; start++) {
                int j = 0;
                int k = start;
                while (j < m && k < n && arr[i].charAt(j) == word.charAt(k)) {
                    j++;
                    k++;
                }
                if (j == m) {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
}