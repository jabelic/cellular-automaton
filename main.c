#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int main(void){
  int i, x, p, t, m;

  int road; // roadはセル数。配列の要素数を変数にするための変数。
  printf("セル数 road=");
  scanf("%d", &road);
  int r1[2][road], tmp[2][road]; // セル数がroad個の配列。

  for (i = 0; i < road; i++){
    r1[0][i] = 0;
    tmp[0][i] = 0;
  }

  int car;
  printf("道にいる車の数 car=");
  scanf("%d", &car);

  if (car >= road){
    printf("車が溢れてます\n");
    exit(1);
  }

  srand((unsigned int)time(NULL)); //実行時間で乱数生成

  while (car > 0){ //セルに車を入れる。
    x = rand() % road;

    if (r1[0][x] == 0){ //そのセルに元々車がいるか判定
      r1[0][x] = 1;
      car = car - 1;
    }
  }

  for (i = 0; i < road; i++){
    printf("%d", r1[0][i]);
  }
  printf(" /t=0");
  printf("\n");

  //ここまでは最初の位置を作った
  //ここから下は従うルールによって変わる

  printf("何回実行する？");
  scanf("%d", &t);

  p = 0;
  while (p < t){

    for (x = 0; x < road; x++){
      if (x < road - 1){
        if (r1[0][x] == 1 && r1[0][x + 1] == 0){
          tmp[0][x] = 0;
          tmp[0][x + 1] = 1;
          if (x < road - 2){  //右に出すぎてオーバーしちゃうから調節
            x = x + 1;
          }
        }
        else{
          tmp[0][x] = r1[0][x];
        }
      }else{
        if (r1[0][road - 1] == 1 && r1[0][0] == 0){ //右端１かつ左端０
          tmp[0][road - 1] = 0;
          tmp[0][0] = 1;
        }
        else if (r1[0][road - 1] == 1 && r1[0][0] == 1){
          tmp[0][x] = 1; // x = road - 1
        }
      }
    }

    for (x = 0; x < road; x++){
      r1[0][x] = tmp[0][x];
    }

    for (x = 0; x < road; x++){
      printf("%d", r1[0][x]);
      tmp[0][x] = 0;
    }

    p++;
    printf(" /t=%d\n", p);
  }

  printf("\n");
  return 0;
}
