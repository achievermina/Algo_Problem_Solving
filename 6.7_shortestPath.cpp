//
// Created by Mina on 09/04/2019.
//


int n;
double dist[max][max];


double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength){

    if(path.size() ==n)
        return currentLength + dist[path[0]][path.back()];

    double ret = INF;

    for(int next =0; next < n; ++next){
        if(visited[next])
            continue;

        int here = path.back();

        path.push_back(next);
        visited[next] = ture;

        // Find the remaining paths through recursive function

        double cand = shortestPath(path, visited, currentLength + dist[here][next]);
        ret = min(ret, cand);

        visited[next] =false;
        path.pop_back();

    }
    return ret;
}