class Solution:
    def countOperations(self, num1: int, num2: int) -> int:
        operations = 0
        while num1 != 0 and num2 != 0:
            if num1 >= num2:
                # Use integer division to count how many times num2 fits into num1
                count = num1 // num2
                operations += count
                # Update num1 to the remainder
                num1 %= num2
            else:
                # Use integer division to count how many times num1 fits into num2
                count = num2 // num1
                operations += count
                # Update num2 to the remainder
                num2 %= num1
        
        return operations