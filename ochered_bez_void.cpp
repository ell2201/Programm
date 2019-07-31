#include <iostream>
using namespace std;
class och
{
	private:
	int *mas,size,maxsize,n,k;
	public:
	och()
	{	maxsize=10;
		mas=new int[maxsize];
		size=0;
		n=0;
		k=0;
	}
	och(int kol)
	{
		maxsize=kol;
		mas=new int[maxsize];
		size=0;
		n=0;
		k=0;
	}
	~och()
	{
		delete mas;
		size=0;
		maxsize=0;
		n=0;
		k=0;
		
	}
	void show()
	{
		int i,j; 
		for(i=0,j=n;i<size;j=(j+1)%maxsize,i++) cout<<mas[j]<<" ";
		cout<<endl;
	}
	int put(int x)
	{
		if(size<maxsize)
		{
			mas[k]=x;
			k=(k+1)%maxsize;
			size++; 
			return 0;
		}
		else
		{
			cout<<"ocered polna"<<endl;
			return -1;
		}
	}
	int pop(int *a)
	{
		if(size>0)
		{
			size--;
			*a=mas[n];
			n=(n+1)%maxsize;
			return 0;
		}
		else
		{
			cout<<"ocered pusta"<<endl;
			return -1;
		}
	}
	och &operator =(const och &b)
	{
		int i;
		maxsize=b.maxsize;
		delete mas;
		mas=new int[maxsize];
		size=b.size;
		n=b.n;
		k=b.k;
		for(i=0;i<maxsize;i++)
		{
			mas[i]=b.mas[i];
		}
		return *this;
	}
	och (const och &b)
	{
		int i;
		maxsize=b.maxsize;
		mas=new int[maxsize];
		size=b.size;
		n=b.n;
		k=b.k;
		for(i=0;i<maxsize;i++)
		{
			mas[i]=b.mas[i];
		}
	}
	
	och operator +(const och &b)
	{
		och c(maxsize+b.maxsize);
		int i,x=n,y=b.n;
		for(i=0;i<maxsize;i++)
		{
			if(i<size)
			{
				c.put(mas[x]);
				x=(x+1)%maxsize;
			}
		if(i<b.size)
			{
				c.put(b.mas[y]);
				y=(y+1)%(b.maxsize);
			}
		}
		return c;
	}
	friend ostream &operator <<(ostream &stream,och &ob);
};
ostream &operator <<(ostream &stream,och &ob)
	{
		int i,j; 
		for(i=0,j=ob.n;i<ob.size;j=(j+1)%(ob.maxsize),i++)
		{
			stream<<ob.mas[j]<<" ";
		}
		stream<<endl;
		return stream;
	}
int main()
{
	
	cout<<endl<<"test na elementi"<<endl;
	och ob4;
	int i,a;
		for(i=0;i<5;i++)
	{
		ob4.put(i);
	}
	for(i=0;i<1000000;i++)
	{
		ob4.put(i);
		ob4.pop(&a);
	}
	ob4.show();
	cout<<endl;
	cout<<endl<<"test na udalenie i sozdanie"<<endl;
	och* test=new och(1000);
	for(i=0;i<1000000;i++)
	{
		delete test;
		test=new och(1000);
			for(int j=1;j<51;j++)
			{
				test->put(i+j);
			}
	}
			test->show();

	cout<<endl<<"test na cout"<<endl;
	cout<<ob4;
	cout<<endl<<"test na +"<<endl;
	och ob1,ob2;
	for(i=0;i<5;i++)ob1.put(i);
	for(i=10;i<17;i++)ob2.put(i);
	ob1.show();
	ob2.show();
	och o7=ob1+ob2;
	o7.show();
	och o(27),o1;
	for(i=0;i<5;i++)
	{
		o.put(i);
	}
	for(;i<25;i++)
	{
		o.put(i);o.pop(&a);
	}
	cout<<endl;
	o.show();
	o1=o;
	cout<<endl<<"test na ="<<endl;
	o1.show();
	och o2=o1;
	cout<<endl<<"test na const copii"<<endl;
	o2.show();
	return 0;
}
