class Solution {
    public int maximumLength(int[] nums) {
        HashMap<Long, Integer> freq = new HashMap<>();
        for (int x : nums)
            freq.put((long)x, freq.getOrDefault((long)x, 0) + 1);
        int ans = 1;

        if (freq.containsKey(1L)) {
            int cnt = freq.get(1L);
            ans = Math.max(ans, (cnt % 2 == 0) ? cnt - 1 : cnt);
        }

        for (long start : freq.keySet()) {
            if (start == 1) continue;
            long cur = start;
            int len = 0;
            while (freq.containsKey(cur)) {

            long next = cur * cur;

                if (freq.get(cur) >= 2 && freq.containsKey(next)) {
                    len += 2;
                    cur = next;
                } else {
                    len += 1;      // current becomes the middle
                    break;
                }
            }

            // if next square doesn't exist,
            // last pair can't be completed
            if (!freq.containsKey(cur))
                len--;

            ans = Math.max(ans, len);
        }

        return ans;
    }
}