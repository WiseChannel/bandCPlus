#include <iostream>
#include <string>
#include <list>

using namespace std;

class IObserver
{
public:
	virtual void Update(string date) = 0;
};

class IObservable
{
public:
	virtual void Add(IObserver *o) = 0;
	virtual void Remove(IObserver *o) = 0;
	virtual void Notify(string date) = 0;
};

class Group :public IObservable
{
	list<IObserver*> gr;

public:
	virtual void Add(IObserver * o) override
	{
		gr.push_back(o);
	}

	virtual void Remove(IObserver * o) override
	{
		gr.remove(o);
	}

	virtual void Notify(string date) override
	{
		for each (IObserver * o in gr)
			o->Update(date);
	}

};

class Robber :public IObserver
{

public:
	virtual void Update(string date) override
	{
		cout << "Robbing ... " << date << endl;
	}
};

class Malder :public IObserver
{

public:
	virtual void Update(string date) override
	{
		cout << "Scally, come here! ... " << date << endl;
	}
};

class Scally :public IObserver
{

public:
	virtual void Update(string date) override
	{
		cout << "Malder, I'm here! ... " << date << endl;
	}
};

class FBI :public IObserver
{

public:
	virtual void Update(string date) override
	{
		cout << "Got it! Catch them on " << date << "!!!\n";
	}
};

class FBIAgent :public IObserver, public IObservable
{

	list<IObserver*> fbi;
public:
	virtual void Update(string date) override
	{
		cout << "FBI! Robbing on ... " << date << endl;
		Notify(date);
	}

	virtual void Add(IObserver * o) override
	{
		fbi.push_back(o);
	}
	virtual void Remove(IObserver * o) override
	{
		fbi.remove(o);
	}
	virtual void Notify(string date) override
	{
		for each (IObserver * o in fbi)
			o->Update(date);
	}
};

void main()
{
	Group gr;
	Robber * r1 = new Robber;
	Robber * r2 = new Robber;
	Robber * r3 = new Robber;
	Malder * mldr = new Malder;
	Scally * sc = new Scally;
	FBIAgent * agent = new FBIAgent;
	FBI * fbi = new FBI;

	agent->Add(fbi);
	gr.Add(r1);
	gr.Add(r2);
	gr.Add(r3);
	gr.Add(mldr);
	gr.Add(sc);
	gr.Add(agent);
	gr.Notify("22.02.18");


	cout << endl;
	system("pause");
}