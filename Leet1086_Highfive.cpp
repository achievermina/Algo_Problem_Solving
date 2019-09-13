//
//  Leet1086_Highfive.cpp
//  algo
//
//  Created by Mina on 10/09/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

#include <iostream>
#include <vector>
#include <vector>

using namespace std;
struct comp{
    bool operator()(const vector<int>& a, const vector<int>& b){ //operator을 썼었어야 함 comp도 써야하고
        if(a[0]==b[0]){
            return a[1]>b[1];
        }else
            return a[0]<b[0];
    }
};
//multiset  - repetitive 0, automatically sort

vector<vector<int>> highFive(vector<vector<int>>& items) {
    vector<vector<int>>  res;
    
    if(items.size()<1)
        return res;
    
    sort(items.begin(), items.end(), comp()); // vector이냐 아니냐가 중요한게 아님

    
    
    int idx=1, curStudent = items[0][0], sumScores=0;
    for(int i =1; i<items.size(); i++){
        if(items[i][0]==curStudent && idx<=5){
            sumScores+=items[i][1];
            idx++;
        }
        else{
            vector<int> student={};
            student.push_back(curStudent);
            student.push_back(sumScores/idx); // 한번에 vector<int> 넣는 방법없나?
            res.push_back(student);
            //res.push_back({curStudent,sumScores/idx});
            
            curStudent = items[i][0];
            sumScores=0;
            sumScores+=items[i][1];
            idx=1;
        }
    }
    return res;
}


//         vector<vector<int>> student;
//         int curStudent, sum_scores=0;;
//         vector<vector<int>> res;
//         vector<int> each;

//         if(items.size()<1)
//             return

//         sort(items[0].rbegin(), items[0].rend());
//         curStudent = items[0][0];
//         student.push_back(items[0][1]);

//         for(int i =1; i<items.size(); i++){

//             if(items[i][0]==curStudent)
//                 student.push_back(items[i][1]);
//             else{
//                 sort(student.begin(), student.end());
//                 for(int j=0; j<5 || j<student.size(); ++j){
//                     sum_scores+=student[j][1];
//                 }
//                 each.push_back(curStudent); each.push_back((sum_scores/j);
//                 res.push_back(each) // 한번에 vector<int> 넣는 방법없나?

//                 //resuet
//                 each.clear();
//                 curStudent=items[i][0];
//                 student.clear();
//                 sum_scores=0;
//             }
//         }

//     }
