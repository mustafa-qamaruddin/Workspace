import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.math.BigInteger;

public class Solution {

    public BigInteger mod_fib(int a, int b, int n){
        BigInteger[] dp = new BigInteger[n];
        dp[0] = new BigInteger(Integer.toString(a));
        dp[1] = new BigInteger(Integer.toString(b));
        for(int i = 2; i < n; i++){
            BigInteger tn_1_squared = dp[i-1].pow(2);
            dp[i] = tn_1_squared.add(dp[i-2]);
        }
        return dp[n-1];
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a,b,n;
        a = in.nextInt();
        b = in.nextInt();
        n = in.nextInt();
        Solution s = new Solution();
        BigInteger ret = s.mod_fib(a, b, n);
        System.out.println(ret);
    }
}