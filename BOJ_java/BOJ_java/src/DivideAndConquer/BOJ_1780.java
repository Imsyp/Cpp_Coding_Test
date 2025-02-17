package DivideAndConquer;

import java.util.*;
import java.io.*;

public class BOJ_1780 {

	public static int[] result = new int[3];
	public static int[][] board; 
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		board = new int[N][N];
		
		for(int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < N; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		recursion(0, 0, N);
		
		// 결과 출력
		for(int r : result) {
			System.out.println(r);
		}
	}
	
	public static void recursion(int beginX, int beginY, int unit) {
		int color = board[beginX][beginY];
		
		// base case: unit == 1
		if(unit == 1) {
			result[color + 1] += 1;
			return ;
		}
		
		boolean square = true;
		
		Outer:
		for(int i = 0; i < unit; i++) {
			for(int j = 0; j < unit; j++) {
				if(board[beginX + i][beginY + j] != color) {
					square = false;
					break Outer;
				}
			}
		}
		
		// 단색의 사각형인 경우
		if(square) {
			result[color + 1] += 1;
			return ;
		} 
		
		// 단색의 사각형이 아닌 경우
		unit /= 3;
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				recursion(beginX + (unit * i), beginY + (unit * j), unit);
			}
		}
	}
}
