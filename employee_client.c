/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "employee.h"
#include<sqlite3.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int z=1;
static int callback(void *notused,int ncol,char** colinrow,char ** colname)
{
	int i;
		printf("full details of employee %d:\n",z++);
	for(i=0;i<ncol;i++)
		printf("%s=%s\n",colname[i],colinrow[i]?colinrow[i]:"null");
	return 0;
}
////////////////////////////////////////////////////////////////////////////////
void
employee_prog_1(char *host)
{
	CLIENT *clnt;
	
	char * *result_1;
	struct details  operation1_1_arg;

	char * *result_2;
	static char * operation2_1_arg;

	char * *result_3;
	char * operation3_1_arg;

	char * *result_4;
	char * operation4_1_arg;

	char * *result_5;
	char * operation5_1_arg;

	char ch,ch1;
	int op;

#ifndef	DEBUG
	clnt = clnt_create (host, employee_prog, employee_vers, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
do
{
	sqlite3 *db;
	char *errmsg=0;
	int rc,opendb=1;
	char *sql;
	char *c;	
	ch='0';
	ch1='0';
	printf("enter an option \n1) Add an employee data \
			\n2) Add multiple employee data\
			\n3) Delete one employee data,\
			\n4) Delete multiple employee data,\
			\n5) Delete all employee data,\
			\n6) Get one employee data,\
			\n7) Get multiple employee data,\
			\n8) Get all employee data: ");
	scanf("%d",&op);
	switch(op)
	{
	case 1: printf("enter employee details\n");
		printf("enter name:");
		scanf("%s",operation1_1_arg.name);
		printf("enter id:");
		scanf("%d",&operation1_1_arg.id);
		printf("enter phone:");
		scanf("%s",operation1_1_arg.phone);
		printf("enter city:");
		scanf("%s",operation1_1_arg.city);
		printf("enter pincode:");
		scanf("%d",&operation1_1_arg.pincode);
		result_1 = operation1_1(&operation1_1_arg, clnt);
		if (result_1 == (char **) NULL) 
		{
			clnt_perror (clnt, "call failed");
		}
		else
		{
			printf("%s\n",*result_1);
		}
	break;
	case 2: do
		{	
			ch='0';
			printf("enter employee details\n");
			printf("enter name:");
			scanf("%s",operation1_1_arg.name);
			printf("enter id:");
			scanf("%d",&operation1_1_arg.id);
			printf("enter phone:");
			scanf("%s",operation1_1_arg.phone);
			printf("enter city:");
			scanf("%s",operation1_1_arg.city);
			printf("enter pincode:");
			scanf("%d",&operation1_1_arg.pincode);
			result_1 = operation1_1(&operation1_1_arg, clnt);
			if (result_1 == (char **) NULL)
			{
				clnt_perror (clnt, "call failed");
			}
			else
			{
				printf("%s\n",*result_1);
			}
			printf("u want to give one more employee data y/n:");
			scanf(" %c",&ch);
		}while(ch=='y');
	break;
	case 3: printf("enter condition to delete:");
		scanf("%s",operation2_1_arg);
		result_2 = operation2_1(&operation2_1_arg, clnt);
		if (result_2 == (char **) NULL) 
		{
			clnt_perror (clnt, "call failed");
		}
		else
		{
			printf("%s\n",*result_2);
		}
	break;
	case 4: do
		{
			printf("enter condition to delete:");
			scanf("%s",operation2_1_arg);
			result_2 = operation2_1(&operation2_1_arg, clnt);
			if (result_2 == (char **) NULL)
			{
				clnt_perror (clnt, "call failed");
			}
			else
			{
				printf("%s\n",*result_2);
			}
			printf("do u want to delete data again y/n:\n");
			scanf(" %c",&ch);
		}while(ch=='y');
	break;
	case 5: operation3_1_arg="delete from details";
		result_3 = operation3_1(&operation3_1_arg, clnt);
		if (result_3 == (char **) NULL)
		{
			clnt_perror (clnt, "call failed");
		}
		else
		{
			printf("%s\n",*result_3);
		}	
	break;
	case 6:	printf("enter condition to get the data:");
		scanf("%s",operation4_1_arg);
		z=1;
		result_4 = operation4_1(&operation4_1_arg, clnt);
		if (result_4 == (char **) NULL)
		{
			clnt_perror (clnt, "call failed");
		}
		else
		{
			opendb=sqlite3_open("mohan.db",&db);
			if(opendb==0)
			{
				rc=sqlite3_exec(db,*result_4,callback,0,&errmsg);
				if(rc)
				{
					printf("sql error:%s\n",errmsg);
					sqlite3_free(errmsg);
					sqlite3_close(db);
				}
				else
				{
					printf("get the data successfully\n");
					sqlite3_close(db);
				}
			}
			else
			{
			printf("cant open database:%s\n",sqlite3_errmsg(db));
			}
		}
	break;
	case 7: do
		{
			z=1;	
			printf("enter condition to get the data:");
			scanf("%s",operation4_1_arg);
			result_4 = operation4_1(&operation4_1_arg, clnt);
			if (result_4 == (char **) NULL)
			{
				clnt_perror (clnt, "call failed");
			}
			else
			{
				opendb=sqlite3_open("mohan.db",&db);
				if(opendb==0)
				{
					rc=sqlite3_exec(db,*result_4,callback,0,&errmsg);
					if(rc)
					{
						printf("sql error:%s\n",errmsg);
						sqlite3_free(errmsg);
						sqlite3_close(db);
					}
					else
					{
						printf("get the data successfully\n");
						sqlite3_close(db);	
					}
				}
				else
				{
				printf("cant open database:%s\n",sqlite3_errmsg(db));
				}
			}
			printf("do u want to get another data y/n:");
			scanf(" %c",&ch);
		}while(ch=='y');
	break;
	case 8:	operation5_1_arg="select * from details;";
		z=1;
		result_5 = operation5_1(&operation5_1_arg, clnt);
		if (result_5 == (char **) NULL)
		{
			clnt_perror (clnt, "call failed");
		}
		else
		{
			opendb=sqlite3_open("mohan.db",&db);
			if(opendb==0)
			{
			rc=sqlite3_exec(db,operation5_1_arg,callback,0,&errmsg);
				if(rc)
				{
					printf("sql error:%s\n",errmsg);
					sqlite3_free(errmsg);
					sqlite3_close(db);
				}
				else
				{
					printf("Get all the data successfully\n");
					sqlite3_close(db);
				}
			}
			else
			{
			printf("cant open database:%s\n",sqlite3_errmsg(db));
			}
		}
	break;
	default: printf("enter valid option\n");
		 printf("u want to give option again y/n:");
		 scanf(" %c",&ch1);
	}
	if(ch1=='0')	
	{
		printf("U want to do operation again y/n:");
		scanf(" %c",&ch);
	}
}while((ch=='y')||(ch1=='y'));

	
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	employee_prog_1 (host);
exit (0);
}
