struct details
{
	char name[20];
	int id;
	char phone[15];
	char city[20];
	int pincode;
};
program employee_prog
{
	version employee_vers
	{
		string operation1(struct details)=1;
		string operation2(string)=2;
		string operation3(string)=3;
		string operation4(string)=4;
		string operation5(string)=5;
	}=1;
}=0x99999999;
