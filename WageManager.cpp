#include<iostream>
#include<string>
#include<fstream>

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
	void ClearList(PList &L);//清空链表
	void ClearList(TList &T);//清空链表
	void Count(PList &L);//统计平均工资，工资总额
	void Count(TList &T);//统计平均工资，工资总额
	void CountIncome(PList &L);//计算实际工资
	void CountIncome(TList &T);//计算实际工资
	void DestroyList(PList &L);//销毁链表
	void DestroyList(TList &T);//销毁链表
	void OpenFile(PList &L);//读取链表PerStuff
	void OpenFile(TList &T);//读取链表
	void SaveFile(PList &L);
	void SaveFile(TList &T);
};


//读取链表PerStuff
void List::OpenFile(PList &L)
{
	fstream _file;
	_file.open("D://PerStuff.txt", ios::in);
	if (!_file) { return; }
	ifstream fin("D://PerStuff.txt");
	if (!fin.is_open())
	{
		cout << "数据文件读取失败";
		exit(1);
	}
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

	while (!fin.eof())
	{
		PerStuff *p = new PerStuff();
		// fin >> id >>" ">> name >> " " >> sex >> " " >> age >> " " >> adr >> " " >> wage >> " " >> bounty >> " " >> pension >> " " >> housingFund >> " " >> tax >> " " >> insurance >> " " >> income>> "\n";
		fin >> id >> name >> sex >> age >> adr >> wage >> bounty >> pension >> housingFund >> tax >> insurance >> income;
		p->SetId(id);
		p->SetName(name);
		p->SetSex(sex);
		p->SetAge(age);
		p->SetAdr(adr);
		p->SetWage(wage);
		p->SetBounty(bounty);
		p->SetPension(pension);
		p->SetHousingFund(housingFund);
		p->SetTax(tax);
		p->SetInsurance(insurance);
		p->SetIncome(income);
		p->next = NULL;
		p->next = tp->next;
		tp->next = p;
		tp = p;
	}
	fin.close();
}

//读取链表TempStuff
void List::OpenFile(TList &T)
{
	fstream _file;
	_file.open("D://TempStuff.txt", ios::in);
	if (!_file) { return; }
	ifstream fin("D://TempStuff.txt");
	if (!fin.is_open())
	{
		cout << "数据文件读取失败";
		exit(1);
	}
	string id = "0";//编号
	string name = "0";//姓名
	string sex = "0";//性别
	int age = 0;//年龄
	string adr = "0";//家庭住址
	double wage = 0;//基本职务工资
	double tax = 0;//所得税
	double reward = 0;//奖金
	double income = 0;//实发工资
	int n = 0;
	TempStuff *tp = T;

	while (!fin.eof())
	{
		TempStuff *p = new TempStuff();
		fin >> id >> name >> sex >> age >> adr >> wage >> reward >> tax >> income;
		p->SetId(id);
		p->SetName(name);
		p->SetSex(sex);
		p->SetAge(age);
		p->SetAdr(adr);
		p->SetWage(wage);
		p->SetReward(reward);
		p->SetTax(tax);
		p->SetIncome(income);
		p->next = NULL;
		p->next = tp->next;
		tp->next = p;
		tp = p;
	}
	fin.close();
}

//保存链表PerStuff
void List::SaveFile(PList &L)
{
	PerStuff *p = L;
	ofstream out("D://PerStuff.txt");
	if (out.is_open())
	{
		while (p->next != NULL)
		{
			p = p->next;
			out <<"\n"<< p->GetId() << " " << p->GetName() << " " << p->GetSex() << " " << p->GetAge() << " "
				<< p->GetAdr() << " " << p->GetWage() << " " << p->GetBounty() << " " << p->GetPension() << " "
				<< p->GetHousingFund() << " " << p->GetTax() << " " << p->GetInsurance() << " " << p->GetIncome() ;
		}
	}
	out.close();
}


//保存链表TempStuff
void List::SaveFile(TList &T)
{
	TempStuff *p = T;
	ofstream out("D://TempStuff.txt");
	if (out.is_open())
	{
		while (p->next != NULL)
		{
			p = p->next;
			out << "\n" << p->GetId() << " " << p->GetName() << " " << p->GetSex() << " " << p->GetAge() << " " << p->GetAdr()
				<< " " << p->GetWage() << " " << p->GetReward() << " " << p->GetTax() << " " << p->GetIncome() ;
		}
	}
	out.close();
}


