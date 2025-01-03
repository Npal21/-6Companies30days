
//Link: https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/description/

class Solution {

    private int[][] rects;
    private Random random;
    private TreeMap<Integer, Integer> map;
    private int totalPoints;

    public Solution(int[][] rects) {
        this.rects = rects;
        random = new Random();
        map = new TreeMap();
        totalPoints = 0;

        for(int i=0; i<rects.length; i++){
            int[] rect = rects[i];
            totalPoints += (rect[2]-rect[0]+1) * (rect[3]-rect[1]+1);
            map.put(totalPoints,i);
        }        
    }
    
    public int[] pick() {
        int r = random.nextInt(totalPoints)+1;
        int num = map.ceilingKey(r);
        int[] rectangle = rects[map.get(num)];
        return new int[]{
            rectangle[0] + random.nextInt(rectangle[2] - rectangle[0] + 1),
            rectangle[1] + random.nextInt(rectangle[3] - rectangle[1] + 1) };
        
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(rects);
 * int[] param_1 = obj.pick();
 */