import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.math.BigInteger;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n;
        n = in.nextInt();
        BigInteger bi = new BigInteger(Integer.toString(n));
        BigInteger temp;
        for(int i = n-1; i > 0; i--){
            temp = new BigInteger(Integer.toString(i));
            bi = bi.multiply(temp);
        }
        System.out.println(bi);
    }
}