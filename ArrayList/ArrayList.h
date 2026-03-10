#pragma once
#include<stdio.h>
#include<stdlib.h>

/*顺序表 表头*/
typedef int elem_t;
typedef struct {
	elem_t* data;		//正文数据区指针
	size_t capacity;	//正文数据区最大容量，索引不能取到该值，[0, capacity)
	size_t len;			//尾插下标索引+当前正文数据区元素个数
}ArrayList;

/*顺序表 初始化*/
void initArrayList(ArrayList* table, int num);		//已有表头，初始化正文数据区
void deleteArrayList(ArrayList* table);				//释放正文数据区
ArrayList* creatArrayList(int num);					//初始化表头和正文数据区
void releaseArrayList(ArrayList* table);			//释放表头和正文数据区

/*顺序表 插入*/
void push_backArrayList(ArrayList* table, elem_t value);		//尾插
void insertArrayList(ArrayList* table, size_t pos, elem_t value);	//指定位置插入

/*顺序表 输出*/
void showArrayList(const ArrayList* table);		//输出顺序表元素

/*顺序表 删除*/
void deleteValueArrayList(ArrayList* table, elem_t value);	//删除指定值元素
void deletePosArrayList(ArrayList* table, size_t pos);		//删除指定位置元素

/*顺序表 查找*/ 
size_t findArrayList(ArrayList* table, elem_t value);		//查找指定值元素位置