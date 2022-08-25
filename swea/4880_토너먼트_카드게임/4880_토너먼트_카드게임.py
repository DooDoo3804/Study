# 4880_토너먼트_카드게임
# 2022-08-23
import sys
sys.stdin = open('input.txt', 'r')
T = int(input())

# start, (end+start)//2
# (end+start)//2+1, end
def winner(pre_idx, stf_idx):
    """
        두 사람의 인덱스를 받아 game_list값으로 가위바위보를 진행하고 우승자의 인덱스를 반환하는 함수

        Args:
            pre_idx (int): 왼쪽 / 앞사람의 인덱스
            stf_idx (int): 오른쪽 / 뒷사람의 인덱스
        Returns:
            int : 우승자의 인덱스를 반환
    """
    # pre는 앞 사람의 값 stf는 뒷 사람의 값
    # 1 : 가위, 2 : 바위, 3 : 보
    # 위에 따르면 큰 값이 이김
    # 가위와 보(1, 3)인 경우만 가위(1)가 이김
    # 우승자를 가리고 인덱스를 반환
    pre = game_list[pre_idx]
    stf = game_list[stf_idx]
    if pre == stf:
        return pre_idx
    elif (pre, stf) == (1, 3) or (pre, stf) == (3, 1):
        if pre == 1:
            return pre_idx
        else:
            return stf_idx
    else :
        if pre > stf:
            return pre_idx
        else:
            return stf_idx

def div_area(start, end):
    """
        처음과 끝의 인덱스를 받아서 두 구간으로 나눠 winner()함수를 수행하는 함수

        구간이 2개 이하가 될때 까지 div_area를 반복 수행
        구간(start, end)이 하나면 그 자체를 반환
        구간(start, end)이 차이가 하나면 두 명만 있으므로 winner()함수 수행

        Args:
            start (int): 구간의 시작 인덱스
            end (int): 구간의 끝 인덱스
        Returns:
            int : game의 최종 우승자의 인덱스를 반환
    """
    # 구간이 같으면 start 반환
    # 구간에 숫자가 2개이면 우승자를 가려서 반환
    if start == end:
        return start
    elif end - start == 1 :
        return winner(start, end)
    # 구간이 2보다 길면 2아래가 될 때까지 앞뒤 구간을 나누고 그 값들로 다시 우승자를 선정
    else :
        pre_list = [start, (start+end)//2]
        pre = div_area(pre_list[0], pre_list[1])
        stf_list = [(start + end) // 2 + 1, end]
        stf = div_area(stf_list[0], stf_list[1])
        return winner(pre, stf)

for t in range(1, T+1):
    students = int(input())
    game_list = list(map(int, input().split()))
    total_idx = []
    for i in range(students):
        total_idx.append(i)

    # 구간 시작 인덱스 : start, 구간 마지막 인데스 : end
    start = total_idx[0]
    end = total_idx[-1]
    print('#{} {}' .format(t, div_area(start, end)+1))