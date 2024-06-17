#include <bits/stdc++.h>
#include <ctime>
using namespace std;
int Win,Lose,Collection[5];
int order=1;
int resist[3];
int save[6];
bool evade,crit;
struct Stat{
	int MAXHP,HP,ATK,DEF,Accuracy,Dodge,CritRate,CritDMG,Silence,Potential;};
int RanDom(int min,int max){
    return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));}
int Size(int x){
	int cnt=0;
	while(x){
		x/=10; cnt++;}
	return cnt;}
void Format(int space){
	while(space--) cout<<" ";}
void Contribute(int &temp, int &PT){
	cin>>temp; 
	if(temp<0) temp=0;
	if(temp>PT) temp=PT;}
int main (){
	srand(time(NULL));
	map<int,int> Master;
	for(int i=1;i<=12;i++) Master[i]=i;
	map <int,string> Skill;
	Skill[1]="Crack";
	Skill[2]="Agility";
	Skill[3]="Violence";
	Skill[4]="Counter";
	Skill[5]="Accumulate";
	Skill[6]="DOT";
	Skill[7]="Smash";
	Skill[8]="Debuff";
	Skill[9]="Lifesteal";
	Skill[10]="Healing";
	Skill[11]="Invincible";
	Skill[12]="Fatal";
	Stat Main,Enemy;
	Main.MAXHP=6000;
	Main.HP=Main.MAXHP;
	Main.ATK=300;
	Main.DEF=100;
	Main.Accuracy=5;
	Main.Dodge=5;
	Main.CritRate=10;
	Main.CritDMG=200;
	Main.Potential=100;
	cout<<"                                              TRO CHOI DAU TRUONG";
	int SoTranDau;
	cout<<"\nNhap so tran dau (mot con so nguyen): "; cin>>SoTranDau;
	while(SoTranDau<1) {
		cout<<"So tran dau khong hop le , vui long nhap lai mot so nguyen lon hon 0: ";
		cin>>SoTranDau;}
	for(int i=1;i<=SoTranDau;i++){
		Enemy.MAXHP=RanDom(int(Main.HP*70/100+RanDom(30,50)*(i-1)*20),int(Main.HP*110/100+RanDom(30,50)*(i-1)*20));
		Enemy.HP=Enemy.MAXHP;
		Enemy.ATK=RanDom(int((Main.ATK*RanDom(60,100)/100+Main.DEF)*110/100+RanDom(30,50)*(i-1)*1.1),int((Main.ATK*RanDom(60,100)/100+Main.DEF)*150/100+RanDom(30,50)*(i-1)*1.1));
		Enemy.DEF=RanDom(int((Main.ATK+Main.HP/20)*(min(30,10+i))/100+RanDom(min(10+i,20),40+i*2)*i),int((Main.ATK+Main.HP/20)*(min(80,40+i*2))/100+RanDom(min(10+i,20),40+i*2)*i));
		Enemy.Accuracy=RanDom(int(i+min(45,15+i)/100*Main.Dodge),int(i*2+10+(min(95,40+i*4))/100*Main.Dodge));
		Enemy.Dodge=RanDom(1,10+i*5);
		Enemy.CritRate=RanDom(i*2,int(min(100,int(10+float(Main.CritRate)*0.1+i*6))));
		Enemy.CritDMG=200;
		Enemy.Silence=RanDom(1,min(50,10+i*2));
		Main.HP=Main.MAXHP;
		if(i<5) {
			Enemy.MAXHP-=200;
			Enemy.HP=Enemy.MAXHP;
			Enemy.ATK*=0.7;}
		if(i!=1) cout<<endl;
		cout<<"Phan bo "<<Main.Potential<<" diem thien phu vao chi so nhan vat: ";
		int PT=Main.Potential; int temp;
		while(true){
		cout<<"\n1.Potential (He so 0.5): "; 
		Contribute(temp,PT);
		Main.Potential+=temp*0.5; PT-=temp;
		if(PT==0){
			cout<<"2.HP(He so 20): 0";
			cout<<"\n3.ATK(He so 1): 0";
			cout<<"\n4.DEF(He so 1): 0";
			cout<<"\n5.Accuracy(He so 0.2): 0";
			cout<<"\n6.Dodge(He so 0.2): 0";
			cout<<"\n7.CritRate(He so 0.2): 0";
			cout<<"\n8.CritDMG(He so 1): 0";
			break;}
		cout<<"2.HP(He so 20): "; 
		Contribute(temp,PT);
		Main.MAXHP+=temp*20; Main.HP=Main.MAXHP; PT-=temp;
		if(PT==0){
			cout<<"3.ATK(He so 1): 0";
			cout<<"\n4.DEF(He so 1): 0";
			cout<<"\n5.Accuracy(He so 0.2): 0";
			cout<<"\n6.Dodge(He so 0.2): 0";
			cout<<"\n7.CritRate(He so 0.2): 0";
			cout<<"\n8.CritDMG(He so 1): 0";
			break;}
		cout<<"3.ATK(He so 1): ";
		Contribute(temp,PT);
		Main.ATK+=temp; PT-=temp;
		if(PT==0){
			cout<<"4.DEF(He so 1): 0";
			cout<<"\n5.Accuracy(He so 0.2): 0";
			cout<<"\n6.Dodge(He so 0.2): 0";
			cout<<"\n7.CritRate(He so 0.2): 0";
			cout<<"\n8.CritDMG(He so 1): 0";
			break;}
		cout<<"4.DEF(He so 1): ";
		Contribute(temp,PT);
		Main.DEF+=temp; PT-=temp;
		if(PT==0){
			cout<<"5.Accuracy(He so 0.2): 0";
			cout<<"\n6.Dodge(He so 0.2): 0";
			cout<<"\n7.CritRate(He so 0.2): 0";
			cout<<"\n8.CritDMG(He so 1): 0";
			break;}
		cout<<"5.Accuracy(He so 0.2): ";
		Contribute(temp,PT);
		Main.Accuracy+=temp*0.2; PT-=temp;
		if(PT==0){
			cout<<"6.Dodge(He so 0.2): 0";
			cout<<"\n7.CritRate(He so 0.2): 0";
			cout<<"\n8.CritDMG(He so 1): 0";
			break;}
		cout<<"6.Dodge(He so 0.2): ";
		Contribute(temp,PT);
		Main.Dodge+=temp*0.2; PT-=temp;
		if(PT==0){
			cout<<"7.CritRate(He so 0.2): 0";
			cout<<"\n8.CritDMG(He so 1): 0";
			break;}	
		cout<<"7.CritRate(He so 0.2): ";
		Contribute(temp,PT);
		Main.CritRate+=temp*0.2; PT-=temp;
		if(PT==0){
			cout<<"8.CritDMG(He so 1): 0";
			break;}					
		cout<<"8.CritDMG(He so 1): "<<PT;
		Main.CritDMG+=PT; break;}
		if(Collection[4]==0) {
		cout<<"\nChon 1 trong 3 ky nang sau (toi da 4 ky nang): ";
		int X[4]={0};
		int Roll[4]={0};
		for(int i=1;i<=3;i++) {
			X[i]=RanDom(1,12);
			Roll[i]=Master[X[i]];
			if(Roll[i]==0) i--;
			Master[X[i]]=0;}
		for(int i=1;i<=3;i++) {
			Master[X[i]]=X[i];
			cout<<"\n"<<i<<"."<<Skill[Roll[i]];}
		cout<<"\n4.Bo luot chon nay";
		int LuaChon;
		cout<<"\nBan chon: "; cin>>LuaChon;
		while(LuaChon<1||LuaChon>4) {
			cout<<"Cau lenh khong hop le , vui long nhap lai 1 so nguyen tu 1 den 3: ";
			cin>>LuaChon;}
		while(true){
		if(LuaChon==4) break;
		Collection[order++]=Roll[LuaChon];
		Master[Roll[LuaChon]]=0;
		break;}}
		else {
			int A=RanDom(10,20);
			cout<<"\nVi ban da co du bo ky nang , ban duoc cong "<<A<<" diem thien phu.\n";
			Main.Potential+=A;}
		cout<<"Tran dau thu "<<i<<": ";
		cout<<"\nMain:";Format(25);cout<<"Enemy:";
		cout<<"\nHP: "<<Main.HP;Format(30-4-Size(Main.HP));cout<<"HP: "<<Enemy.HP;
		cout<<"\nATK: "<<Main.ATK;Format(30-5-Size(Main.ATK));cout<<"ATK: "<<Enemy.ATK;
		cout<<"\nDEF: "<<Main.DEF;Format(30-5-Size(Main.DEF));cout<<"DEF: "<<Enemy.DEF;
		cout<<"\nAccuracy: "<<Main.Accuracy;Format(30-10-Size(Main.Accuracy));cout<<"Accuracy: "<<Enemy.Accuracy;
		cout<<"\nDodge: "<<Main.Dodge;Format(30-7-Size(Main.Dodge));cout<<"Dodge: "<<Enemy.Dodge;
		cout<<"\nCritRate: "<<Main.CritRate;Format(30-10-Size(Main.CritRate));cout<<"CritRate: "<<Enemy.CritRate;
		cout<<"\nCritDMG: "<<Main.CritDMG;Format(30-9-Size(Main.CritDMG));cout<<"CritDMG: "<<Enemy.CritDMG;
		cout<<"\nPotential: "<<Main.Potential;Format(30-11-Size(Main.Potential));cout<<"Silence: "<<Enemy.Silence;
		int Round=1;
		save[3]=Main.ATK;
		save[4]=Main.CritDMG;
		save[5]=Main.DEF;
		int dot=0;
		while(true){
			cout<<"\n";system("pause");
			cout<<"Luot "<<Round++<<": ";
			int ST1=0,ST2=0,ST3=0,ST4=0;save[1]=Main.HP; save[2]=Enemy.HP; 
			if((Collection[1]==11||Collection[2]==11||Collection[3]==11||Collection[4]==11)&&(Round==1||Round==2||(RanDom(1,2)==1&&Round==3)||(RanDom(1,2)==1&&Round==4))){
				cout<<"\nInvincible , khong nhan sat thuong."; ST1=0;}
			else{
			if(RanDom(1,100)<=Main.Dodge-Enemy.Accuracy) evade=1;
			if(RanDom(1,100)<=Enemy.CritRate)             crit=1;
			if(evade&&crit) {
				cout<<"\nDoi phuong ra 1 don chi mang vao dau ban nhung ban lai ne duoc , sat thuong nhan vao chi con 3/10.";
				ST1=((Enemy.ATK-Main.DEF)*Enemy.CritDMG/100*3/10);
				if(ST1<0) ST1=0;
				cout<<"\nSat thuong: "<<ST1;
				Main.HP-=ST1;}
			else if(evade){
				cout<<"\nDoi phuong ra don nhung ban lai ne duoc , sat thuong nhan vao bang 0.";
				ST1=0;
				cout<<"\nSat thuong: 0";}
			else if(crit){
				cout<<"\nDoi phuong ra 1 don chi mang vao dau ban , sat thuong gay ra tang gap nhieu lan.";
				ST1=((Enemy.ATK-Main.DEF)*Enemy.CritDMG/100);
				if(ST1<0) ST1=0;
				cout<<"\nSat thuong: "<<ST1;
				Main.HP-=ST1;}
			else {
				cout<<"\nDoi phuong nhanh tay ra don , gay ra 1 luong sat thuong khong nho.";
				ST1=Enemy.ATK-Main.DEF;
				if(ST1<0) ST1=0;
				cout<<"\nSat thuong: "<<ST1;
				Main.HP-=ST1;}
			evade=0; crit=0;
			if(Main.HP<0) Main.HP=0;}
			cout<<"\nMain's HP: "<<save[1]<<" -> "<<Main.HP;
			if(Main.HP<=0) {cout<<"\nBan da thua.\n"; system("pause"); return 0;}
			if(RanDom(1,100)<=Enemy.Silence){
			Main.ATK=save[3];
			Main.CritDMG=save[4];
			Main.DEF=save[5];
			cout<<"\nAnh huong tu don danh cua dich lam ban bi cam lang chi co the danh thuong.";
			if(RanDom(1,100)<=Enemy.Dodge-Main.Accuracy) evade=1;
			if(RanDom(1,100)<=Main.CritRate)             crit=1;
			if(evade&&crit) {
				cout<<"\nBan ra 1 don chi mang vao dau doi phuong nhung doi phuong lai ne duoc , sat thuong nhan vao chi con 3/10.";
				ST2=((Main.ATK-Enemy.DEF)*Main.CritDMG/100*3/10);
				if(ST2<0) ST2=0;
				cout<<"\nSat thuong: "<<ST2;
				Enemy.HP-=ST2;}
			else if(evade){
				cout<<"\nBan ra don nhung doi phuong lai ne duoc , sat thuong nhan vao bang 0.";
				ST2=0;
				cout<<"\nSat thuong: 0";}
			else if(crit){
				cout<<"\nBan ra 1 don chi mang vao dau doi phuong , sat thuong gay ra tang gap nhieu lan.";
				ST2=((Main.ATK-Enemy.DEF)*Main.CritDMG/100);
				if(ST2<0) ST2=0;
				cout<<"\nSat thuong: "<<ST2;
				Enemy.HP-=ST2;}
			else {
				cout<<"\nBan nhanh tay ra don , gay ra 1 luong sat thuong khong nho.";
				ST2=Main.ATK-Enemy.DEF;
				if(ST2<0) ST2=0;
				cout<<"\nSat thuong: "<<ST2;
				Enemy.HP-=ST2;}
			evade=0; crit=0;
			if(Enemy.HP<0) Enemy.HP=0;
			cout<<"\nEnemy's HP: "<<save[2]<<" -> "<<Enemy.HP;
			if(Enemy.HP==0) {cout<<"\nBan da thang."; break;}}
			else{
			if(Collection[1]==4||Collection[2]==4||Collection[3]==4||Collection[4]==4){
				cout<<"\nCounter: "<<int(ST1*3/10);
				int temp=(Enemy.HP-int(ST1*3/10));
				if(temp<0) temp=0;
				cout<<"\nEnemy's HP: "<<Enemy.HP<<"->"<<temp;
				Enemy.HP-=int(ST1*3/10);
				if(Enemy.HP<=0) {cout<<"\nBan da thang."; break;}}
			if(Collection[1]==10||Collection[2]==10||Collection[3]==10||Collection[4]==10){
				int heal=0.1*(Main.MAXHP-Main.HP);
				cout<<"\nHealing: "<<heal;
				cout<<"\nMain's HP: "<<Main.HP<<"->"<<Main.HP+heal;
				Main.HP+=heal;}
			if(Collection[1]==1||Collection[2]==1||Collection[3]==1||Collection[4]==1){
				cout<<"\nCrack pha nat toan bo kha nang phong thu cua doi phuong.";
				resist[1]=Enemy.DEF;
				Enemy.DEF-=resist[1];}
			if(Collection[1]==2||Collection[2]==2||Collection[3]==2||Collection[4]==2){
				cout<<"\nAgility , don danh chac chan dinh doi phuong. ";
				resist[2]=Enemy.Dodge;
				Enemy.Dodge-=resist[2];}
			if(Collection[1]==3||Collection[2]==3||Collection[3]==3||Collection[4]==3){
				cout<<"\nViolence , phong thu giam phan nua , bu lai khi chi mang sat thuong se nhan doi.";
				save[5]=Main.DEF;
				Main.DEF=int(Main.DEF/2);
				save[4]=Main.CritDMG;
				Main.CritDMG=Main.CritDMG*2;}
			if(Collection[1]==5||Collection[2]==5||Collection[3]==5||Collection[4]==5){
				Main.ATK=int(Main.ATK*105/100);
				cout<<"\nAccumulate ATK: "<<Main.ATK;}		
			if(Collection[1]==6||Collection[2]==6||Collection[3]==6||Collection[4]==6){
				dot++;}
			if(Collection[1]==7||Collection[2]==7||Collection[3]==7||Collection[4]==7){
			int temp=Enemy.HP;
			if(RanDom(1,100)<=Enemy.Dodge-Main.Accuracy) evade=1;
			if(RanDom(1,100)<=Main.CritRate)             crit=1;
			if(evade&&crit) {
				cout<<"\nSmash Critical + Enemy Dodge (ST=30%).";
				ST3=((int(Main.HP*10/100)-Enemy.DEF)*Main.CritDMG/100*3/10);
				if(ST3<0) ST3=0;
				cout<<"\nSat thuong: "<<ST3;
				Enemy.HP-=ST3;}
			else if(evade){
				cout<<"\nSmash + Enemy Dodge (ST=0%).";
				ST3=0;
				cout<<"\nSat thuong: 0";}
			else if(crit){
				cout<<"\nSmash Critical.";
				ST3=((int(Main.HP*10/100)-Enemy.DEF)*Main.CritDMG/100);
				if(ST3<0) ST3=0;
				cout<<"\nSat thuong: "<<ST3;
				Enemy.HP-=ST3;}
			else {
				cout<<"\nNormal Smash.";
				ST3=int(Main.HP*10/100)-Enemy.DEF;
				if(ST3<0) ST3=0;
				cout<<"\nSat thuong: "<<ST3;
				Enemy.HP-=ST3;}
			evade=0; crit=0;
			if(Enemy.HP<0) Enemy.HP=0;
			cout<<"\nEnemy's HP: "<<temp<<" -> "<<Enemy.HP;
			if(Enemy.HP==0) {cout<<"\nBan da thang."; break;}}
			if(Collection[1]==8||Collection[2]==8||Collection[3]==8||Collection[4]==8){
				if(RanDom(1,2)==1){
					if(RanDom(1,100)<=30) {
						cout<<"\nDebuff , giam 10% CritRate cua doi phuong.";
						Enemy.CritRate-=10;
						if(Enemy.CritRate<0) Enemy.CritRate=0;
						cout<<"\nEnemy's CritRate: "<<Enemy.CritRate;}
					if(RanDom(1,100)<=30) {
						cout<<"\nDebuff , giam 5% Silence cua doi phuong.";
						Enemy.Silence-=5;
						if(Enemy.Silence<0) Enemy.Silence=0;
						cout<<"\nEnemy's Silence: "<<Enemy.Silence;}
					if(RanDom(1,100)<=30) {
						cout<<"\nDebuff , giam 10% Dodge cua doi phuong.";
						Enemy.Dodge-=10;
						if(Enemy.Dodge<0) Enemy.Dodge=0;
						cout<<"\nEnemy's Dodge: "<<Enemy.Dodge;}}
				else{
					int temp=RanDom(1,10);
					if(temp<4){
						cout<<"\nDebuff , giam 10% CritRate cua doi phuong.";
						Enemy.CritRate-=10;
						if(Enemy.CritRate<0) Enemy.CritRate=0;
						cout<<"\nEnemy's CritRate: "<<Enemy.CritRate;}
					else if(temp<7){
						cout<<"\nDebuff , giam 5% Silence cua doi phuong.";
						Enemy.Silence-=5;
						if(Enemy.Silence<0) Enemy.Silence=0;
						cout<<"\nEnemy's Silence: "<<Enemy.Silence;}
					else if(temp<10){
						cout<<"\nDebuff , giam 10% Dodge cua doi phuong.";
						Enemy.Dodge-=10;
						if(Enemy.Dodge<0) Enemy.Dodge=0;
						cout<<"\nEnemy's Dodge: "<<Enemy.Dodge;}}}
			if(Collection[1]==12||Collection[2]==12||Collection[3]==12||Collection[4]==12){
				if(Enemy.HP<int(Enemy.MAXHP/100)*RanDom(1,50)){
					if(RanDom(1,100)<=Main.CritRate){
						cout<<"\nFatal , lap tuc ket lieu doi thu.";
						cout<<"\nEnemy's HP: 0";
						cout<<"\nBan da thang.";
						break;}}}
			int temp=Enemy.HP;
			if(RanDom(1,100)<=Enemy.Dodge-Main.Accuracy) evade=1;
			if(RanDom(1,100)<=Main.CritRate)             crit=1;
			if(evade&&crit) {
				cout<<"\nBan ra 1 don chi mang vao dau doi phuong nhung doi phuong lai ne duoc , sat thuong nhan vao chi con 3/10.";
				ST4=((Main.ATK-Enemy.DEF)*Main.CritDMG/100*3/10);
				if(ST4<0) ST4=0;
				cout<<"\nSat thuong: "<<ST4;
				Enemy.HP-=ST4;}
			else if(evade){
				cout<<"\nBan ra don nhung doi phuong lai ne duoc , sat thuong nhan vao bang 0.";
				ST4=0;
				cout<<"\nSat thuong: 0";}
			else if(crit){
				cout<<"\nBan ra 1 don chi mang vao dau doi phuong , sat thuong gay ra tang gap nhieu lan.";
				ST4=((Main.ATK-Enemy.DEF)*Main.CritDMG/100);
				if(ST4<0) ST4=0;
				cout<<"\nSat thuong: "<<ST4;
				Enemy.HP-=ST4;}
			else {
				cout<<"\nBan nhanh tay ra don , gay ra 1 luong sat thuong khong nho.";
				ST4=Main.ATK-Enemy.DEF;
				if(ST4<0) ST4=0;
				cout<<"\nSat thuong: "<<ST4;
				Enemy.HP-=ST4;}
			evade=0; crit=0;
			if(Enemy.HP<0) Enemy.HP=0;
			cout<<"\nEnemy's HP: "<<temp<<" -> "<<Enemy.HP;
			if(Enemy.HP==0) {cout<<"\nBan da thang."; break;}	
			if(Collection[1]==9||Collection[2]==9||Collection[3]==9||Collection[4]==9){
				cout<<"\nLifeSteal: "<<int((ST3+ST4)*30/100);
				cout<<"\nMain's HP: "<<Main.HP<<"->"<<Main.HP+int((ST3+ST4)*30/100);
				Main.HP+=int((ST3+ST4)*30/100);}			
			if(Collection[1]==1||Collection[2]==1||Collection[3]==1||Collection[4]==1){
				Enemy.DEF=resist[1];}
			if(Collection[1]==2||Collection[2]==2||Collection[3]==2||Collection[4]==2){
				Enemy.Dodge=resist[2];}
			if(Collection[1]==3||Collection[2]==3||Collection[3]==3||Collection[4]==3){
				Main.DEF=save[5];
				Main.CritDMG=save[4];}}
			if(dot!=0){
			int temp=Enemy.HP-(3/100*Main.ATK+1/100*Main.HP)*dot;
			if(temp<0) temp=0;
			cout<<"\nDOT :"<<int(3/100*Main.ATK+1/100*Main.HP)*dot;
			cout<<"\nEnemy's HP: "<<Enemy.HP<<"->"<<temp;
			Enemy.HP-=int(3/100*Main.ATK+1/100*Main.HP)*dot;
			if(Enemy.HP<=0) {cout<<"\nBan da thang."; break;}}}
		if(Collection[1]==1||Collection[2]==1||Collection[3]==1||Collection[4]==1){
			Enemy.DEF=resist[1];}
		if(Collection[1]==2||Collection[2]==2||Collection[3]==2||Collection[4]==2){
			Enemy.Dodge=resist[2];}
		if(Collection[1]==3||Collection[2]==3||Collection[3]==3||Collection[4]==3){
			Main.DEF=save[5];
			Main.CritDMG=save[4];}		
		Main.ATK=save[3];}
	system("pause");
	return 0;}
