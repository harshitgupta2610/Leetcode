class Solution {
    public String reverseWords(String s) {
        String[] arr = s.split(" ");
        StringBuilder sb = new StringBuilder();
        for (int i = arr.length - 1; i >= 0; i--) {
            if (arr[i].isEmpty())
                continue;
            sb.append(" " + arr[i]);
        }
        return sb.substring(1).toString();
    }
}