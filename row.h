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
		Info_unit* _GetUnit(int i);
	public:
		Row(int height,int columns,const int *width,const string *x_ticks,const string separator="=");
		Row(Info_unit* units,const string sep="=");
		Row(int height,int width, int columns, Info_unit* unit); // create a row with n columns, where head_unit = unit
		~Row(void);
		void Insert(int pos,int width,string x_tick);
		void Insert(int pos,Info_unit* unit);
		void Delete(int pos);
		void Replace(int pos,int width,string x_tick);
		void Replace(int pos,Info_unit* unit);
		void Modify(int pos,string x_ticks);
		void Show(void);
		void SetNextRow(Row* nextRow);
		void SetHeight(int height);
		Row* GetNextRow(void);
};


#endif
 
