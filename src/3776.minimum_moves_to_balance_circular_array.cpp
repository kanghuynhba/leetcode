class Solution {
public:
    long long minMoves(vector<int>& balance) {
        long long sum=0;
        int size=balance.size();
        int id=-1;
        for(int i=0; i<size; i++) {
            sum+=balance[i];
            if(balance[i]<0) {
                id=i; 
            }
        }       
        if(sum<0) {
            return -1;
        }
        if(id==-1) {
            return 0;
        }
        int left=(id-1+size)%size, right=(id+1)%size;
        long long ans=0, curSum=0;
        long long negNumb=balance[id];
        int count=1;
        int pos;
        while(left!=right) {
            curSum=balance[left]+balance[right]; 
            if(curSum+negNumb<0) {
                ans+=(curSum*count);
                negNumb+=curSum;
                count++;
            } else {
                ans+=((-negNumb)*count);
                negNumb=0;
                break;
            }
            left=(left-1+size)%size;
            right=(right+1)%size;
        }
        if(negNumb<0) {
            ans+=(-negNumb*count);
        }
        return ans;
    }
};
