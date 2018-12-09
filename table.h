#ifndef TABLE_H_
#define TABLE_H_

#include<iostream>
#include<string>
#include "row.h"
using std::cout;
using std::endl;
using std::string;

class Table
{
	private:
		Row *head_row;
		Row *tail_row;
		int rows;
		int columns;
		string *x_ticks;
		string *y_ticks;
	public:
		Table(int rows,int columns,string* x_ticks,string* y_ticks);
		~Table(void);
		void Show(void);
//		void Insert(int i,int j,Info_unit* unit);
//		void Delete(int i,int j);
//		void Replace(int i,int j,Info_unit* unit);
//		void InsertRow(int i,Row* row);
//		void DeleteRow(int i);
//		void ReplaceRow(int i,Row* row); 
};

#endif

