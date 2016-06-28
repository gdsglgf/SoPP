import java.util.Arrays;

public class BubbleSort {
    public static void bubbleSort(int[] data) {
        int last = data.length - 1;
        boolean sorted;
        for (int i = 0; i < last; i++) {
            sorted = true;
            for (int j = last; j > i; j--) {
                if (data[j] < data[j - 1]) {
                    CommUtil.swap(data, j, j - 1);
                    sorted = false;
                }
            }
            if (sorted) {
                break;
            }
            System.out.println(Arrays.toString(data));
        }
    }

    public static void main(String[] args) {
        int[] data = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
        System.out.println(Arrays.toString(data));
        bubbleSort(data);
        System.out.println(Arrays.toString(data));
    }
}