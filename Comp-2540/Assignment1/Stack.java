import java.util.EmptyStackException;

public class Stack {
    private int len;
    private char[] array;
    private int top_element;

    public Stack() {
        len = 100;
        array = new char[len];
        top_element = 0;
    }
    
    public boolean isEmpty() {
        if (top_element == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    public int size() {
        return top_element + 1;
    }

    public void push(char object) throws Exception {
        if (top_element == array.length - 1) {
            throw new Exception("Stack is full\n");
        }
        else {
            top_element += 1;
            array[top_element] = object;
        }
    }

    public char pop() throws EmptyStackException {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        else {
            top_element -= 1;
            return array[top_element + 1];
        }
    }

    public char top() throws EmptyStackException {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        else {
            return array[top_element];
        }
    }
}