#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
/*
시간 복잡도는 input의 길이가 n이라고 했을 때 문자열을 한번 탐색하는 시간, n만큼이 필요할 것입니다.
공간 복잡도 역시 최악의 경우 input의 2배길이, 2n이 될 것이기 때문에 n이 될 것입니다.
*/

//int main() {
//	int testcase;
//	cin >> testcase;
//
//	for (int tc = 0; tc < testcase; tc++) {
//		string input;
//		cin >> input;
//
//		string output = "";
//		int count = 1;
//		for (int i = 1; i < input.length(); i++) {
//			if (input.at(i - 1) != input.at(i)) {//같지 않으면
//				string temp;
//				temp = to_string(count);//여태까지 갯수
//				output += temp;//를 합침
//				output += input.at(i - 1);//그 단어를 합침
//				count = 0;//초기화해줌
//			}
//			count++;
//		}
//		string temp;
//		temp = to_string(count);
//		output += temp;
//		output += input.at(input.length() - 1);
//
//		cout << output<<endl;
//	}
//	return 0;
//}
//int parent[100001] = { -1, };
//int maxs = 0;
//int Find(int x)
//{
//	if (parent[x] <= -1)
//		return x;
//	parent[x]=Find(parent[x]);
//	return parent[x];
//}
//void Union(int x, int y)
//{
//	if (Find(x) == Find(y))return;
//	int a = Find(x);
//	int b = Find(y);
//	parent[a] += parent[b];
//	parent[b] = a;
//}
//int main() {
//	int N, output = 0;
//	cin >> N;
//	for (int n = 0; n < 100001; n++)
//	{
//		parent[n] = -1;
//	}
//	for (int n = 0; n < N; n++) {
//		int x, y;
//		cin >> x >> y;
//		if (maxs < x)maxs = x;
//		if (maxs < y)maxs = y;
//		Union(x, y);
//	}
//	for (int i = 0; i <= maxs ; i++)
//	{
//		if (parent[i] < -1)output++;
//	}
//	cout << output<< endl;
//	return 0;
//}
public class Line {

	/**
	* Time complexity:
	* Space complexity:
	*/
	public static void main(String[] args) throws Exception {
		try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
			StringTokenizer tokens = new StringTokenizer(br.readLine().trim());
			int userX = Integer.parseInt(tokens.nextToken());
			int userY = Integer.parseInt(tokens.nextToken());
			int shopCount = Integer.parseInt(tokens.nextToken());
			//우선순위 큐 사용
			PriorityQueue<Shop> list = new PriorityQueue<Shop>();
			for (int i = 0; i < shopCount; i++) {
				tokens = new StringTokenizer(br.readLine().trim());
				int shopX = Integer.parseInt(tokens.nextToken());
				int shopY = Integer.parseInt(tokens.nextToken());
				String name = tokens.nextToken();
				int coupon = Integer.parseInt(tokens.nextToken());

				//거리구하는 공식
				int dist = (int)Math.sqrt(Math.pow(userX - shopX, 2) + Math.pow(userY - shopY, 2));
				//절삯을 위해 100의 자리수로 나눔
				int remain = dist / 100;
				//나눈값에 100을 곱하여 절삯완료
				dist = remain * 100;
				list.add(new Shop(shopX, shopY, dist, coupon, name));
			}
			while (!list.isEmpty()) {
				Shop s = list.poll();
				System.out.println(s.x + " " + s.y + " " + s.name + " " + s.couponCount);
			}
		}
	}
}
class Shop implements Comparable<Shop> {
	int x, y;
	int dist;
	int couponCount;
	String name;
	public Shop(int x, int y, int dist, int count, String n) {
		this.x = x;
		this.y = y;
		this.dist = dist;
		couponCount = count;
		name = n;
	}
	@Override
		public int compareTo(Shop o) {
		//문제에 명시된 정렬기준을 세워서 거기에 따른 정렬
		return dist < o.dist ? -1 : dist == o.dist ? couponCount > o.couponCount ? -1 :
			couponCount == o.couponCount ? nameFirst(name, o.name) ? -1 : 1 : 1 : 1;
	}
	//name의 값이 name2보다 우선순위인지 판별
	public boolean nameFirst(String name, String name2) {
		for (int i = 0; i < 6; i++) {
			if ((int)name.charAt(i) < (int)name2.charAt(i))
				return true;
			else if ((int)name.charAt(i) > (int)name2.charAt(i)) {
				return false;
			}
		}
		return false;
	}

}