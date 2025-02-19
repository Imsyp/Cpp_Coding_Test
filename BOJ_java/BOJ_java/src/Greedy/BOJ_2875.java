package Greedy;

import java.util.*;
import java.io.*;

public class BOJ_2875 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		
		/*
			
		1. 여학생 2명 있는지 확인 
		2. 남학생 1명 있는지 확인
		3. 남은 학생의 수가 K보다 크거나 같은지 확인
		4. 3.까지 모두 충족하면 팀 수 +1
			
		 */
		
		int result = 0;
		
		while(true) {
			N -= 2;
			if(N < 0) {
				break;
			}
			
			M -= 1;
			if(M < 0) {
				break;
			}
			
			if(N + M < K) {
				break;
			}
			
			// 모든 조건을 충족해야 +1
			result++;
		}
		
		System.out.println(result);
	}
}