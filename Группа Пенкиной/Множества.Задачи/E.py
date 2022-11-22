n = int(input())
a = set(range(1, n + 1))    #ввод
q = []

for i in range(n):
    try:
        z = set([int(i) for i in input().split()])    #про вот это все есть в D
    except ValueError:
        break
    
    if(len(a & z) > len(a - z)):     # определяем, какая операция была использована и добавляем
        q.append("YES")              # ее в массив, а так же проводим ее на нашем множестве
        a &= z
    else:
        q.append("NO")
        a -= z
for i in q: print(i)   #печатаем массив и итоговое множество
print(*sorted(a))