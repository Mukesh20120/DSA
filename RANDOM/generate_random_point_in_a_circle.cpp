#define d double
class Solution {
    private:
     d r,x1,y1;
public:
    Solution(double radius, double x_center, double y_center) {
        r=radius;
        x1=x_center;
        y1=y_center;
    }
    bool iscircle(d x,d y){
        return (x-x1)*(x-x1)+(y-y1)*(y-y1)<=(r*r);
    }
    vector<double> randPoint() {
       d x,y;
        while(!iscircle(x,y)){
            x=(d)rand()/RAND_MAX*(r+r)+x1-r;
            y=(d)rand()/RAND_MAX*(r+r)+y1-r;
        }
        return {x,y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */