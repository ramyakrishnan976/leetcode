import java.util.*;

class Solution {
    public List<List<Integer>> getSkyline(int[][] buildings) {
        List<List<Integer>> result = new ArrayList<>();
        List<int[]> events = new ArrayList<>();
        
        // 1. Convert buildings into sweep-line events
        for (int[] b : buildings) {
            // Left edge event: store height as negative to distinguish it and sort correctly
            events.add(new int[]{b[0], -b[2]});
            // Right edge event: store height as positive
            events.add(new int[]{b[1], b[2]});
        }
        
        // 2. Sort events primarily by x-coordinate.
        // If x-coordinates are identical, sorting by height (with its sign) handles edge cases:
        // - Two left edges: higher building processed first (-height is smaller).
        // - Two right edges: lower building processed first (height is smaller).
        // - Left and right edge: left edge processed first (-height vs +height).
        Collections.sort(events, (e1, e2) -> {
            if (e1[0] != e2[0]) {
                return Integer.compare(e1[0], e2[0]);
            }
            return Integer.compare(e1[1], e2[1]);
        });
        
        // 3. Use a TreeMap as a Max-Heap to track active building heights and their frequencies
        // Key: Height, Value: Count of active buildings with this height
        TreeMap<Integer, Integer> activeHeights = new TreeMap<>();
        activeHeights.put(0, 1); // Base ground level height
        
        int prevMaxHeight = 0;
        
        // 4. Process all events sequentially
        for (int[] event : events) {
            int x = event[0];
            int h = event[1];
            
            if (h < 0) {
                // Left edge: a building starts, add height to active collection
                int actualHeight = -h;
                activeHeights.put(actualHeight, activeHeights.getOrDefault(actualHeight, 0) + 1);
            } else {
                // Right edge: a building ends, remove or decrement height
                int count = activeHeights.get(h);
                if (count == 1) {
                    activeHeights.remove(h);
                } else {
                    activeHeights.put(h, count - 1);
                }
            }
            
            // The highest active building is always the last key in a sorted TreeMap
            int currMaxHeight = activeHeights.lastKey();
            
            // If the peak height changed at this x-coordinate, it's a skyline key point
            if (currMaxHeight != prevMaxHeight) {
                result.add(Arrays.asList(x, currMaxHeight));
                prevMaxHeight = currMaxHeight;
            }
        }
        
        return result;
    }
}
