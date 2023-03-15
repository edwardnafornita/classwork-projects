public class Queue<T> {
    private LinkedList<T> list;

    public Queue() {
        list = new LinkedList<T>();
    }

    public void enqueue(T object) {
        list.addLast(object);
    }

    public T dequeue() {
        return list.removeFirst();
    }

    public int size() {
        return list.size();
    }

    public boolean isEmpty() {
        if (list.size() == 0) {
            return true;
        } else {
            return false;
        }
    }

    public T front() {
        return list.getFirst();
    }

    // dequeueAll method to display all values in the queue and empty out 
    // the solution queue. Used for convenience.
    public void dequeueAll() {
        while (list.size() > 0) {
            System.out.print(list.removeFirst() + " ");
        }
        System.out.println();
    }
}
