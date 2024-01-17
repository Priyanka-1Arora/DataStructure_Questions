import java.util.HashMap;

class AtmostTwoCharacters {
    public static void main(String[] args){
        assert(lengthOfLongestSubstring("ninninja")==6);
    }
	public static int lengthOfLongestSubstring(String s) {
		// Write your code here.
		int i=0;
		int j=0;
		int max=0;
		HashMap<Character,Integer> h1=new HashMap<>();
		while(j<s.length()){
			if(h1.containsKey(s.charAt(j))){
				int old=h1.get(s.charAt(j));
				h1.put(s.charAt(j),old+1);
			}
			else{
				h1.put(s.charAt(j),1);
			}
			while(i<j && h1.size()>2){
				int old=h1.get(s.charAt(i));
				if(old-1==0){ h1.remove(s.charAt(i));}
				else{h1.put(s.charAt(i),old-1);}
				i+=1;
			}
			max=Math.max(max,(j-i+1));
			j+=1;
		}
		return max;
	}
}