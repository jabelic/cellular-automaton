

# cellular automaton simulation 

ce-automaton.py

シミュレーション例. 2は車線減少部分及び中央分離帯, 路側帯を意味する.


2行目からlane1, 2, 3として, 実際に車が走行するcellはlane1,2,3の0番目から9番目までで, 最後の1は便宜上置いている.

lane1で, 隣に車がいない場合で前方よりも隣のレーンの方が空いていた場合, そちらに動く. そうでなければ直進する.
lane2で, 左隣に車がいない場合で前方よりも左のレーンの方が空いていた場合, そちらに動く, そうでなければ直進する.
lane3で, 隣に車がいない場合で前方よりも隣のレーンの方が空いていた場合, そちらに動く. そうでなければ直進する.



```
[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]
[1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1]
[0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1]
[1, 0, 0, 0, 0, 0, 1, 2, 2, 2, 1]
[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]

[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]
[1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1]
[0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1]
[0, 1, 0, 0, 0, 0, 0, 2, 2, 2, 1]
[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]

[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]
[0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1]
[1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1]
[1, 0, 1, 0, 0, 0, 0, 2, 2, 2, 1]
[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]

[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]
[1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1]
[0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1]
[0, 1, 0, 1, 0, 0, 0, 2, 2, 2, 1]
[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]

[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]
[0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1]
[1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1]
[1, 0, 1, 0, 1, 0, 0, 2, 2, 2, 1]
[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]

[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]
[1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1]
[1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1]
[0, 1, 0, 1, 0, 1, 0, 2, 2, 2, 1]
[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]

[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]
[0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1]
[1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1]
[0, 0, 1, 0, 1, 0, 1, 2, 2, 2, 1]
[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]

[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]
[1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1]
[0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1]
[1, 0, 0, 1, 0, 1, 1, 2, 2, 2, 1]
[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]

[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]
[1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1]
[0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1]
[0, 1, 0, 0, 1, 1, 1, 2, 2, 2, 1]
[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]

[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]
[1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1]
[1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1]
[0, 0, 1, 0, 1, 1, 1, 2, 2, 2, 1]
[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]

[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]
[0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1]
[0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1]
[0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 1]
[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]

```



### ver. 2

lane3の車は左前にスペースがあれば割り込む.

ex

```

[0,0,1,0,1]   ->   [0,1,1,1,1]
[1,0,1,0,0]   ->   [0,0,0,0,0]

```



```

[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]
[0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1]
[1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1]
[0, 1, 0, 1, 1, 0, 1, 2, 2, 2, 1]
[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]

[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]
[1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1]
[0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1]
[1, 0, 0, 1, 0, 1, 0, 2, 2, 2, 1]
[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]

[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]
[1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1]
[0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1]
[1, 1, 0, 0, 1, 0, 1, 2, 2, 2, 1]
[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]

[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]
[0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1]
[1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1]
[1, 0, 1, 0, 0, 1, 0, 2, 2, 2, 1]
[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]

[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]
[1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1]
[1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1]
[1, 1, 0, 1, 0, 0, 1, 2, 2, 2, 1]
[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]

[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]
[0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1]
[1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1]
[1, 0, 1, 0, 1, 0, 0, 2, 2, 2, 1]
[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]

[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]
[0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1]
[1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1]
[1, 1, 0, 1, 0, 1, 0, 2, 2, 2, 1]
[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]

[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]
[0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1]
[1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1]
[1, 0, 1, 0, 1, 0, 1, 2, 2, 2, 1]
[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]

[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]
[0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1]
[1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1]
[1, 1, 0, 1, 0, 1, 1, 2, 2, 2, 1]
[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]

[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]
[0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1]
[1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1]
[1, 0, 1, 0, 1, 1, 0, 2, 2, 2, 1]
[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]

[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]
[0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1]
[1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1]
[0, 1, 0, 1, 1, 0, 1, 2, 2, 2, 1]
[2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]

```