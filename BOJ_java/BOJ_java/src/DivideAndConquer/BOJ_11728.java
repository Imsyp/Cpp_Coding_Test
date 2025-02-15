package DivideAndConquer;

import java.util.*;
import java.io.*;

public class BOJ_11728 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());	// 첫 번째 배열 길이
		int m = Integer.parseInt(st.nextToken());	// 두 번째 배열 길이
		int[] arr = new int[n + m];
		
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < m; i++) {
			arr[i + n] = Integer.parseInt(st.nextToken());
		}
		
		Arrays.sort(arr);
		
		StringBuilder sb = new StringBuilder();
		
		for(int r : arr) {
			sb.append(r + " ");
		}
		System.out.println(sb);
	}
}