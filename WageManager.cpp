#include<iostream>
#include<string>

using namespace std;

typedef int Status;

#define ERROR 0;
#define ok 1;

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
		return sex;
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
	PerStuff(string id, string name, string sex, int age, string adr, double wage, double b, double p, double h, double t, double i, double in)
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
private:
	double bounty;//岗位津贴
	double pension;//养老金
	double housingFund;//住房公积金
	double tax;//所得税
	double insurance;//医疗保险
	double income;//实发工资
	PerStuff *next;
}PerStuff, *PList;//*PList为头结点

typedef class TempStuff :public Stuff {
public:
	friend class List;
	//无参构造函数
	TempStuff()
	{
		reward = 0.0;
		tax = 0.0;
		income = 0.0;
		next = NULL;
	}
	//有参构造函数
	TempStuff(string i, string n, string s, int a, string ad, double w, double r, double t, double in)
	{
		Stuff(i, n, s, a, ad, w);
		SetReward(r);
		SetTax(t);
		SetIncome(in);
		next = NULL;
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
}TempStuff, *TList;//*TList为头结点

class List {
public:
	void InitList_L(PList &L);//创建PL链表  传入表头 
	void InitList_L(TList &T);//创建TL链表  传入表头
	void Add(PList &L);//添加节点
	void Add(TList &T);//添加节点
	Status Delete(PList &L);//删除PL节点
	Status Delete(TList &T);//删除TL节点
	void Modify(PList &L);//修改链表
	void Modify(TList &T);//修改链表
	void Search(PList &L);//搜索PL
	void Search(TList &T);//搜索TL
	bool IsEmpty(PList &L);//是否为空链表
	bool IsEmpty(TList &T);//是否为空链表
	void Copy(PList &L, PList &L1);//复制PL链表           
	void Copy(TList &T, TList &T1);//复制TL链表          
	int Length(PList &L);//长度
	int Length(TList &T);//长度
	void ShowList(PList &L);//打印Lp 链表
	void ShowList(TList &T);//打印Tp 链表
	void Count(PList &L);//
	void Count(TList &T);//
	void CountIncome(PList &L);//计算实际工资
	void CountIncome(TList &T);//计算实际工资
};
//计算PL实际工资
void List::CountIncome(PList &L)
{
	double sum = 0;
	PerStuff *p = L;
	if (IsEmpty(L))
	{
		cout << "这是空表！！！";
		return;
	}
	while (p->next != NULL)
	{
		p = p->next;
		p->income = p->GetWage() + p->GetBounty() - p->GetPension() - p->GetHousingFund() - p->GetTax() - p->GetInsurance();
	}
}

//计算TL实际工资
void List::CountIncome(TList &T)
{
	double sum = 0;
	TempStuff *p = T;
	if (IsEmpty(T))
	{
		cout << "这是空表！！！";
		return;
	}
	while (p->next != NULL)
	{
		p = p->next;
		p->income = p->GetWage() + p->GetReward() - p->GetTax();
	}
}

//统计工资总额，平均值
void List::Count(PList &L)
{
	;
}

//创建PL链表
void List::InitList_L(PList &L)//输入头结点参数
{
	L = new PerStuff();
}

//创TL链表
void List::InitList_L(TList &T)//输入头结点参数
{
	T = new TempStuff();
}

//添加PL节点
void List::Add(PList &L)
{
	//在链表末尾添加节点
	string id = "0";//编号
	string name = "0";//姓名
	string sex = "0";//性别
	int age = 0;//年龄
	string adr = "0";//家庭住址
	double wage = 0;//基本职务工资
	double bounty = 0;//岗位津贴
	double pension = 0;//养老金
	double housingFund = 0;//住房公积金
	double tax = 0;//所得税
	double insurance = 0;//医疗保险
	double income = 0;//实发工资
	int n = 0;

	PerStuff *tp = L;
	while (tp->next != NULL)
		tp = tp->next;
	do {
		PerStuff *p = new PerStuff();//生成新节点
		cout << "\n请输入第" << Length(L) + 1 << "个节点信息：\n" << "编号：";
		cin >> id;
		p->SetId(id);
		cout << "姓名";
		cin >> name;
		p->SetName(name);
		cout << "性别：";
		cin >> sex;
		p->SetSex(sex);
		cout << "年龄：";
		cin >> age;
		p->SetAge(age);
		cout << "家庭住址：";
		cin >> adr;
		p->SetAdr(adr);
		cout << "基本职务工资：";
		cin >> wage;
		p->SetWage(wage);
		cout << "岗位津贴";
		cin >> bounty;
		p->SetBounty(bounty);
		cout << "养老金:";
		cin >> pension;
		p->SetPension(pension);
		cout << "住房公积金:";
		cin >> housingFund;
		p->SetHousingFund(housingFund);
		cout << "所得税:";
		cin >> tax;
		p->SetTax(tax);
		cout << "医疗保险:";
		cin >> insurance;
		p->SetInsurance(insurance);
		tp->next = p;
		tp = p;
		cout << "\n1.继续输入\t0.退出";
		cin >> n;
	} while (n != 0);
	CountIncome(L);
}

//添加TL节点
void List::Add(TList &T)
{
	//在链表末尾添加节点
	string id = "0";//编号
	string name = "0";//姓名
	string sex = "0";//性别
	int age = 0;//年龄
	string adr = "0";//家庭住址
	double wage = 0;//基本职务工资
	double reward = 0;//奖金
	double tax = 0;//所得税
	double income = 0;//实发工资
	int n = 0;

	TempStuff *tp = T;
	while (tp->next)
		tp = tp->next;
	do {
		TempStuff *p = new TempStuff();//生成新节点
		cout << "\n请输入第" << Length(T) + 1 << "个节点信息：\n" << "编号：";
		cin >> id;
		p->SetId(id);
		cout << "姓名";
		cin >> name;
		p->SetName(name);
		cout << "性别：";
		cin >> sex;
		p->SetSex(sex);
		cout << "年龄：";
		cin >> age;
		p->SetAge(age);
		cout << "家庭住址：";
		cin >> adr;
		p->SetAdr(adr);
		cout << "基本职务工资：";
		cin >> wage;
		p->SetWage(wage);
		cout << "奖金";
		cin >> reward;
		p->SetReward(reward);
		cout << "所得税:";
		cin >> tax;
		p->SetTax(tax);
		tp->next = p;
		tp = p;
		cout << "\n1.继续输入\t0.退出";
		cin >> n;
	} while (n != 0);
	CountIncome(T);
}

//Tp  判断
bool List::IsEmpty(TList &T)
{
	if (T->next == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Lp  判断
bool List::IsEmpty(PList &L)
{
	if (L->next == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//删除PL节点                                               
Status List::Delete(PList &L)
{
	//按id查找，若存在，则删除，若不存在，则打印错误
	string id;
	PerStuff *p = L;
	if (IsEmpty(L))
	{
		cout << "这是空表！！";
		return ERROR;
	}
	else
	{
		cout << "请输入要删除的id：";
		cin >> id;
		while (p->next != NULL)
		{
			if (p->next->GetId() == id)
			{
				PerStuff *tp = p->next;
				p->next = tp->next;
				cout << "\n删除成功！";
				free(tp);
				return ok;
			}
			p = p->next;
		}
		if (p->next == NULL)
		{
			cout << "没有该成员！！";
			return ERROR;
		}
	}
}

//删除TL节点     
Status List::Delete(TList &T)
{
	//按id查找，若存在，则删除，若不存在，则打印错误
	string id;
	TempStuff *p = T;
	if (IsEmpty(T))
	{
		cout << "这是空表！！";
		return ERROR;
	}
	else
	{
		cout << "请输入要删除的id：";
		cin >> id;
		while (p->next != NULL)
		{
			if (p->next->GetId() == id)
			{
				TempStuff *tp = p->next;
				p->next = tp->next;
				cout << "\n删除成功！";
				free(tp);
				return ok;
			}
			p = p->next;
		}
		if (p->next == NULL)
		{
			cout << "没有该成员！！";
			return ERROR;
		}
	}
}

//PL 长度
int List::Length(PList &L)
{
	int n = 0;
	PerStuff *p = L;
	while (p->next != NULL)
	{
		p = p->next;
		n++;
	}
	return n;
}

//TL 长度
int List::Length(TList &T)
{
	int n = 0;
	TempStuff *p = T;
	while (p->next != NULL)
	{
		p = p->next;
		n++;
	}
	return n;
}

//修改   
void List::Modify(PList &L)//输入表头，id
{
	string id = "-1";//编号
	string name = "0";//姓名
	string sex = "0";//性别
	int age = 0;//年龄
	string adr = "0";//家庭住址
	double wage = 0;//基本职务工资
	double bounty = 0;//岗位津贴
	double pension = 0;//养老金
	double housingFund = 0;//住房公积金
	double tax = 0;//所得税
	double insurance = 0;//医疗保险

	PerStuff *p = L;
	int l = 0;//计数器
	if (IsEmpty(L))
	{
		cout << "这是空表！！！";
		return;
	}
	cout << "\n请输入要修改的职工id:";
	cin >> id;
	while (p->next != NULL)
	{
		p = p->next;
		if (p->GetId() == id)
		{
			cout << "\n编号：" << p->GetId() << "\n姓名：" << p->GetName() << "\n性别：" << p->GetSex()
				<< "\n年龄：" << p->GetAge() << "\n家庭住址：" << p->GetAdr() << "\n基本职务工资：" << p->GetWage()
				<< "\n岗位津贴：" << "\n养老金:" << p->GetPension() << "\n住房公积金：" << p->GetHousingFund()
				<< "\n所得税：" << p->GetTax() << "\n医疗保险：" << p->GetInsurance() << "\n实际收入：" << p->GetIncome();
			cout << "\n\n请输入修改的数据：\n编号：";
			cin >> id;
			p->SetId(id);
			cout << "姓名";
			cin >> name;
			p->SetName(name);
			cout << "性别：";
			cin >> sex;
			p->SetSex(sex);
			cout << "年龄：";
			cin >> age;
			p->SetAge(age);
			cout << "家庭住址：";
			cin >> adr;
			p->SetAdr(adr);
			cout << "基本职务工资：";
			cin >> wage;
			p->SetWage(wage);
			cout << "岗位津贴";
			cin >> bounty;
			p->SetBounty(bounty);
			cout << "养老金:";
			cin >> pension;
			p->SetPension(pension);
			cout << "住房公积金:";
			cin >> housingFund;
			p->SetHousingFund(housingFund);
			cout << "所得税:";
			cin >> tax;
			p->SetTax(tax);
			cout << "医疗保险:";
			cin >> insurance;
			p->SetInsurance(insurance);
			cout << "\n编号：" << p->GetId() << "\n姓名：" << p->GetName() << "\n性别：" << p->GetSex()
				<< "\n年龄：" << p->GetAge() << "\n家庭住址：" << p->GetAdr() << "\n基本职务工资：" << p->GetWage()
				<< "\n岗位津贴：" << "\n养老金:" << p->GetPension() << "\n住房公积金：" << p->GetHousingFund()
				<< "\n所得税：" << p->GetTax() << "\n医疗保险：" << p->GetInsurance() << "\n实际收入：" << p->GetIncome() << "\n修改成功！";
			p->income = p->GetWage() + p->GetBounty() - p->GetPension() - p->GetHousingFund() - p->GetTax() - p->GetInsurance();
			return;
		}
		l++;
	}
	if (l >= Length(L) && p->GetId() != id)//索引完链表未找到
	{
		cout << "\n表中没有该职工！";
	}
}

//修改   
void List::Modify(TList &T)//输入表头，id
{
	string id = "-1";//编号
	string name = "0";//姓名
	string sex = "0";//性别
	int age = 0;//年龄
	string adr = "0";//家庭住址
	double wage = 0;//基本职务工资
	double reward = 0;//奖金
	double tax = 0;//所得税
	double income = 0;//实发工资

	TempStuff *p = T;
	int l = 0;//计数器
	if (IsEmpty(T))
	{
		cout << "这是空表！！！";
		return;
	}
	cout << "\n请输入要修改的职工id:";
	cin >> id;
	while (p->next != NULL)
	{
		p = p->next;
		if (p->GetId() == id)
		{
			cout << "\n编号：" << p->GetId() << "\n姓名：" << p->GetName() << "\n性别：" << p->GetSex()
				<< "\n年龄：" << p->GetAge() << "\n家庭住址：" << p->GetAdr() << "\n基本职务工资：" << p->GetWage()
				<< "\n奖金：" << p->GetReward() << "\n所得税：" << p->GetTax() << "\n实发工资:" << p->GetIncome();
			cout << "\n\n请输入修改的数据：\n编号：";
			cin >> id;
			p->SetId(id);
			cout << "姓名";
			cin >> name;
			p->SetName(name);
			cout << "性别：";
			cin >> sex;
			p->SetSex(sex);
			cout << "年龄：";
			cin >> age;
			p->SetAge(age);
			cout << "家庭住址：";
			cin >> adr;
			p->SetAdr(adr);
			cout << "基本职务工资：";
			cin >> wage;
			p->SetWage(wage);
			cout << "奖金";
			cin >> reward;
			p->SetReward(reward);
			cout << "所得税:";
			cin >> tax;
			cout << "\n\n编号：" << p->GetId() << "\n姓名：" << p->GetName() << "\n性别：" << p->GetSex()
				<< "\n年龄：" << p->GetAge() << "\n家庭住址：" << p->GetAdr() << "\n基本职务工资：" << p->GetWage()
				<< "\n奖金：" << p->GetReward() << "\n所得税：" << p->GetTax() << "\n实发工资:" << p->GetIncome();
			CountIncome(T);
			return;
		}
		l++;
	}
	if (l >= Length(T) && p->GetId() != id)//索引完链表未找到
	{
		cout << "\n表中没有该职工！";
	}
}

//复制PL
void List::Copy(PList &L, PList &L1)
{

	//将L复制给L1
	PerStuff *p = L;
	PerStuff *p1 = L1;
	while (p->next != NULL)
	{
		p = p->next;//p移向下一个
		PerStuff *tp = new PerStuff();//生成新节点
		tp->SetId(p->GetId());//赋值
		tp->SetName(p->GetName());
		tp->SetSex(p->GetSex());
		tp->SetAge(p->GetAge());
		tp->SetAdr(p->GetAdr());
		tp->SetWage(p->GetWage());
		tp->SetBounty(p->GetBounty());
		tp->SetPension(p->GetPension());
		tp->SetHousingFund(p->GetHousingFund());
		tp->SetTax(p->GetTax());
		tp->SetInsurance(p->GetInsurance());
		tp->SetIncome(p->GetIncome());
		while (p1->next != NULL)
			p1 = p1->next;
		p1->next = tp;
		p1 = tp;
	}
}

//复制TL
void List::Copy(TList &T, TList &T1)
{

	//将T复制给T1
	TempStuff *p = T;
	TempStuff *p1 = T1;
	while (p->next != NULL)
	{
		p = p->next;//p移向下一个
		TempStuff *tp = new TempStuff();//生成新节点
		tp->SetId(p->GetId());//赋值
		tp->SetName(p->GetName());
		tp->SetSex(p->GetSex());
		tp->SetAge(p->GetAge());
		tp->SetAdr(p->GetAdr());
		tp->SetWage(p->GetWage());
		tp->SetReward(p->GetReward());
		tp->SetTax(p->GetTax());
		tp->SetIncome(p->GetIncome());
		while (p1->next != NULL)
			p1 = p1->next;
		p1->next = tp;
		p1 = tp;
	}
}

//打印Pl   
void List::ShowList(PList &L)
{
	PerStuff *p = L;
	if (p->next == NULL)
	{
		cout << "\n这是空链表！";
	}
	while (p->next != NULL)
	{
		p = p->next;
		cout << "\n\n编号：" << p->GetId() << "\n姓名：" << p->GetName() << "\n性别：" << p->GetSex()
			<< "\n年龄：" << p->GetAge() << "\n家庭住址：" << p->GetAdr() << "\n基本职务工资：" << p->GetWage()
			<< "\n岗位津贴：" << "\n养老金:" << p->GetPension() << "\n住房公积金：" << p->GetHousingFund()
			<< "\n所得税：" << p->GetTax() << "\n医疗保险：" << p->GetInsurance() << "\n实际收入：" << p->GetIncome();
	}

}

//打印Tl    
void List::ShowList(TList &T)
{
	TempStuff *p = T;
	if (p->next == NULL)
	{
		cout << "\n这是空链表！";
	}
	while (p->next != NULL)
	{
		p = p->next;
		cout << "\n\n编号：" << p->GetId() << "\n姓名：" << p->GetName() << "\n性别：" << p->GetSex()
			<< "\n年龄：" << p->GetAge() << "\n家庭住址：" << p->GetAdr() << "\n基本职务工资：" << p->GetWage()
			<< "\n奖金：" << p->GetReward() << "\n所得税：" << p->GetTax() << "\n实发工资:" << p->GetIncome();
	}

}

//搜索PL
void List::Search(PList &L)
{
	string id;
	PerStuff *p = L;
	cout << "请输入要寻找的id" << endl;
	cin >> id;
	if (IsEmpty(L))
	{
		cout << "\n这是空表！";
		return;
	}
	while (p->next != NULL&&p->next->GetId() != id)
	{
		p = p->next;
	}
	p = p->next;
	cout << "姓名：" << p->GetName() << endl
		<< "性别：" << p->GetSex() << endl
		<< "年龄：" << p->GetAge() << endl
		<< "家庭住址：" << p->GetAdr() << endl
		<< "基本职务工资：" << p->GetWage() << endl
		<< "岗位津贴：" << p->GetBounty() << endl
		<< "养老金：" << p->GetPension() << endl
		<< "住房公积金：" << p->GetHousingFund() << endl
		<< "所得税：" << p->GetTax() << endl
		<< "医疗保险：" << p->GetInsurance() << endl
		<< "实发工资：" << p->GetIncome() << endl;

}

//搜索TL
void List::Search(TList &T)
{
	string id;
	TempStuff *p = T;
	cout << "请输入要寻找的id" << endl;
	cin >> id;
	if (IsEmpty(T))
	{
		cout << "\n这是空表！";
		return;
	}
	while (p->next != NULL&&p->next->GetId() != id)
	{
		p = p->next;
	}
	p = p->next;
	cout << "姓名：" << p->GetName() << endl
		<< "性别：" << p->GetSex() << endl
		<< "年龄：" << p->GetAge() << endl
		<< "家庭住址：" << p->GetAdr() << endl
		<< "基本职务工资：" << p->GetWage() << endl
		<< "\n奖金：" << p->GetReward() << "\n所得税：" << p->GetTax()
		<< "实发工资：" << p->GetIncome() << endl;
}

int main()
{
	List L;
	PList p, p1;
	L.InitList_L(p);
	int i = 0;
	do {
		cout << "\n*************************************************\n"
			<< "*\t\t\t\t\t\t*\n"
			<< "*\t\t职工工资信息管理系统\t\t*\n"
			<< "*\t\t\t\t\t\t*\n"
			<< "*\t\t1.输入职工信息\t\t\t*\n"
			<< "*\t\t2.插入职工信息\t\t\t*\n"
			<< "*\t\t3.查询职工信息\t\t\t*\n"
			<< "*\t\t4.修改职工信息\t\t\t*\n"
			<< "*\t\t5.删除职工信息\t\t\t*\n"
			<< "*\t\t6.\t\t\t\t*\n"
			<< "*\t\t\t\t\t\t*\n"
			<< "*************************************************\n"
			<< endl;
		cout << "\t\t选择：";
		cin >> i;
		switch (i)
		{
		case 1:
			L.Add(p);
			break;
		case 2:
			L.Add(p);
			break;
		case 3:
			L.Search(p);
			break;
		case 4:
			L.Modify(p);
			break;
		case 5:
			L.Delete(p);
			break;
		}
	} while (i != 0);
	return ERROR;
}
