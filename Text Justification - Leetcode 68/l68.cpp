#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        std::vector<std::string> result;
        int i = 0;
        int n = words.size();
        
        while (i < n) {
            int j = i + 1;
            int lineLength = words[i].length();
            
            // Step 1: Find how many words can fit in the current line
            while (j < n && lineLength + 1 + words[j].length() <= maxWidth) {
                lineLength += 1 + words[j].length();
                j++;
            }
            
            int numWords = j - i;
            std::string line = "";
            
            // Step 2: Format the line based on the conditions
            // Condition A: It's the last line OR the line only contains 1 word (Left Justification)
            if (j == n || numWords == 1) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        line += " ";
                    }
                }
                // Pad the remaining spaces at the end
                line += std::string(maxWidth - line.length(), ' ');
            } 
            // Condition B: Middle lines with multiple words (Full Justification)
            else {
                int totalWordLength = 0;
                for (int k = i; k < j; k++) {
                    totalWordLength += words[k].length();
                }
                
                int totalSpaces = maxWidth - totalWordLength;
                int gaps = numWords - 1;
                
                int baseSpaces = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;
                
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        // Assign base spaces + 1 extra space if available for leftmost slots
                        int spacesToApply = baseSpaces + (k - i < extraSpaces ? 1 : 0);
                        line += std::string(spacesToApply, ' ');
                    }
                }
            }
            
            result.push_back(line);
            i = j; // Move to the next set of words
        }
        
        return result;
    }
};
