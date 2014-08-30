class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ret;
        if(num.size() < 4)
            return ret;
        
        sort(num.begin(), num.end());
        map<int, vector<pair<int, int> > >  m;
        set<vector<int> > fourSumSet;
        int i, j;
        
        for(i = 0; i < num.size() - 1; i++){
            for(j = i + 1; j < num.size(); j++){
                m[num[i] + num[j]].push_back(make_pair(i,j));
            }
        }
        
        pair<int, int> p, q;
        map<int, vector<pair<int, int> > >::iterator itStart = m.begin();
        map<int, vector<pair<int, int> > >::iterator itEnd = m.end();
        itEnd--;
        int start = 0;
        int end = m.size() - 1;
        
        while(start <= end){
            if(itStart->first + itEnd->first < target){
                itStart++;
                start++;
            }else if(itStart->first + itEnd->first > target){
                itEnd--;
                end--;
            }else{
                for(i = 0; i < itStart->second.size(); i++){
                    for(j = 0; j < itEnd->second.size(); j++){
                        p = itStart->second[i];
                        q = itEnd->second[j];
                        
                        if(p.first == q.first || p.first == q.second
                        || p.second == q.first || p.second == q.second){
                            continue;
                        }
                        
                        vector<int> vec;
                        vec.push_back(num[p.first]);
                        vec.push_back(num[p.second]);
                        vec.push_back(num[q.first]);
                        vec.push_back(num[q.second]);
                        sort(vec.begin(), vec.end());
                        fourSumSet.insert(vec);
                    }
                }
                itStart++;
                itEnd--;
                i++;
                j--;
            }
        }
        
        for(set<vector<int> >::iterator it = fourSumSet.begin();
            it != fourSumSet.end();
            it++){
                ret.push_back(*it);
            }
            
        return ret;
    }
};