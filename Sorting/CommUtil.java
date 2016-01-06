public class CommUtil {
    public static void swap(int[] data, int i, int j) {
        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }

    public static int[] arrayCopy(int[] data) {
        int[] dest = new int[data.length];
        System.arraycopy(data, 0, dest, 0, data.length);

        return dest;
    }
}