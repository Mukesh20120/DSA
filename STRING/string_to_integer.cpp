class Solution {
public:
    int myAtoi(string s) {
        //assume there is only given character of number the foundation of code
        int num=0;
        int n=s.length();
        for(int i=0;i<n;i++)
            num=num*10+(s[i]-'0');
        
        return num;
    }
};

//step 2 checking for white space
class Solution {
public:
    int myAtoi(string s) {
        //assume there is only given character of number the foundation of code
        int num=0;
        int n=s.length();
        //dealing with whitespace
        int j=0;
        while(j<n && s[j]==' ')j++; //assume the string only have white space then we check other case
        if(j>=n)return 0;
        
        for(int i=0;i<n;i++)
            num=num*10+(s[i]-'0');
        
        return num;
    }
};


//sign check 
class Solution {
public:
    int myAtoi(string s) {
       //assume there is only given character of number the foundation of code
        int num=0;
        int n=s.length();
        //dealing with whitespace
        int j=0;
        while(j<n && s[j]==' ')j++; //assume the string only have white space then we check other case
        if(j>=n)return 0;
        
        int sign=1;
        if(s[j]=='+' || s[j]=='-'){
            sign=s[j]=='+'?+1:-1;
            j++;
        }
        if(j>=n)return 0;
        for(int i=0;i<n;i++)
            num=num*10+(s[i]-'0');
        
        return num*sign;
    }
};


//handling the overflow condition and under flow condition
class Solution {
public:
    int myAtoi(string s) {
        //assume there is only given character of number the foundation of code
        int num=0;
        int n=s.length();
        //dealing with whitespace
        int j=0;
        while(j<n && s[j]==' ')j++; //assume the string only have white space then we check other case
        if(j>=n)return 0;
        
        int sign=1;
        if(s[j]=='+' || s[j]=='-'){
            sign=s[j]=='+'?+1:-1;
            j++;
        }
        if(j>=n)return 0;
        for(;j<n && s[j]>='0' && s[j]<='9';j++){
            if(num>INT_MAX/10 || (num==INT_MAX/10 && s[j]-'0'>INT_MAX%10))
                return (sign==1)?INT_MAX:INT_MIN;
            num=num*10+(s[j]-'0');
        }
        
        return num*sign;
    }
};