public class Merge {
    private static Queue<Integer> S = new Queue<Integer>();

    public static Queue<Integer> merge(Queue<Integer> A, Queue<Integer> B) throws Exception {
        while (!A.isEmpty() && !B.isEmpty()) {
            int a = A.front();
            int b = B.front();

            if (a <= b) {
                S.enqueue(A.dequeue());
            } else {
                S.enqueue(B.dequeue());
            }
        }

        // In the event that A or B is empty, we need to add the remaining elements of A or B to the end of the S queue
        while (!A.isEmpty()) {
            S.enqueue(A.dequeue());
        }

        while (!B.isEmpty()) {
            S.enqueue(B.dequeue());
        }
        return S;
    }

    public static void main(String[] args) throws Exception {
        Queue<Integer> A = new Queue<Integer>(), B = new Queue<Integer>();
        A.enqueue(1);
        A.enqueue(3);
        A.enqueue(5);
        A.enqueue(7);
        A.enqueue(9);
        B.enqueue(2);
        B.enqueue(3);
        B.enqueue(6);
        B.enqueue(8);
        B.enqueue(10);
        
        Queue<Integer> mergedQueue = merge(A, B);
        mergedQueue.dequeueAll();

        A.enqueue(1);
        A.enqueue(2);
        A.enqueue(3);
        A.enqueue(4);
        A.enqueue(5);
        B.enqueue(6);
        B.enqueue(7);
        B.enqueue(8);
        B.enqueue(9);
        B.enqueue(10);

        mergedQueue = merge(A, B);
        mergedQueue.dequeueAll();

        A.enqueue(2);
        A.enqueue(4);
        A.enqueue(8);
        A.enqueue(16);
        A.enqueue(32);
        B.enqueue(1);
        B.enqueue(3);
        B.enqueue(5);
        B.enqueue(7);
        B.enqueue(9);

        mergedQueue = merge(A, B);
        mergedQueue.dequeueAll();

        A.enqueue(10);
        A.enqueue(11);
        A.enqueue(12);
        A.enqueue(13);
        B.enqueue(1);
        B.enqueue(2);
        B.enqueue(3);
        B.enqueue(4);

        mergedQueue = merge(A, B);
        mergedQueue.dequeueAll();
    }
}
