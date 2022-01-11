import java.io.*;
import java.util.*;

public class Main {

	private static String parentStr;
	private static String [] words;
	private static int [] dp;
	private static int [][] wordCost;		// [startIdx] -> [endIdx]
	private static int n;
	
	public static void main(String[] args) throws Exception {
		inputFun();
		
		for(int idxStart=0; idxStart<parentStr.length(); idxStart++){
			for(int i=0; i<n; i++) {
				int idxEnd = idxStart + words[i].length();
				if(idxEnd <= parentStr.length()){
					int cost = calMinCost(parentStr.substring(idxStart, idxEnd), words[i]);
					if(cost >= 0){
						wordCost[idxStart][idxEnd] = Math.min(wordCost[idxStart][idxEnd], cost);
					}
				}
			}
		}
		
		for(int row=0; row<=parentStr.length(); row++){
			for(int col=row+1; col<=parentStr.length(); col++){
				dp[col] = Math.min(dp[col], dp[row]+wordCost[row][col]);
			}
		}
		if(dp[parentStr.length()]==999999999){
			System.out.println(-1);
		}
		else{
			System.out.println(dp[parentStr.length()]);
		}
		return;
	}
	
	public static int calMinCost(String parentStr, String childStr){
		PriorityQueue<Character> parentPQ = new PriorityQueue<>();
		PriorityQueue<Character> childPQ = new PriorityQueue<>();
		int count=0;
		// 비교 문자열 길이가 다른 경우
		if(parentStr.length() != childStr.length()){
			return -1;
		}
		
		// 자릿수가 다른 문자열 찾기 cost 계산
		for(int i = 0; i<parentStr.length(); i++){
			if(parentStr.charAt(i) != childStr.charAt(i)){
				count+=1;
			}
			parentPQ.add(parentStr.charAt(i));
			childPQ.add(childStr.charAt(i));
		}
		
		// 같은 문자열인지 확인
		for(int i = 0; i<parentStr.length(); i++) {
			if(parentPQ.poll() != childPQ.poll()){
				return -1;
			}
		}
		return count;
	}
	
	public static void inputFun() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		parentStr = br.readLine();
		n = Integer.parseInt(br.readLine());
		words = new String [n+2];
		dp = new int [parentStr.length()+2];
		wordCost = new int [parentStr.length()+2][parentStr.length()+2];
		
		for(int i=0; i<n; i++){
			words[i]= br.readLine();
		}
		
		for(int i=0; i<parentStr.length()+2; i++){
			for(int j=0; j<parentStr.length()+2; j++){
				wordCost[i][j]=999999999;	//INF 설정
			}
		}
		
		for(int i=1; i<parentStr.length()+2; i++){
			dp[i]=999999999;	//INF 설정
		}
	}
}
