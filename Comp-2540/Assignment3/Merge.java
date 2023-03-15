public class Merge {
    public static Queue<Integer> merge(Queue<Integer> A, Queue<Integer> B) {
        Queue<Integer> S = new Queue<Integer>();

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
}
