#pragma once
#ifndef ADMINMANAGER
#define ADMINMANAGER
#include <iostream>
#include "Admin.h"
using namespace std;
class AdminManager
{
public:
	AdminManager();
	int adminNum;
	Admin admin[100];
	void addAdmin(string, string);
	int getAdminNum();
	int checkPassword(string, string);
};
#endif
