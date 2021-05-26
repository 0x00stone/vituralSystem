// vituralSystem.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
using namespace std;

#include <iostream>

#include<stdlib.h>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

#include "File.h"
#include "users.h"
#include "MFD.h"
#include "UFD.h"
#include "helpmenu.cpp"

int mfdcnt = 8; // 用户数
string u_name ="";
int u_id = -1;

void see(string u_name) {
    int addr = -1;
    for (int i = 0; i < mfdcnt; i++) {
        if (mfd[i].u_name == u_name) addr = mfd[i].addr;
    }
    if (addr == -1) { cout << "没有该用户" << endl; }
    else {
        UFD user = ufd[addr];
        cout << "********************用户名" << u_name << "********************\n";
        cout << "文件个数: " << user.cnt << "\t文件打开数: " << user.open_cnt << endl;
        cout << "文件名\t文件状态\t文件权限\t文件内容\n";
        for (int i = 0; i < user.id; i++) {
            File f = user.file[i];
            if (f.exist == 0) 
                continue;
            cout << f.name << "\t";
            if (f.state == 0) 
                cout << "关闭\t\t";
            else 
                cout << "打开\t\t";

            if (f.protect == 1)
                cout << "只执行\t\t";
            else if (f.protect == 2)
                cout << "只读\t\t";
            else if (f.protect == 3)
                cout << "可写\t\t";
            else if (f.protect == 4)
                cout << "可读写\t\t";
            cout << f.content << endl;
        }
    }
}




void login() {
    if (u_name == "" && u_id == -1) {
        cout << "请输入登入用户名称: "; cin >> u_name;
        for (int i = 0; i < mfdcnt; i++) {
            if (mfd[i].u_name == u_name) {
                while (1) {
                    cout << "输入密码：";   
                    string pwd; 
                    cin >> pwd;
                    if (pwd == usrarray[i].pwd)
                    {
                        cout << "密码正确，登入成功！" << endl<<endl<<endl;
                        u_id = mfd[i].addr;
                        break;
                    }
                    else {
                        cout << "密码错误。" << endl;
                    }
                }
            }
        }
        if (u_id == -1) { 
            cout << "没有该用户" << endl; 
            return; 
        }
    }
}


void select() {
    while (1) {
        login();

        cout << u_name << ":~$";

        string str;
        string ops[100];
        int index = 0;
        while (cin >> str) {//string遇到空格会停止
            ops[index++] = str;
            char ch = getchar();//通过getchar()来判断最后输入回车符结束
            if (ch == '\n') break;
        }
        
        if (ops[1] == "help") {
            helpmenu::help(ops[0]);
            select();
        }
        else {
            if (index == 2) {
                if (ops[0] == "create") ufd[u_id].create(ops[1]);
            }
            else if (index == 3)
                if (ops[0] == "create") ufd[u_id].create(ops[1], ops[2]);

            if (ops[0] == "quit") break;
            else if (ops[0] == "ls") see(u_name);
            else if (ops[0] == "logout") { 
                u_name = "";
                u_id = -1;
                login(); 
            }
            else if (ops[0] == "help") 
                helpmenu::menu();
            else if (ops[0] == "delete" || ops[0] == "open" || ops[0] == "close" || ops[0] == "read" || ops[0] == "write") {
                string name;
                if (ops[1] != "") {
                    name = ops[1];
                }
                else {
                    cout << "请输入操作文件名: ";
                    cin >> name;
                }
                int pos = ufd[u_id].Find(name);
                if (pos == -1) continue;
                if (ops[0] == "delete") ufd[u_id].del(pos);
                else if (ops[0] == "open") ufd[u_id].open(pos);
                else if (ops[0] == "close") ufd[u_id].close(pos);
                else if (ops[0] == "read") ufd[u_id].read(pos);
                else if (ops[0] == "write") ufd[u_id].write(pos);

            }
            else {
                select();
            }
        }
        cout << endl;
    }
}



void InitUser() {
    for (int i = 0; i < mfdcnt; i++) {
        mfd[i].u_name = usrarray[i].name;  
        mfd[i].addr = i;
        ufd[i].u_name = usrarray[i].name;
    }
}
int main() {
    cout << "当前用户数: "; 
    cout << mfdcnt << endl;
    cout << "用户最多可以打开的文件数: "; 
    cout << k << endl;
    InitUser();
    helpmenu::menu();

    select();
}