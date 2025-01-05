
//Link: https://leetcode.com/problems/repeated-dna-sequences/description/

class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        Map<String, Integer> cntMap = new HashMap<>();
        List<String> list = new ArrayList<>();

        for(int i=0; i< s.length()-10+1; i++){
            String t = s.substring(i, i+10);
            if(cntMap.merge(t, 1, Integer::sum)==2){
                list.add(t);
            }
        }
        return list;
    }
}