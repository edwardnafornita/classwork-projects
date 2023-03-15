public class InPlaceQuickSort extends InPlaceInsertionSort{
    // method overload for quicksort
    public static void sort(int[] arr, int firstElement, int lastElement) {
        if (firstElement >= lastElement) return;

        int pivot = arr[lastElement], left = firstElement, right = lastElement - 1;
        while (left <= right) {
            while (left <= right && arr[left] <= pivot) left++;
            while (left <= right && arr[right] >= pivot) right--;
            if (left < right) {
                int temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
            }
        }
        int temp = arr[left];
        arr[left] = arr[lastElement];
        arr[lastElement] = temp;
        sort(arr, firstElement, left - 1);
        sort(arr, left + 1, lastElement);
    }

    public static void main(String[] args) {
        int[] arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, arr3 = {1, 2, 4, 5, 3, 7, 8, 10, 11, 9, 6};
        System.out.println("Before:");
        print(arr);
        print(arr2);
        print(arr3);
        System.out.println("After:");
        sort(arr, 0, 9);
        sort(arr2, 0, 9);
        sort(arr3, 0, 10);
        print(arr);
        print(arr2);
        print(arr3);
    }
}
