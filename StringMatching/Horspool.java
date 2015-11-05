import java.util.Scanner;
import java.io.FileNotFoundException;
import java.io.File;

/** Horspool算法 */
public class Horspool {
    /** 从右往左查找字符 */
    private static int findBack(String pattern, char key, int i) {
        for(;i >= 0; i--) {
            if (pattern.charAt(i) == key) {
                return i;
            }
        }
        return -1;
    }

    public static int match(String text, String pattern) {
        if (text == null || pattern == null || pattern.equals("")) {
            return -1;
        }

        int textLength = text.length();
        int patternLength = pattern.length();
        int size = textLength - patternLength;
        for (int i = 0; i <= size; ) {
            int j = patternLength - 1;
            int k = i + j;
            for(;j >= 0 && pattern.charAt(j) == text.charAt(k); j--, k--);  // 从右向左比较
            //System.out.printf("i = %d, k = %d, j = %d", i, k, j);
            if (j == -1) {
                return i;    // 匹配成功, 返回
            }

            int index = findBack(pattern, text.charAt(k), j - 1);
            if (index != -1) {
                i = k - index;      // 字符对齐
            } else {
                i += patternLength;     // 移动一个模式串长度
            }
            //System.out.printf("i = %d\n", i);
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