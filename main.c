#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define LINE 2

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
  int t1, t2;
  /*
  for (int c = road-1; c >= 0; c--){
    for (int l = 0; l < 2; l++){
      if (r1[l][c]){ // 車がこのセルにあるとき
        for (int t1 = 0; !r1[l+t1][c] ; t1++); // 自分の前の空いているスペース
        if (c == 0){
          for (int t2 = 0; !r1[l+t2][c+1] ; t2++); // となり車線
        }else if(c == 1){
          for (int t2 = 0; !r1[l+t2][c-1] ; t2++); // となり車線
        }
        if (t1 > t2){
          tmp[l+t1-1][c] = 1;
          tmp[l][c] = 0;
        }else{
          if(c==0){
            tmp[l+t2-1][c+1] = 1;
            tmp[l][c] = 0;
          }else if(c==1){
            tmp[l+t2-1][c-1] = 1;
            tmp[l][c] = 0;
          }
        }
      }
    }
  }*/
  for (int c = road-1; c >= 0; c--){
    for (int l = 0; l < 2; l++){
      if (r1[l][c]){
        // for (int t1 = 0; !r1[l+t1][c] ; t1++);
        t1 = 0;
        while(!r1[l+t1][c]){
          t1++;
        }
      }
      // printf("%d", r1[l][c]);
      printf("%d\n", t1);
    }
  }printf("\n");

  for (int t = 0; t < LINE; t++){
      for (x = 0; x < road; x++){
        printf("%d", tmp[t][x]);
        // tmp[t][x] = 0;
      }
      if (t!=LINE-1){
        printf("\n");
      }
  }
/*
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
  }*/

  printf("\n");
  return 0;
}
