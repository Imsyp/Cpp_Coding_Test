package Greedy;

import java.util.*;
import java.io.*;

public class BOJ_11047 {
	
	public static int N;
	public static int K;
	public static int[] coins;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		coins = new int[N];
		
		for(int i = N - 1; i >= 0; i--) {
			coins[i] = Integer.parseInt(br.readLine());
		}
		
		int count = 0;
		int amount = K;
		int idx = 0;
		while(K > 0 && idx < N) {
			if(coins[idx] > amount) {
				idx++;
				continue;
			}
			amount -= coins[idx];
			count++;
		}
		
		System.out.println(count);
	}
}
