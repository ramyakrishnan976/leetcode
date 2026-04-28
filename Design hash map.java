class MyHashMap {
    class Node {
        int key, val;
        Node next;
        Node(int key, int val) { this.key = key; this.val = val; }
    }

    private final int SIZE = 1000; // Number of buckets
    private Node[] buckets;

    public MyHashMap() {
        buckets = new Node[SIZE];
    }

    private int hash(int key) {
        return key % SIZE;
    }

    public void put(int key, int value) {
        int index = hash(key);
        if (buckets[index] == null) {
            buckets[index] = new Node(-1, -1); // Dummy head
        }
        Node prev = find(buckets[index], key);
        if (prev.next == null) {
            prev.next = new Node(key, value);
        } else {
            prev.next.val = value;
        }
    }

    public int get(int key) {
        int index = hash(key);
        if (buckets[index] == null) return -1;
        Node prev = find(buckets[index], key);
        return prev.next == null ? -1 : prev.next.val;
    }

    public void remove(int key) {
        int index = hash(key);
        if (buckets[index] == null) return;
        Node prev = find(buckets[index], key);
        if (prev.next != null) {
            prev.next = prev.next.next;
        }
    }

    // Helper to find the node BEFORE the target key
    private Node find(Node bucket, int key) {
        Node curr = bucket, prev = null;
        while (curr != null && curr.key != key) {
            prev = curr;
            curr = curr.next;
        }
        return prev;
    }
}
