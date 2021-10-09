#include <iostream>
using namespace std;
const int d=3;
typedef
struct bdnode
{
	int cnt;
	int keys[d-1];
	struct bdnode *ptr[d]={NULL};
}*bdptr;
typedef
struct ofnode
{
	int cnt;
	int keys[d];
	struct bdnode *ptr[d+1]={NULL};
}*ofptr;
bdptr find_node(bdptr T,int n,bdptr &P)
{
	if(T->ptr[0]==NULL)
	{
		return T;
	}
	else
	{
		if(n<T->keys[0])
		{
			P=T;
			find_node(T->ptr[0],n,P);
		}
		else
		{
			int i;
			for(i=1;i<T->cnt;i++)
			{
				if(n>T->keys[i-1]&&n<T->keys[i])
					break;
			}
			P=T;
			find_node(T->ptr[i],n,P);
		}
	}
}
void find_parent(bdptr Q,bdptr T,bdptr &P)
{
    for(int i=0;i<d;i++)
	{
		if(Q->ptr[i]!=NULL)
		{
		    P=Q;
			if(Q->ptr[i]==T)
			{
				break;
			}
			else
			{
				find_parent(Q->ptr[i],T,P);
			}
		}
	}
}
void move(bdptr &T,int n)
{
	for(int j=T->cnt;j>n;j--)
	{
		T->ptr[j+1]=T->ptr[j];
		T->keys[j]=T->keys[j-1];
	}
}
void insert_sort(bdptr &temp,int n,bdptr &O,bdptr &N,bool flag)
{
	int i=temp->cnt;
	if(n<temp->keys[i-1])
	{
		if(n<temp->keys[0])
		{
			move(temp,0);
			i=0;
		}
		else
		{
			for(i=1;i<temp->cnt;i++)
			{
				if(n>temp->keys[i-1] && n<temp->keys[i])
					break;
			}
			move(temp,i);
		}
	}
	temp->keys[i]=n;
	temp->ptr[i+1]=NULL;
	temp->cnt++;
	if(flag==false)
	{
		temp->ptr[i]=O;
		temp->ptr[i+1]=N;
	}
}
void move2(ofptr &OF,int n)
{
	for(int j=OF->cnt;j>n;j--)
	{
		OF->ptr[j+1]=OF->ptr[j];
		OF->keys[j]=OF->keys[j-1];
	}
}
void create_ofnode(ofptr &OF,bdptr temp,int n,bdptr &O,bdptr &N,bool flag)
{
	OF=new(ofnode);
	int i;
	for(i=0;i<temp->cnt;i++)
	{
		OF->ptr[i]=temp->ptr[i];
		OF->keys[i]=temp->keys[i];
	}
	OF->cnt=temp->cnt;
	OF->ptr[i]=temp->ptr[i];
	i=OF->cnt;
	if(n<OF->keys[i-1])
	{
		if(n<OF->keys[0])
		{
			move2(OF,0);
			i=0;
		}
		else
		{
			for(i=1;i<OF->cnt;i++)
			{
				if(n>OF->keys[i-1] && n<OF->keys[i])
					break;
			}
			move2(OF,i);
		}
	}
	OF->keys[i]=n;
	OF->ptr[i+1]=NULL;
	OF->cnt++;
	if(flag==false)
	{
		OF->ptr[i]=O;
		OF->ptr[i+1]=N;
	}
}
bool check_overflow(bdptr t)
{
	if(t->cnt==d-1)
		return true;
	else
		return false;
}
void print(bdptr T)
{
    for(int i=0;i<T->cnt;i++)
    {
        if(T->ptr[i]!=NULL)
        {
            print(T->ptr[i]);
        }
        cout<<T->keys[i]<<" ";
    }
    if(T->ptr[T->cnt]!=NULL)
        print(T->ptr[T->cnt]);
}
void add(bdptr &T,bdptr &N,bdptr &O,bdptr &Q,int n,bool flag)
{
	if(T==NULL)
	{
		T=new(bdnode);
		T->keys[0]=n;
		T->cnt=1;
		if(flag==false)
		{
			T->ptr[0]=O;
			T->ptr[1]=N;
		}
		Q=T;
	}
	else
	{
		bdptr P=new(bdnode);
		P=NULL;
		bdptr temp=new(bdnode);
		temp=NULL;
		if(flag==true)
		{
			temp=find_node(T,n,P);
		}
		else
		{
			temp=T;
			if(T==Q)
				P=NULL;
			else
				find_parent(Q,T,P);
		}
		bool a=check_overflow(temp);
		if(a==false)
		{
			insert_sort(temp,n,O,N,flag);
		}
		else
		{
			ofptr OF=new(ofnode);
			create_ofnode(OF,temp,n,O,N,flag);
			for(int i=0;i<d;i++)
				temp->ptr[i]=NULL;
			temp->cnt=0;
			int ind=(d+1)/2-1;
			for(int i=0;i<ind;i++)
			{
				temp->keys[i]=OF->keys[i];
				temp->ptr[i]=OF->ptr[i];
				temp->cnt++;
			}
			temp->ptr[ind]=OF->ptr[ind];
			N=new(bdnode);
			N->cnt=0;
			int j=0;
			for(int i=ind+1;i<d;i++,j++)
			{
				N->keys[j]=OF->keys[i];
				N->ptr[j]=OF->ptr[i];
				N->cnt++;
			}
			N->ptr[j]=OF->ptr[d];
			flag=false;
			add(P,N,temp,Q,OF->keys[ind],flag);
		}
	}
}
void levelorder(int &i,int &n,bdptr a[])
{
    if(i!=n && a[i]!=NULL)
    {
        int k;
        for(k=0;k<=a[i]->cnt;k++)
        {
            if(k<a[i]->cnt)
            cout<<a[i]->keys[k]<<" ";
            if(a[i]->ptr[k]!=NULL)
            {
                n++;
                a[n]=a[i]->ptr[k];
            }
        }
        i++;
		levelorder(i,n,a);
    }
    else if(a[i]==NULL && i!=n)
    {
        cout<<endl;
        n++;
        a[n]=NULL;
        i++;
		levelorder(i,n,a);
    }
}
int main()
{
	bdptr T=NULL;
	bdptr Q=T;
	bdptr N=NULL;
	bdptr O=NULL;
	int n;
	cin>>n;
	bool flag=true;
	while(n>0)
	{
		add(T,N,O,Q,n,flag);
		T=Q;
		flag=true;
		cin>>n;
	}
	cout<<"sorted order"<<endl;
	print(T);
	cout<<endl<<"levelorder"<<endl;
	bdptr a[50];
  	a[0]=T;
    a[1]=NULL;
    int i=0;
    n=1;
    levelorder(i,n,a);
}
// 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 16 17 18 0
