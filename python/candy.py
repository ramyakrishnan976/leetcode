class Solution:
    def candy(self, ratings: list[int]) -> int:
        n = len(ratings)
        if n == 0:
            return 0
            
        candies = [1] * n
        
        # Step 2: Left-to-Right Pass
        for i in range(1, n):
            if ratings[i] > ratings[i - 1]:
                candies[i] = candies[i - 1] + 1
                
        # Step 3: Right-to-Left Pass
        for i in range(n - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                candies[i] = max(candies[i], candies[i + 1] + 1)
                
        # Step 4: Return total aggregate candies
        return sum(candies)
