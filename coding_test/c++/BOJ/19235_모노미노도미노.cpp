#include <iostream>
#include <algorithm>
#include <vector>

int score;
int blocks;
int total_map[10][10] = { 0 };
int block[3][2][2] = { {{0, 0}, {0, 0}}, {{0, 1}, {0, 0}}, {{1, 0}, {0, 0}} };
using namespace std;

void move_green(int t, int x, int y, int num)
{
	for (int i = 4; i < 11; i++)
	{
		int f_check_x = x + block[t][0][0];
		int f_check_y = i + block[t][0][1];
		int s_check_x = x + block[t][1][0];
		int s_check_y = i + block[t][1][1];

		int f_next_x = f_check_x;
		int f_next_y = f_check_y + 1;
		int s_next_x = s_check_x;
		int s_next_y = s_check_y + 1;

		if (f_next_y == 10 || s_next_y == 10)
		{
			total_map[f_check_x][f_check_y] = num;
			total_map[s_check_x][s_check_y] = num;
			break;
		}

		else if (total_map[f_next_x][f_next_y] != 0 || total_map[s_next_x][s_next_y] != 0)
		{
			total_map[f_check_x][f_check_y] = num;
			total_map[s_check_x][s_check_y] = num;
			break;
		}
	}
}

void move_blue(int t, int x, int y, int num)
{
	for (int i = 4; i < 11; i++)
	{
		int f_check_x = i + block[t][0][0];
		int f_check_y = y + block[t][0][1];
		int s_check_x = i + block[t][1][0];
		int s_check_y = y + block[t][1][1];

		int f_next_x = f_check_x + 1;
		int f_next_y = f_check_y;
		int s_next_x = s_check_x + 1;
		int s_next_y = s_check_y;

		if (f_next_x == 10 || s_next_x == 10)
		{
			total_map[f_check_x][f_check_y] = num;
			total_map[s_check_x][s_check_y] = num;
			break;
		}

		if (total_map[f_next_x][f_next_y] != 0 || total_map[s_next_x][s_next_y] != 0)
		{
			total_map[f_check_x][f_check_y] = num;
			total_map[s_check_x][s_check_y] = num;
			break;
		}
	}
}

void boundary_green()
{
	int over_line = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i + 4 == 4)
			{
				if (total_map[i + 4][j] != 0)
				{
					over_line = 2;
					break;
				}
			}
			if (i + 4 == 5)
			{
				if (total_map[i + 4][j] != 0)
				{
					over_line = 1;
					break;
				}
			}
		}
		if (over_line != 0)
			break;
	}
	if (over_line == 0)
		return;
	else
	{
		for (int i = 9; i >= 4; i--)
		{
			for (int j = 0; j < 4; j++)
			{
				total_map[i][j] = total_map[i - over_line][j];
				if (i <= 5)
				{
					total_map[i][j] = 0;
				}
			}
		}
	}
}

void boundary_blue()
{
	int over_line = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i + 4 == 4)
			{
				if (total_map[j][i + 4] != 0)
				{
					over_line = 2;
					break;
				}
			}
			if (i + 4 == 5)
			{
				if (total_map[j][i + 4] != 0)
				{
					over_line = 1;
					break;
				}
			}
		}
		if (over_line != 0)
			break;
	}
	if (over_line == 0)
		return;
	else
	{
		for (int i = 9; i >= 4; i--)
		{
			for (int j = 0; j < 4; j++)
			{
				total_map[j][i] = total_map[j][i - over_line];
				if (i <= 5)
				{
					total_map[j][i] = 0;
				}
			}
		}
	}
}

bool pos_below_green(int l) {
	int re_result = 0;
	while (l >= 4) {
		int check_idx = 0;
		
		while (check_idx <= 4) {
			bool pair = false;
			int move_count = 0;
			if (total_map[l][check_idx] == 0) {
				check_idx++;
				continue;
			}
			if (total_map[l][check_idx] == total_map[l][check_idx + 1]) pair = true;
			if (pair == true) {
				for (int k = 0; k < 6; k++)	{
					if (l + k + 1 >= 10) break;
					else if (total_map[l + k + 1][check_idx] != 0 || total_map[l + k + 1][check_idx + 1] != 0) break;
					else move_count++;
				}

				if (move_count != 0) re_result++;

				total_map[l + move_count][check_idx] = total_map[l][check_idx];
				total_map[l + move_count][check_idx + 1] = total_map[l][check_idx + 1];
				if (move_count) total_map[l][check_idx] = 0;
				if (move_count) total_map[l][check_idx + 1] = 0;
				check_idx += 2;
			}
			else {
				for (int k = 0; k < 6; k++) {
					if (l + k + 1 >= 10) break;
					if (total_map[l + k + 1][check_idx] != 0) break;
					else move_count++;
				}

				if (move_count != 0) re_result++;

				total_map[l + move_count][check_idx] = total_map[l][check_idx];
				if (move_count) total_map[l][check_idx] = 0;
				check_idx++;
			}
		}
		l--;
	}


	if (re_result) return true;
	else return false;
}

