class Solution {
    public String reverseWords(String s) {
        String[] words = s.trim().split("\\s+");
        StringBuilder sb = new StringBuilder();
        
        // Step 3: Traverse words array in reverse order
        for (int i = words.length - 1; i >= 0; i--) {
            sb.append(words[i]);
            if (i > 0) { // add space between words
                sb.append(" ");
            }
        }
        
        return sb.toString();
    }
}