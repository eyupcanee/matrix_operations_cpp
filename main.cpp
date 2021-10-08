#include <iostream>
#include <math.h>
using namespace std;

int ** matrix(int satir,int sutun)
{
	int **arr = new int*[satir];
	for(int i = 0; i < satir; i++)
	{
		arr[i] = new int[sutun];
	}
	return arr;
}
void fill_matrix(int **m,int satir,int sutun)
{
	for(int i = 0; i < satir; i++)
	{
		for(int j = 0; j < sutun; j++)
		{
			cout<<i+1<<". Row "<<j+1<<". Column : ";
			cin>>m[i][j];
		}
	}
}
void fill_null_matrix(int **m,int satir,int sutun)
{
	for(int i = 0; i < satir; i++)
	{
		for(int j = 0; j < sutun; j++)
		{		
			m[i][j] = 0;
		}
	}
}
void sum_matrix(int **a,int **b,int **t,int satir,int sutun)
{
	for(int i = 0; i< satir; i++)
	{
		for(int j = 0; j < sutun; j++)
		{
			t[i][j] = a[i][j] + b[i][j];
		}
	}
}
void ext_matrix(int **a,int **b,int **e,int satir,int sutun)
{
	for(int i = 0; i < satir; i++)
	{
		for(int j = 0; j < sutun; j++)
		{
			e[i][j] = a[i][j] - b[i][j];
		}
	}
}
void multiple_matrix_w_matrix(int **a,int **b,int **c,int satir,int sutun,int esdgr)
{
	for(int i = 0; i < satir; i++)
	{
		for(int j = 0; j < sutun; j++)
		{
			for(int k = 0; k < esdgr; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}
void multiple_matrix_w_scalar(int **a,int satir,int sutun,int value)
{
	for(int i = 0; i < satir; i++ )
	{
		for(int j = 0; j < sutun; j++)
		{
			a[i][j] = a[i][j] * value;
		}
	}
}
void transposition_matrix(int **a,int **tr,int satir,int sutun)
{
	for(int i = 0; i < satir; i++)
	{
		for(int j = 0; j < sutun; j++)
		{
			tr[i][j] = a[j][i];
		}
	}
}
int determinant_matrix(int **a,int satir,int sutun,int order)
{
	int det = 0;
	int subi,subj;
	int **temp = matrix(satir,sutun);
	fill_null_matrix(temp,satir,sutun);
	if(order == 2)
	{
		return ((a[0][0] * a[1][1]) - (a[1][0] * a[0][1]));
	}
	else
	{
		for(int k = 0; k < order; k++)
		{
			subi = 0;
			for(int i = 1; i < order; i++)
			{
				subj = 0;
				for(int j = 0; j < order; j++)
				{
					if(j == k)
					{
						continue;
					}
					temp[subi][subj] = a[i][j];
					subj++;
				}
				subi++;
			}
		det = det +(pow(-1 ,k) * a[0][k] * determinant_matrix(temp,satir,sutun,order-1));
		}
	}
	return det;
}
void cofactor_matrix(int **a,int **temp,int satir,int sutun,int order)
{
	int i = 0;
	int j = 0;
	for(int row = 0; row < order; row++)
	{
		for(int col = 0; col < order; col++)
		{
			if(row != satir && col != sutun)
			{
				temp[i][j++] = a[row][col];
				
				if(j == order - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}
}
void adjoint_matrix(int **a,int **adj,int satir,int sutun)
{
	if (satir == 1)
	{
		adj[0][0] = 1;
		return;
	}
	int sign = 1;
	int **temp = matrix(satir,sutun);
	for(int i = 0; i < satir; i++)
	{
		for(int j = 0; j < satir; j++)
		{
			cofactor_matrix(a,temp,i,j,satir);
			sign = ((i+j)%2 == 0)? 1: -1;
			adj[j][i] = (sign)*(determinant_matrix(temp,satir,sutun,(satir-1)));
		}
	}
}
void inverse_matrix(int **a,int **adj,int satir,int sutun)
{
	int det = 0;
	det = determinant_matrix(a,satir,sutun,satir);
	float inv[satir][sutun];
	if(det != 0)
	{
		adjoint_matrix(a,adj,satir,sutun);
		for(int i = 0; i < satir; i++)
		{
			for(int j = 0; j < sutun; j++)
			{
				inv[i][j] = adj[i][j] / float(det);
			}
		}
		cout<<"Inverse Matrix :"<<endl;
		for(int i = 0; i < satir; i++)
		{
			for(int j = 0; j < sutun; j++)
			{
				cout<<inv[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	else
	{
		cout<<"This Matrix Cannot Be Inverted. Determinant Equal to 0"<<endl;
	}
	
}
void print_matrix(int **m,int satir,int sutun)
{
	for(int i = 0; i < satir; i++)
	{
		for(int j = 0; j < sutun; j++)
		{
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(int argc, char** argv) {
	cout<<"Welcome To Matrix Program v0.1"<<endl;
	int a = 1;
	int hak = 3;
	while(a)
	{
		cout<<"Select Process"<<endl;
		cout<<"Addition(+),Subtraction(-),Multiplication(*),Scalar Multiplication(s) \nTransposition(t),Determinant(d),Adjoint Matrix(a).Inverse(i)\nOutput(e)"<<endl;
		char islem;
		cin>>islem;
		switch(islem)
		{
			case '+':
				{	
					int satir = 0;
					int sutun = 0;
					cout<<"Enter Number Of Row :";
					cin>>satir;
					cout<<"Enter Number Of Column :";
					cin>>sutun;
					int **a = matrix(satir,sutun);
					int **b = matrix(satir,sutun);
					int **t = matrix(satir,sutun);
					cout<<"For 1.Matrix :"<<endl;
					fill_matrix(a,satir,sutun);
					cout<<"1. Matrix : "<<endl;
					print_matrix(a,satir,sutun);
					cout<<"For 2. Matrix :"<<endl;
					fill_matrix(b,satir,sutun);
					cout<<"2. Matrix : "<<endl;
					print_matrix(b,satir,sutun);
					cout<<endl;
					sum_matrix(a,b,t,satir,sutun);
					cout<<"Total Matrix : "<<endl;
					print_matrix(t,satir,sutun);
					break;
				}
				case '-':
					{
					int satir = 0;
					int sutun = 0;
					cout<<"Enter Number Of Row :";
					cin>>satir;
					cout<<"Enter Number Of Column :";
					cin>>sutun;
					int **a = matrix(satir,sutun);
					int **b = matrix(satir,sutun);
					int **e = matrix(satir,sutun);
					cout<<"For 1.Matrix :"<<endl;
					fill_matrix(a,satir,sutun);
					cout<<"1. Matrix : "<<endl;
					print_matrix(a,satir,sutun);
					cout<<"For 2. Matrix :"<<endl;
					fill_matrix(b,satir,sutun);
					cout<<"2. Matrix : "<<endl;
					print_matrix(b,satir,sutun);
					cout<<endl;
					ext_matrix(a,b,e,satir,sutun);
					cout<<"Fark Matrisi :"<<endl;
					print_matrix(e,satir,sutun);
					break;
					}
			case '*':
				{
					cout<<"Attention!!! In order to perform multiplication in matrices, the number of columns of the 1st matrix must be equal to the number of rows of the 2nd matrix."<<endl;
					int stA = 0;
					int suA = 0;
					int stB = 0;
					int suB = 0;
					cout<<"1. Number of Rows of the Matrix :";
					cin>>stA;
					cout<<"1. Number of Columns of the Matrix :";
					cin>>suA;
					cout<<"2. Number of Rows of the Matrix :";
					cin>>stB;
					cout<<"2. Number of Columns of the Matrix:";
					cin>>suB;
					if(suA == stB)
					{
						int **a = matrix(stA,suA);
						int **b = matrix(stB,suB);
						int **c = matrix(stA,suB);
						fill_null_matrix(c,stA,suB);
						cout<<"For 1. Matrix :"<<endl;
						fill_matrix(a,stA,suA);
						cout<<"1. Matrix :"<<endl;
						print_matrix(a,stA,suA);
						cout<<"For 2. Matrix :"<<endl;
						fill_matrix(b,stB,suB);
						cout<<"2. Matrix :"<<endl;
						print_matrix(b,stB,suB);
						multiple_matrix_w_matrix(a,b,c,stA,suB,suA);
						cout<<"Product Matrix :"<<endl;
						print_matrix(c,stA,suB);
					}
					else
					{
						cout<<"The Number of Columns of the 1st Matrix and the Number of Rows of the 2nd Matrix Do Not Match! These Matrices Cannot Be Multiplied!!!"<<endl;
					}
					break;
				}
			case 's':
				{
					cout<<"Enter the Number of Rows and Columns of the Matrix You Want to Multiply By Scalar"<<endl;
					int satir = 0;
					int sutun = 0;
					int skaler = 0;
					cout<<"Rows :";
					cin>>satir;
					cout<<"Columns :";
					cin>>sutun;
					int **a = matrix(satir,sutun);
					cout<<endl;
					cout<<"Enter Matrix Values :"<<endl;
					fill_matrix(a,satir,sutun);
					cout<<endl;
					cout<<"Matrix :"<<endl;
					print_matrix(a,satir,sutun);
					cout<<endl;
					cout<<"Enter the Scalar Value You Want to Multiply :";
					cin>>skaler;
					multiple_matrix_w_scalar(a,satir,sutun,skaler);
					cout<<endl;
					cout<<"Product Matrix :"<<endl;
					print_matrix(a,satir,sutun);
					break;
				}
			case 't':
				{
					cout<<"Enter the number of rows and columns of the matrix you want to transpose."<<endl;
					int satir = 0;
					int sutun = 0;
					cout<<"Rows :";
					cin>>satir;
					cout<<"Columns :";
					cin>>sutun;
					int **a = matrix(satir,sutun);
					int **tr = matrix(sutun,satir);
					cout<<"Enter Matrix Values :"<<endl;
					fill_matrix(a,satir,sutun);
					cout<<endl;
					cout<<"Matrix :"<<endl;
					print_matrix(a,satir,sutun);
					fill_null_matrix(tr,sutun,satir);
					transposition_matrix(a,tr,sutun,satir);
					cout<<endl;
					cout<<"Transposition Matrix :"<<endl;
					print_matrix(tr,sutun,satir);
					break;
				}
			case 'd':
				{
					cout<<"Enter the Number of Rows and Columns of the Matrix You Want to Get the Determinant of"<<endl;
					cout<<"The matrix you want to get the determinant must be a square matrix!!"<<endl;
					int satir = 0;
					int sutun = 0;
					cout<<"Rows :";
					cin>>satir;
					cout<<"Columns :";
					cin>>sutun;
					if(satir == sutun)
					{
						int **a = matrix(satir,sutun);
						cout<<"Enter Matrix Values :"<<endl;
						fill_matrix(a,satir,sutun);
						cout<<endl;
						cout<<"Matrix :"<<endl;
						print_matrix(a,satir,sutun);
						int determinant = determinant_matrix(a,satir,sutun,satir);
						cout<<endl;
						cout<<"Determinant Of Matrix : "<<determinant<<endl;
					}
					else
					{
						cout<<"The Determinant of This Matrix Cannot Be Taken!!!"<<endl;
					}
					break;
				}
			case 'a':
				{
					cout<<"Enter the Number of Rows and Columns of the Matrix You Want to Adjoint"<<endl;
					cout<<"The Matrix You Want To Adjoint Must Be A Square Matrix!!"<<endl;
					int satir = 0;
					int sutun = 0;
					cout<<"Rows :";
					cin>>satir;
					cout<<"Columns :";
					cin>>sutun;
					if(satir == sutun)
					{
						int **a = matrix(satir,sutun);
						int **adj = matrix(satir,sutun);
						cout<<"Enter Matrix Values :"<<endl;
						fill_matrix(a,satir,sutun);
						cout<<endl;
						cout<<"Matrix :"<<endl;
						print_matrix(a,satir,sutun);
						adjoint_matrix(a,adj,satir,sutun);
						cout<<"Adjoint Of Matrix :"<<endl;
						print_matrix(adj,satir,sutun);
					}
					else
					{
						cout<<"This Matrix Cannot Be Adjoined"<<endl;
					}
					break;
				}
			case 'i':
				{
					cout<<"Enter the Number of Rows and Columns of the Matrix You Want to Invert"<<endl;
					cout<<"The Matrix You Want To Get Inverted Must Be A Square Matrix!!"<<endl;
					int satir = 0;
					int sutun = 0;
					cout<<"Rows :";
					cin>>satir;
					cout<<"Columns :";
					cin>>sutun;
					if(satir == sutun)
					{
						int **a = matrix(satir,sutun);
						int **adj = matrix(satir,sutun);
						
						cout<<"Enter Matrix Values :"<<endl;
						fill_matrix(a,satir,sutun);
						cout<<endl;
						cout<<"Matrix :"<<endl;
						print_matrix(a,satir,sutun);
						inverse_matrix(a,adj,satir,sutun);	
					}
					else
					{
						cout<<"This Matrix Cannot Be Inverted"<<endl;
					}
					break;
				}
			case 'e':
				{
					a = 0;
					break;	
				}
			default:
				{
					if(hak > 0)
					{
						cout<<"Invalid Transaction Entered! "<<"Your Remaining Transaction Rights :"<<hak<<endl;
						hak = hak - 1;
					}
					else
					{
						cout<<"Your Right to Enter a Transaction Has Ended"<<endl;
						a = 0;
					}
				}
		}
	}
	return 0;
}
