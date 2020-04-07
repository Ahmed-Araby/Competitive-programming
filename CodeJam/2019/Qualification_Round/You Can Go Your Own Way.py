# this is a very nice solution 
# but the problem could be harder if the 
# grid is not square 


t = int(input())
ca = 1
while True:
    n = int(input())
    s = input()
    print("case #{}: ".format(ca), end='')
    for i in range(0 , 2*n-2 , 1):
        if s[i]=='E':
            print('S', end='')
        else:
            print('E', end='')
    print()
    t-=1
    ca +=1
    if t==0:
        break
