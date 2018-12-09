#ifndef ROW_H
#define ROW_H

#include <iostream>
#include "info_unit.h"

class Row
{
	private:
		Info_unit *head_unit;
		int height;
		int columns;
		string separator;
		Row *nextRow;
	public:
		Row(int height,int columns,const int *width,const string *x_ticks,const string separator="=");
		Row(Info_unit* units,const string sep="=");
		Row(int height,int width, int columns, Info_unit* unit); // create a row with n columns, where head_unit = unit
		~Row(void);
		void Insert(int pos,int width,string x_tick);
		void Delete(int pos);
		void Show(void);
		void SetNextRow(Row* nextRow);
		Row* GetNextRow(void);
};


#endif
 
