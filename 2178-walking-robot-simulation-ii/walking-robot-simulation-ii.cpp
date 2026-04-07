class Robot {
public:
    int x = 0;
    int y = 0;
    char dir = 'E';
    int width;
    int height;

    Robot(int width, int height) {
        this->width = width;     
        this->height = height;  
    }
    
    void step(int num) {
        int cycle = 2 * (width + height - 2);   
        if (cycle > 0) {
            num %= cycle;
            if (num == 0) num = cycle;   // ⭐ IMPORTANT FIX
        }         

        for(int i = 0; i < num; i++){
            if(dir == 'E'){
                if(x >= width - 1){  
                    dir = 'N';
                    y++;
                }else{
                    x++;
                }
            }
            else if(dir == 'N'){
                if(y >= height - 1){  
                    dir = 'W';
                    x--;
                }else{
                    y++;
                }
            }
            else if(dir == 'W'){
                if(x <= 0){
                    dir = 'S';
                    y--;
                }else{
                    x--;
                }
            }else{
                if(y <= 0){
                    dir = 'E';
                    x++;
                }else{
                    y--;
                }
            }
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        if(dir == 'E') return "East";
        else if(dir == 'W') return "West";
        else if(dir == 'S') return "South";
        else return "North";
    }
};