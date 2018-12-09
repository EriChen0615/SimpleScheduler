#include "table.h"

Table::Table(int rows,int columns,string *x_ticks,string *y_ticks)
{
	this->rows = rows;
	this->columns = columns;
	int *width = new int[columns];
	for(int i=0;i<columns;i++)
	{
		width[i] = 10;
	}
	this->head_row = new Row(5,columns,width,x_ticks);
 	Row* current_row = head_row;
	 for(int i=0;i<rows;i++)
 	{
 		current_row->SetNextRow(new Row(5,10,columns,new Info_unit(5,10,y_ticks[i])));
 		current_row = current_row->GetNextRow();
	}
}

Table::~Table()
{
	Row* before = head_row;
	Row* current = head_row->GetNextRow();
	while(current!=NULL)
	{
		delete before;
		before = current;
		current = current->GetNextRow();
	}
	delete before;
}

void Table::Show()
{
	Row* current_row = head_row;
	while(current_row!=NULL)
	{
		current_row->Show(); 
		current_row = current_row->GetNextRow();
	} 
}


