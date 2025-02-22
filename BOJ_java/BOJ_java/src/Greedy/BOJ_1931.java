package Greedy;

import java.util.*;
import java.io.*;

public class BOJ_1931 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		int[][] time = new int[N][2];	// [][0]은 시작시점, [][1]은 종료시점
		
		StringTokenizer st;
		
		for(int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			time[i][0] = Integer.parseInt(st.nextToken());
			time[i][1] = Integer.parseInt(st.nextToken());
		}
		
		Arrays.sort(time, new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				// 종료시간이 같을 경우 시작시간이 빠른 순으로 정렬
				if(o1[1] == o2[1]) {
					return o1[0] - o2[0];
				}
				
				return o1[1] - o2[1];
			}
		});
		
		int	result = 0;
		int prev_end_time = 0;
		
		for(int i = 0; i < N; i++) {
			// 직전 종료 시간이 다음 회의 시작 시간과 겹치지 않으면 갱신
			if(prev_end_time <= time[i][0]) {
				prev_end_time = time[i][1];
				result++;
			}
		}
		
		System.out.println(result);
	}
}
