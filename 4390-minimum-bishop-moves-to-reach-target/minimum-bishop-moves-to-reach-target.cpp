class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int a = source[0]+source[1];
        int b = target[0]+target[1];
        if(a%2 == 0 && b%2 != 0 || (a%2 != 0 && b%2 == 0)){
            return -1;
        }
        int x = source[0];
        int y = source[1];
        int xt = target[0];
        int yt = target[1];
        for(int i = 0; i<8; i++){
            if(x+i == xt && y+i == yt || (x+i == xt && y-i == yt) || (x-i == xt && y+i == yt) || (x-i == xt && y-i == yt)){
                return 1;
            }
        }
        return 2;
    }
};