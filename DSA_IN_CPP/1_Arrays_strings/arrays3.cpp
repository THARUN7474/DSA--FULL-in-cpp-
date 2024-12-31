#include <bits/stdc++.h>

using namespace std;

void findkeyin2darray(int rows, int cols, int arr[][6], int key)
{
    int flag = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (arr[i][j] == key)
            {
                flag = 1;
                cout << "yes we found the key " << arr[i][j] << " it is at position row=> " << i << " and col=> " << j << endl;
            }
        }
    }
    if (!flag)
    {
        cout << "no we didn't found the key " << endl;
    }
}

void transpoematrix(int ROWS, int COLS, int ar[][4], int transar[][3])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            transar[j][i] = ar[i][j];
        }
    }
}

const int MAX_SIZE = 100; // Maximum size for the matrix

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
    int transposed[MAX_SIZE][MAX_SIZE];

    // Computing transpose
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            transposed[j][i] = matrix[i][j];
        }
    }

    // Printing transpose
    std::cout << "Transpose of the matrix:" << std::endl;
    for (int i = 0; i < cols; ++i)
    {
        for (int j = 0; j < rows; ++j)
        {
            std::cout << transposed[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int arr[3][3];

    int arr1[2][3] = {{0, 1, 3}, {10, 11, 13}};

    // in memory it stores as (c*i)+j post in linear formate only

    // input taking function
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "****************************************************************" << endl;
    // printing row wise
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "***********" << endl;
    // printing column wise
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
    cout << "****************************************************************" << endl;
    // printing only diagonal elements
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
            {
                cout << arr[i][j] << " ";
            }
            else
            {
                cout << " ";
            };
        }
        cout << endl;
    }

    cout << "****************************************************************" << endl;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "****************************************************************" << endl;

    // give me an array of size [5][6];
    int arr3[5][6] = {
        {0, 1, 2, 3, 4, 5},
        {10, 11, 22, 33, 44, 55},
        {100, 111, 222, 333, 444, 555},
        {1000, 1111, 2222, 3333, 4444, 5555},
        {10000, 11111, 22222, 33333, 44444, 55555}};

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << arr3[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << arr3[j][i] << " ";
        }
        cout << endl;
    }

    cout << "******************************************" << endl;
    // row wise sum

    vector<int>
        rowsum;

    for (int i = 0; i < 5; i++)
    {
        int sum = 0;
        for (int j = 0; j < 6; j++)
        {
            sum = sum + arr3[i][j];
        }
        rowsum.push_back(sum);
    }

    for (int i = 0; i < 5; i++)
    {
        cout << rowsum[i] << " ";
    }
    cout << endl;

    cout << "******************************************" << endl;

    vector<int> colsum;

    for (int i = 0; i < 6; i++)
    {
        int sum = 0;
        for (int j = 0; j < 5; j++)
        {
            sum = sum + arr3[j][i];
        }
        colsum.push_back(sum);
    }

    for (int i = 0; i < 6; i++)
    {
        cout << colsum[i] << " ";
    }
    cout << endl;

    findkeyin2darray(5, 6, arr3, 44);

    cout << "****************************************" << endl;

    const int ROWS = 3;
    const int COLS = 4;
    int ar[ROWS][COLS] = {
        {5, 8, 3, 2},
        {10, 6, 7, 1},
        {4, 9, 12, 11}};

    int maxElement = INT_MIN;
    int minElement = INT_MAX;

    // Find maximum and minimum elements
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            if (ar[i][j] > maxElement)
            {
                maxElement = ar[i][j];
            }
            if (arr[i][j] < minElement)
            {
                minElement = ar[i][j];
            }
        }
    }

    std::cout << "Maximum element: " << maxElement << std::endl;
    std::cout << "Minimum element: " << minElement << std::endl;

    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }

    cout << "transpose of above matrix" << endl;
    for (int i = 0; i < COLS; ++i)
    {
        for (int j = 0; j < ROWS; ++j)
        {
            cout << ar[j][i] << " ";
        }
        cout << endl;
    }

    // or else

    int transar[COLS][ROWS];
    transpoematrix(ROWS, COLS, ar, transar);
    for (int i = 0; i < COLS; ++i)
    {
        for (int j = 0; j < ROWS; ++j)
        {
            cout << transar[i][j] << " ";
        }
        cout << endl;
    }

    cout << "********************************" << endl;

    // Declaration of a 2D vector of integers
    // vector<vector<int>> matrix;

    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    for (const auto &row : matrix)
    {
        for (int elem : row)
        {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    vector<vector<int>> vv;

    vector<int> a = {1, 2, 3};
    vector<int> b = {11, 22, 33};
    vector<int> c = {111, 222, 333};
    vector<int> d = {1111, 2222, 3333};

    vv.push_back(a);
    vv.push_back(b);
    vv.push_back(c);
    vv.push_back(d);

    for (int i = 0; i < vv.size(); i++)
    {
        for (int j = 0; j < vv[i].size(); j++)
        {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector<int>> vvrr(3, vector<int>(4, 0));

    cout << "enter elements for 2d vector arrays" << endl;
    for (int i = 0; i < vvrr.size(); i++)
    {
        for (int j = 0; j < vvrr[i].size(); j++)
        {
            cin >> vvrr[i][j];
        }
    }

    for (int i = 0; i < vvrr.size(); i++)
    {
        for (int j = 0; j < vvrr[i].size(); j++)
        {
            cout << vvrr[i][j] << " ";
        }
        cout << endl;
    }
}
