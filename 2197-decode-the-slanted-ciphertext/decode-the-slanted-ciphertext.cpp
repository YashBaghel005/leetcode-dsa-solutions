class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        if(n == 0){
            return "";
        }
        int cols = n/rows;
        int index = 0;
        vector<vector<char>> mat(rows,vector<char>(cols));
        for(int i = 0; i<rows;i++){
            for(int j = 0; j<cols; j++){
                if(index<n){
                    mat[i][j] = encodedText[index];
                    index++;
                }else{
                    mat[i][j] = ' ';
                }
                
            }
        }
        string ans = "";
        for(int i = 0; i<cols; i++){
            int p = 0;
            int q = i;
            while(p<rows && q<cols){
                ans.push_back(mat[p][q]);
                p++;
                q++;
            }
        }
    
        while(ans[ans.size()-1] == ' '){
            ans.pop_back();
        }
        return ans;
    }
};