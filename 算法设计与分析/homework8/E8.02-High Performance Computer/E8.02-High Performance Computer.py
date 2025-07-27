import sys

def read():
    return list(map(int, sys.stdin.readline().split()))

na, nb = read()
p = read()[0]

ta, tb, ka, kb = [0] * (p+1), [0] * (p+1), [0] * (p+1), [0] * (p+1)

for i in range(1, p+1):
    ta[i], tb[i], ka[i], kb[i] = read()

f1 = [[[0 for _ in range(nb+1)] for _ in range(na+1)] for _ in range(p+1)]
f2 = [[[float('inf') for _ in range(nb+1)] for _ in range(na+1)] for _ in range(p+1)]

#f1[p][i][j]表示第p个节点执行i个A任务，j个B任务的最短时间
def DP1():
    for a in range(1, p+1):
        F = [[[float('inf') for _ in range(nb+1)] for _ in range(na+1)] for _ in range(2)]
        F[0][0][0], F[1][0][0] = 0, 0
        for i in range(na+1):
            for j in range(nb+1):
                for k in range(1, i+1):
                    F[0][i][j] = min(F[0][i][j], F[1][i-k][j] + ka[a] * k * k + ta[a])
                for k in range(1, j+1):
                    F[1][i][j] = min(F[1][i][j], F[0][i][j-k] + kb[a] * k * k + tb[a])
                f1[a][i][j] = min(F[0][i][j], F[1][i][j])

#f2[p][i][j]表示前p个节点执行i个A任务，j个B任务的最短时间
def DP2():
    for i in range(na+1):
        for j in range(nb+1):
            f2[1][i][j] = f1[1][i][j]
    for a in range(2, p+1):
        for i in range(na+1):
            for j in range(nb+1):
                for k in range(i+1):
                    for l in range(j+1):
                        f2[a][i][j] = min(f2[a][i][j], max(f2[a-1][k][l], f1[a][i-k][j-l]))

DP1()
DP2()
print(f2[p][na][nb])
