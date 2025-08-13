class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        
        vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        vector<string> teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", 
                               "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> units = {"", "Thousand", "Million", "Billion"};
        
        vector<string> parts;
        int unitIndex = 0;
        
        while (num > 0) {
            int chunk = num % 1000;
            
            if (chunk > 0) {
                string chunkStr = "";
                
                // Handle hundreds
                if (chunk >= 100) {
                    chunkStr += ones[chunk / 100] + " Hundred";
                    chunk %= 100;
                    if (chunk > 0) chunkStr += " ";
                }
                
                // Handle tens and ones
                if (chunk >= 20) {
                    chunkStr += tens[chunk / 10];
                    chunk %= 10;
                    if (chunk > 0) chunkStr += " " + ones[chunk];
                }
                else if (chunk >= 10) {
                    chunkStr += teens[chunk - 10];
                }
                else if (chunk > 0) {
                    chunkStr += ones[chunk];
                }
                
                // Add unit
                if (unitIndex > 0) {
                    chunkStr += " " + units[unitIndex];
                }
                
                parts.push_back(chunkStr);
            }
            
            num /= 1000;
            unitIndex++;
        }
        
        // Join parts in reverse order
        string result = "";
        for (int i = parts.size() - 1; i >= 0; i--) {
            if (!result.empty()) result += " ";
            result += parts[i];
        }
        
        return result;
    }
};
