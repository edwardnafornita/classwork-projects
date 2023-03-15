import java.util.EmptyStackException;

public class Stack<T> {
    private LinkedList<T> list;

    public Stack() {
        list = new LinkedList<T>();
    }
    
    public boolean isEmpty() {
        if (list.head == null) {
            return true;
        }
        else {
            return false;
        }
    }

    public int size() {
        return list.size();
    }

    public void push(T object) {
        list.addFirst(object);
    }

    public T pop() throws Exception {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        else {
            return list.removeFirst();
        }
    }

    public T top() throws Exception {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        else {
            return list.getFirst();
        }
    }
}