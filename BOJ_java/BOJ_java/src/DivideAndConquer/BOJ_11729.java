package DivideAndConquer;

import java.util.*;
import java.io.*;

public class BOJ_11729 {
	
	public static int N;
	public static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		
		System.out.println(Hanoi(1, 2, 3, N));
		System.out.println(sb);
	}
	
	public static int Hanoi(int from, int temp, int to, int N) {
		int result = 0;
		
		// base case: N == 1
		if(N == 1) {
			sb.append(from + " " + to + "\n");
			return 1;
		}
		
		// 1 ~ n-1이 from -> temp
		result += Hanoi(from, to, temp, N - 1);
		
		// N이 from -> to
		result += Hanoi(from, temp, to, 1);
		
		// 1 ~ n-1이 temp -> to
		result += Hanoi(temp, from, to, N - 1);
		
		return result;
	}
}
