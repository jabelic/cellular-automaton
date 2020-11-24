#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define LINE 3

int main(void){
  int i, x, p, t, m;

  int road; // roadはセル数。配列の要素数を変数にするための変数。
  printf("セル数 road=");
  scanf("%d", &road);
  int r1[LINE][road], tmp[LINE][road]; // セル数がroad個の配列。


  // initialization
  for (int i = 0; i < LINE; i++){
    for (int j = 0; j < road; j++){
      r1[i][j] = 0;
      tmp[i][j] = 0;
    }
  }

  int car, car_num;
  printf("道にいる車の数 car=");
  scanf("%d", &car);

  if (car >= road){
    printf("車が溢れてます\n");
    exit(1);
  }

  srand((unsigned int)time(NULL)); //実行時間で乱数生成

  for(int t = 0; t < LINE; t++){
    car_num = car;
    while (car_num > 0){ //セルに車を入れる。
      x = rand() % road;

      if (r1[t][x] == 0){ //そのセルに元々車がいるか判定
        r1[t][x] = 1;
        car_num -= 1;
      }
    }
  }

  for (int tmp = 0; tmp < LINE; tmp++){
    for (i = 0; i < road; i++){
      printf("%d", r1[0][i]);
    }
    if (tmp != LINE-1){
      printf("\n");
    }
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

    for (int t = 0; t < LINE; t++){
      for (x = 0; x < road; x++){
        printf("%d", r1[t][x]);
        tmp[t][x] = 0;
      }
      if (t!=LINE-1){
        printf("\n");
      }
    }
    p++;
    printf(" /t=%d\n\n", p);
  }

  printf("\n");
  return 0;
}
