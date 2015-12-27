#include <iostream>
using namespace std;

/*
@param r 二维数组行数
@param c 二维数组列数
@return  动态创建的二维数组
*/
int** createSpace(int r, int c) {
    int** data = new int*[r];
    for (int i = 0; i < c; ++i) {
        data[i] = new int[c];
    }
    return data;
}

/*
销毁的二维数组
@param data 要销毁的二维数组
@param r    二维数组行数
*/
void freeSpace(int** data, int r) {
    for (int i = 0; i < r; ++i) {
        delete [] data[i];
    }
    delete data;
}

/*
将数据加载到二维数组中
@param data 存放数据的二维数组
@param r    二维数组行数
@param c    二维数组列数
*/
void loadData(int** data, int r, int c) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> data[i][j];
        }
    }
}

/*
输出二维数组中数据
@param data 存放数据的二维数组
@param r    二维数组行数
@param c    二维数组列数
*/
void showData(int** data, int r, int c) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

/*
在行列有序的二维数组中查找关键字
@param data          存放数据的二维数组
@param top_left_i    二维数组左上角行号
@param top_left_j    二维数组左上角列号
@param lower_right_i 二维数组右下角行号
@param lower_right_j 二维数组右下角列号
@param key           查找关键字
@return              查找到, 返回true, 反之, 返回false
*/
bool findKey(int** data, int top_left_i, int top_left_j, 
             int lower_right_i, int lower_right_j, int key) {
    // 检查下标或关键字越界
    if (top_left_i > lower_right_i || top_left_j > lower_right_j
        || key < data[top_left_i][top_left_j] || key > data[lower_right_i][lower_right_j]) {
        return false;
    }

    // 匹配值
    if (key == data[top_left_i][top_left_j]) {
        printf("(%d, %d)\n", top_left_i, top_left_j);
        return true;
    } else if (key == data[lower_right_i][lower_right_j]) {
        printf("(%d, %d)\n", lower_right_i, lower_right_j);
        return true;
    }

    int mid_i = (top_left_i + lower_right_i) / 2;
    int mid_j = (top_left_j + lower_right_j) / 2;

    if (key == data[mid_i][mid_j]) {
        printf("(%d, %d)\n", mid_i, mid_j);
        return true;    // 查找成功
    } else if (key < data[mid_i][mid_j]) {
        // 比中间值小, 在上方和左下方查找
        return findKey(data, top_left_i, top_left_j, mid_i - 1, lower_right_j, key)
            || findKey(data, mid_i, top_left_j, lower_right_i, mid_j - 1, key);
    } else {
        // 比中间值大, 在右边和左下方查找
        return findKey(data, top_left_i, mid_j + 1, lower_right_i, lower_right_j, key)
            || findKey(data, mid_i + 1, top_left_j, lower_right_i, mid_j, key);
    }
}

/*
在行列有序的二维数组中查找关键字
@param data 存放数据的二维数组
@param r    二维数组行数
@param c    二维数组列数
*/
bool findKey(int** data, int r, int c, int key) {
    return findKey(data, 0, 0, r - 1, c - 1, key);
}

int main() {
    freopen("data.txt", "r", stdin);
    int r, c;
    while(cin >> r >> c) {
        int** data = createSpace(r, c);
        loadData(data, r, c);
        //showData(data, r, c);

        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int key;
            cin >> key;
            //cout << key << " ";
            bool flag = findKey(data, r, c, key);
            if (flag == false) {
                cout << "Not found" << endl;
            }
        }

        freeSpace(data, r);
    }
    
    return 0;
}