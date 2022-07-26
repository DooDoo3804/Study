total_sw = int(input())
sw_list_proto = list(input())
sw_list = []
for i in range(len(sw_list_proto)):
    if sw_list_proto[i] != ' ':
        sw_list.append(sw_list_proto[i])

students = int(input())
for i in range(students):
    gender, sw_num = map(int, input().split())
    if gender == 1 :
        for j in range(total_sw):
            if int(j+1) % sw_num == 0 :
                if sw_list[j] == '1' :
                    sw_list[j] = '0'
                else : 
                    sw_list[j] = '1'
    if gender == 2 :
        sw_len = min(abs(sw_num), abs(sw_num-total_sw-1)) #3
        for j in range(sw_len):
            if sw_list[sw_num-1-j] == sw_list[sw_num-1+j]:
                if sw_list[sw_num-1-j] == '1' :
                    sw_list[sw_num-1+j] = '0'
                    sw_list[sw_num-1-j] = '0'
                else : 
                    sw_list[sw_num-1+j] = '1'
                    sw_list[sw_num-1-j] = '1'
            else : break

for i in range(len(sw_list)):
    if (i+1) % 20 == 0 :
        print(sw_list[i], end='\n')
    elif i == len(sw_list)-1:
        print(sw_list[i])
    else : print(sw_list[i], end = ' ')