import java.io.FileNotFoundException;
import java.io.File;
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;

class Country {
    public String getName() {
        return name;
    }

	public void setName(String name) {
		this.name = name;
	}

	public void setData(String[] dataString) {
		this.data = new int[dataString.length];
		for (int i = 0; i < dataString.length; i++) {
			data[i] = Integer.parseInt(dataString[i]);
		}
	}

	public int getData(int i) {
		return data[i];
	}

	public int getDataLength() {
		return data.length;
	}

	public String toString() {
		return String.format("%s,%s", name, Arrays.toString(data));
	}

	private String name;
	private int[] data;
}

public class Kmeans {
	public static List<Country> countrys = new ArrayList<Country>();
	public static double[][] matrix;
    public static double[][] centroid;

    public static void main (String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File(args[0]));
        String line;        
        while (sc.hasNext()) {
        	line = sc.nextLine();
            line = line.trim();
            String[] elements = line.split(", ");
            String[] data = elements[1].split(" ");
            Country country = new Country();
            country.setName(elements[0]);
            country.setData(data);
            countrys.add(country);
        }

        specialization();
        System.out.println("Centroid initation...");
        initCentroid();
        System.out.println("Start iteration...");
        int times = 10;
        for (int i = 0; i < times; i++) {
            System.out.printf("Start iteration #%d...\n", i);
            iteration();
        }
        
    }

    public static void specialization() {
    	matrix = new double[countrys.size()][countrys.get(0).getDataLength()];
    	int m = 0;
    	for (Country c : countrys) {
    		int length = c.getDataLength();
    		for (int i = 0; i < length; i++) {
    			int max = getMax(i);
    			int min = getMin(i);
    			matrix[m][i] = (c.getData(i) - min) * 1.0 / (max - min);
    			System.out.printf("%f ", matrix[m][i]);
    		}
    		m++;
    		System.out.println();
    	}
    }

    public static void initCentroid() {
        int[] ref = {1, 12, 9};
        int length = matrix[0].length;
        centroid = new double[ref.length][length];
        for (int i = 0; i < ref.length; i++) {
            for (int j = 0; j < length; j++) {
                centroid[i][j] = matrix[ref[i]][j];
                System.out.printf("%f ", centroid[i][j]);
            }
            System.out.println();
        }
    }

    public static void iteration() {
        int[] level = new int[matrix.length];
        for (int i = 0; i < matrix.length; i++) {
            double min = 10000;
            int minPosition = 0;
            for (int j = 0; j < centroid.length; j++) {
                double dist = 0;
                for (int k = 0; k < matrix[i].length; k++) {
                    double diff = matrix[i][k] - centroid[j][k];
                    dist += diff * diff;
                }
                dist = Math.sqrt(dist);
                if (dist < min) {
                    minPosition = j;
                    min = dist;
                }
                System.out.printf("%f ", dist);
            }
            System.out.printf("%f %d %s\n", min, minPosition, countrys.get(i).getName());
            level[i] = minPosition;
        }
        updateCentroid(level);
    }

    public static void updateCentroid(int[] level) {
        System.out.println("Update Centroid...");
        for (int i = 0; i < centroid.length; i++) {
            double[] newCentroid = new double[centroid[0].length];
            int count = 0;
            for (int j = 0; j < level.length; j++) {
                if (level[j] == i) {
                    for (int k = 0; k < centroid[0].length; k++) {
                        newCentroid[k] += matrix[j][k];
                    }
                    count++;
                }
            }
            for (int j = 0; j < newCentroid.length; j++) {
                newCentroid[j] /= count;
                System.out.printf("%f ", newCentroid[j]);
            }
            System.out.println();
            System.arraycopy(newCentroid, 0, centroid[i], 0, newCentroid.length);
        }
    }

    public static int getMax(int index) {
    	int max = countrys.get(0).getData(index);
    	int length = countrys.size();
    	for (int i = 1; i < length; i++) {
    		Country country = countrys.get(i);
    		int data = country.getData(index);
    		if (data > max) {
    			max = data;
    		}
    	}
    	return max;
    }

    public static int getMin(int index) {
    	int min = countrys.get(0).getData(index);
    	int length = countrys.size();
    	for (int i = 1; i < length; i++) {
    		Country country = countrys.get(i);
    		int data = country.getData(index);
    		if (data < min) {
    			min = data;
    		}
    	}
    	return min;
    }

}