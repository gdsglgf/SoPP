import java.util.Scanner;
import java.io.FileNotFoundException;
import java.io.File;

/** 蛮力搜索算法 */
public class BruteForce {
    public static int match(String text, String pattern) {
        if (text == null || pattern == null || pattern.equals("")) {
            return -1;
        }

        int textLength = text.length();
        int patternLength = pattern.length();
        int size = textLength - patternLength;
        for (int i = 0; i <= size; i++) {
            boolean isMatch = true;
            for (int j = i, k = 0; k < patternLength; k++, j++) {
                if (text.charAt(j) != pattern.charAt(k)) {  // 从左向右比较
                    isMatch = false;    // 未匹配成功
                    break;
                }
            }
            if (isMatch) {
                return i;    // 匹配成功, 返回
            }
        }
        return -1;
    }

    public static void main (String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File(args[0]));
        String line;
        while (sc.hasNext()) {
            line = sc.nextLine();
            line = line.trim();
            String[] elements = line.split(" \\| ");
            System.out.println(match(elements[0], elements[1]));
        }
        sc.close();
    }
}