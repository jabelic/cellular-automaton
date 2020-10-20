#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int main (void){
  int i,x,p,t,m;

  int road;//roadは要素数。配列の要素数を変数にするための変数。
  printf("道の数 road=");
  scanf("%d",&road);
  int r[road],a[road];//要素数がroad個の配列。
  //a[m]は一旦記録しておくための配列

  for(i=0;i<road;i++){//初期値入力
    r[i]=0;
    a[i]=0;
  }

  int car;//numは車の数
  printf("道にいる車の数 car=");
  scanf("%d",&car);

  if(car>=road){
    printf("車が溢れてます\n");
    exit(1);
  }

  srand((unsigned int)time(NULL));//実行時間で乱数生成

  while(car>0){//セルに車を入れる。
    x = rand()%road;

    if(r[x]==0){//そのセルに元々車がいるか判定
      r[x]=1;
      car=car-1;
    }
  }

  for(i=0;i<road;i++){
    printf("%d",r[i]);
  }//現在の車の位置を表示

  printf(" /t=0");
  printf("\n");

  //ここまでは最初の位置を作った
  //ここから下は従うルールによって変わる

  printf("何回実行する？");
  scanf("%d",&t);

  p=0;

  while(p<t){//何回試行するか

    for(x=0;x<road;x++){
      if(x<road-1){//右端だけ除外
        if(r[x]==1 && r[x+1]==0){
          a[x]=0;//一旦記録
          a[x+1]=1;
          if(x<road-2){//右に出すぎてオーバーしちゃうから調節
            x=x+1;//わかるように書く
          }
        }else{
          a[x]=r[x];
        }
      }else{//右端の話
        if(r[road-1]==1 && r[0]==0){//右端１かつ左端０
          a[road-1]=0;
          a[0]=1;
        }else if(r[road-1]==1 && r[0]==1){
          a[x]=1;
        }
      }

    }//ここで横１周

    for(x=0;x<road;x++){//本番用に記録用をコピー
      r[x]=a[x];
    }
    for(x=0;x<road;x++){
      printf("%d",r[x]);
      a[x]=0;//a初期化
    }
    //r[road]=0;
    printf(" /t=%d",p+1);
    printf("\n");

    p=p+1;

  }//p

  printf("\n");
  //delete[] r;
  return 0;
}
