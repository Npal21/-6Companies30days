class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {

        auto f = [](int part1, int part2, int partCenter) -> int{
            if(part1 <= partCenter && partCenter <= part2){
                return 0;
            }
            return partCenter<part1 ? part1-partCenter : partCenter-part2;
        };

        int a = f(x1, x2, xCenter);
        int b = f(y1, y2, yCenter);
        return a*a + b*b <= radius*radius;
        
    }
};