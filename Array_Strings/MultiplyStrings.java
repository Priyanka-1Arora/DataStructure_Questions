class MultiplyStrings {
    public static void main(String[] args){
        assert(multiply("0", "1234").equals("0")==true);
        assert(multiply("123", "456").equals("56088")==true);
    }
    public static String multiply(String num1, String num2) {
        if(num1.equals("0") || num2.equals("0")) return "0";
        int zeroes=0;
        String ans_str="";
        for(int i=num2.length()-1;i>=0;i--){
            String str="";
            int base=num2.charAt(i)-'0';
            int carry=0;
            for(int k=0;k<zeroes;k++){
                str='0'+str;
            }
            zeroes+=1;
            for(int j=num1.length()-1;j>=0;j--){
                int mul=num1.charAt(j)-'0';
                int ans=(base*mul)+carry;
                if(ans>=10){
                    carry=0;
                    while(ans>=10){
                        carry+=1;
                        ans-=10;
                    }
                }
                else{
                    carry=0;
                }
                char c=(char)(ans+'0');
                str=c+str;
            }
            if(carry>0){
                char b=(char)(carry+'0');
                str=b+str;
            }
            if(base==0){
                str="";
                str=str+"0";
            }
            ans_str=add(ans_str,str);
            System.out.println(str+"  "+ans_str);
        }
        return ans_str;
    }
    public static String add(String s1,String s2){
        String str="";
        int i=s1.length()-1;
        int j=s2.length()-1;
        int carry=0;
        while(i>=0 && j>=0){
            int c1=s1.charAt(i)-'0';
            int c2=s2.charAt(j)-'0';
            int a=c1+c2+carry;
            if(a>=10){
                carry=0;
                    while(a>=10){
                        carry+=1;
                        a-=10;
                    }
            }
            else{
                carry=0;
            }
            i-=1;
            j-=1;
            char c=(char)(a+'0');
            str=c+str;
        }
        while(i>=0){
            int c1=s1.charAt(i)-'0';
            int a=c1+carry;
            if(a>=10){
                a-=10;
                carry=1;
            }
            else{
                carry=0;
            }
            char c=(char)(a+'0');
            str=c+str;
            i-=1;
        }
        while(j>=0){
            int c1=s2.charAt(j)-'0';
            int a=c1+carry;
            if(a>=10){
                a-=10;
                carry=1;
            }
            else{
                carry=0;
            }
            char c=(char)(a+'0');
            str=c+str;
            j-=1;
        }
        if(carry==1) str='1'+str;
        return str;
    }
}
