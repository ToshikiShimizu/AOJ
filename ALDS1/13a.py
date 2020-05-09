from itertools import permutations
K = int(input())
N = 8
RC = []
for k in range(K):
    r, c = map(int,input().split())
    RC.append((r,c))

def diag(board):
    for i in range(2*N-1):
        sm = 0
        for j in range(i+1):
            if (i-j>=8 or j>=8):
                continue
            sm += board[i-j][j]
        if sm > 1:
            return False
    return True

def judge(ls):
    board = [[0]*N for _ in range(N)]
    for r in range(N):
        c = ls[r]
        board[r][c] = 1
    for r, c in RC:
        if board[r][c] == 0:
            return False
    
    if not diag(board):
        return False
    
    if not diag(board[::-1]):
        return False
    return True

for ls in permutations(range(N)):
    if judge(ls):
        for c in ls:
            s = ['.'] * N
            s[c] = 'Q'
            print (''.join(s))
        exit()



