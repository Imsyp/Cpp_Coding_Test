package BruteForce;

import java.util.*;
import java.io.*;

public class BOJ_1107 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int M = Integer.parseInt(br.readLine());
	
		
		boolean[] brokenBtns = new boolean[10];
		// 고장난 버튼이 없는 경우 스킵
		if(M != 0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int i = 0; i < M; i++) {
				brokenBtns[Integer.parseInt(st.nextToken())] = true;
			}
		}		
		
		int result = Math.abs(N - 100);
		
		// 모든 범위에 대해 전수탐색 수
		Loop1:
		for(int i = 0; i <= 999999; i++) {
			String num = String.valueOf(i);
			
			// 고장난 버튼을 포함한 경우 스킵
			for(int j = 0; j < num.length(); j++) {
				if(brokenBtns[Character.getNumericValue(num.charAt(j))]) {
					continue Loop1;
				}
			}
			
			// result 갱신
			result = Math.min(result, num.length() + Math.abs(N - Integer.parseInt(num)));
		}
		
		System.out.println(result);
	}
}
