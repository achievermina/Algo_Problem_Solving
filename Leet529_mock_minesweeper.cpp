//
//  Leet000_mock_minesweeper.cpp
//  algo
//
//  Created by Mina on 13/08/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
//LESSON
/*
 instead of writing all cases
vector<vector<int> > v = { {1,-1},{ 1,0 },{ 1,1 },{ -1,-1 },{ -1,0 },{ -1,1 },{ 0,-1 },{ 0,1 } };
int count = 0;
if (b[x][y] == 'E') {
    for (int i = 0; i < 8; i++) {
        if (judge(x + v[i][0], y + v[i][1], b) && b[x + v[i][0]][y + v[i][1]] == 'M')
        count++;
    }
    if (count > 0)
    b[x][y] = '0' + count;
    else {
        b[x][y] = 'B';
        for (int i = 0; i < 8; i++) {
            dfs(b, x + v[i][0], y + v[i][1]);
        }
    }
}
*/

int checkEightDirections(vector<vector<char>>& board, int x, int y){
    int count =0;
    
    if((x-1>=0 && y-1>=0 && x-1<board.size() && y-1<board[0].size()) && board[x-1][y-1] == 'M') count++;
    if((x-1>=0 && y>=0 && x-1<board.size() && y<board[0].size()) &&board[x-1][y] == 'M') count++;
    if((x-1>=0 && y+1>=0 && x-1<board.size() && y+1<board[0].size()) &&board[x-1][y+1] == 'M') count++;
    if((x>=0 && y-1>=0 && x<board.size() && y-1<board[0].size()) &&board[x][y-1] == 'M') count++;
    if((x>=0 && y+1>=0 && x<board.size() && y+1<board[0].size()) &&board[x][y+1] == 'M') count++;
    if((x+1>=0 && y-1>=0 && x+1<board.size() && y-1<board[0].size()) &&board[x+1][y-1] == 'M') count++;
    if((x+1>=0 && y>=0 && x+1<board.size() && y<board[0].size()) &&board[x+1][y] == 'M') count++;
    if((x+1>=0 && y+1>=0 && x+1<board.size() && y+1<board[0].size()) &&board[x+1][y+1] == 'M') count++;
    
    return count;
    
}

vector<vector<int>> checkNearbyMine(vector<vector<char>>& board){
    vector<vector<int>> MineMem;
    vector<int> temp;
    
    for(int i =0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            temp.push_back(checkEightDirections(board, i , j));
        }
        MineMem.push_back(temp);
        temp.clear();
    }
    return MineMem;
    
}

bool check(int x, int y, vector<vector<char>>& board){
    if((x>=0 && y>=0 && x<board.size() && y<board[0].size()) && (board[x][y] == 'M' || board[x][y] == 'E'))
        return true;
    else
        return false;
}

void recursive(vector<vector<char>>& board, int x, int y, vector<vector<int>> MineMem){
    if(board[x][y]== 'E' && MineMem[x][y]>0){ //This case, not checking the adjacent mines
        board[x][y] = '0'+MineMem[x][y]; //cast int to char
    }else if(board[x][y]== 'E' && MineMem[x][y]==0){
        board[x][y] = 'B';
    
        if(check(x-1,y-1,board)) recursive(board,  x-1,  y-1, MineMem);
        if(check(x-1,y,board)) recursive(board,  x-1,  y, MineMem);
        if(check(x-1,y+1,board)) recursive(board,  x-1,  y+1, MineMem);
        if(check(x,y-1,board)) recursive(board,  x,  y-1, MineMem);
        if(check(x,y+1,board)) recursive(board,  x,  y+1, MineMem);
        if(check(x+1,y-1,board)) recursive(board,  x+1,  y-1, MineMem);
        if(check(x+1,y,board)) recursive(board,  x+1,  y, MineMem);
        if(check(x+1,y+1,board)) recursive(board,  x+1,  y+1, MineMem);
    }
}


vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    if(board[click[0]][click[1]]== 'M'){
        board[click[0]][click[1]]='X';
        return board;
    }
    
    vector<vector<int>> MineMem = checkNearbyMine(board);
    recursive(board, click[0],click[1],MineMem);
    
    return board;
    
}


int main(){
    vector<vector<char>> board = {{'E','E','E','E','E'},{'E','E','M','E','E'},{'E','E','E','E','E'},{'E','E','E','E','E'}};
    vector<int> click = {3,0};
    
    vector<vector<char>> output = updateBoard(board, click);
    
    for(int i =0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
}
