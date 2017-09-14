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
}TempStuff,*TList;//*TList为头结点

class List {
public:
	void CreateList_L(PList &L);//创建PL链表  传入表头 
	void CreateList_L(TList &T);//创建TL链表  传入表头
	void Add(PList &L);//添加节点
	void Add(TList &T);//添加节点
	void Delete(PList &L);//删除节点
	void Delete(TList &T);//删除节点
	void Modify(PList &L);//修改链表
	void Modify(TList &T);//修改链表
	void Search(PList &L);//搜索PL
	void Search(TList &T);//搜索TL
	bool IsEmpty(PList &L);//是否为空链表
	bool IsEmpty(TList &T);//是否为空链表
	void Copy(PList &L,PList &L1);//复制PL链表           
	void Copy(TList &T,TList &T1);//复制TL链表          
	int Length(PList &L);//长度
	int Length(TList &T);//长度
	void ShowList(PList &L);//打印Lp 链表
	void ShowList(TList &T);//打印Tp 链表
	void Count(PList &L);//
	void Count(TList &T);//
};

//创建PL链表
void List::CreateList_L(PList &L)//输入头结点参数，节点个数
{
	string id="0";//编号
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

	PerStuff *p = NULL;
	L = new PerStuff();//初始化头结点
	cout << "请输入节点数：";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		p = new PerStuff();//生成新节点
		cout << "\n请输入第"<<i+1<<"个节点信息：\n" << "编号：";
		cin>>id;
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
		p->next = L->next;//为空
		L->next = p;//逆序插入
	}
}

//创TL链表
void List::CreateList_L(TList &L)//输入头结点参数，节点个数
{
	string id= "0";//编号
	string name = "0";//姓名
	string sex= "0";//性别
	int age=0;//年龄
	string adr = "0";//家庭住址
	double wage=0;//基本职务工资
	double reward=0;//奖金
	double tax=0;//所得税
	double income=0;//实发工资
	int n = 0;

	TempStuff *p = NULL;
	L = new TempStuff();//初始化头结点
	cout << "请输入节点数：";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		p = new TempStuff();//生成新节点
		cout << "\n请输入第" << i + 1 << "个节点信息：\n" << "编号：";
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

		p->next = L->next;//为空
		L->next = p;//逆序插入
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

	PerStuff *p = L->next;
	int l=1;//计数器
	cout << "\n请输入要修改的职工id:";
	cin >> id;
	while (p->GetId() != id&&p->next!=NULL)
	{
		p = p->next;
		l++;
	}
	if (l >= Length(L)&&p->GetId()!=id)//索引完链表未找到
	{
		cout << "\n表中没有该职工！";
	}
	if (l <= Length(L) && p->GetId() == id)
	{
		cout << "\n编号：" << p->GetId() << "\n姓名：" << p->GetName() << "\n性别：" << p->GetSex()
			<< "\n年龄：" << p->GetAge()<< "\n家庭住址：" << p->GetAdr() << "\n基本职务工资：" << p->GetWage()
			<< "\n岗位津贴：" <<"\n养老金:"<<p->GetPension()<< "\n住房公积金：" << p->GetHousingFund()
			<< "\n所得税：" << p->GetTax() << "\n医疗保险：" << p->GetInsurance() << "\n实际收入：" << p->GetIncome();
		cout<< "\n\n请输入修改的数据：\n编号：";
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
	}
}

//修改   
void List::Modify(TList &T)//输入表头，id
{
	string id = "-1";//编号
	string name = "0";//姓名
	string sex = "0";//性别
	int age;//年龄
	string adr = "0";//家庭住址
	double wage;//基本职务工资
	double reward;//奖金
	double tax;//所得税


	TempStuff *p = T->next;
	int l = 1;//计数器
	cout << "\n请输入要修改的职工id:";
	cin >> id;
	while (p->GetId() != id&&p->next!=NULL)
	{
		p = p->next;
		l++;
	}
	if (l >= Length(T)&&p->GetId()!=id)
	{
		cout << "\n表中没有该职工！";
	}
	if(l<=Length(T)&&p->GetId()==id)
	{
		cout << "\n编号：" << p->GetId() << "\n姓名：" << p->GetName() << "\n性别：" << p->GetSex()
			<< "\n年龄：" << p->GetAge() << "\n家庭住址：" << p->GetAdr() << "\n基本职务工资：" << p->GetWage()
			<< "\n奖金：" << p->GetReward() << "\n所得税：" << p->GetTax() << "\n实发工资:" << p->GetIncome();
		cout << "\n\n请输入修改的数据:\n编号：";
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
		cout << "\n编号：" << p->GetId() << "\n姓名：" << p->GetName() << "\n性别：" << p->GetSex()
			<< "\n年龄：" << p->GetAge() << "\n家庭住址：" << p->GetAdr() << "\n基本职务工资：" << p->GetWage()
			<< "\n奖金：" << p->GetReward() << "\n所得税：" << p->GetTax() << "\n实发工资:" << p->GetIncome() << "\n修改成功！";
	}
}

//Tp  判断
bool List::IsEmpty(TList &T)
{
	if (T->next == NULL)
	{
		cout << "这是空表！";
		return false;
	}
	else
	{
		return true;
	}
}

//Lp  判断
bool List::IsEmpty(PList &L)
{
	if (L->next == NULL)
	{
		cout << "这是空表！";
		return false;
	}
	else
	{
		return true;
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
	if (p->next==NULL)
	{
		cout << "\n这是空链表！";
	}
	while (p->next!=NULL)
	{
		p = p->next;
		cout << "\n\n编号：" << p->GetId() << "\n姓名：" << p->GetName() << "\n性别：" << p->GetSex()
			<< "\n年龄：" << p->GetAge() << "\n家庭住址：" << p->GetAdr() << "\n基本职务工资：" << p->GetWage()
			<< "\n岗位津贴：" <<"\n养老金:"<<p->GetPension()<< "\n住房公积金：" << p->GetHousingFund()
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

int main()
{
	/*cout<< "*************************************************\n"
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
		<< endl;*/
	List L;
	PList p, p1 = new PerStuff();
	int i = 0;

	L.CreateList_L(p);
	
	
//	L.Modify(t);
	L.Copy(p,p1);
	L.ShowList(p1);

	cin >> i;
	return ERROR;
}
