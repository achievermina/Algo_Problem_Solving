//
//  Leet353_designSnakeGame.cpp
//  algo
//
//  Created by Mina on 25/08/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

class SnakeGame {
public:
    int i,j;
    int  w,h, idx;
    deque<pair<int, int>> snake;  //list has continuous memory space but not deque
    vector<vector<int>> food;
    
    SnakeGame(int width, int height, vector<vector<int>> food) {
        this->food=food;
        idx=0;
        w = width;
        h = height;
        
        snake.push_back(make_pair(0,0));
        i=0; j=0;
    }
    

    int move(string direction) {
        //coordination is different with what I think!
        //Refer to the grid example
        if(direction=="U") i-=1;
        if(direction=="L") j-=1;
        if(direction=="R") j+=1;
        if(direction=="D") i+=1;
        
        if(!alive(i,j,w,h, snake))
        return -1;
        
        if(idx<food.size() && i==food[idx][0] && j==food[idx][1]){ //coordination check - x and y
            idx++;
        }else{
            snake.pop_back();
        }
        
        snake.push_front(make_pair(i,j));
        return idx;
    }
    
    //Need to consider bite itself
    bool alive(int i, int j, int w, int h, deque<pair<int, int>> snake){
        if(j>=w || j<0 || i>=h || i<0)
        return 0;
        else if(find(snake.begin(), snake.end(), make_pair(i,j))==snake.end()||find(snake.begin(), snake.end(), make_pair(i,j)) == snake.end() - 1)
        return 1;
        else
        return 0;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */

//grid가 위로 움직이는게 아니라 아래로 움직이는거니까 x y를 쓰면 헷갈림 --> i,j로 바꾸기
// IF THE NEXT MOVE IS AT THE TAIL OF CURRENT SNAKE, THAT IS FINE CUZ THE TAIL WILL MOVE AWAY  ALSO SHOULD BE MAKEPAIR(Y, X) HERE TOO, NOT X, Y

//reference https://leetcode.com/problems/design-snake-game/discuss/354586/C%2B%2B-solution-beats-100
//class SnakeGame {
//public:
//    int x,y;
//    int  w,h, idx;
//    deque<pair<int, int>> snake;  //list has continuous memory space but not deque
//    vector<vector<int>> food;
//    /** Initialize your data structure here.
//     @param width - screen width
//     @param height - screen height
//     @param food - A list of food positions
//     E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
//
//
//    SnakeGame(int width, int height, vector<vector<int>> food) {
//        this->food=food;
//        idx=0;
//        w = width;
//        h = height;
//
//        snake.push_back(make_pair(0,0));
//        x=0; y=0;
//    }
//
//
//    int move(string direction) {
//        //coordination is different with what I think!
//        //Refer to the grid example
//        //i, j로 사용하는게 나중에 안헷갈림
//        if(direction=="U") y-=1;
//        if(direction=="L") x-=1;
//        if(direction=="R") x+=1;
//        if(direction=="D") y+=1;
//
//        if(!alive(x,y,w,h, snake))
//        return -1;
//
//        if(idx<food.size() && x==food[idx][1] && y==food[idx][0]){ //coordination check - x and y
//            idx++;
//        }else{
//            snake.pop_back();
//        }
//
//        if(idx>=food.size()) return -1;
//
//        snake.push_front(make_pair(x,y));
//        return idx;
//    }
//
//    //Need to consider bite itself
//    bool alive(int x, int y, int w, int h, deque<pair<int, int>> snake){
//        if(x>=w || x<0 || y>=h || y<0)
//        return 0;
//        else if(find(snake.begin(), snake.end(), make_pair(x,y))==snake.end()||find(snake.begin(), snake.end(), make_pair(x,y)) == snake.end() - 1)
//        return 1;
//        else
//        return 0;
//    }
//};


int main(){
    
    vector<vector<int>> food = {{4,5}};
    int width=44;
    int height=7;
    
    SnakeGame* snake = new SnakeGame(width, height, food);
    cout<<snake->move("D");
    cout<<snake->move("R");
    cout<<snake->move("D");
    cout<<snake->move("D");
    cout<<snake->move("R");
    cout<<snake->move("R");

}






//
//
//
//
//
//
////나는 그냥 x, y로 햇는데 사람들은 vector<pair<int, int>> 로했다
////이렇게하는 이유가 있는가? 따로해도 상관없는듯
////움직이는걸 어떻게 하나 생각했는데
////스네이크를 벡터나 큐에 넣어놓고 새로 움직인 공간을 넣고 마지막껄 빼버리는식으로 한다 --> 그럼 모든 공간이 벡터속의 벡터에 들어있어
//
//
//class SnakeGame {
//public:
//    int x, y, length;
//    int foodx, foody, w,h;
//    vector<vector<int>> snake;
//
//
//    /** Initialize your data structure here.
//     @param width - screen width
//     @param height - screen height
//     @param food - A list of food positions
//     E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
//    SnakeGame(int width, int height, vector<vector<int>>& food) {
//        foodx= food[0][0];
//        foody= food[0][1];
//        w = width;
//        h =height;
//
//        x=0;
//        y=0;
//        lenght=1;
//    }
//
//    /** Moves the snake.
//     @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
//     @return The game's score after the move. Return -1 if game over.
//     Game over when snake crosses the screen boundary or bites its body. */
//    int move(string direction) {
//
//        if(direction=='U') y-=1;
//        if(direction=='L') x-=1;
//        if(direction=='R') x+=1;
//        if(direction=='D') y+=1;
//
//        if(!alive(x,y,w,h,length))
//            return -1;
//
//        //food
//        if(x=foodx && y==foody){
//
//            return 1;
//
//        }
//
//
//    bool alive(int x, int y, int w, int h, int length){
//        if(x<=w && x>=0 && y<=h && y>0 )
//            return 0;
//        return 1;
//    }
//};
//
///**
// * Your SnakeGame object will be instantiated and called as such:
// * SnakeGame* obj = new SnakeGame(width, height, food);
// * int param_1 = obj->move(direction);
// */
