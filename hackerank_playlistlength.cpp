//
//  hackerank_playlistlength.cpp
//  algo
//
//  Created by Mina on 08/10/2019.
//  Copyright © 2019 Mina. All rights reserved.
//

#include <stdio.h>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int curmin, cursec;
    int min =0, sec =0, hr=0;
    int tempMin, tempHr;
    int N;
    cin>>N;
    for (int i =0; i<N; i++){
        cin>>curmin>>cursec;
        min+=curmin;
        sec+=cursec;
    }
    if(sec>60){
        tempMin = sec/60;
        min+=tempMin;
        sec-=tempMin*60;
    }
    if(min>60){
        tempHr = min/60;
        hr+=tempHr;
        min-=tempHr*60;
    }
    
    cout<<hr<<" "<<min<<" "<<sec;
    return 0;
}
