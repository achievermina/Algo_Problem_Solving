//
// Created by Mina on 16/04/2019.
//



string reverse(string::iterator& it){
    char head = *it;
    it++;

    if(head=='b' || head =='w')
        return string(1, head);

    string UL = reverse(it);
    string UR = reverse(it);
    string LL = reverse(it);
    string LR = reverse(it);

    return string("x") + LL+LR+UL+UR;


}

int main(){

    int caseNumber;
    cin>>caseNumber;

    for(int i=0; i<caseNumber; i++){
        string tree;
        cin>>tree;

        string::iterator it = tree.begin();
        cout<<reverse(it);
    }
}