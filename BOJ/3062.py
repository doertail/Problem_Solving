Test_case = int(input())

for i in range(Test_case):
    num = input()
    new_number = num[::-1]
    re = str(int(num)+int(new_number))

    lens = len(re)
    
    for j in range(lens):
        if re[j] != re[lens-j-1]:
            print("NO")
            break
        if(j == lens-1):
            print("YES")
            
    