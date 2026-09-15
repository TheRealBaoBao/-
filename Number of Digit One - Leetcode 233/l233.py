class Solution:
    def countDigitOne(self, n: int) -> int:
        if n <= 0:
            return 0
            
        count = 0
        factor = 1
        
        while factor <= n:
            # Divide the number into three parts based on the current place value (factor)
            higher_numbers = n // (factor * 10)
            current_digit = (n // factor) % 10
            lower_numbers = n % factor
            
            # 1. Count 1s contributed by the completely filled higher number cycles
            count += higher_numbers * factor
            
            # 2. Count 1s contributed by the remaining partially filled cycle
            if current_digit == 1:
                count += lower_numbers + 1
            elif current_digit > 1:
                count += factor
                
            # Move to the next place value (e.g., units -> tens -> hundreds)
            factor *= 10
            
        return count
