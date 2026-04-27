class TextEditor {
    private StringBuilder left = new StringBuilder();
    private StringBuilder right = new StringBuilder();

    public TextEditor() {}

    public void addText(String text) {
        left.append(text);
    }

    public int deleteText(int k) {
        int numToDelete = Math.min(k, left.length());
        left.setLength(left.length() - numToDelete);
        return numToDelete;
    }

    public String cursorLeft(int k) {
        int numToMove = Math.min(k, left.length());
        for (int i = 0; i < numToMove; i++) {
            right.append(left.charAt(left.length() - 1));
            left.setLength(left.length() - 1);
        }
        return getLeftText();
    }

    public String cursorRight(int k) {
        int numToMove = Math.min(k, right.length());
        for (int i = 0; i < numToMove; i++) {
            left.append(right.charAt(right.length() - 1));
            right.setLength(right.length() - 1);
        }
        return getLeftText();
    }

    private String getLeftText() {
        int len = Math.min(10, left.length());
        return left.substring(left.length() - len);
    }
}
