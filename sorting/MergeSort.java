import java.util.Arrays;

public class MergeSort {
	private static void merge(int[] data, int p, int q, int r) {
		int n1 = q - p + 1;
		int n2 = r - q;
		int[] left = new int[n1];
		int[] right = new int[n2];
		System.arraycopy(data, p, left, 0, n1);
		System.arraycopy(data, q + 1, right, 0, n2);
		int i = 0;
		int j = 0;
		int k = p;
		while (i != n1 && j != n2) {
			if (left[i] <= right[j]) {
				data[k] = left[i];
				i++;
			} else {
				data[k] = right[j];
				j++;
			}
			k++;
		}
		while (i < n1) {
			data[k] = left[i];
			i++;
			k++;
		}
		while (j < n2) {
			data[k] = right[j];
			j++;
			k++;
		}
	}

	private static void mergeSort(int[] data, int i, int j) {
		if (i < j) {
			int mid = (i + j) / 2;
			mergeSort(data, i, mid);
			mergeSort(data, mid + 1, j);
			merge(data, i, mid, j);
		}
	}

	public static int[] mergeSort(int[] data) {
		int[] dest = CommUtil.arrayCopy(data);
		mergeSort(dest, 0, dest.length - 1);
		return dest;
	}

	public static void main(String[] args) {
		int[] data = {9, 8, 7, 6, 5, 4, 3, 2, 1};
		System.out.println(Arrays.toString(data));
		System.out.println(Arrays.toString(mergeSort(data)));
	}
}