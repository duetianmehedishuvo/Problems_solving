package problem;

import java.math.BigInteger;

public class BigIntegerExample {

	public static void main(String[] args) {
		
		// bigInteger object to store result
		BigInteger sum,mul,sub;
		
		//for user input
		//use scanner or BufferReader
		
		// Two object of string created
		// Holds the value to calculate the sum
		
		String input1 = "012345678901234567"
                + "8901234567890123"
                + "4567890123456789"
                + "0123456789012345"
                + "6789012345678901"
                + "2345678901234567"
                + "8901234567890123"
                + "4567890123456789"
                + "0123456789012345"
                + "6789012345678901"
                + "2345678901234567"
                + "8901234567890123"
                + "4567890123456789"
                + "0123456789012345"
                + "6789012345678901"
                + "2345678901234567"
                + "8901234567890123"
                + "4554324324362432"
                + "7674637264783264"
                + "7832678463726478"
                + "3264736274673864"
                + "7364732463546354"
                + "6354632564532645"
                + "6325463546536453"
                + "6546325463546534"
                + "6325465345326456"
                + "4635463263453264"
                + "654632498739473";
String input2 = "0123456789012345"
                + "6789012345678901"
                + "2345678901234567"
                + "8901234567890123"
                + "4567890123456789"
                + "0123456789012345"
                + "6789012345678901"
                + "2345678901234567"
                + "8901234567890123"
                + "4567890123456789"
                + "0123456789012345"
                + "6789012345678901"
                + "2345678901234567"
                + "8901234567890123"
                + "4567890123456789"
                + "0123456789012345"
                + "6789012345678901"
                + "2345873271893718"
                + "2974897146378481"
                + "7489127847281478"
                + "2174871248721847"
                + "8748327463756475"
                + "6745781641263981"
                + "2839721897438974"
                + "3286574365764576"
                + "2376914689217817"
                + "4362473624721647"
                + "61247612748612746";
		
		// convert the string input to BIGInteger
		BigInteger a=new BigInteger(input1);
		BigInteger b=new BigInteger(input2);
		
		//Using add() method
		sum=a.add(b);
		sub=a.subtract(b);
		mul=a.multiply(b);
		
		
		//Display the result in BigInteger
		System.out.println("The Sum of\n"+a+"\nAnd\n"+b+" "+"\nis\n"+sum+"\n");
		System.out.println("The Subtraction of\n"+a+"\nAnd\n"+b+" "+"\nis\n"+sub+"\n");
		System.out.println("The Multiplication of\n"+a+"\nAnd\n"+b+" "+"\nis\n"+mul+"\n");

	}

}
