#include "function.h"

int main()
{
    while (true)
    {
        ifstream input;
        char fileName[20];
        cout << "Enter the name of file: ";
        cin >> fileName;
        // 打开文件
        input.open(fileName);

        if (input.fail())
        {
            cout << "File does not exist" << endl;
            cout << "Exit program" << endl;
            return 0;
        }

        // 从文件中输入进程个数
        int process_num;
        input >> process_num;

        // 从文件中输入资源的种类数
        int resources_num;
        input >> resources_num;

        // 从文件中输入最大需求矩阵
        int Max[MAX_SIZE][MAX_SIZE];
		inputData(input, Max, process_num, resources_num);

        // 从文件中输入分配矩阵
        int Allocation[MAX_SIZE][MAX_SIZE];
		inputData(input, Allocation, process_num, resources_num);

        // 从文件中输入可利用资源向量
        int Available[MAX_SIZE];
		inputData(input, Available, resources_num);

        input.close();

        // 计算分配后的可利用资源向量
		int i;
        for (i = 0; i < process_num; i++)
        {
            computeArray(Available, Allocation[i], resources_num, '-');
        }

        // 计算需求矩阵
        int Need[MAX_SIZE][MAX_SIZE];
        computeArray(Need, Max, Allocation, process_num, resources_num, '-');

        // 初始化进程请求向量
        int Request[MAX_SIZE][MAX_SIZE];
        for (i = 0; i < process_num; i++)
        {
            setZero(Request[i], resources_num);
        }

        // 初始化记录进程执行顺序向量
        int Finish[MAX_SIZE];
        setZero(Finish, process_num);

        char ans;
        while (true)
        {
            cout << "Request resources for process(Y/N): ";
            cin >> ans;
            bool safe = false;    // 安全性检测结果
            // 进程请求资源
            if (ans == 'Y' || ans == 'y')
            {
                // 输入某一进程的请求向量
                int pid = inputRequest(Request, process_num, resources_num);

                // 请求向量小于或等于需求向量
                if (isNotGreater(Request[pid], Need[pid], resources_num))
                {
                    // 请求向量小于或等于可利用资源向量
                    if (isNotGreater(Request[pid], Available, resources_num))
                    {
                        // 修改可利用资源向量
                        // computeArray(Available, Request, resources_num, '-');
                        int Work[MAX_SIZE];
                        for (i = 0; i < resources_num; i++)
                        {
                            Available[i] -= Request[pid][i];
                            Work[i] = Available[i];
                        }
                        // 修改分配资源向量
                        computeArray(Allocation[pid], Request[pid], resources_num, '+');
                        // 修改需求资源向量
                        computeArray(Need[pid], Request[pid], resources_num, '-');

                        // 安全性算法 Available, Finish向量改变
                        safe = isSafe(Work, Need, Finish, Allocation, process_num, resources_num);

                        if (!safe)
                        {
                            cout << "\nDoesn't allocate resources for process! If allocate,"
                                << " then there is no safe list. Process waitting!" << endl;
                            // 恢复可利用资源向量
                            computeArray(Available, Request[pid], resources_num, '+');
                            // 恢复分配资源向量
                            computeArray(Allocation[pid], Request[pid], resources_num, '-');
                            // 恢复需求资源向量
                            computeArray(Need[pid], Request[pid], resources_num, '+');
                        }
                    }
                    else    // 请求向量大于可利用资源向量
                    {
                        cout << "\nRequest > Available! Process waitting!" << endl;
                    }
                }
                else    // 请求向量大于需求向量
                {
                    cout << "\nError: Request > Need!" << endl;
                }
            }
            else    // 进程不请求资源
            {
                int Work[MAX_SIZE];
                for (i = 0; i < resources_num; i++)
                {
                    Work[i] = Available[i];
                }
                // 安全性算法
                safe = isSafe(Work, Need, Finish, Allocation, process_num, resources_num);
                if (!safe)
                {
                    cout << "\nThere is not safe list exist." << endl;
                }
            }

            if (safe)
            {
                printSafeList(Finish, process_num);
            }

            // Finish置0，为下次分配资源准备
            setZero(Finish, process_num);
            cout << "\nContinue testing with file: " << fileName << "(Y/N?): ";
            cin >> ans;
            if (ans == 'N' || ans == 'n')
            {
                cout << "Exit file: " << fileName << endl;
                break;
            }
        }

        cout << "\nContinue with new file(Y/N?): ";
        cin >> ans;
        if (ans == 'N' || ans == 'n')
        {
            cout << "Exit program" << endl;
            return 0;
        }
    }

    return 0;
}
