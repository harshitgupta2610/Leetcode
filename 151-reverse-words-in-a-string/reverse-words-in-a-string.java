class Solution {
    public String reverseWords(String s) {
        String[] arr = s.trim().split(" ");
        int n =arr.length;
        StringBuilder sb = new StringBuilder();
        for(int i=n-1;i>=0;i-- ){
            if (arr[i].isEmpty())
                continue;
            sb.append(" " + arr[i]);
        }
        return sb.substring(1).toString();
    }
}