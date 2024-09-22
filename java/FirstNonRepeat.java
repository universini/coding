import java.util.HashMap;
import java.util.Map;

public class FirstNonRepeat {
    
    public static char nonRepeat(String str) {
        Map<Character, Integer> charCount = new HashMap<>();
        
        // Count occurrences of each character
        for (char c : str.toCharArray()) {
            charCount.put(c, charCount.getOrDefault(c, 0) + 1);
        }
        
        // Find the first non-repeating character
        for (char c : str.toCharArray()) {
            if (charCount.get(c) == 1) {
                return c;
            }
        }
        
        return '\0'; // Return null character if no non-repeating character found
    }
    
    public static void main(String[] args) {
        String str = "siddesi";
        char result = nonRepeat(str);
        
        if (result != '\0') {
            System.out.println("First non-repeat char: " + result);
        } else {
            System.out.println("No non-repeating character found");
        }
    }
}
