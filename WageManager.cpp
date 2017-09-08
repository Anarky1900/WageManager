#include<iostream>

using namespace std;

#define ERROR 0;

class Stuff
{
public:
	//无参构造函数
	Stuff()
	{
		id = "0";
		name = "0";
		sex = "0";
		age = 0;
		adr = "0";
		wage = 0.0;

	}
	//有参构造函数
	Stuff(string i, string n, string s, int a, string ad, double w)
	{
		SetId(i);
		SetName(n);
		SetSex(s);
		SetAge(a);
		SetAdr(ad);
		SetWage(w);
	}
	//设置编号
	void SetId(string i)
	{
		id = i;
	}
	//返回编号
	string GetId()
	{
		return id;
	}
	//设置名字
	void SetName(string n)
	{
		name = n;
	}
	//返回名字
	string GetName()
	{
		return name;
	}
	//设置性别
	void SetSex(string s)
	{
		sex = s;
	}
	//返回性别
	string GetSex()
	{
		return id;
	}
	//设置年龄
	void SetAge(int a)
	{
		age = a;
	}
	//返回年龄
	int GetAge()
	{
		return age;
	}
	//设置家庭住址
	void SetAdr(string ad)
	{
		adr = ad;
	}
	//返回家庭住址
	string GetAdr()
	{
		return adr;
	}
	//设置基本职务工资
	void SetWage(double w)
	{
		wage = w;
	}
	//返回基本职务工资
	double GetWage()
	{
		return wage;
	}

private:
	string id;//编号
	string name;//姓名
	string sex;//性别
	int age;//年龄
	string adr;//家庭住址
	double wage;//基本职务工资
};

class PerStuff :public Stuff
{
public:
	//无参构造函数
	PerStuff()
	{
		bounty = 0;
		pension = 0;
		housingFund = 0;
		tax = 0;
		insurance = 0;
		income = 0;
	}
	//有参构造函数
	PerStuff(double b, double p, double h, double t, double i, double in)
	{
		SetBounty(b);
		SetPension(p);
		SetHousingFund(h);
		SetTax(t);
		SetInsurance(i);
		SetIncome(in);
	}
	//设置津贴
	void SetBounty(double b)
	{
		bounty = b;
	}
	//返回津贴
	double GetBounty()
	{
		return bounty;
	}
	//设置养老金
	void SetPension(double p)
	{
		pension = p;
	}
	//返回养老金
	double GetPension()
	{
		return pension;
	}
	//设置住房公积金
	void SetHousingFund(double h)
	{
		housingFund = h;
	}
	//返回住房公积金
	double GetHousingFund()
	{
		return housingFund;
	}
	//设置所得税
	void SetTax(double t)
	{
		tax = t;
	}
	//返回所得税
	double GetTax()
	{
		return tax;
	}
	//设置医疗保险
	void SetInsurance(double i)
	{
		insurance = i;
	}
	//返回医疗保险
	double GetInsurance()
	{
		return insurance;
	}
	//设置实发工资
	void SetIncome(double in)
	{
		income = in;
	}
	//返回实发工资
	double GetIncome()
	{
		return income;
	}
	//打印所有信息???
	void GetInfo()
	{
		cout << "";
	}
private:
	double bounty;//岗位津贴
	double pension;//养老金
	double housingFund;//住房公积金
	double tax;//所得税
	double insurance;//医疗保险
	double income;//实发工资
};

class TempStuff :public Stuff {
public:

	TempStuff()
	{
		reward = 0.0;
		tax = 0.0;
		income = 0.0;
	}

	TempStuff(double r, double t, double i)
	{
		SetReward(r);
		SetTax(t);
		SetIncome(i);
	}

	void SetReward(double r)
	{
		reward = r;
	}

	double GetReward()
	{
		return reward;
	}

	void SetTax(double t)
	{
		tax = t;
	}

	double GetTax()
	{
		return tax;
	}
	void SetIncome(double i)
	{
		income = i;
	}

	double GetIncome()
	{
		return income;
	}

private:
	double reward;
	double tax;//
	double income;//
};
int main()
{
	cout << "================================================\n\n"
		 << "\t\t职工工资信息管理系统\n\n"
		 << "\t\t1.输入职工信息\n"
		 << "\t\t2.插入职工信息\n"
		 << "\t\t3.查询职工信息\n"
		 << "\t\t4.修改职工信息\n"
		 << "\t\t5.删除职工信息\n"
		 << "\t\t0.退出系统\n\n"
		 << "================================================\n"
		 << endl;
	return ERROR;
}