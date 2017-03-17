#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>

using namespace std;

int countBattleships(vector<vector<char> >& board)
{
    int count = 0;
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board[i].size(); j++)
        {
            if(board[i][j] == 'X')
            {
                if(!((i>0 && board[i-1][j] == 'X') || (j>0 && board[i][j-1] == 'X' )))
                   count++;
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<char> > board;
    char charBoard[10][10] = { {'X', 'X', '.', '.', 'X', '.'},
                               {'.', '.', '.', '.', 'X', '.'},
                               {'.', '.', '.', '.', 'X', '.'},
                               {'.', 'X', 'X', '.', '.', '.'},
                               {'.', '.', '.', '.', 'X', '.'},
                               {'X', 'X', '.', '.', 'X', '.'}
                             };
    for(int i=0; i<6; i++)
    {
        vector<char> row;
        for(int j=0; j<6; j++)
        {
            row.push_back(charBoard[i][j]);
        }
        board.push_back(row);
    }

    cout<<"Number of battleShips : "<<countBattleships(board);
    return 0;
}
