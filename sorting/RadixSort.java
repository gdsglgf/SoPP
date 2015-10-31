import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class RadixSort {
    public static final int DECEM = 10;

    public static void radixSort(int[] data, int d) {
        int n = 1;
        for (int i = 0; i < d; i++) {
            List<List<Integer>> radix = new ArrayList<List<Integer>>(DECEM);
            for (int j = 0; j < DECEM; j++) {
                radix.add(new ArrayList<Integer>());
            }
            for (int j = 0; j < data.length; j++) {
                int mod = ((data[j] / n) % DECEM);
                List<Integer> list = radix.get(mod);
                list.add(data[j]);
            }
            int index = 0;
            for (int j = 0; j < DECEM; j++) {
                List<Integer> list = radix.get(j);
                int length = list.size();
                for (int k = 0; k < length; k++) {
                    data[index] = list.get(k);
                    index++;
                }
            }
            n *= DECEM;
        }
    }

    public static void main(String[] args) {
        int[] data = {73, 22, 93, 43, 55, 14, 28, 65, 39, 81, 33, 100};
        System.out.println(Arrays.toString(data));
        radixSort(data, 3);
        System.out.println(Arrays.toString(data));
    }
}