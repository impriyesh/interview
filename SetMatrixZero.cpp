#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stdlib.h>
#include "SetMatrixZero.h"

using namespace std;

// void Solution::setZeroes(vector<vector<int> >& matrix) {
//        int i,j,count =0;
//        map<int,bool> firstCol,firstRow;
//
//    for(i=0;i<matrix.size();i++){
//        firstRow[i]=false;
//        if(matrix[i][0]){
//            firstRow[i]=true;
//        }
//    }
//    for(j=0;j<matrix[i].size;j++){
//            firstCol=false;
//        if(matrix[0][j] == 0){
//            firstCol[j]=true;
//        }
//    }
//
//    cout <<endl;
//        for(i=1;i<matrix.size();i++){
//        for(j=1;j<matrix[i].size();j++)
//            if(matrix[i][j] == 0){
//                matrix[i][0] =0;
//                matrix[0][j]=0;
//                if(firstCol[i].second)
//                    firstCol[i].second=false;
//                if(firstRow[j].second)
//                    firstRow[j].second=false;
//            }
//        }
//
//// Now scan 1'st row, column by column, if 0, mark all rows of that column to 0
//        for(j=0;j<matrix[0].size();j++){
//             if(matrix[0][j] == 0 && firstRow[j].second){
//                for(i=0;i<matrix.size();i++)
//                        matrix[i][j]=0;
//            }
//        }
//
//
//// Now scan first column row by row, if 0 , mark all column of that row to zero.
//
//        for(i=0;i<matrix.size();i++){
//                if(matrix[i][0] == 0){
//                     for(j=0;j<matrix[0].size();j++)
//                            matrix[i][j]=0;
//                }
//        }
//
//}


void Solution::setZeroes(vector<vector<int> >& matrix) {

    set<int> rows, cols;

    for(int i = 0; i<matrix.size(); i++)
    {
        vector<int> &row = matrix[i];
        for(int j=0; j< row.size(); j++)
        {
            if(row[j] == 0)
            {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }

    for(int i=0; i<rows.size(); i++)
    {
        vector<int> &row = matrix[rows[i]];
        for(int j=0; j<row.size(); j++)
        {
            row[j] = 0;
        }
    }

    for(int j=0; j<cols.size(); j++)
    {
        for(int i=0; i<matrix.size(); i++)
        {
            matrix[i][cols[j]] = 0;
        }
    }

}

int main(){

    cout << "Priyesh" << endl;
    Solution s;

//    char charBoard[10][10] = { {'X', 'X', '0', '.', 'X', '.'},
//                               {'.', '.', '.', '.', 'X', '.'},
//                               {'.', '.', '.', '.', 'X', '.'},
//                               {'.', 'X', 'X', '.', '.', '.'},
//                               {'.', '.', '.', '.', 'X', '.'},
//                               {'X', 'X', '.', '.', 'X', '.'}
//                             };

    int charBoard[5][4] = { {0,0,0,5},
                            {4,3,1,4},
                            {0,1,1,4},
                            {1,2,1,3},
                            {0,0,1,5}};


    for(int i=0; i<5; i++)
    {
        vector<int> row;
        for(int j=0; j<4; j++)
        {
            row.push_back(charBoard[i][j]);
        }
        s.m_board.push_back(row);
    }

    cout << "***************** \n" << "Original matrix" <<endl;
    for(int i=0; i<5; i++)
    {
        cout << "\n";
        for(int j=0; j<4; j++)
            cout << s.m_board[i][j] << "\t";
    }
    s.setZeroes(s.m_board);
    cout <<endl;
    cout << "***************** \n" << "transformed matrix" <<endl;
    for(int i=0; i<5; i++)
    {
        cout << "\n";
        for(int j=0; j<4; j++)
            cout << s.m_board[i][j] << "\t";
    }
}
