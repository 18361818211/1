
#include<stdio.h>
#include<string.h>

int part1(void){
    printf("请输入您的账号和密码：\n");
    char s1[20];
    char s2[20];
    gets(s1);
    gets(s2);

    char zh[20]="aaa123";
    char mm[20]="123456";

    if(!strcmp(s1,zh)){
        if(!strcmp(s2,mm)){
            printf("登陆成功!\n");
            printf("\n");
            return 1;
        }
    
    }

    printf("账号或密码错误请重试！\n");
    printf("\n");
    part1();

    
    
}
