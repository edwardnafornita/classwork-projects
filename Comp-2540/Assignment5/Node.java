public class Node<T> {
    private T value;
    private int key;
    private Node<T> left;
    private Node<T> right;

    public Node(int key, T value) {
        this.key = key;
        this.value = value;
        left = null;
        right = null;
    }

    public int getKey() {
        return key;
    }

    public T getValue() {
        return value;
    }

    public Node<T> getLeft() {
        return left;
    }

    public Node<T> getRight() {
        return right;
    }

    public void setLeft(Node<T> left) {
        this.left = left;
    }

    public void setRight(Node<T> right) {
        this.right = right;
    }

    public void setKey(int key) {
        this.key = key;
    }

    public void setValue(T value) {
        this.value = value;
    }
}
