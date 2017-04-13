import java.util.Arrays;

public class HeapSort {
    private static void maxHeapify(int[] data, int heapSize, int i) {
        while (true) {
            int x = 2 * i + 1;      // left child
            int y = x + 1;      // right child

            // find largest index in [i, x, y]
            int largest = i;
            if (x < heapSize && data[x] > data[i]) {
                largest = x;
            }
            if (y < heapSize && data[y] > data[largest]) {
                largest = y;
            }

            if (largest != i) {
                CommUtil.swap(data, i, largest);
                i = largest;
            } else {
                break;
            }
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
        for (int i = data.length - 1; i >= 0; i--) {
            CommUtil.swap(data, 0, i);
            heapSize--;
            maxHeapify(data, heapSize, 0);
            // System.out.println(i + Arrays.toString(data));            
        }
    }

    public static void main(String[] args) {
        int[] data = {9, 8, 7, 6, 5, 4, 3, 2, 1};
        System.out.println(Arrays.toString(data));
        heapSort(data);
        System.out.println(Arrays.toString(data));
    }
}