//统计平均工资，工资总额
void List::Count(PList &L)
{
	int m = 0;
	double avge = 0;
	double Wage = 0;
	cout << "\t\t1.查看平均工资\n"
		<< "\t\t2.查看工资总额\n"
		<<"\t\t3.查看总人数\n"
		<<"\t\t0.返回"
		<< endl;
	cout << "\t\t选择：";
	cin >> m;
	while (m<0||m>3)
	{
		cout << "\t\t选择：";
		cin >> m;
	}
	PerStuff* p = L;
	while (p->next != NULL)
	{
		p = p->next;
		Wage += p->GetIncome();
	}
	switch (m)
	{
	case 3:
		cout << "\t\t总人数为:" << Length(L);
		break;
	case 2:
		cout << "\t\t工资总额为：" << Wage;
		break;
	case 1:
		if (Wage == 0)
		{
			avge = 0;
		}
		avge = Wage / Length(L);
		cout << "\t\t平均工资为：" << avge;
		break;
	case 0:
		break;
	}
}

//统计平均工资，工资总额
void List::Count(TList &T)
{
	int m = 0;
	double avge = 0;
	static double Wage = 0;
	cout << "\t\t1.查看平均工资\n"
		<< "\t\t2.查看工资总额\n" 
		<<"\t\t3.查看总人数\n"
		<<"\t\t0.返回"
		<< endl;
	cout << "\t\t选择：";
	cin >> m;
	while (m != 1 || m != 2||m!=3||m!=0)
	{
		cout << "\t\t选择：";
		cin >> m;
	}
	TempStuff* p = T;
	while (p->next != NULL)
	{
		p = p->next;
		Wage += p->GetIncome();
	}
	switch (m)
	{
	case 3:
		cout << "\t\t总人数为:" << Length(T);
		break;
	case 2:
		cout << "\t\t工资总额为：" << Wage;
		break;
	case 1:
		if(Wage==0)
		{
			avge = 0;
		}
		avge = Wage / Length(T);
		cout << "\t\t平均工资为：" << avge;
		break;
	case 0:
		break;
	}
}

//销毁链表
void List::DestroyList(PList &L)
{
	ClearList(L);
	free(L);
	cout << "\t\t成功释放空间！\n";
}

//销毁链表
void List::DestroyList(TList &T)
{
	ClearList(T);
	free(T);
	cout << "\t\t成功释放空间！\n";
}

