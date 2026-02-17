# include<stdio.h>
struct demo
     {
     unsigned int a:2;
     unsigned int b:3;
    };
    int main()
   {
    struct demo v;
   v.a =3;
   v.b =7;
  printf("\n%d %d",v.a,v.b);
return 0;
}

