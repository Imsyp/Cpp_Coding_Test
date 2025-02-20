package Greedy;

import java.util.*;
import java.io.*;

public class BOJ_10610 {
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringBuilder sb = new StringBuilder();
		
		String N = br.readLine();
		char[] numbers = N.toCharArray();
		int sum = 0;
		
		for(int i = 0; i < N.length(); i++) {
			sum += Character.getNumericValue(N.charAt(i));
		}
		
		Arrays.sort(numbers);
		
		// 10의 배수 & 3의 배수 판정법 -> 만족하지 않는 경우
		if(!(N.contains("0")) || sum % 3 != 0) {
			System.out.println(-1);
			return ;
		}
		
		// 30의 배수인 경우 가장 큰 수
		for(int i = N.length() - 1; i >= 0; i--) {
			sb.append(numbers[i]);
		}
		
		System.out.println(sb.toString());
		br.close();
	}

}
