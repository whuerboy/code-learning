#pragma once
#ifndef CLIENTMANAGER
#define CLIENTMANAGER
#include<iostream>
#include"Client.h"
using namespace std;
class Clientmanager
{
public:
	Clientmanager();
	int clientNum;
	Client client[100];
	void addClient(Client t);
	int getClientNum();
	void showQuery(string a);//��ѯ
	void showAll();
};
#endif
