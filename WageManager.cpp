#include<iostream>
#include<string>

using namespace std;

#define ERROR 0;

class Stuff 
{
public:
	//无参构造函数
	Stuff()
	{
		id ="0";
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
		name=n;
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

typedef class PerStuff :public Stuff
{
public:
	friend class List;
	//无参构造函数
	PerStuff()
	{
		bounty = 0;
		pension = 0;
		housingFund = 0;
		tax = 0;
		insurance = 0;
		income = 0;
		next = NULL;
	}
	//有参构造函数
	PerStuff(string id, string name, string sex, int age, string adr, double wage,double b, double p, double h, double t, double i, double in)
	{
		Stuff(id, name, sex, age, adr, wage);
		SetBounty(b);
		SetPension(p);
		SetHousingFund(h);
		SetTax(t);
		SetInsurance(i);
		SetIncome(in);
		next = NULL;
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
	PerStuff *next;
}PerStuff,*PList;//*PList为头结点

typedef class TempStuff :public Stuff {
public:
	friend class List;
	//无参构造函数
	TempStuff()
	{
		reward = 0.0;
		tax = 0.0;
		income = 0.0;
	}
	//有参构造函数
	TempStuff(string i, string n, string s, int a, string ad, double w,double r, double t, double in)
	{
		Stuff( i,  n, s, a,  ad, w);
		SetReward(r);
		SetTax(t);
		SetIncome(in);
	}
	//设置奖金
	void SetReward(double r)
	{
		reward = r;
	}
	//返回奖金
	double GetReward()
	{
		return reward;
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
	//设置实发工资
	void SetIncome(double i)
	{
		income = i;
	}
	//返回实发工资
	double GetIncome()
	{
		return income;
	}

private:
	double reward;//奖金
	double tax;//所得税
	double income;//实发工资
	TempStuff *next;
}TempStuff,*TList;//*TList为头结点

class List {
public:
	void CreateList_L(PList &Lp,int n);//创建PL链表  传入表头  n:节点个数
	void CreateList_L(TList &Tp, int n);//创建TL链表  传入表头  n:节点个数
	void Add();//添加节点
	void Delete();//删除节点
	void Modify();//修改链表
	void Serach();//搜索
	bool IsEmpty();//是否为空链表
	void ShowList();//打印链表
	void Copy();//复制链表
};

//创建PL链表
void List::CreateList_L(PList &L, int n)//输入头结点参数，节点个数
{
	string id;//编号
	string name;//姓名
	string sex;//性别
	int age;//年龄
	string adr;//家庭住址
	double wage;//基本职务工资
	double bounty;//岗位津贴
	double pension;//养老金
	double housingFund;//住房公积金
	double tax;//所得税
	double insurance;//医疗保险
	double income;//实发工资

	PerStuff *p = NULL;
	L = new PerStuff();//初始化头结点
	for (int i = 0; i < n; i++)
	{
		p = new PerStuff();//生成新节点
		cout << "请输入节点信息：\n" << "编号：";
		cin>>id;
		p->SetId(id);
		cout << "\n姓名";
		cin >> name;
		p->SetName(name);
		cout << "\n性别：";
		cin >> sex;
		p->SetSex(sex);
		cout << "\n年龄：";
		cin >> age;
		p->SetAge(age);
		cout << "\n家庭住址：";
		cin >> adr;
		p->SetAdr(adr);
		cout << "\n基本职务工资：";
		cin >> wage;
		p->SetWage(wage);
		cout << "\n岗位津贴";
		cin >> bounty;
		p->SetBounty(bounty);
		cout << "\n养老金:";
		cin >> pension;
		p->SetPension(pension);
		cout << "\n住房公积金:";
		cin >> housingFund;
		p->SetHousingFund(housingFund);
		cout << "\n所得税:";
		cin >> tax;
		p->SetTax(tax);
		cout << "\n医疗保险:";
		cin >> insurance;
		p->SetInsurance(insurance);
		p->next = L->next;//为空
		L->next = p;//逆序插入
	}
}

//创建PL链表
void List::CreateList_L(TList &L, int n)//输入头结点参数，节点个数
{
	string id;//编号
	string name;//姓名
	string sex;//性别
	int age;//年龄
	string adr;//家庭住址
	double wage;//基本职务工资
	double reward;//奖金
	double tax;//所得税
	double income;//实发工资

	TempStuff *p = NULL;
	L = new TempStuff();//初始化头结点
	for (int i = 0; i < n; i++)
	{
		p = new TempStuff();//生成新节点
		cout << "请输入节点信息：\n" << "编号：";
		cin >> id;
		p->SetId(id);
		cout << "\n姓名";
		cin >> name;
		p->SetName(name);
		cout << "\n性别：";
		cin >> sex;
		p->SetSex(sex);
		cout << "\n年龄：";
		cin >> age;
		p->SetAge(age);
		cout << "\n家庭住址：";
		cin >> adr;
		p->SetAdr(adr);
		cout << "\n基本职务工资：";
		cin >> wage;
		p->SetWage(wage);
		cout << "\n岗位津贴";//?
		cin >> reward;
		p->SetReward(reward);
		cout << "\n养老金:";//?
		cin >> tax;
		p->SetTax(tax);
		cout << "\n住房公积金:";//?
		cin >> income;
		p->SetIncome(income);
		p->next = L->next;//为空
		L->next = p;//逆序插入
	}
}

int main()
{
	cout<< "*************************************************\n"
		<< "*\t\t\t\t\t\t*\n"
		<< "*\t\t职工工资信息管理系统\t\t*\n"
		<< "*\t\t\t\t\t\t*\n"
		<< "*\t\t1.输入职工信息\t\t\t*\n"
		<< "*\t\t2.插入职工信息\t\t\t*\n"
		<< "*\t\t3.查询职工信息\t\t\t*\n"
		<< "*\t\t4.修改职工信息\t\t\t*\n"
		<< "*\t\t5.删除职工信息\t\t\t*\n"
		<< "*\t\t6.\t\t\t*\n"
		<< "*\t\t\t\t\t\t*\n"
		<< "*************************************************\n"
		<< endl;
	List L;
	PList p;
	return ERROR;
}
