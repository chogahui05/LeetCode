/*
    Bitwise ORs of Subarrays solution
    author : chogahui05 (kyungwan cho)
*/
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        vector <int> P; P.clear();
        vector <int> C; C.clear();
        vector <int> R; R.clear();
        vector <int> T; T.clear();
        for(int i=0;i<(int)A.size();i++)
        {
            int te = A[i];
            C.push_back(te);
            for(int j=0;j<(int)P.size();j++)
                C.push_back(te|P[j]);
            C.erase(unique(C.begin(),C.end()),C.end()); P.clear();
            for(int j=0;j<(int)C.size();j++)
            {
                P.push_back(C[j]); R.push_back(C[j]);
            }
            C.clear();
        }
        radix_sort(R,T);
        R.erase(unique(R.begin(),R.end()),R.end());
        return (int)R.size();
    }
    void radix_sort(vector <int> &R,vector <int> &T)
    {
        int co[65536] = {0}; T.resize(R.size());
        for(int i=0;i<R.size();i++)
            co[R[i]&65535]++;
        for(int i=1;i<65536;i++)
            co[i] += co[i-1];
        for(int i=0;i<R.size();i++)
        {
            int kei = (R[i]&65535); co[kei]--;
            T[co[kei]] = R[i];
        }
        for(int i=0;i<65536;i++)
            co[i] = 0;
        for(int i=0;i<T.size();i++)
            co[T[i]>>16]++;
        for(int i=1;i<65536;i++)
            co[i] += co[i-1];
        
        for(int i=0;i<T.size();i++)
        {
            int kei = (T[i]>>16); co[kei]--;
            R[co[kei]] = T[i];
        }
    }
};
