#include "stdafx.h"
#include <stdio.h>
int N, Answer = 0;
int map[20][20];
void req(int(*m)[20], int dir, int cnt)
{
	if (cnt >= 5)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (Answer < m[i][j])Answer = m[i][j];
			}
		}
		return;
	}
	int temp_map[20][20];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			temp_map[i][j] = 0;
		}
	}
	if (dir == 0)//상
	{
		for (int i = 0; i < N; i++)//가로로
		{
			int temp = 0, position = 0;
			for (int j = 0; j < N; j++)//세로로
			{
				if (m[j][i] != 0)//값이 있을 때
				{
					if (temp == m[j][i])//그전값이랑 같으면
					{
						temp_map[position - 1][i] = 2 * m[j][i];//합쳐줌
						temp = 0;//2개로 묶였으니 0으로 초기화
					}
					else//그 전 값이랑 다르면
					{
						temp_map[position][i] = m[j][i];//0부터 차례로 채워줌 결국 밀어주는거임
						position += 1;//
						temp = m[j][i];//값 저장
					}
				}
			}
		}
		req(temp_map, 0, cnt + 1);
		req(temp_map, 1, cnt + 1);
		req(temp_map, 2, cnt + 1);
		req(temp_map, 3, cnt + 1);
	}
	else if (dir == 1)//하
	{
		for (int i = 0; i < N; i++)//가로로
		{
			int temp = 0, position = N - 1;
			for (int j = N - 1; j >= 0; j--)//세로로
			{
				if (m[j][i] != 0)
				{
					if (temp == m[j][i])
					{
						temp_map[position + 1][i] = 2 * m[j][i];
						temp = 0;
					}
					else
					{
						temp_map[position][i] = m[j][i];
						position -= 1;
						temp = m[j][i];
					}
				}
			}
		}
		req(temp_map, 0, cnt + 1);
		req(temp_map, 1, cnt + 1);
		req(temp_map, 2, cnt + 1);
		req(temp_map, 3, cnt + 1);
	}
	else if (dir == 2)//좌
	{
		for (int i = 0; i < N; i++)//가로로
		{
			int temp = 0, position = 0;
			for (int j = 0; j < N; j++)//세로로
			{
				if (m[i][j] != 0)
				{
					if (temp == m[i][j])
					{
						temp_map[i][position - 1] = 2 * m[i][j];
						temp = 0;
					}
					else
					{
						temp_map[i][position] = m[i][j];
						position += 1;
						temp = m[i][j];
					}
				}
			}
		}
		req(temp_map, 0, cnt + 1);
		req(temp_map, 1, cnt + 1);
		req(temp_map, 2, cnt + 1);
		req(temp_map, 3, cnt + 1);
	}
	else if (dir == 3)//우
	{
		for (int i = 0; i < N; i++)//가로로
		{
			int temp = 0, position = N - 1;
			for (int j = N - 1; j >= 0; j--)//세로로
			{
				if (m[i][j] != 0)
				{
					if (temp == m[i][j])
					{
						temp_map[i][position + 1] = 2 * m[i][j];
						temp = 0;
					}
					else
					{
						temp_map[i][position] = m[i][j];
						position -= 1;
						temp = m[i][j];
					}
				}
			}
		}
		req(temp_map, 0, cnt + 1);
		req(temp_map, 1, cnt + 1);
		req(temp_map, 2, cnt + 1);
		req(temp_map, 3, cnt + 1);
	}
}
int main() {
	Answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			map[i][j] = 0;
		}
	}
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	req(map, 0, 0);
	req(map, 1, 0);
	req(map, 2, 0);
	req(map, 3, 0);
	printf("%d\n", Answer);
	return 0;
}