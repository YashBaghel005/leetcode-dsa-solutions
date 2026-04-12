class Solution {
public:
    double findAngle(double a, double b, double c) {
        double cosC = (a*a + b*b - c*c) / (2*a*b);
        
        // To avoid precision issues (cos value should be between -1 and 1)
        cosC = max(-1.0, min(1.0, cosC));
        
        double angle = acos(cosC); // result in radians
        
        // Convert to degrees
        return angle * 180.0 / M_PI;
    }
    vector<double> internalAngles(vector<int>& sides) {
        int x = sides[0];
        int y = sides[1];
        int z = sides[2];

        if(x+y <= z || x+z <= y || y+z <= x){
            return {};
        }

        double a = findAngle(x,y,z);
        double b = findAngle(x,z,y);
        double c = findAngle(y,z,x);
        vector<double> v = {a,b,c};
        sort(v.begin(),v.end());

        return v;

    }
};