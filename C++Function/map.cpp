#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;
auto getMap(vector<int>& scores, vector<int>& ages) {
    multimap<int,int> age_score;
    for(int i=0;i<scores.size();i++){
        //3种插入方式
        age_score.insert(pair<int,int>(ages[i],scores[i]));
//        age_score.insert({ages[i],scores[i]});
//        age_score.insert(make_pair(ages[i],scores[i]));
    }

    return age_score;
}

struct classcomp {
    bool operator() (const string& lhs, const string& rhs) const
    {return lhs>rhs;}
};

void mysort(){
//    multimap<char, int>mymultimap{ {'a',1},{'b',2} };
//    multimap<char, int, less<char>>mymultimap{ {'a',1},{'b',2} };
    multimap<string, int, classcomp>mymultimap{ {"a",1},{"b",2} };
    for(auto it=mymultimap.begin();it!=mymultimap.end();it++){
        cout<<it->first;
    }
}


int main()
{

    vector<int> scores={1,3,5,10,15};
    vector<int> ages={5,2,3,4,1};
//    auto myMap=getMap(scores,ages);
    mysort();
    return 0;
}
