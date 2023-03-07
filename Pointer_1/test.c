#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


int str_len(char* str) 
{
	char* start = str;
	char* end = str;
	
	while (*end != '\0') 
	{
		end++;
	}
	

	return end - start;
}

int main() {

	//指针是一个变量，而指针里面存的是地址，所以说是指针也叫地址

	//内存被划分一个个小的单元的格子， 而一个单元格占用一个字节    
	// 32位内，是有32个0/1组成的二进制序列，所以一个指针是四个字节大小
	//64同等

	//printf("%d\n", sizeof(char*));  //8
	//printf("%d\n", sizeof(int*));
	//printf("%d\n", sizeof(double*));
	//printf("%d\n",sizeof(short*));


	////指针类型的区别 int* char*等
	//int a = 0x11223344;
	//int* sp = &a; 
	//*sp = 0;  //因为sp是int类型的，所以修改的权限是四个字节，最后修改的地址是 00 00 00 00

	////char* cp = &a;
	////*cp = 0;   //因为cp是char类型的，所以修改的权限是一个字节，最后修改的地址是 00 33 22 11
	//printf("%p\n",sp);


	//指针类型决定了指针类型解引用操作的时候能够访问操作空间的大小
	//意义；在给指针赋值的时候，要给指针赋一个合理的值 
	//如果我只想往后一个字节，就需要返回一个char类型的指针

	/*int a = 0x11223344;
	int* pa = &a;
	char* pc = &a;
	printf("%p\n", pa);
	printf("%p\n", pa+1);
	printf("%p\n", pc);
	printf("%p\n", pc+1);*/
	//指针类型决定了走多远，也就是步长；
	//指针类型只考虑空间大小
	//int arr[10] = {0};
	//int* pa = arr;
	///*char* pc =arr ;*/
	//int i = 0;
	//for (i = 0; i < 10;i++) {
	//	*(pa+i) = 1;
	//}

	//printf("%p\n",pa);

	//该程序，int类型的改了40个字节，而char类型的只改了10个字节
	// 1如果指针不初始化，他指向的是随机值，就成了野指针，找不到他在哪。
	// 2数组越界，内存越界，指针越界，指针也会成为野指针，列：当p指向的地方超过arr的范围就会越界，成为野指针
	// 3 指针指向的空间释放了，如局部变量进入会被创建，出局部就会消失，
	//  所以如果指针指向的是局部变量的话，变量出局部范围时就被销毁，指针就会变成野指针
	//野指针就是指向的空间是未知的，未定义的，没初始化的。


	/*char a[] = "abc";
	char b[] = { 'a','b','c' };
	printf("%d\n",sizeof(a)); 
	printf("%d\n", sizeof(b));*/

	//指针类型的解引用    什么类型就有多大的权限，比如int类型有四个字节，而char类型只有一个字节


	//当指针真的不知道指向谁的时候，就指向NULL（本质就是0）
	//指针释放：即把指针指向空
	//指针使用之前检查有效性


	/*int a = 10;
	int* pa = &a;
	pa = NULL;
	if (pa != NULL) {

	}*/


	/*char arr[] = "bit";
	int len = str_len(arr);
	printf("%d\n", len);*/



	//允许指向数组元素的指针与指向数组最后一个元素后面的那个内存位置的指针进行比较，
	//但是不允许与指向第一个元素之前的那个内存位置的指针进行比较


	//int a = 10;
	//int* pa = &a;
	//int** ppa = &pa;
	//int*** pppa = &ppa;
	////int* pa说明pa指向的对象是int类型的
	////int** ppa 第二个*说明该类型是指针，int*说明，ppa指向的类型是一个指针
	//**ppa = 20;
	//printf("%d\n", **ppa);
	//printf("%d\n", a);


	//指针数组------存放指针的数组
	//数组指针
	int a = 10;
	int b = 20;
	int c = 30;
	int i = 0;
	char* arr[3] = { &a,&b,&c }; //指针数组
	for (i = 0; i < 3; i++) 
	{
		//arr[i]此时取得的是a  b  c的地址，需要解引用来获取a  b  c的值
		printf("%d  ", *(arr[i]));
	}


	return 0;
}