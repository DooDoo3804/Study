from collections import deque

def solution(priorities, location):
    # 각 프로세스의 인덱스와 중요도를 튜플로 저장
    priority_queue = deque([(i, p) for i, p in enumerate(priorities)])

    executed_count = 0
    while priority_queue:
        # 대기열에서 첫 번째 프로세스를 가져옴
        current_process = priority_queue.popleft()
        # 가져온 프로세스보다 우선순위가 높은 프로세스가지 확인
        if any(current_process[1] < waiting_process[1] for waiting_process in priority_queue):
            priority_queue.append(current_process)
        else:
            # 높은 우선순위가 없다면 실행 완료로 처리
            executed_count += 1
            if current_process[0] == location:
                return executed_count