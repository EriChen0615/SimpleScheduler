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
	public:
		Row(int height,int columns,const int *width,const string *x_ticks,const string separator="=");
		~Row(void);
		void Insert(int pos,int width,string x_tick);
		void Delete(int pos);
		void Show(void);
};


#endif
 
