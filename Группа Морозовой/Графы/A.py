a = "NO"
n = int(input())
q = []


for i in range(n):
    q.append(list(map(int, input().split())))
    
for i in range(n):
    if(q[i][i] == 1):           #петля может быть только если вершина соединена сама с собой
        a = "YES"
print(a)