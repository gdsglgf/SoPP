#include "function.h"

int main()
{
    while (true)
    {
        ifstream input;
        char fileName[20];
        cout << "Enter the name of file: ";
        cin >> fileName;
        // ���ļ�
        input.open(fileName);

        if (input.fail())
        {
            cout << "File does not exist" << endl;
            cout << "Exit program" << endl;
            return 0;
        }

        // ���ļ���������̸���
        int process_num;
        input >> process_num;

        // ���ļ���������Դ��������
        int resources_num;
        input >> resources_num;

        // ���ļ�����������������
        int Max[MAX_SIZE][MAX_SIZE];
		inputData(input, Max, process_num, resources_num);

        // ���ļ�������������
        int Allocation[MAX_SIZE][MAX_SIZE];
		inputData(input, Allocation, process_num, resources_num);

        // ���ļ��������������Դ����
        int Available[MAX_SIZE];
		inputData(input, Available, resources_num);

        input.close();

        // ��������Ŀ�������Դ����
		int i;
        for (i = 0; i < process_num; i++)
        {
            computeArray(Available, Allocation[i], resources_num, '-');
        }

        // �����������
        int Need[MAX_SIZE][MAX_SIZE];
        computeArray(Need, Max, Allocation, process_num, resources_num, '-');

        // ��ʼ��������������
        int Request[MAX_SIZE][MAX_SIZE];
        for (i = 0; i < process_num; i++)
        {
            setZero(Request[i], resources_num);
        }

        // ��ʼ����¼����ִ��˳������
        int Finish[MAX_SIZE];
        setZero(Finish, process_num);

        char ans;
        while (true)
        {
            cout << "Request resources for process(Y/N): ";
            cin >> ans;
            bool safe = false;    // ��ȫ�Լ����
            // ����������Դ
            if (ans == 'Y' || ans == 'y')
            {
                // ����ĳһ���̵���������
                int pid = inputRequest(Request, process_num, resources_num);

                // ��������С�ڻ������������
                if (isNotGreater(Request[pid], Need[pid], resources_num))
                {
                    // ��������С�ڻ���ڿ�������Դ����
                    if (isNotGreater(Request[pid], Available, resources_num))
                    {
                        // �޸Ŀ�������Դ����
                        // computeArray(Available, Request, resources_num, '-');
                        int Work[MAX_SIZE];
                        for (i = 0; i < resources_num; i++)
                        {
                            Available[i] -= Request[pid][i];
                            Work[i] = Available[i];
                        }
                        // �޸ķ�����Դ����
                        computeArray(Allocation[pid], Request[pid], resources_num, '+');
                        // �޸�������Դ����
                        computeArray(Need[pid], Request[pid], resources_num, '-');

                        // ��ȫ���㷨 Available, Finish�����ı�
                        safe = isSafe(Work, Need, Finish, Allocation, process_num, resources_num);

                        if (!safe)
                        {
                            cout << "\nDoesn't allocate resources for process! If allocate,"
                                << " then there is no safe list. Process waitting!" << endl;
                            // �ָ���������Դ����
                            computeArray(Available, Request[pid], resources_num, '+');
                            // �ָ�������Դ����
                            computeArray(Allocation[pid], Request[pid], resources_num, '-');
                            // �ָ�������Դ����
                            computeArray(Need[pid], Request[pid], resources_num, '+');
                        }
                    }
                    else    // �����������ڿ�������Դ����
                    {
                        cout << "\nRequest > Available! Process waitting!" << endl;
                    }
                }
                else    // ��������������������
                {
                    cout << "\nError: Request > Need!" << endl;
                }
            }
            else    // ���̲�������Դ
            {
                int Work[MAX_SIZE];
                for (i = 0; i < resources_num; i++)
                {
                    Work[i] = Available[i];
                }
                // ��ȫ���㷨
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

            // Finish��0��Ϊ�´η�����Դ׼��
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
