#include <stdio.h>
#include <math.h>
#define N (20)          //行列の最大の大きさ.array size             
#define EPS (1e-18)     //10の-18乗

double A[N+1][N+1], x[N+1], b[N+1];    //A[行][列] 2次元配列
double keep, new/*反復計算後の解*/, dx/*delta x*/, sum/*sum*/, sumt/*sum total*/,ndia/*非対角行列*/;
int i,j,size,count=0,flag=0;

int main(){
    printf("A                                  x    =   b\n"
            "  _                             _  _  _   _    _\n"
            " |A(1,1) A(2,2) A(3,3) ... A(1,n)| |x1|   |b(1)|\n"
            " |A(2,1) A(2,2) A(2,3) ... A(2,n)| |x2| = |b(2)|\n"
            " |A(3,1) A(3,2) A(3,3) ... A(3,n)| |x3|   |b(3)|\n"
            " |...    ...    ...    ... ...   | |..|   |... |\n"
            " |A(n,1) A(n,2) A(n,3) ... A(n,n)| |xn|   |b(n)|\n"
            "  ￣                            ￣  ￣    ￣  ￣ \n");
    printf("正方行列Aの大きさn:");
    scanf("%d",&size);

    for(i=0;i<size;i++){
        x[i] = 0;
        for(j=0;j<size;j++){
            printf("行列Aの(%2d,%2d) :",i+1,j+1);
            scanf("%lf",&keep);
            A[i][j] = keep;
        }
        printf("\nbの(1,%d) :",i+1);
        scanf("%lf",&keep);
        b[i] = keep;
        printf("\n");
    }
    do{
        dx=0.00;
        sumt=0.00;
        for(i=0;i<size;i++){
            sum = 0;
            ndia = 0;
            for(j=0;j<size;j++){
                if(i != j){
                    sum += A[i][j]*x[j]; //対角要素以外の足し合わせ
                    ndia += fabs(A[i][j]);
                }
            }
            //printf("%d,%lf,%lf\n", i, fabs(A[i][i]), ndia);//デバッグ1
            new=(b[i]-sum)/A[i][i];           
            dx += fabs(new-x[i]);               //xの誤差を絶対値で表す。
            sumt += fabs(new);
            x[i]=new;
            //printf("%d,%lf,%lf\n", i, fabs(A[i][i]), ndia);//デバッグ2
            if(fabs(A[i][i]) <=  ndia){         //このifに入ってきた時点で収束しないことが確定するわけではなかった。
                flag = 1;
                //printf("%d,%lf,%lf", i, fabs(A[i][i]), ndia);//デバッグ用
            }
            count += 1;
            if(count == 1000) break;
        }
        if(count == 1000) break;
    }while( (dx/sumt > EPS) || (count == 1000) );

    if(flag == 1){
        printf("対角優位な行列ではないので収束しない可能性があります.\n");
    }
    if(count == 1000){
        printf("1000回では収束しません.\n");    //1000回以上で収束する可能性はある。
        printf("試行回数:%d回\n",count);
    }else{
        printf("試行回数%d回で収束します.\n",count);
    }
    for(i=0;i<size;i++){
        printf("x[%2d]=%25.20f\n",i+1,x[i]);
    }
}
