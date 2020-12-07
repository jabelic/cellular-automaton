#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int main (void){
  int a,b,x,t,lval,rval,count;
  int rail,length;
  printf("rail line num=");//2車線限定
  scanf("%d",&rail);
  printf("length(cell num)=");
  scanf("%d",&length);
  printf("count=");
  scanf("%d",&count);

  int p[rail][length+1];//rail=車線数、length=道の長さ。一個架空セル用意
  for(a=0;a<rail;a++){
    for(b=0;b<length+1;b++){
      p[a][b]=0;
    }
  }

  int leftcar;//左車線
  printf("leftcar=");
  scanf("%d",&leftcar);
  if(leftcar>=length){
    printf("over\n");
    exit(1);
  }
  int rightcar;//右車線
  printf("rightcar=");
  scanf("%d",&rightcar);
  if(rightcar>=length){
    printf("over\n");
    exit(1);
  }
  printf("\n");

  while(leftcar>0){
    x=rand()%length;
    if(p[0][x]==0){
      p[0][x]=1;//車格納
      leftcar=leftcar-1;
    }
  }

  while(rightcar>0){
    x=rand()%length;
    if(p[1][x]==0){
      p[1][x]=1;
      rightcar=rightcar-1;
    }
  }

  for(b=length-5;b<length;b++){//前５つをずっと車いる状態にして車線減少
    p[1][b]=2;
  }

  for(a=0;a<rail;a++){
    for(b=0;b<length;b++){
      printf("%d",p[a][b]);
    }
    printf("\n");
  }

  /*p[1][length]=1;
  printf("%d",p[1][length]);*/

  lval=0;
  rval=0;
  t=0;

  //ここまでで車の配置完了
  //ここからは進ませる
  p[a][length]=p[a][0];//架空セルは左端のセルと同じ値

  for(t=0;t<count;t++){
    for(b=length-1;b>=0;b--){//前方のセルから
      for(a=0;a>rail;b++){//2車線ずつ検索
        if(a==0){//左車線
          if(p[0][b]==1 && p[0][b+1]==0){
            if(p[1][b+1]==0){
              if(rval>=lval){//左車線のプレッシャーが右より弱かったらそのまま移動
                p[0][b]=0;
                p[1][b+1]=1;
                rval=lval+1;
              }else{
                p[0][b]=0;
                p[0][b+1]=1;
                lval=0;
              }
            }else{
              p[0][b]=0;
              p[0][b+1]=1;
              lval=0;
            }
          }else if(p[0][b]==1 && p[0][b+1]==1){
            lval=0;
          }else if(p[0][b]==0 && p[0][b+1]==0){
            lval=lval+1;
          }else{
            lval=lval+1;
          }
        }
        //if(p[a][b]==1
        if(a==1){//右車線
          if(p[1][b]==1 && p[1][b+1]==0){
            if(p[0][b+1]==0){
              if(rval>=lval){//左車線のプレッシャーが右より弱かったらそのまま移動
                p[1][b]=0;
                p[1][b+1]=1;
                rval=0;
              }else{
                p[1][b]=0;
                p[0][b+1]=1;
                rval=rval+1;
              }
            }else{
              p[1][b]=0;
              p[1][b+1]=1;
              rval=0;
            }
          }else{
            rval=rval+1;
          }
        }
      }
      p[0][0]=p[0][length];
      p[1][0]=p[1][length];

    }
    for(a=0;a<rail;a++){
      for(b=0;b<length;b++){
        printf("%d",p[a][b]);
      }
      printf("\n");
    }
    printf("----------------------\n");
  }

  return 0;
}