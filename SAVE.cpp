#include<iostream>
#include<windows.h>

using namespace std;

string getpath(){
	char un[256] = {0};
	DWORD size = 256;
 	string path1 = "C:\\Users\\", path2 = "\\AppData\\Local\\";
 	string path;
	if (GetUserName(un,&size))
		path = path1 + un + path2;
	else 
		path = path1 + "Public" + path2;
	return path;
}

void io(char &sel, string path){
	cout << "保存(I)或提取(O)？这将删除原有文件：";
	cin >> sel;
	
	//输入i 
	if(((sel == 'i')||(sel == 'I'))){
		//改名原游戏文件
		string com1 = "ren " + path + "UNDERTALE" + " UT"; 
		
		if(system(com1.c_str()) == 0){//改名成功 
			//保存至SAVE 
			system("rd /s /q SAVE");
			string com2 = string("xcopy ") + path + "UT" + string(" SAVE\\ "); 
			system(com2.c_str());
			sel = 0;
			
			//改回原游戏文件
			string com3 = "ren " + path + "UT" + " UNDERTALE";
			system(com3.c_str());
		}
		else{
			cout << "未找到游戏存档！"  << endl;
		} 
	}
	
	//输入o 
	else if((sel == 'o')||(sel == 'O')){
		//改名save
		string com1 = "ren SAVE s"; 
		
		//改名成功 
		if(system(com1.c_str()) == 0) {
			//提取至游戏 
			system(string("rd /s /q " + path + "UNDERTALE").c_str());
			string command = string("xcopy ") + " s " + path + "UNDERTALE\\"; 
			system(command.c_str());
			sel = 0;
			
			//改回save
			system("ren s SAVE");
		}
		//改名失败 
		else{
			cout << "找不到SAVE文件夹！" << endl; 
		}
	}
	else{
		cout << "无效输入！" << endl; 
	}
}

int main(){
	string path = getpath();
	char sel = 1;
	
	cout << "使用时请关闭游戏，以免造成不必要的错误"  << endl; 
	
	while(sel != 0){
		io(sel, path);
	}
	system("pause");
	return 0;
	
}
