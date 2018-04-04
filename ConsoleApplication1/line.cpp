#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
/*
�ð� ���⵵�� input�� ���̰� n�̶�� ���� �� ���ڿ��� �ѹ� Ž���ϴ� �ð�, n��ŭ�� �ʿ��� ���Դϴ�.
���� ���⵵ ���� �־��� ��� input�� 2�����, 2n�� �� ���̱� ������ n�� �� ���Դϴ�.
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
//			if (input.at(i - 1) != input.at(i)) {//���� ������
//				string temp;
//				temp = to_string(count);//���±��� ����
//				output += temp;//�� ��ħ
//				output += input.at(i - 1);//�� �ܾ ��ħ
//				count = 0;//�ʱ�ȭ����
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
			//�켱���� ť ���
			PriorityQueue<Shop> list = new PriorityQueue<Shop>();
			for (int i = 0; i < shopCount; i++) {
				tokens = new StringTokenizer(br.readLine().trim());
				int shopX = Integer.parseInt(tokens.nextToken());
				int shopY = Integer.parseInt(tokens.nextToken());
				String name = tokens.nextToken();
				int coupon = Integer.parseInt(tokens.nextToken());

				//�Ÿ����ϴ� ����
				int dist = (int)Math.sqrt(Math.pow(userX - shopX, 2) + Math.pow(userY - shopY, 2));
				//������ ���� 100�� �ڸ����� ����
				int remain = dist / 100;
				//�������� 100�� ���Ͽ� ����Ϸ�
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
		//������ ��õ� ���ı����� ������ �ű⿡ ���� ����
		return dist < o.dist ? -1 : dist == o.dist ? couponCount > o.couponCount ? -1 :
			couponCount == o.couponCount ? nameFirst(name, o.name) ? -1 : 1 : 1 : 1;
	}
	//name�� ���� name2���� �켱�������� �Ǻ�
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