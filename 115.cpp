# include<stdio.h>
union student 
{
 int roll;
 float marks;
  };
 int  main()
 {
union student s;
 s.roll = 667;
 printf("\n size of s is %d",sizeof(s));
 printf("\n student roll no : %d",s.roll);
 s.marks = 99;
 printf("\n student marks =%f",s.marks );
 return 0;
}
      
