#include <stdlib.h>
#include <iostream>
using namespace std;


class DynamicArray
{
public:
	int *arr;
	int capacity;
	int space;
	int size;

	DynamicArray(int i)
	{
		int *new_arr = (int*)malloc(sizeof(int)*i);
		arr = new_arr;
		capacity = i;
		space = 0;
		size = sizeof(int);
	}


	int pop()
	{
		int x = -1;
		if(space==0)
		{
			cout<<"Nothing to pop\n";
		}
		else
		{
			x = *(arr + (size*(space--)));
		}
		return(x);
	}


	void shift(int pos)
	{
		for(int i=space-1;i>pos-1;i--)
		{
			*(arr + ((i+1)*size)) = *(arr + (i*size));
		}
	}


	void increase_size()
	{
		capacity *= 2;
		int *new_arr = (int*)malloc(size*capacity);
		for(int i=0;i<space;i++)
		{
			*(new_arr + (i*size)) = *(arr + (i*size));
		}
		free(arr);
		arr = new_arr;
	}


	void push(int x)
	{
		if(space==capacity)
		{
			increase_size();
		}
		*(arr + (space*size)) = x;
		space++;
	}


	void insert(int x, int pos)
	{
		if(space==capacity)
		{
			increase_size();
		}
		shift(pos);
		*(arr + ((pos-1)*size)) = x;
	}


	void remove(int index)
	{
		return;
	}

};


int main(int argc, char const *argv[])
{
	int a[10];
	int b[2][2];
	b[0][2] = [1,2];
	b[1][2] = [3,5];
	int **p = b;
	a[0] = 0;
	a[1] = 1;
	a[2] = 2;
	cout<<a<<endl;
	cout<<sizeof(int)<<endl;
	cout<<*(a+1)<<endl; 

	// DynamicArray a(4);
	// for(int i=0;i<14;i++)
	// {
	// 	a.push(i);
	// 	cout<<a.space<<" - "<<a.capacity<<endl;
	// }
	// a.pop();
	// cout<<endl;
	// for(int i=0;i<14;i++)
	// {
	// 	if(i<a.space)
	// 	{
	// 		cout<<*(a.arr + (i*a.size))<<" - ";
	// 	}
	// 	else
	// 	{
	// 		cout<<"Index out of bound"<<endl;
	// 	}
	// }
	// cout<<endl;

	return 0;
}



	









