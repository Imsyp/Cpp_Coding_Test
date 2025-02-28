package BruteForce;

import java.util.*;
import java.io.*;

public class BOJ_1451 {
	
	static int[][] board; 
	
	// 영역합 계산
	static long area(int x1, int y1, int x2, int y2) {
		int result = 0;
		
		for(int i = x1; i <= x2; i++) {
			for(int j = y1; j <= y2; j++) {
				result += board[i][j];
			}
		}
		
		return result;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		board = new int[N + 1][M + 1];
		for(int i = 0; i < N; i++) {
			String line = br.readLine();
			for(int j = 0; j < M; j++) {
				int num = Character.getNumericValue(line.charAt(j));
				board[i + 1][j + 1] = num;
			}
		}
		
		long area1, area2, area3;
		long result = 0;
		
		// case 1: ㅜ
		for(int i = 1; i <= N - 1; i++) {
			area1 = area(1, 1, i, M);
			for(int j = 1; j <= M - 1; j++) {
				area2 = area(i + 1, 1, N, j);
				area3 = area(i + 1, j + 1, N, M);
				result = Math.max(result, area1 * area2 * area3);
			}
		}
		
		// case 2: ㅏ
		for(int i = 1; i <= N - 1; i++) {
			for(int j = 1; j <= M - 1; j++) {
				area1 = area(1, 1, N, j);
				area2 = area(1, j + 1, i, M);
				area3 = area(i + 1, j + 1, N, M);
				result = Math.max(result, area1 * area2 * area3);
			}
		}
		
		// case 3: ㅗ
		for(int i = 1; i <= N - 1; i++) {
			area1 = area(i + 1, 1, N, M);
			for(int j = 1; j <= M - 1; j++) {
				area2 = area(1, 1, i, j);
				area3 = area(1, j + 1, i, M);
				result = Math.max(result, area1 * area2 * area3);
			}
		}
		
		// case 4: ㅓ
		for(int i = 1; i <= N - 1; i++) {
			for(int j = 1; j <= M - 1; j++) {
				area1 = area(1, j + 1, N, M);
				area2 = area(1, 1, i, j);
				area3 = area(i + 1, 1, N, j);
				result = Math.max(result, area1 * area2 * area3);
			}
		}
		
		// case 5: ㅣㅣ
		for(int i = 1; i <= M - 2; i++) {
			area1 = area(1, 1, N, i);
			for(int j = i + 1; j <= M - 1; j++) {
				area2 = area(1, i + 1, N, j);
				area3 = area(1, j + 1, N, M);
				result = Math.max(result, area1 * area2 * area3);
			}
		}

		// case 6: ㅡㅡ
		for(int i = 1; i <= N - 2; i++) {
			area1 = area(1, 1, i, M);
			for(int j = i + 1; j <= N - 1; j++) {
				area2 = area(i + 1, 1, j, M);
				area3 = area(j + 1, 1, N, M);
				result = Math.max(result, area1 * area2 * area3);
			}
		}
		
		System.out.println(result);
	}	
}

