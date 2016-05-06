import java.util.Arrays;

public class SelectionSort {
    public static void selectionSort(int[] data) {
        int min, minIndex;
        for (int i = 0; i < data.length - 1; i++) {
            min = data[i];
            minIndex = i;
            for (int j = i + 1; j < data.length; j++) {
                if (data[j] < min) {
                    min = data[j];
                    minIndex = j;
                }
            }
            if (i != minIndex) {
                CommUtil.swap(data, i, minIndex);
            }
            System.out.println(Arrays.toString(data));
        }
    }

    public static void main(String[] args) {
        int[] data = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
        System.out.println(Arrays.toString(data));
        selectionSort(data);
        System.out.println(Arrays.toString(data));
    }
}