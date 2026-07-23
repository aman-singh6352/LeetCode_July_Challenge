class Solution {
    public:
        vector<int> segTree;
        void buildTree(int i, int l, int r,
                       vector<int>& nums) {
            if (l == r) {
                segTree[i] = nums[l];
                return;
            }
            int mid = (l + r) / 2;
            buildTree(2 * i + 1, l, mid, nums);
            buildTree(2 * i + 2, mid + 1, r, nums);
            segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);
        }
        int queryTree(int i, int l, int r,
                      int start, int end) {
            int mid = (l + r) / 2;
            if (l > end || r < start)
                return 0; // out of bound
            else if (l >= start && r <= end)
                return segTree[i]; // inside
            return max(queryTree(2 * i + 1, l, mid, start, end),
                   queryTree(2 * i + 2, mid + 1, r, start, end));
        }
        vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
            int n = s.size();
            int activeCount = count(begin(s), end(s), '1');
            vector<int> blockStart, blockEnd, blockSize;
            for(int i = 0;i < n;i++){
                if(s[i] == '0'){
                    blockStart.push_back(i);
                    int last = i;
                    while(last < n && s[last] == '0'){
                        last++;
                    }
                    blockEnd.push_back(last-1);
                    blockSize.push_back(last-i);
                    i = last;
                }
            }
            int m = blockSize.size();
            if(m < 2) {
                return vector<int> (queries.size(), activeCount);
            }
    
            vector<int> pairSum;
            for(int i = 1;i < blockSize.size();i++){
                pairSum.push_back(blockSize[i-1]+blockSize[i]);
            }
             
            segTree.resize(4*pairSum.size());
            buildTree(0, 0, pairSum.size()-1, pairSum);
            vector<int> result;
            for(auto &it:queries){
                int startIdx = it[0], endIdx = it[1];
                int low = lower_bound(begin(blockEnd), end(blockEnd), startIdx)-begin(blockEnd);
                int high = upper_bound(begin(blockStart), end(blockStart), endIdx)-begin(blockStart)-1;
    
                int maxpairsum = 0;
                if(low < high) {
                    int firstlen = blockEnd[low] - max(blockStart[low], startIdx) + 1;
                    int lastlen = min(blockEnd[high], endIdx) - blockStart[high] + 1;
                    if(high - low == 1) maxpairsum = firstlen + lastlen;
                    else {
                        int pair1 = firstlen + blockSize[low+1];
                        int pair2 = lastlen + blockSize[high-1];
                        int RMQmaxsum = queryTree(0, 0, pairSum.size()-1, low+1, high-2);
                        maxpairsum = max(pair1, max(pair2, RMQmaxsum));
                    }
                }
                result.push_back(maxpairsum + activeCount);
            }
            return result;
        }
    };