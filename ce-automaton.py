# Ver. 4

import random
import copy
import sys
import matplotlib.pyplot as plt
import collections


def rand_ints_nodup(a, b, k):
    ns = []
    while len(ns) < k:
        n = random.randint(a, b)
        if not n in ns:
            ns.append(n)
    return ns

def setcar_list(car, line, lines, cell):
    index = rand_ints_nodup(0, (cell-1)*(line-2), car)
    for i in range(car):
        lines[index[i]%3+1][index[i]//3] = 1
    return lines

def process(line, cell, lines, tmplist):
    forward = 0
    next_forward = 0
    for c in range(cell, -1, -1):
        for l in range(1, line-2+1):
            if lines[l][c] == 1 and c <= cell-1 and (lines[l][c+1] == 0 or lines[l][c+1] == 2):
                forward = 1
                next_forward = 1
                
                # 自分より前にどのくらい空きスペースがあるかどうか
                while(not lines[l][c+forward]):
                    forward += 1
                
                # 隣の車線のスペースを算出
                left_forward = 0
                right_forward = 0
                if l==1:
                    if lines[l+1][c] == 0: #隣のレーンに車が並んでいないか. 並んでいたらぶつかるかもしれない.
                        right_forward = 1
                        while(right_forward <= cell - c and not lines[l+1][c+right_forward]):
                            right_forward += 1
                        next_forward = right_forward
                elif l==2:
                    if lines[l-1][c] == 0:
                        left_forward = 1
                        while(left_forward <= cell - c and not lines[l-1][c+left_forward]):
                            left_forward += 1
                        next_forward = left_forward
                        right_forward = 0
                elif l==3: # lane3は左前が空いていれば強制的にlane2に移動する.
                    left_forward = 1
                    while(left_forward <= cell - c and not lines[l- 1][c+left_forward]):
                        left_forward += 1
                    next_forward = left_forward
                
                # 隣の車線の方が空いているとき
                if next_forward > forward and l==1:
                    tmplist[l+1][c+1] = 1
                    tmplist[l][c] = 0
                elif next_forward > forward and l==2:
                    if left_forward:
                        tmplist[l-1][c+1] = 1
                        tmplist[l][c] = 0
                    else:
                        tmplist[l+1][c+1] = 1
                        tmplist[l][c] = 0
                elif next_forward > forward and l==3:
                    tmplist[l-1][c+1] = 1  # 左前に進む
                    tmplist[l][c] = 0
                # 前方の方が空いているとき.
                elif next_forward <= forward and lines[l][c+1] == 0:
                    if l == 2 and lines[l+1][c] == 1: #lane2で右に車がいれば, 譲る
                        tmplist[l][c] = 1
                    elif l==3 and lines[l-1][c] == 0 and lines[l-1][c+1] == 0: # lane3 は左に行ける余裕があればいく.
                        tmplist[l-1][c+1] = 1
                        tmplist[l][c] = 0
                    else:
                        tmplist[l][c+1] = 1
                        tmplist[l][c] = 0
            elif c == cell-1:
                if lines[l][c] == 1 and lines[l][c+1] == 1:
                    tmplist[l][c] = 0
            else:
                if lines[l][c] == 1:
                    tmplist[l][c] = 1
    return tmplist


def analysis(lines, cell_length):
    jam = 0
    for i in range(1, 4):
        for j in range(cell_length-1):
            if lines[i][j] == 1 and lines[i][j+1] == 1:
                jam += 1
    return jam

def main(version):
    cell = 20
    line = 2+3
    lines = [[0]*cell, [0]*cell, [0]*cell, [0]*cell, [0]*cell]
    lines[0] = [2]*(cell+1)
    lines[1].append(1)
    lines[2].append(1)
    lines[3].append(1)
    lines[4] = [2]*(cell+1)
    car = 30
    lines = setcar_list(car, line, lines, cell)
    redc = 8 # cell num for lane reduction
    for i in range(redc):
        lines[3][-2 - i] = 2
    if version == 1:
        lines[3][-cell+3] = 2
        lines[3][-cell+4] = 2
    tmplist = copy.deepcopy(lines)
    for i in range(line):
        print(lines[i])
    print()
    jamlist = []
    trialnum = 5000
    for _ in range(trialnum):
        tmplist = process(line, cell, lines, tmplist)
        for i in range(1, 4):
            if tmplist[i][0] == 0:
                tmplist[i][0] = random.randint(0,1)
        #for i in range(line):
        #    print(tmplist[i])
        #print()
        jamlist.append(analysis(tmplist, cell))
        lines = copy.deepcopy(tmplist)
    tmpdic = dict(collections.Counter(jamlist))
    print(tmpdic)
    data = sorted(tmpdic.items(), key=lambda x:x[0])
    dataX = [data[i][0] for i in range(len(data))]
    dataY = [data[i][1] for i in range(len(data))]
    plt.plot(dataX,dataY)
    plt.show()
    
if __name__ == "__main__":
    main(0)
    main(1)