//计算PL实际工资
void List::CountIncome(PList &L)
{
	double sum = 0;
	PerStuff *p = L;
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
	while (p->next != NULL)
	{
		p = p->next;
		p->income = p->GetWage() + p->GetReward() - p->GetTax();
	}
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
		cout << "\n\t\t请输入第" << Length(L) + 1 << "个节点信息：\n" << "\t\t编号：";
		cin >> id;
		p->SetId(id);
		cout << "\t\t姓名:";
		cin >> name;
		p->SetName(name);
		cout << "\t\t性别：";
		cin >> sex;
		p->SetSex(sex);
		cout << "\t\t年龄：";
		cin >> age;
		p->SetAge(age);
		cout << "\t\t家庭住址：";
		cin >> adr;
		p->SetAdr(adr);
		cout << "\t\t基本职务工资：";
		cin >> wage;
		p->SetWage(wage);
		cout << "\t\t岗位津贴";
		cin >> bounty;
		p->SetBounty(bounty);
		cout << "\t\t养老金:";
		cin >> pension;
		p->SetPension(pension);
		cout << "\t\t住房公积金:";
		cin >> housingFund;
		p->SetHousingFund(housingFund);
		cout << "\t\t所得税:";
		cin >> tax;
		p->SetTax(tax);
		cout << "\t\t医疗保险:";
		cin >> insurance;
		p->SetInsurance(insurance);
		tp->next = p;
		tp = p;
		cout << "\n\t\t1.继续输入\t0.退出";
		cout << "\n\t\t选择：";
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
		cout << "\n\t\t请输入第" << Length(T) + 1 << "个节点信息：\n" << "\t\t编号：";
		cin >> id;
		p->SetId(id);
		cout << "\t\t姓名";
		cin >> name;
		p->SetName(name);
		cout << "\t\t性别：";
		cin >> sex;
		p->SetSex(sex);
		cout << "\t\t年龄：";
		cin >> age;
		p->SetAge(age);
		cout << "\t\t家庭住址：";
		cin >> adr;
		p->SetAdr(adr);
		cout << "\t\t基本职务工资：";
		cin >> wage;
		p->SetWage(wage);
		cout << "\t\t奖金";
		cin >> reward;
		p->SetReward(reward);
		cout << "\t\t所得税:";
		cin >> tax;
		p->SetTax(tax);
		tp->next = p;
		tp = p;
		cout << "\n\t\t1.继续输入\t0.退出\n";
		cout << "\t\t选择：";
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
		cout << "\t\t这是空表！！";
		return ERROR;
	}
	else
	{
		cout << "\t\t请输入要删除的id：";
		cin >> id;
		while (p->next != NULL)
		{
			if (p->next->GetId() == id)
			{
				PerStuff *tp = p->next;
				p->next = tp->next;
				cout << "\n\t\t删除成功！";
				free(tp);
				return ok;
			}
			p = p->next;
		}
		if (p->next == NULL)
		{
			cout << "\t\t没有该成员！！";
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
		cout << "\t\t这是空表！！";
		return ERROR;
	}
	else
	{
		cout << "\t\t请输入要删除的id：";
		cin >> id;
		while (p->next != NULL)
		{
			if (p->next->GetId() == id)
			{
				TempStuff *tp = p->next;
				p->next = tp->next;
				cout << "\n\t\t删除成功！";
				free(tp);
				return ok;
			}
			p = p->next;
		}
		if (p->next == NULL)
		{
			cout << "\t\t没有该成员！！";
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
		cout << "\t\t这是空表！！！";
		return;
	}
	cout << "\n\t\t请输入要修改的职工id:";
	cin >> id;
	while (p->next != NULL)
	{
		p = p->next;
		if (p->GetId() == id)
		{
			cout << "\n\t\t编号：" << p->GetId()
				<< "\n\t\t姓名：" << p->GetName()
				<< "\n\t\t性别：" << p->GetSex()
				<< "\n\t\t年龄：" << p->GetAge()
				<< "\n\t\t家庭住址：" << p->GetAdr()
				<< "\n\t\t基本职务工资：" << p->GetWage()
				<< "\n\t\t岗位津贴：" << p->GetBounty()
				<< "\n\t\t养老金:" << p->GetPension()
				<< "\n\t\t住房公积金：" << p->GetHousingFund()
				<< "\n\t\t所得税：" << p->GetTax()
				<< "\n\t\t医疗保险：" << p->GetInsurance()
				<< "\n\t\t实际收入：" << p->GetIncome() << endl;
			cout << "\n\n\t\t请输入修改的数据：\n\t\t编号：";
			cin >> id;
			p->SetId(id);
			cout << "\t\t姓名";
			cin >> name;
			p->SetName(name);
			cout << "\t\t性别：";
			cin >> sex;
			p->SetSex(sex);
			cout << "\t\t年龄：";
			cin >> age;
			p->SetAge(age);
			cout << "\t\t家庭住址：";
			cin >> adr;
			p->SetAdr(adr);
			cout << "\t\t基本职务工资：";
			cin >> wage;
			p->SetWage(wage);
			cout << "\t\t岗位津贴";
			cin >> bounty;
			p->SetBounty(bounty);
			cout << "\t\t养老金:";
			cin >> pension;
			p->SetPension(pension);
			cout << "\t\t住房公积金:";
			cin >> housingFund;
			p->SetHousingFund(housingFund);
			cout << "\t\t所得税:";
			cin >> tax;
			p->SetTax(tax);
			cout <<"\t\t医疗保险:";
			cin >> insurance;
			p->SetInsurance(insurance);
			cout << "\n\t\t编号：" << p->GetId()
				<< "\n\t\t姓名：" << p->GetName()
				<< "\n\t\t性别：" << p->GetSex()
				<< "\n\t\t年龄：" << p->GetAge()
				<< "\n\t\t家庭住址：" << p->GetAdr()
				<< "\n\t\t基本职务工资：" << p->GetWage()
				<< "\n\t\t岗位津贴：" << p->GetBounty()
				<< "\n\t\t养老金:" << p->GetPension()
				<< "\n\t\t住房公积金：" << p->GetHousingFund()
				<< "\n\t\t所得税：" << p->GetTax()
				<< "\n\t\t医疗保险：" << p->GetInsurance()
				<< "\n\t\t实际收入：" << p->GetIncome()
				<< "\n\t\t修改成功！" << endl;
			p->income = p->GetWage() + p->GetBounty() - p->GetPension() - p->GetHousingFund() - p->GetTax() - p->GetInsurance();
			return;
		}
		l++;
	}
	if (l >= Length(L) && p->GetId() != id)//索引完链表未找到
	{
		cout << "\n\t\t表中没有该职工！";
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
		cout << "\t\t这是空表！！！";
		return;
	}
	cout << "\n\t\t请输入要修改的职工id:";
	cin >> id;
	while (p->next != NULL)
	{
		p = p->next;
		if (p->GetId() == id)
		{
			cout << "\n\t\t编号：" << p->GetId()
				<< "\n\t\t姓名：" << p->GetName()
				<< "\n\t\t性别：" << p->GetSex()
				<< "\n\t\t年龄：" << p->GetAge()
				<< "\n\t\t家庭住址：" << p->GetAdr()
				<< "\n\t\t基本职务工资：" << p->GetWage()
				<< "\n\t\t奖金：" << p->GetReward()
				<< "\n\t\t所得税：" << p->GetTax()
				<< "\n\t\t实发工资:" << p->GetIncome() << endl;
			cout << "\n\n\t\t请输入修改的数据：\n\t\t编号：";
			cin >> id;
			p->SetId(id);
			cout << "\t\t姓名";
			cin >> name;
			p->SetName(name);
			cout << "\t\t性别：";
			cin >> sex;
			p->SetSex(sex);
			cout << "\t\t年龄：";
			cin >> age;
			p->SetAge(age);
			cout << "\t\t家庭住址：";
			cin >> adr;
			p->SetAdr(adr);
			cout << "\t\t基本职务工资：";
			cin >> wage;
			p->SetWage(wage);
			cout << "\t\t奖金";
			cin >> reward;
			p->SetReward(reward);
			cout << "\t\t所得税:";
			cin >> tax;
			cout << "\n\n\t\t编号：" << p->GetId()
				<< "\n\t\t姓名：" << p->GetName()
				<< "\n\t\t性别：" << p->GetSex()
				<< "\n\t\t年龄：" << p->GetAge()
				<< "\n\t\t家庭住址：" << p->GetAdr()
				<< "\n\t\t基本职务工资：" << p->GetWage()
				<< "\n\t\t奖金：" << p->GetReward()
				<< "\n\t\t所得税：" << p->GetTax()
				<< "\n\t\t实发工资:" << p->GetIncome() << endl;
			CountIncome(T);
			return;
		}
		l++;
	}
	if (l >= Length(T) && p->GetId() != id)//索引完链表未找到
	{
		cout << "\n\t\t表中没有该职工！";
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
		tp->next = p1->next;
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
		tp->next = p1->next;
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
	int option;
	string id, name;
	PerStuff *p = L;

	if (IsEmpty(L))
	{
		cout << "\n\n\t\t请先输入职工信息！\n";

		return;
	}

	printf("\t\t1.按工号查找\n\t\t2.按姓名查找\n");
	cout << "\t\toption:";
	cin >> option;

	if (option == 1)
	{
		printf("\t\t工号：");
		cin >> id;

		while (p->next != NULL)
		{
			if (p->next->GetId() == id)
			{
				p = p->next;

				cout << "=================================================\n"
					<< "\t\t工号：" << p->GetId() << endl
					<< "\t\t姓名：" << p->GetName() << endl
					<< "\t\t性别：" << p->GetSex() << endl
					<< "\t\t年龄：" << p->GetAge() << endl
					<< "\t\t家庭住址：" << p->GetAdr() << endl
					<< "\t\t基本职务工资：" << p->GetWage() << endl
					<< "\t\t岗位津贴：" << p->GetBounty() << endl
					<< "\t\t养老金：" << p->GetPension() << endl
					<< "\t\t住房公积金：" << p->GetHousingFund() << endl
					<< "\t\t所得税：" << p->GetTax() << endl
					<< "\t\t医疗保险：" << p->GetInsurance() << endl
					<< "\t\t实发工资：" << p->GetIncome() << endl
					<< "=================================================\n"
					<< endl;

				option += 2;
			}

			if (option < 2)
			{
				printf("\t\t不存在该员工\n");

				break;
			}
		}
	}

	if (option == 2)
	{
		printf("姓名：");
		cin >> name;

		while (p->next != NULL)
		{
			if (p->next->GetName() == name)
			{
				p = p->next;

				cout << "=================================================\n"
					<< "\t\t工号：" << p->GetId() << endl
					<< "\t\t姓名：" << p->GetName() << endl
					<< "\t\t性别：" << p->GetSex() << endl
					<< "\t\t年龄：" << p->GetAge() << endl
					<< "\t\t家庭住址：" << p->GetAdr() << endl
					<< "\t\t基本职务工资：" << p->GetWage() << endl
					<< "\t\t岗位津贴：" << p->GetBounty() << endl
					<< "\t\t养老金：" << p->GetPension() << endl
					<< "\t\t住房公积金：" << p->GetHousingFund() << endl
					<< "\t\t所得税：" << p->GetTax() << endl
					<< "\t\t医疗保险：" << p->GetInsurance() << endl
					<< "\t\t实发工资：" << p->GetIncome() << endl
					<< "=================================================\n"
					<< endl;

				option += 1;
			}

			if (option < 2)
			{
				printf("\t\t不存在该员工\n");
				
				break;
			}
		}
	}
}

//搜索TL
void List::Search(TList &T)
{
	int option;
	string id, name;
	TempStuff *p = T;

	if (IsEmpty(T))
	{
		cout << "\n\n\t\t请先输入职工信息！\n";

		return;
	}

	printf("\t\t1.按工号查找\n\t\t2.按姓名查找\n");
	cout << "\t\toption:";
	cin >> option;

	if (option == 1)
	{
		printf("\t\t工号：");
		cin >> id;

		while (p->next != NULL)
		{
			if (p->next->GetId() == id)
			{
				p = p->next;

				cout << "=================================================\n"
					<< "\t\t工号：" << p->GetId() << endl
					<< "\t\t姓名：" << p->GetName() << endl
					<< "\t\t性别：" << p->GetSex() << endl
					<< "\t\t年龄：" << p->GetAge() << endl
					<< "\t\t家庭住址：" << p->GetAdr() << endl
					<< "\t\t基本职务工资：" << p->GetWage() << endl
					<< "\t\t奖金：" << p->GetReward() 
					<< "\n\t\t所得税：" << p->GetTax()
					<< "\n\t\t实发工资：" << p->GetIncome() << endl
					<< "=================================================\n"
					<< endl;

				option += 2;
			}

			if (option < 3)
			{
				printf("\t\t不存在该员工\n");

				break;
			}
		}
	}

	if (option == 2)
	{
		printf("\t\t姓名：");
		cin >> name;

		while (p->next != NULL)
		{
			if (p->next->GetName() == name)
			{
				p = p->next;

				cout << "=================================================\n"
					<< "\t\t工号：" << p->GetId() << endl
					<< "\t\t姓名：" << p->GetName() << endl
					<< "\t\t性别：" << p->GetSex() << endl
					<< "\t\t年龄：" << p->GetAge() << endl
					<< "\t\t家庭住址：" << p->GetAdr() << endl
					<< "\t\t基本职务工资：" << p->GetWage() << endl
					<< "\t\t\n奖金：" << p->GetReward() << "\n所得税：" << p->GetTax()
					<< "\t\t实发工资：" << p->GetIncome() << endl
					<< "=================================================\n"
					<< endl;

				option += 1;
			}

			if (option < 3)
			{
				printf("\t\t不存在该员工\n");

				break;
			}
		}
	}
}
//清空链表PL
void List::ClearList(PList &L)
{
	while (L->next != NULL)
	{
		PerStuff* p = L;
		p = L->next;
		L->next = p->next;
		free(p);
	}
	if (IsEmpty(L))
		cout << "\t\t清除成功！";
}

//清空链表TL
void List::ClearList(TList &T)
{
	while (T->next != NULL)
	{
		TempStuff* p = T;
		p = T->next;
		T->next= p->next;
		free(p);
	}
	if (IsEmpty(T))
		cout << "\t\t清除成功！";
}

/*
void menu()
{

	cout << "\n*************************************************\n"
		<< "*\t\t\t\t\t\t*\n"
		<< "*\t\t职工工资信息管理系统\t\t*"
		<< "\n*************************************************\n"
		<< "*\t\t\t\t\t\t*\n"
		<< "*\t\t1.输入职工信息\t\t\t*\n"
		<< "*\t\t2.插入职工信息\t\t\t*\n"
		<< "*\t\t3.查询职工信息\t\t\t*\n"
		<< "*\t\t4.修改职工信息\t\t\t*\n"
		<< "*\t\t5.删除职工信息\t\t\t*\n"
		<< "*\t\t6.恢复到本次初始状态\t\t*\n"
		<< "*\t\t7.查看统计\t\t\t*\n"
		<< "*\t\t0.退出\t\t\t\t*\n"
		<< "*\t\t\t\t\t\t*\n"
		<< "*************************************************\n"
		<< endl;
}

bool IsPer(int option)
{
	if (option == 1)
		return true;
	else
		return false;
}

int main()
{
	List L;
	PList p,p1;
	PList t,t1;

	L.InitList_L(p1);
	L.InitList_L(t1);
	L.InitList_L(p);
	L.InitList_L(t);

	int option, i;



	//此处读取数据
	L.OpenFile(p);
	//L.OpenFile(t);


	L.Copy(t, t1);										//备份数据，做恢复使用
	//L.Copy(p, p1);
	while (true)
	{
		menu();

		cout << "\t\toption:";
		cin >> option;

		switch (option)
		{
		case 1:
		case 2:
			printf("\n\t\t1.正式员工\n\t\t2.临时员工\n");
			cout << "\t\toption:";
			cin >> i;

			if (IsPer(i))
				L.Add(p);
			else
				L.Add(t);
			system("cls");
			break;
		case 3:
			printf("\n\t\t1.正式员工\n\t\t2.临时员工\n");
			cout << "\t\toption:";
			cin >> i;

			if (IsPer(i))
				L.Search(p);
			else
				L.Search(t);
			system("pause");
			system("cls");
			break;
		case 4:
			printf("\n\t\t1.正式员工\n\t\t2.临时员工\n");
			cout << "\t\toption:";
			cin >> i;

			if (IsPer(i))
				L.Modify(p);
			else
				L.Modify(t);
			system("pause");
			system("cls");
			break;
		case 5:
			printf("\n\t\t1.正式员工\n\t\t2.临时员工\n");
			cout << "\t\toption:";
			cin >> i;

			if (IsPer(i))
				L.Delete(p);
			else
				L.Delete(t);
			system("pause");
			system("cls");
			break;
		case 6:
			printf("\n\t\t1.正式员工\n\t\t2.临时员工\n");
			cout << "\t\toption:";
			cin >> i;

			if (IsPer(i))
			{
				L.ClearList(p);
				L.Copy(p1, p);
				cout << "\n\t\t恢复成功！";
			}
			else
			{
				L.ClearList(t);
				L.Copy(t1, t);
				cout << "\n\t\t恢复成功！";
			}
			system("pause");
			system("cls");
			break;
		case 7:
			printf("\n\t\t1.正式员工\n\t\t2.临时员工\n");
			cout << "\t\toption:";
			cin >> i;

			if (IsPer(i))
				L.Count(p);
			else
				L.Count(t);
			system("pause");
			system("cls");
			break;
		case 8:
			L.SaveFile(p);
			//L.SaveFile(t);
			break;
		case 0:
			//此处保存数据
			L.SaveFile(p);
			L.SaveFile(t);


			L.DestroyList(p);//销毁p链表
			L.DestroyList(p1);
			L.DestroyList(t);//销毁p链表
			L.DestroyList(t1);
			exit(0);
			break;
		}
	}
	return ERROR;
}*/


int main()
{
	List L;
	PList p, p1;
	TList k, k1;
	L.InitList_L(k);
	L.InitList_L(k1);
	L.InitList_L(p1);
	L.InitList_L(p);
	int i = 0, a = 0;





	do {
		cout << "\n*************************************************\n"
			<< "*\t\t\t\t\t\t*\n"
			<< "*\t\t职工工资信息管理系统\t\t*\n"
			<< "*\t\t\t\t\t\t*\n"
			<< "*\t\t1.正式职工系统\t\t\t*\n"
			<< "*\t\t2.临时职工系统\t\t\t*\n"
			<< "*\t\t0.退出\t\t\t\t*\n"
			<< "*\t\t\t\t\t\t*\n"
			<< "*************************************************\n" << endl;
		cout << "\t\t选择：";
		cin >> i;
		switch (i)
		{
		case 2:
			//此处读入数据到临时职工链表，并返回结果
			L.OpenFile(k);
			L.Copy(k, k1);										//备份数据，做恢复使用
			do {
				cout << "\n*************************************************\n"
					<< "*\t\t\t\t\t\t*\n"
					<< "*\t职工工资信息管理系统(临时职工）\t\t*\n"
					<< "*\t\t\t\t\t\t*\n"
					<< "*\t\t1.输入职工信息\t\t\t*\n"
					<< "*\t\t2.插入职工信息\t\t\t*\n"
					<< "*\t\t3.查询职工信息\t\t\t*\n"
					<< "*\t\t4.修改职工信息\t\t\t*\n"
					<< "*\t\t5.删除职工信息\t\t\t*\n"
					<< "*\t\t6.恢复到本次初始状态\t\t*\n"
					<< "*\t\t7.查看统计\t\t\t*\n"
					<< "*\t\t0.退出\t\t\t\t*\n"
					<< "*\t\t\t\t\t\t*\n"
					<< "*************************************************\n"
					<< endl;
				cout << "\t\t选择：";
				cin >> i;
				switch (i)
				{
				case 1:
					L.Add(k);

					system("cls");
					break;
				case 2:
					L.Add(k);

					system("cls");
					break;
				case 3:
					L.Search(k);
					cout << "\t\t任意键返回";
					cin >> a;
					system("cls");
					break;
				case 4:
					L.Modify(k);
					cout << "\t\t任意键返回";
					cin >> a;
					system("cls");
					break;
				case 5:
					L.Delete(k);
					cout << "\t\t任意键返回";
					cin >> a;
					system("cls");
					break;
				case 6:
					L.ClearList(k);
					L.Copy(k1, k);
					cout << "\n\t\t恢复成功！";
					cout << "\t\t任意键返回";
					cin >> a;
					system("cls");
					break;
				case 7:
					L.Count(k);
					cout << "\t\t任意键返回";
					cin >> a;
					system("cls");
					break;
				}
			} while (i != 0);
			//保存数据
			L.SaveFile(k);
			L.DestroyList(k);//销毁临时链表
			L.DestroyList(k1);
			return ERROR;
			break;
		case 1:
			//此处读入数据到正式职工链表，并返回结果
			L.OpenFile(p);
			L.Copy(p, p1);										//备份数据，做恢复使用

			L.ShowList(p);
			do {
				cout << "\n*************************************************\n"
					<< "*\t\t\t\t\t\t*\n"
					<< "*\t职工工资信息管理系统（正式职工）\t*\n"
					<< "*\t\t\t\t\t\t*\n"
					<< "*\t\t1.输入职工信息\t\t\t*\n"
					<< "*\t\t2.插入职工信息\t\t\t*\n"
					<< "*\t\t3.查询职工信息\t\t\t*\n"
					<< "*\t\t4.修改职工信息\t\t\t*\n"
					<< "*\t\t5.删除职工信息\t\t\t*\n"
					<< "*\t\t6.恢复到本次初始状态\t\t*\n"
					<< "*\t\t7.查看统计\t\t\t*\n"
					<< "*\t\t0.退出\t\t\t\t*\n"
					<< "*\t\t\t\t\t\t*\n"
					<< "*************************************************\n"
					<< endl;
				cout << "\t\t选择：";
				cin >> i;
				switch (i)
				{
				case 1:
					L.Add(p);
					system("cls");
					break;
				case 2:
					L.Add(p);
					system("cls");
					break;
				case 3:
					L.Search(p);
					cout << "\t\t任意键返回";
					cin >> a;
					system("cls");
					break;
				case 4:
					L.Modify(p);
					cout << "\t\t任意键返回";
					cin >> a;
					system("cls");
					break;
				case 5:
					L.Delete(p);
					cout << "\t\t任意键返回";
					cin >> a;
					system("cls");
					break;
				case 6:
					L.ClearList(p);
					L.Copy(p1, p);
					cout << "\n\t\t恢复成功！";
					cout << "\t\t任意键返回";
					cin >> a;
					system("cls");
					break;
				case 7:
					L.Count(p);
					cout << "\t\t任意键返回";
					cin >> a;
					system("cls");
					break;
				}
			} while (i != 0);
			//此处保存p链表数据
			L.SaveFile(p);
			L.DestroyList(p);//销毁p链表
			L.DestroyList(p1);
			return ERROR;
			break;
		}
	} while (i != 0);
}
