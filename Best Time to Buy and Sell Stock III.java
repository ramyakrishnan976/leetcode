class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) return 0;

        int buy1 = Integer.MIN_VALUE;
        int sell1 = 0;
        int buy2 = Integer.MIN_VALUE;
        int sell2 = 0;

        for (int price : prices) {
            // 1. Maximize balance after first buy (cheapest price)
            buy1 = Math.max(buy1, -price);
            
            // 2. Maximize profit after first sell
            sell1 = Math.max(sell1, buy1 + price);
            
            // 3. Maximize balance after second buy (using profit from sell1)
            buy2 = Math.max(buy2, sell1 - price);
            
            // 4. Maximize total profit after second sell
            sell2 = Math.max(sell2, buy2 + price);
        }

        return sell2;
    }
}
