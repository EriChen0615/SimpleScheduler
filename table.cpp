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
 		current_row->SetNextRow(new Row(DEFAULT_WIDTH,DEFAULT_HEIGHT,columns,new Info_unit(5,10,y_ticks[i])));
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

Row* Table::_GetRow(int i)
{
	Row* current = head_row;
	for(int j=0;j<i;j++)
		current = current->GetNextRow();
	return current; 
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

void Table::SetRowHeight(int i,int height)
{
	Row *current = head_row;
	for(int j=0;j<i;j++)
	{
		current = current->GetNextRow();
	 } 
	current->SetHeight(height);
}

void Table::Insert(int i,int j, Info_unit* unit)
{
	Row* row_i = _GetRow(i);
	row_i->Insert(j,unit); 
} 
 
void Table::Delete(int i,int j)
{
	Row* row_i = _GetRow(i);
	row_i->Delete(j);
 } 
 
void Table::Replace(int i,int j,Info_unit* unit)
{
	Row* row_i = _GetRow(i);
	row_i->Replace(j,unit);
}
 
void Table::InsertRow(int i,Row* row_i)
{
	if(i==0)
	{
		row_i->SetNextRow(head_row);
		head_row = row_i; 
	}
	else
	{
		Row* before = _GetRow(i-1);
		Row* current = _GetRow(i);
		before->SetNextRow(row_i);
		row_i->SetNextRow(current); 
	}
}

void Table::DeleteRow(int i)
{
	if(i==0)
	{
		Row* tmp = _GetRow(1);
		delete head_row;
		head_row = tmp;
	}
	else
	{
		Row *before = _GetRow(i-1);
		Row *current = before->GetNextRow();
		Row *after = current->GetNextRow();
		before->SetNextRow(after);
		delete current;
	}
}

void Table::ReplaceRow(int i,Row* row)
{
	if(i==0)
	{
		row->SetNextRow(head_row->GetNextRow());
		delete head_row;
		head_row = row;
	}
	else
	{
		Row *before = _GetRow(i-1);
		Row *current = before->GetNextRow();
		Row *after = current->GetNextRow();
		before->SetNextRow(row);
		row->SetNextRow(after); 
		delete current;
	}
}
