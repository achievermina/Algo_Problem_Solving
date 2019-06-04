/*

Leet code 207_Course schedule
Connected Graph


*/



class Solution {
public:
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> Noprerequsite;
        bool flag;
        int visited[numCourses] =0;
        
        //Find no preprequesite required courses       
        for(int i=0; i<numCourses; i++){
            flag= true;
           for(int j =0; j<prerequisites.size(); j++){
               if(prerequisites[j][0]==i)
                   flag = false;
                   break;
           }
            if(flag) Noprerequsite.push_back(i);
        }
        
        //explore DFS
        while(Noprerequsite.size()!=0){
            int courseNum = Noprerequsite.pop();
            explore(courseNum, visited,prerequisites);
        }
        
    }
    
    void explore(int coursenumber, int* visited[], vector<vector<int>>& prerequisites){
        for(int j =0; j<prerequisites.size(); j++){
            int nextCourse;
               if(prerequisites[j][1]==coursenumber && !visited[j])
                   nextCourse = prerequisites[j][0];
                    visited[nextCourse] = 1;
                    explore(nextCourse,visited,prerequisites);
           }
    }
};