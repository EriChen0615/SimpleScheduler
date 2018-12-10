#include "row.h"

Row::Row(int height,int columns,const int *width,const string *x_ticks,const string separator)
{
	this->height = height;
	this->columns = columns;
	this->head_unit = new Info_unit(height,width[0],x_ticks[0]); 
	this->separator = separator;
	this->nextRow = NULL; 
	Info_unit *current_unit = head_unit;
	for(int i=1;i<columns;i++)
	{
		current_unit->SetRightUnit(new Info_unit(height,width[i],x_ticks[i]));
		current_unit = current_unit->GetRightUnit();
	}
}

Row::Row(Info_unit* units,const string sep)
{
	this->head_unit = units;
	this->height = head_unit->GetHeight();
	this->separator = sep;
	this->nextRow = NULL;
}
  
Row::Row(int height,int width, int columns, Info_unit* unit)
{
	this->height = height;
	this->columns = columns;
	this->head_unit = unit;
	this->separator = separator;
	this->nextRow = NULL; 
	Info_unit *current_unit = head_unit;
	string tmp  = "";
	for(int i=1;i<columns;i++)
	{
		current_unit->SetRightUnit(new Info_unit(height,width,tmp));
		current_unit = current_unit->GetRightUnit();
	}
}

Row::~Row(void)
{
	
}  

Info_unit* Row::_GetUnit(int i)
{
	Info_unit* current = head_unit;
	for(int j=0;j<i;j++)
		current = current->GetRightUnit();
	return current;
}

void Row::Show(void)
{
	//units[0].Show();
	head_unit->Show();
	Info_unit* current = head_unit;
	int total_width = 0;
	for(int i=0;i<columns;i++)
	{
		//total_width += units[i].GetWidth();
		total_width+= current->GetWidth();
		current = current->GetRightUnit(); 
	}
	for(int i=0;i<total_width;i++) cout << separator;
	cout << endl;
}

void Row::Insert(int pos,int width,string x_tick)
{
	Info_unit *tmp = new Info_unit(height,width,x_tick);
	if(pos==0)
	{
		tmp->SetRightUnit(head_unit);
		tmp->SetDownUnit(head_unit->GetDownUnit());
		head_unit->SetDownUnit((Info_unit*)NULL);
		head_unit = tmp;
	}
	else
	{
		Info_unit* current = head_unit->GetRightUnit(); 
		Info_unit* before = head_unit;
		for(int i=1;i<pos;i++)
		{
			before = before->GetRightUnit();
			current = current->GetRightUnit();
		}
		before->SetRightUnit(tmp);
		tmp->SetRightUnit(current);
	}
}

void Row::Insert(int pos,Info_unit* unit)
{
	if(pos==0)
	{
		unit->SetRightUnit(head_unit);
		unit->SetDownUnit(head_unit->GetDownUnit());
		head_unit->SetDownUnit((Info_unit*)NULL);
		head_unit = unit;
	}
	else
	{
		Info_unit* current = head_unit->GetRightUnit(); 
		Info_unit* before = head_unit;
		for(int i=1;i<pos;i++)
		{
			before = before->GetRightUnit();
			current = current->GetRightUnit();
		}
		before->SetRightUnit(unit);
		unit->SetRightUnit(current);
	}
 } 
 
void Row::Delete(int pos)
{
	if(pos==0)
	{
		Info_unit *tmp = head_unit->GetRightUnit();
		tmp->SetDownUnit(head_unit->GetDownUnit());
		delete head_unit;
		head_unit = tmp;
	}
	else
	{
		Info_unit* current = head_unit->GetRightUnit(); 
		Info_unit* before = head_unit;
		for(int i=1;i<pos;i++)
		{
			before = before->GetRightUnit();
			current = current->GetRightUnit();
		}
		before->SetRightUnit(current->GetRightUnit());
		delete current;
	}
}

void Row::Replace(int pos,int width,string x_tick)
{
	Info_unit* current = head_unit;
	for(int i=0;i<pos;i++)
	{
		current = current->GetRightUnit();
	}
	current->SetWidth(width);
	current->SetContent(x_tick);
}

void Row::Replace(int pos,Info_unit* unit)
{
	Info_unit* unit_i = _GetUnit(pos);
	unit_i->SetWidth(unit->GetWidth());
	unit_i->SetContent(unit->GetContent());	
}

void Row::Modify(int pos,string x_ticks)
{
	Info_unit* current = head_unit;
	for(int i=0;i<pos;i++)
	{
		current = current->GetRightUnit();
	}
	current->SetContent(x_ticks);
}
void Row::SetNextRow(Row* nextRow)
{
	this->nextRow = nextRow;
}

void Row::SetHeight(int height)
{
	this->height = height;
	Info_unit *current = this->head_unit;
	while(current!=NULL)
	{
		current->SetHeight(height);
		current = current->GetRightUnit();
	}
}
Row* Row::GetNextRow(void)
{
	return this->nextRow;
}
