#include<stdio.h>
#include<string.h>
#include"login.h"
#include"create_data.h"
#include"search_data.h"
#include"tools.h"
#define FILENAME "data.txt"




void add(){
    printf("\n");
    printf("请选择货物的种类:\n1.休闲零食\n2.饮料冲调\n3.鲜甜水果\n4.营养早餐\n5.牛奶面包\n6.速冻食品\n");
    int choice;
    scanf("%d",&choice);

    if (choice < 1 || choice > 6) {
        printf("输入的货物种类不合法。\n");
        return;
    }

    struct shangpin *p = NULL;
    int i = 1;
    while (i < 11 && a[i][choice].sign != 0) {
        i++;
    }

    if (i < 11) {
        p = &a[i][choice];
    } else {
        printf("该种类货物已满，请选择是否添加其它种类。\n");
        printf("按0返回上一届面,按1表示选择其它种类\n");

        int c;
        scanf("%d",&c);
        if(c)
        add();

        control();
    }

    getchar();

    printf("请输入你要添加商品的名称:\n");

    fgets(p->name, sizeof(p->name), stdin);
    p->name[strcspn(p->name, "\n")] = '\0';

    printf("请输入商品的价格和数量:\n");
    scanf("%d",&p->price);
    scanf("%d",&p->number);
    printf("请输入生产日期:\n");
    scanf("%d %d %d",&p->sc.year,&p->sc.month,&p->sc.day);
    printf("请输入过期日期:\n");
    scanf("%d %d %d",&p->jz.year,&p->jz.month,&p->jz.day);

    p->sign=1;

    printf("添加完成，是否要继续添加还是退出？\n");
    printf("1:继续\n0:退出\n");
    int pick;
    scanf("%d",&pick);
    if(pick)
        add();

    control();



}



int main(){
    FILE *file = fopen(FILENAME, "r");
    if (file != NULL) {
        // 逐行读取文件内容并解析到商品数组中
        for (int i = 1; i < 11; i++) {
            for (int j =1 ; j < 7; j++) {
                fscanf(file, "%s %d %d %d %d %d %d %d %d %d",
                       a[i][j].name, &a[i][j].price, &a[i][j].number,
                       &a[i][j].sc.year, &a[i][j].sc.month, &a[i][j].sc.day,
                       &a[i][j].jz.year, &a[i][j].jz.month, &a[i][j].jz.day,
                       &a[i][j].sign);
            }
        }
        fclose(file);
        printf("数据读取成功\n");
        printf("\n");
    } else 
        printf("数据文件不存在，将创建新文件\n");


                    
    if(part1()){
        control();

    }
    

    file = fopen(FILENAME, "w");
    if (file != NULL) {
        for (int i = 1; i < 11 ; i++) {
            for (int j = 1; j < 7; j++) {
                fprintf(file, "%s %d %d %d %d %d %d %d %d %d\n",
                        a[i][j].name, a[i][j].price, a[i][j].number,
                        a[i][j].sc.year, a[i][j].sc.month, a[i][j].sc.day,
                        a[i][j].jz.year, a[i][j].jz.month, a[i][j].jz.day,
                        a[i][j].sign);
            }
        }
        fclose(file);
        printf("数据已保存到文件: %s\n", FILENAME);
    } else {
        printf("无法打开文件进行写入\n");
    }



    return 0;
 }


