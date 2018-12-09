#include"InfoUnit.h"

template<typename T>
InfoUnit<T>::InfoUnit(int r,int c,T *cont,size_t s)
{
	rows = r;
	columns = c;
	rightUnit = NULL;
	downUnit = NULL;
	// dynamically allocate an array of type T
	content = new T[r*c];
	content = cont;
	size = s;
}

////specialization for T = InfoUnit
//template<>
//InfoUnit< InfoUnit<> >::InfoUnit(int r,int c, InfoUnit<> *cont,size_t s)
//{
//	rows = r;
//	columns = c;
//	rightUnit = NULL;
//	downUnit = NULL;
//	// dynamically allocate an array of type T
//	content = new int[r*c];
//	content = cont;
//	size = s;
//	
//	// assign right/down relationship
//	for(int i=0;i<size;i++)
//	{
//		if(i%columns==0)
//		{
//			content[i-columns].downUnit = content[i]; 
//		}
//		else
//		{
//			content[i-1].rightUnit = content[i]; 
//		}
//	}	
//} 

template<typename T>
InfoUnit<T>::InfoUnit()
{
	cout << typeid(content[0]).name() << endl;
}


template<typename T>
InfoUnit<T>::~InfoUnit()
{
	delete[] content;
} 

template<typename T>
void InfoUnit<T>::SetRightUnit(InfoUnit* info)
{
	rightUnit = info;	
}

template<typename T>
void InfoUnit<T>::SetDownUnit(InfoUnit* info)
{
	downUnit = info;	
}

template<typename T>
void InfoUnit<T>::_ShowLine(int r)
{
	for(int i=r*columns;i<size&&i<(r+1)*columns;i++)
	{
		cout << content[i];
	}
}

//specialization for T = InfoUnit
template<>
void InfoUnit< InfoUnit<string> >::_ShowLine(int r)
{
	for(int i=r*columns;i<size&&i<(r+1)*columns;i++)
	{
		//content[i]._ShowLine();
	}	
} 
		
template<typename T>
void InfoUnit<T>::Show(void)
{
	for(int r=0;r<rows;r++)
	{
		_ShowLine(r);
		if(rightUnit!=NULL)	(*rightUnit)._ShowLine(r);
		cout << endl; 
	}
	if(downUnit!=NULL) (*downUnit).Show();
}



template class InfoUnit<int>;
template class InfoUnit<char>;
template class InfoUnit<string>;
template class InfoUnit< InfoUnit<string> >;
