import java.util.*;
class WithoutRepeatingCharacter {
    public static void main(String[] args){
        assert(lengthOfLongestSubstring("abcabcbb")==3);
        assert(lengthOfLongestSubstring("bbbbb")==1);
    }
    public static int lengthOfLongestSubstring(String s) {
        int i=0;
        int j=0;
        int max=0;
        HashMap<Character,Integer> h1=new HashMap<>();
        while(j<s.length()){
            if(h1.containsKey(s.charAt(j))){
                while(i<j && h1.containsKey(s.charAt(j))){
                    System.out.println(s.charAt(i)+"   "+h1);
                    int old=h1.get(s.charAt(i));
                    if(old-1!=0){
                        h1.put(s.charAt(i),old-1);
                    }
                    h1.remove(s.charAt(i));
                    i+=1;
                }
            }
            h1.put(s.charAt(j),1);
            max=Math.max(j-i+1,max);
            j+=1;
        }
        return max;
    }
}