void remove_green(int l) {
	for (int i = l; i >= 4; i--) {
		for (int j = 0; j < 4; j++) {
			total_map[i][j] = total_map[i - 1][j];
		}
	}
}

void check_green() {
	int line = 9;
	int rem_line = 0;
	while (line >= 4) {
		bool made = true;
		for (int j = 0; j < 4; j++)	{
			if (total_map[line][j] == 0) {
				made = false;
				break;
			}
		}

		if (made) {
			remove_green(line);
			if (rem_line < line) rem_line = line;
			score++;
		}
		else {
			line--;
		}

		if (line < 4 && rem_line != 0) {
			// 아래로 내린 경우
			if (pos_below_green(rem_line)) {
				line = 9;
				rem_line = 0;
			}
			// 아닌 경우
		}
	}
}

bool pos_below_blue(int l)
{
	int re_result = 0;
	while (l >= 4) {
		int check_idx = 0;

		while (check_idx <= 4) {
			bool pair = false;
			int move_count = 0;
			if (total_map[check_idx][l] == 0) {
				check_idx++;
				continue;
			}
			if (total_map[check_idx][l] == total_map[check_idx + 1][l]) pair = true;
			if (pair == true)
			{
				for (int k = 0; k < 6; k++)
				{
					if (l + k + 1 >= 10) break;
					else if (total_map[check_idx][l + k + 1] != 0 || total_map[check_idx + 1][l + k + 1] != 0) break;
					else move_count++;
				}

				if (move_count != 0) re_result++;

				total_map[check_idx][l + move_count] = total_map[check_idx][l];
				total_map[check_idx + 1][l + move_count] = total_map[check_idx + 1][l];
				if (move_count) total_map[check_idx][l] = 0;
				if (move_count) total_map[check_idx + 1][l] = 0;
				check_idx += 2;
			}
			else {
				for (int k = 0; k < 6; k++) {
					if (l + k + 1 >= 10) break;
					if (total_map[check_idx][l + k + 1] != 0) break;
					else move_count++;
				}

				if (move_count != 0) re_result++;

				total_map[check_idx][l + move_count] = total_map[check_idx][l];
				if (move_count) total_map[check_idx][l] = 0;
				check_idx++;
			}
		}
		l--;
	}
	if (re_result) return true;
	else return false;
}

void remove_blue(int l)
{
	for (int i = l; i >= 4; i--) {
		for (int j = 0; j < 4; j++) {
			total_map[j][i] = total_map[j][i - 1];
		}
	}
}

void check_blue()
{
	int line = 9;
	int rem_line = 0;
	while (line >= 4) {
		bool made = true;
		for (int j = 0; j < 4; j++) {
			if (total_map[j][line] == 0) {
				made = false;
				break;
			}
		}

		if (made) {
			remove_blue(line);
			if (rem_line < line) rem_line = line;
			score++;
		}
		else {
			line--;
		}

		if (line < 4 && rem_line != 0) {
			if (pos_below_blue(rem_line)) {
				line = 9;
				rem_line = 0;
			}
		}
	}
}

void count_block()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 6; j < 10; j++)
		{
			if (total_map[i][j] != 0)
			{
				blocks++;
			}
			if (total_map[j][i] != 0)
			{
				blocks++;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n = 0;
	cin >> n;

	for (int i = 1; i < n + 1; i++)
	{
		int t;
		int x;
		int y;
		cin >> t >> x >> y;
		move_green(t - 1, x, y, i);
		move_blue(t - 1, x, y, i);

		check_green();
		check_blue();

		boundary_green();
		boundary_blue();
	}
	count_block();
	cout << score << "\n" << blocks;
	return 0;
}
