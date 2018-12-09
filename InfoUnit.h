#ifndef INFOUNIT_H
#define INFOUNIT_H 

#include <iostream>
#include <typeinfo>
#include <string.h>

using std::cout;
using std::endl;
using std::string;

template <typename T>
class InfoUnit
{
	private:
		int rows;
		int columns;
		size_t size;
		T *content;
		bool visible;
		InfoUnit *rightUnit;
		InfoUnit *downUnit;
		void _ShowLine(int r);
	public:
		InfoUnit(int rows,int columns,T *content,size_t s);
		InfoUnit();
		~InfoUnit(void);
		void SetRightUnit(InfoUnit* info);
		void SetDownUnit(InfoUnit* info);
//		void SetVisibility(bool v);
//		void SetContent(T& content);
//		T* GetContent(int i,int j);
//		T* GetContent(void);
		void Show(void);
};

#endif

