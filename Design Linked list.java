class MyLinkedList {
    class Node {
        int val;
        Node next;
        Node(int val) { this.val = val; }
    }

    private Node head;
    private int size;

    public MyLinkedList() {
        head = new Node(0); // Dummy head
        size = 0;
    }

    public int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node curr = head.next;
        for (int i = 0; i < index; i++) {
            curr = curr.next;
        }
        return curr.val;
    }

    public void addAtHead(int val) {
        addAtIndex(0, val);
    }

    public void addAtTail(int val) {
        addAtIndex(size, val);
    }

    public void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index < 0) index = 0;

        size++;
        Node prev = head;
        for (int i = 0; i < index; i++) {
            prev = prev.next;
        }
        
        Node toAdd = new Node(val);
        toAdd.next = prev.next;
        prev.next = toAdd;
    }

    public void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        size--;
        Node prev = head;
        for (int i = 0; i < index; i++) {
            prev = prev.next;
        }
        prev.next = prev.next.next;
    }
}
