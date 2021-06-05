#include<iostream>
#include<fstream> 
#include<windows.h>
#include<cstdio>
#include<cstring>
#include<stdio.h>
#include<synchapi.h>
#include<conio.h>
#include<time.h>
#include<vector> 
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) 
using namespace std;
string ckpf[10001];//仓库的皮肤 
bool jiandang=0;//临时变量 
string nam,pas;
int ckpfs=1;// 仓库的皮肤数量 
void console()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);  
    CONSOLE_SCREEN_BUFFER_INFO bInfo; 
    GetConsoleScreenBufferInfo(hOut, &bInfo );  
    SetConsoleTitle("XACRAFT 1.0 简体中文版"); // 设置窗口的标题
}
string pfd="XZ";//皮肤 
long long jb=100;//金币数量 
int a[20][5][256][2049],hand[20][50],x[20]={0},y[20];
int i,j;
bool kn=0;
char cmmd;
string comd;
int seed;
void color(int corcorcor){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),corcorcor);
}
bool kd(char ccc){
	if(!KEY_DOWN(ccc)) return 0;
	else return 1;
}
int rdm(int aaaaa,int bbbbb){
	return rand()%(bbbbb-aaaaa+1)+aaaaa;
}
string getTime(){
    time_t timep;
    time (&timep);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%m%d",localtime(&timep) );
    return tmp;
}
string GetTime(){
    time_t timep;
    time (&timep);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y%m%d",localtime(&timep) );
    return tmp;
}
void rightLine(string str){
    int i,l,w;
    w=80;
    l=str.length();
    for(i=0;i<80-l;i++)
    cout<<" ";
    cout<<str<<endl;
    return ;
}
void Line(string str){
    int i,l,w;
    w=80;
    l=str.length();
    for(i=0;i<(w-l)/2;i++)
    cout<<" ";
    cout<<str<<endl;
    return ;
}
void line(string str){
    int i,l,w;
    w=80;
    l=str.length();
    for(i=0;i<(w-l)/2;i++)
    cout<<" ";
    cout<<str;
    return ;
}
//逻辑锁部分（始）
bool end_day(){
	string tmp=GetTime(),temp="20210801";
	if(tmp>=temp) return 1;
	else return 0;
}
bool fool_days(){
	string tmp=getTime();
	if(tmp=="0401") return 1;
	else return 0;
} 
//逻辑锁部分（终） 
void Logical_Lock(){
	if(fool_days()){
		system("cls");
		color(252);
		system("cls");
		cout<<endl;
		Line("抱    歉");
		cout<<endl<<endl;
		color(240);
		Line("出于特殊原因，XACRAFT已停止更新，非常抱歉。");
		cmmd=getch();
		int fk=0;
		cout<<fk/fk;
	}
	if(end_day()){
		system("cls");
		color(252);
		system("cls");
		cout<<endl;
		Line("XACRAFT 版本过低");
		cout<<endl<<endl;
		color(240);
		Line("您现在使用的XACRAFT 1.0已于2021年8月1日过期，请更新至最新版本！");
		cmmd=getch();
		int fk=0;
		cout<<fk/fk;
	}
	return ;
}
int print(int cor){
	if(cor==1){
		color(170);//草方块 
		printf("▇");
	}
	else if(cor==2){
		color(34);//树叶 
		printf("▇");
	}
	else if(cor==3){
		color(136);//石头 
		printf("▇");
	}
	else if(cor==4){
		color(102);//泥土 
		printf("▇");
	}
	else if(cor==6){
		color(96);//橡木 
		printf("WO");
	}
	else if(cor==7){
		color(139);//钻石矿石 
		printf("∷");
	}
	else if(cor==8){
		color(142);//黄金矿石 
		printf("∷");
	}else if(cor==9){
		color(207);
		printf("AP");
	}else if(cor==10){
		color(239);
		printf("GA");
	}else {
		color(255);//空气 
		cout<<"  ";
	}
}
void LoginXZ(){
	char c;
	Log:
	system("cls");
	color(14);
	Line("登录XZ账号 --- Login XZ");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	color(7);
	Line("L-登录     M-退出");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	color(10); 
	Line("没有账号？ R-注册");
	color(7);
	c=getch();
	system("cls");
	if(c=='L' || c=='l'){
		ifstream fin("XZ账户.xzdata");
		fin>>nam>>pas;
		fin.close();
		color(14);
		Line("输入密码");
		color(12);
		Line("用户名："+nam);
		color(7);
		string pass1;
		int i=0;
		char ch;
		while ((ch=_getch())!=13)
		{
			pass1+=ch;
			cout<<"*";
		}
		if(pass1!=pas){
			system("cls");
			Line("抱歉！输入密码错误！请重新登录！(三秒钟后返回)");
			Sleep(3000);
			goto Log;
		}
		return ;
	}
	else if(c=='R' || c=='r'){
		color(14);
		Line("注册XZ账号 --- Register XZ");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		color(7);
		Line("G-注册一个XZ账号   H-读取王子逸的行走账号");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		color(10); 
		Line("已有账号？ M-登录");
		color(7);
		c=getch();
		if(c=='M' || c=='m'){
			goto Log;
		}
		else if(c=='H' || c=='h'){
			system("cls");
			color(14);
			Line("读取XZ账号 --- Read XZ");
			color(7);
			Line("使用提示:请将行走建立的“存档.txt”文件复制到您保存的文件根目录下"); 
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			Line("G-读取存档");
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			color(10); 
			Line("已有账号？ M-登录");
			color(7);
			c=getch();
			if(c=='M' || c=='m'){
				goto Log;
			}else if(c=='G' || c=='g'){
				ifstream fin("存档.txt");
				int lllll;
        		fin>>lllll;
         		fin>>lllll;
     		    fin>>nam;
        		fin>>lllll;
        		fin>>nam;
    			fin.close();
				string s1,s2;
    			system("cls");
				color(14);
				Line("设置密码");
				color(7);
				cin>>s1;
				system("cls");
				color(14);
				Line("再输入一次密码");
				color(7);
				cin>>s2;
				if(s1!=s2){
					system("cls");
					Line("抱歉！输入密码错误！请重新注册！(三秒钟后返回)");
					Sleep(3000);
					goto Log;
				}
				pas=s1;
    			return ;
			}else goto Log;
		} 
		else if(c=='G' || c=='g'){
			system("cls");
			color(14);
			Line("设置用户名");
			color(7);
			cin>>nam;
			string s1,s2;
			system("cls");
			color(14);
			Line("设置密码");
			color(7);
			cin>>s1;
			system("cls");
			color(14);
			Line("再输入一次密码");
			color(7);
			cin>>s2;
			if(s1!=s2){
				system("cls");
				Line("抱歉！输入密码错误！请重新注册！(三秒钟后返回)");
				Sleep(3000);
				goto Log;
			}
			pas=s1;
   			return ;
		}
		else goto Log;
	}else if(c=='M' || c=='m'){
		goto Logok;
	}
	else goto Log;
	Logok:;
}
void XZLogin(){
	color(7);
	LoginXZ();
	ofstream fout("XZ账户.xzdata");
	fout<<nam<<endl<<pas;
	fout.close();
	return ;
}
int cangk()
{
    cout<<"\n\n\n\n\n";
    cout<<"\t\t你现在所拥有的皮肤：";
    for(int i=1;i<=ckpfs;i++)
    {
        cout<<ckpfs<<"."<<ckpf[ckpfs]<<"  ";
     } 
     int bixk;
     cin>>bixk;
     pfd=ckpf[ckpfs];
     cout<<"\n\t\t\t\t\t装备成功！";
     Sleep(1000);
     return 1; 
}
int shang()//本市最繁华的商城 
{
    char gm;
    while(1)
    {
        system("cls");
        Line("此部分由极昼工坊制作");
        cout<<"\n\n\n\n\n";
		line("你现在有:");
		cout<<jb<<"jb\n";
        Line("1.行走纪念皮肤  :AW  (99jb) ");
        Line("2.XA系统纪念皮肤:XA  (99jb) ");
        Line("3.MC致敬皮肤    :MC  (99jb)");
        Line("4.首发纪念皮肤  :┳  (666jb)");
        Line("0.退出商城。=_=             ");
        line("您的选择是：                ");
        cin>>gm;
         if(gm=='1'&&jb<99)
         {
            cout<<"\n\t\t\t\t\t买不起！"; 
            Sleep(1000);
         }
         else if(gm=='1') 
         {
            pfd="AW";
            ckpfs++;
            ckpf[ckpfs]="AW";
            jb-=99;

         }

         if(gm=='2'&&jb<99)
         {
            cout<<"\n\t\t\t\t\t买不起！"; 
            Sleep(1000);
         }
            else if(gm=='2') 
         {
            pfd="XA";
            ckpfs++;
            ckpf[ckpfs]="XA";
            jb-=99;
         }
          if(gm=='4'&&jb<666)
         {
            cout<<"\n\t\t\t\t\t买不起！"; 
            Sleep(1000);
         }
         else if(gm=='4') 
         {
            pfd="┳";
            ckpfs++;
            ckpf[ckpfs]="┳";
            jb-=666;
         }

		if(gm=='3'&&jb<99)
         {
            cout<<"\n\t\t\t\t\t买不起！"; 
            Sleep(1000);
         }
         else if(gm=='3') 
         {
            pfd="MC";
            ckpfs++;
            ckpf[ckpfs]="MC";
            jb-=99;

         }
         if(gm=='0')
         {
            system("cls");
            return 1;
         }
    }

}
int nw(int com){
	for(i=0;i<=2047;i++){
		for(j=1;j<=255;j++){
			a[com][1][j][i]=0;
		}
	}
	for(i=1;i<=50;i++) hand[com][i]=0;
	int ke=0;
	cin>>seed;
	srand((unsigned)seed);
	y[com]=1024;
	int top=0,tot=rdm(40,60);
	for(i=0;i<2048;i++){
		if(i==1024) x[com]=tot+1; 
		a[com][1][tot][top]=1;
		a[com][1][tot-1][top]=4;
		a[com][1][tot-2][top]=4;
		a[com][1][tot-3][top]=4;
		for(j=tot-4;j>=0;j--){
			a[com][1][j][top]=3;
		}
		top++;
		int u=rdm(0,10);
		if(u>=9) tot++;
		if(u<=1) tot--;
		if(tot>=256)tot=255;
		if(tot<3) tot=3;
		int uu=rdm(0,8);
		if((uu==6 && i>4 && i<2045 && i!=1023 && i!=1024 && i!=1025 && ke+1<top && seed!=1234567890)||(seed==123456789)){
			ke=top;
			a[com][1][tot+1][top]=6;
			a[com][1][tot+2][top]=6;
			a[com][1][tot+3][top]=6;
			int uuu=rdm(0,3);
			if(uuu==1){
				a[com][1][tot+4][top]=6;
				a[com][1][tot+4][top-3]=2;
				a[com][1][tot+4][top-2]=2;
				a[com][1][tot+4][top-1]=2;
				a[com][1][tot+4][top+1]=2;
				a[com][1][tot+4][top+2]=2;
				a[com][1][tot+4][top+3]=2;
				a[com][1][tot+5][top-3]=2;
				a[com][1][tot+5][top-2]=2;
				a[com][1][tot+5][top]=2;
				a[com][1][tot+5][top-1]=2;
				a[com][1][tot+5][top+1]=2;
				a[com][1][tot+5][top+2]=2;
				a[com][1][tot+5][top+3]=2;
				a[com][1][tot+6][top-2]=2;
				a[com][1][tot+6][top]=2;
				a[com][1][tot+6][top-1]=2;
				a[com][1][tot+6][top+1]=2;
				a[com][1][tot+6][top+2]=2;
				a[com][1][tot+7][top]=2;
				a[com][1][tot+7][top-1]=2;
				a[com][1][tot+7][top+1]=2;
			}else{
				a[com][1][tot+3][top-3]=2;
				a[com][1][tot+3][top-2]=2;
				a[com][1][tot+3][top-1]=2;
				a[com][1][tot+3][top+1]=2;
				a[com][1][tot+3][top+2]=2;
				a[com][1][tot+3][top+3]=2;
				a[com][1][tot+4][top-3]=2;
				a[com][1][tot+4][top-2]=2;
				a[com][1][tot+4][top]=2;
				a[com][1][tot+4][top-1]=2;
				a[com][1][tot+4][top+1]=2;
				a[com][1][tot+4][top+2]=2;
				a[com][1][tot+4][top+3]=2;
				a[com][1][tot+5][top-2]=2;
				a[com][1][tot+5][top]=2;
				a[com][1][tot+5][top-1]=2;
				a[com][1][tot+5][top+1]=2;
				a[com][1][tot+5][top+2]=2;
				a[com][1][tot+6][top]=2;
				a[com][1][tot+6][top-1]=2;
				a[com][1][tot+6][top+1]=2;
			}
		}
	}
	for(i=1;i<=2048;i++){
		for(j=1;j<=16;j++){
			if(a[com][1][j][i]==3){
				int uuu=rdm(1,1000);
				if(uuu<=5){
					a[com][1][j][i]=7;
				}
			}
		}
		for(j=4;j<=32;j++){
			if(a[com][1][j][i]==3){
				int uuu=rdm(1,1000);
				if(uuu<=10){
					a[com][1][j][i]=8;
				}
			}
		}
		for(j=1;j<=256;j++){
			if(a[com][1][j][i]==2){
				int uuu=rdm(1,1000);
				if(uuu<=5){
					int uuuu=rdm(1,1000);
					if(uuuu>200) a[com][1][j][i]=9;
					else a[com][1][j][i]=10;
				}
			}
		}
	}
}
int cun(int com)
{
	while(cmmd!='P' && cmmd!='p'){
		system("cls");
		for(i=min(256,x[com]+10);i>=max(0,x[com]-10);i--){
			for(j=max(y[com]-19,0);j<=min(y[com]+19,2048);j++){
				if(i!=x[com] || j!=y[com]){
					print(a[com][1][i][j]);
				}else{
					color(240);
					cout<<pfd;
				}
			}
			cout<<endl;
		}
		color(7);
		printf(">>状态栏  坐标: x:%d y:%d  ",x[com],y[com]);
		cout<<"后位方块:";
		print(a[com][1][x[com]][y[com]]);
		color(7);
		cout<<"  破坏模式:";
		if(kn){
			cout<<"开启"; 
		} else cout<<"关闭";
		cout<<"  P-退出至标题画面";
		cout<<endl;
		color(7);
		cout<<"\t\t\t      ";
		for(i=1;i<=50;i++){
			if(hand[com][i]>0){
				print(i);
			}
		}
		color(7);
		cout<<endl<<"\t\t\t      ";
		for(i=1;i<=50;i++){
			if(hand[com][i]>0){
				printf("%02d",hand[com][i]);
			}
		}
		cmmd=getch();
		if(cmmd=='/'){
			system("cls");
			color(12);
			Line("命令");
			bool flag=0;
			while(comd!="esc"){	
				color(7);
				cout<<"/";
				cin>>comd;
				if(comd=="tp"){
					cout<<"/tp @s ";
					cin>>i>>j;
					flag=1;
					x[com]=i;
					y[com]=j;
					comd="esc";
				}
				if(!flag){
					color(12);
					cout<<">>语法错误"<<endl;
					color(7);
				}
			}
			comd="?";
		}
		if(cmmd=='W' || cmmd=='w') x[com]++;
		if(cmmd=='S' || cmmd=='s') x[com]--;
		if(cmmd=='A' || cmmd=='a') y[com]--;
		if(cmmd=='D' || cmmd=='d') y[com]++;
		if(cmmd=='J' || cmmd=='j') kn=!kn;
		if(kn){
			if(cmmd=='Y' || cmmd=='y'){
				hand[com][a[com][1][x[com]+1][y[com]-1]]++;
				a[com][1][x[com]+1][y[com]-1]=0;
			}
			if(cmmd=='U' || cmmd=='u'){
				hand[com][a[com][1][x[com]+1][y[com]]]++;
				a[com][1][x[com]+1][y[com]]=0;
			} 
			if(cmmd=='I' || cmmd=='i'){
				hand[com][a[com][1][x[com]+1][y[com]+1]]++;
				a[com][1][x[com]+1][y[com]+1]=0;
			}
			if(cmmd=='H' || cmmd=='h'){
				hand[com][a[com][1][x[com]][y[com]-1]]++;
				a[com][1][x[com]][y[com]-1]=0;
			}
			if(cmmd=='K' || cmmd=='k'){
				hand[com][a[com][1][x[com]][y[com]+1]]++;
				a[com][1][x[com]][y[com]+1]=0;
			}
			if(cmmd=='B' || cmmd=='b'){
				hand[com][a[com][1][x[com]-1][y[com]-1]]++;
				a[com][1][x[com]-1][y[com]-1]=0;
			}
			if(cmmd=='N' || cmmd=='n'){
				hand[com][a[com][1][x[com]-1][y[com]]]++;
				a[com][1][x[com]-1][y[com]]=0;
			}
			if(cmmd=='M' || cmmd=='m'){
				hand[com][a[com][1][x[com]-1][y[com]+1]]++;
				a[com][1][x[com]-1][y[com]+1]=0;
			}
		}
		color(0);
	}
    return 0;
}
void fm(){
	while(cmmd!='G' && cmmd!='g'){
		system("cls");
		color(240);
		system("cls");
		cout<<endl;
		Line("XACRAFT 1.0");
		cout<<endl<<endl;
		color(249);
		Line(" 开发组团队\n"); 
		color(240);
		Line("创意/营销/策划    王子逸");
		Line("核心程序/外观设计 沙*安");
		Line("小部分思路        冮  欢"); 
		cout<<endl;
		color(249);
		Line(" 特别鸣谢名单\n"); 
		color(240);
		Line(" 注：以上排名不分先后\n");
		Line("吴庞茂旭  武 建 豪  刘 英 杰  杜 文 博  侯 平 仄");
		Line("欧阳语聪  张    帆  赵 逸 凡  赵 奕 帆  陈    曦");
		Line("许 金 夫  江 齐 悦  王 文 博  宣 海 宁  王 子 耀");
		Line("陈 喆 鹏  包 涵 宇  潘 孝 宇");
		cout<<endl; 
		color(252);
		Line("注：所有在鸣谢名单上的人可以申请移出，达到光能级别及以上的人可以申请加入。");
		cout<<endl;
		color(240);
		Line("[1/2]");
		Line("G-切换下一页");
		cmmd=getch();
	}
	while(cmmd!='S' && cmmd!='s'){
		system("cls");
		color(240);
		system("cls");
		cout<<endl;
		Line("XACRAFT 1.0");
		cout<<endl<<endl;
		color(249);
		Line(" 本版本更新内容\n"); 
		color(240);
		Line("这是XACRAFT的第1个版本");
		Line("本版本更新内容如下：");
		cout<<endl;
		Line("随机地形生成");
		Line("破坏方块统计");
		Line("中心商城");
		cout<<endl;
		color(252);
		Line(" XACRAFT开发组团队预祝您游玩愉快！\n");
		color(249);
		Line(" 版权声明\n"); 
		color(240);
		Line("本游戏由兴安科技与极昼游戏工坊联合制作");
		Line("版权所有 未经授权严禁转载 保留所有权利");
		Line("Copyright XAscience & JizhouGameWorkshop All Rights Reserved"); 
		cout<<endl; 
		color(240);
		Line("[2/2]");
		Line("S-开始游戏");
		cmmd=getch();
	}
	while(cmmd!='P' && cmmd!='p'){
		system("cls");
		color(240);
		system("cls");
		if(nam.empty()) rightLine("未登录XZ  L-登录");
		else rightLine(nam+",欢迎您！");
		color(240);
		cout<<"                ▇  ▇   ▇   ▇▇▇ ▇▇▇   ▇   ▇▇▇ ▇▇▇               "<<endl;
		cout<<"                ▇  ▇ ▇  ▇ ▇     ▇  ▇ ▇  ▇ ▇       ▇                 "<<endl;
		cout<<"                  ▇   ▇▇▇ ▇     ▇▇▇ ▇▇▇ ▇▇▇   ▇                 "<<endl;
		cout<<"                ▇  ▇ ▇  ▇ ▇     ▇▇   ▇  ▇ ▇       ▇                 "<<endl;
		cout<<"                ▇  ▇ ▇  ▇ ▇▇▇ ▇  ▇ ▇  ▇ ▇       ▇                 "<<endl;
		cout<<"                                                                               "<<endl;
		cout<<"                                                                               "<<endl;
		cout<<"                                                                               "<<endl;
		cout<<"                                                                               "<<endl;
		cout<<"                           ";
		color(143);
		cout<<"       F-单人游戏       ";
		color(240);
		cout<<"                            "<<endl; 
		cout<<"                                                                               "<<endl;
		cout<<"                           ";
		color(143);
		cout<<"       G-多人游戏       ";
		color(240);
		cout<<"                            "<<endl; 
		cout<<"                                                                               "<<endl;
		cout<<"                           ";
		color(143);
		cout<<"       H-中心商城       ";
		color(240);
		cout<<"                            "<<endl; 
		cout<<"                                                                               "<<endl;
		cout<<"                           ";
		color(143);
		cout<<"  J-教程  ";
		color(240);
		cout<<"    "; 
		color(143);
		cout<<"  P-退出  ";
		color(240);
		cout<<"                            "<<endl; 
		cout<<"                                                                               "<<endl;
		cout<<"                                                                               "<<endl;
		cout<<"                                                                               "<<endl;
		cout<<"                                                                               "<<endl;
		cout<<"                                                                               "<<endl;
		cout<<"                                                                               "<<endl;
		cout<<" XACRAFT 1.0        Copyright XAscience & JizhouGameWorkshop Do not distribute!";
		cmmd=getch();
		if(cmmd=='F' || cmmd=='f'){
		
			if(jiandang){
				color(7);
				cun(1);
				cmmd='?';
			}else{
				system("cls");
				color(252);
				system("cls");
				Line("我的存档");
				color(240);
				Line("新的世界"); 
				cout<<endl<<endl;
				line("输入种子: ");
				color(7);
				nw(1);
				cun(1);
				cmmd='?';
				jiandang=1;
			}
			
		}
		if(cmmd=='G' || cmmd=='g'){
			system("cls");
			color(252);
			system("cls");
			Line("非常抱歉");
			cout<<endl;
			color(240);
			cout<<"     因为XACRAFT开发组未能掌握联机游戏的技术，所以暂时不能体验多人游戏，给 "<<endl;
			cout<<" 您带来不便，敬请谅解！";
			cout<<endl<<endl<<endl<<endl;
			Line("[按任意键退出]");
			cmmd=getch();
			cmmd='?';
		}
		if(cmmd=='H' || cmmd=='h') shang();
		if(cmmd=='L' || cmmd=='l') XZLogin();
		if(cmmd=='J' || cmmd=='j'){
			system("cls");
			color(240);
			system("cls");
			Line("新手教程");
			cout<<endl;
			color(240);
			Line(" 注：以下键位操作大小写皆可\n");
			Line(" W-上移一格 A-左移一格 S-下移一格 D-右移一格\n");
			Line(" J-打开/关闭破坏模式\n");
			Line(" YUIHKBNM 依次为：破坏{左上角,上方,右上角,左边,右边,左下角,下方,右下角}的方块\n");
			Line(" 游戏区域的正下方会统计您破坏的方块\n");
			cout<<endl<<endl<<endl<<endl;
			Line("[按任意键退出]");
			cmmd=getch();
			cmmd='?';
		}
		if(cmmd=='#'){
			system("cls");
			color(12);
			system("cls");
			Line("除错模式");
			cout<<endl;
			color(7);
			Line("注：本模式仅供XACRAFT内部人员使用，如果您不是XACRAFT技术人员，在使用XACRAFT除错模式后因操作不当出现问题，兴安科技和极昼工坊将不承担任何责任。");
			cout<<endl<<endl;
			cout<<"方块外观:";
			for(i=1;i<=35;i++){
				print(i);
				color(7);
			}
			color(7);
			cout<<endl<<"方块UI值:";
			for(i=1;i<=35;i++){
				if(i%2==1) color(9);
				printf("%02d",i);
				color(7);
			}
			cout<<endl<<endl<<endl;
			Line("[按任意键退出]");
			cmmd=getch();
			cmmd='?';
		}
	}
	Sleep(1000);
	return ;
}
int main(){
	console();
	Logical_Lock();
	fm();
	return 0;
}
