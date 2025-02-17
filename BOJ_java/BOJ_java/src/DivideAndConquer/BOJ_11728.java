package DivideAndConquer;

import java.util.*;
import java.io.*;

public class BOJ_11728 {
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(bf.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[] arr = new int[n + m];
		
		st = new StringTokenizer(bf.readLine());
		for(int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		st = new StringTokenizer(bf.readLine());
		for(int i = 0; i < m; i++) {
			arr[i + n] = Integer.parseInt(st.nextToken());
		}
	
		Arrays.sort(arr);
		
		StringBuilder sb = new StringBuilder();
		
		for(int i : arr) {
			sb.append(i + " ");
		}
		
		System.out.println(sb);
	}
}