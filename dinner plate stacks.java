import java.util.*;

class DinnerPlates {
    private int capacity;
    private Map<Integer, Deque<Integer>> stacks;
    private TreeSet<Integer> available;
    private int maxIdx;

    public DinnerPlates(int capacity) {
        this.capacity = capacity;
        this.stacks = new HashMap<>();
        this.available = new TreeSet<>();
        this.maxIdx = -1;
    }

    public void push(int val) {
        // 1. Find the leftmost index with space
        if (available.isEmpty()) {
            maxIdx = Math.max(maxIdx, stacks.size());
            available.add(stacks.size());
        }
        
        int index = available.first();
        stacks.putIfAbsent(index, new ArrayDeque<>());
        stacks.get(index).push(val);
        
        // 2. If stack is now full, remove from available
        if (stacks.get(index).size() == capacity) {
            available.remove(index);
        }
        maxIdx = Math.max(maxIdx, index);
    }

    public int pop() {
        // Find the rightmost non-empty stack
        while (maxIdx >= 0 && (stacks.get(maxIdx) == null || stacks.get(maxIdx).isEmpty())) {
            maxIdx--;
        }
        return popAtStack(maxIdx);
    }

    public int popAtStack(int index) {
        if (index < 0 || !stacks.containsKey(index) || stacks.get(index).isEmpty()) {
            return -1;
        }
        
        int val = stacks.get(index).pop();
        // Since we removed an item, this stack is now "available" for pushing
        available.add(index);
        
        return val;
    }
}
