#include <stdio.h>
float add(float a,float b){return a+b;}
float subtract(float a,float b){return a-b;}
float multiply(float a,float b){return a*b;}
float divide(float a,float b){return b!=0? a/b:0;}
int main(){
  float num1,num2;
  char op;
  float(*operation)(float,float);
  printf("Enter first number:");
  scanf("%f",&num1);
  printf("Enter operator(+,-,*,/):");
  scanf(" %c",&op);
  printf("Enter second number:");
  scanf("%f",&num2);
  switch(op){
    case '+':operation=add;break;
    case '-':operation=subtract;break;
    case '*':operation=multiply;break;
    case '/':operation=divide;break;
    default:printf("Invalid operator!\n");return 1;
  }
  printf("Result:%.2f\n",operation(num1,num2));
  return 0;
}
