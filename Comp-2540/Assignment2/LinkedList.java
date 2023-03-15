public class LinkedList<T> {
    public Node<T> head;
    public Node<T> tail;
    private int size;

    // default constructor
    public LinkedList() {
        // initialise head and tail to null, size to zero
        head = tail = null;
        size = 0;
    }

    // return the first element in the LinkedList
    public T getFirst() {
        if (size == 0) {
            System.out.println("List is empty!");
            return null;
        } else {
            return head.data;
        }
    }

    // return the last element in the LinkedList
    public T getLast() {
        if (size == 0) {
            System.out.println("List is empty!");
            return null;
        } else {
            return tail.data;
        }
    }

    // return the size of the LinkedList
    public int size() {
        return size;
    }

    // add to the front of the list
    public Node<T> addFirst(T element) {
        Node<T> new_node = new Node<T>(element);    // create a new node
        if (size == 0) {
            new_node.next = head;       // set the next value to the current head value
            head = new_node;        // overwrite and set the head value to the new node
            tail = head;
        } else {
            new_node.next = head;
            head = new_node;
        }
        size += 1;      // increment the size of the list
        return new_node;
    }

    // remove the first element in the list
    public T removeFirst() {
        if (head == null || size == 0) {     // check if the list is empty
            System.out.println("List is empty!");
            return null;     // if empty return exception
        } else {        // list is not empty
            Node<T> curr_node = head;       // create a temporary node to store current value
            head = head.next;       // set the head to the next node
            size -= 1;
            return curr_node.data;
        }
    }

    public Node<T> addLast(T element) {
        Node<T> new_node = new Node<T>(element);
        if (size == 0) {
            head = tail = new_node;
        } else {
            tail.next = new_node;
            tail = new_node;
        }
        size += 1;
        return new_node;
    }

    public T removeLast() {
        if (head == null || size == 0) {
            if (size == 0) {
                head = null;
                tail = null;
            }
            System.out.println("List is empty!");
            return null;
        } else {
            Node<T> curr_node = head;
            T data = null, overwriteCurrData = null;
            for (int i = 0; i <= size; i++) {
                if ((size - 2) == -1 || i == size - 2) { // 2 nodes before the node we want to remove
                    overwriteCurrData = curr_node.data;
                }
                if (i == size - 1 || curr_node.next == null) { // node before the node we want to remove
                    tail = curr_node;
                    data = tail.data;
                    tail.data = overwriteCurrData; // updates the tail's data
                    tail.next = null;
                    break;
                }
                curr_node = curr_node.next;
            }
            size -= 1;
            return data;
        }
    }

    public static void main(String[] args) {
        LinkedList<Integer> list = new LinkedList<Integer>();
        list.addFirst(1);
        list.addFirst(2);
        list.removeLast();
        list.removeLast();
    }
}