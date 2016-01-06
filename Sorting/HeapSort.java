import java.util.Arrays;

public class HeapSort {
    private static void maxHeapify(int[] data, int heapSize, int i) {
        int l = 2 * i + 1;      // left child
        int r = l + 1;      // right child

        // find largest index in [i, l, r]
        int largest = i;
        if (l < heapSize && data[l] > data[i]) {
            largest = l;
        }
        if (r < heapSize && data[r] > data[largest]) {
            largest = r;
        }

        if (largest != i) {
            CommUtil.swap(data, i, largest);
            maxHeapify(data, heapSize, largest);
        }
    }

    private static void buildMaxHeap(int[] data, int heapSize) {
        for (int i = heapSize / 2 - 1; i >= 0; i--) {
            maxHeapify(data, heapSize, i);
        }
    }

    public static void heapSort(int[] data) {
        buildMaxHeap(data, data.length);
        int heapSize = data.length;
        for (int i = data.length; i > 0; i--) {
            CommUtil.swap(data, 0, i - 1);
            heapSize--;
            maxHeapify(data, heapSize, 0);
            System.out.println(i + Arrays.toString(data));            
        }
    }

    public static void main(String[] args) {
        int[] data = {9, 8, 7, 6, 5, 4, 3, 2, 1};
        System.out.println(Arrays.toString(data));
        heapSort(data);
        System.out.println(Arrays.toString(data));
    }
}