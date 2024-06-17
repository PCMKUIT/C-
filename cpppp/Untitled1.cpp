#include <bits/stdc++.h>
#include <ctime>
using namespace std;
bool Fixed=1;
bool Load=1;
bool Dangerous,Lucky;
int Again,TheLuc,Road,Goodcase,Badcase,Enhance,Percent;
int Boost=0; bool Note[3];
int Round=1;
int *Lost;
int RanDom(int min,int max){
    return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));}
bool Check(){ return (TheLuc<1);}
void Lose(){
	cout<<"\nBan da di lien tuc trong vong nhieu ngay , ban guc nga vi qua met moi.";
	cout<<"\nRat tiec , ban da thua.";
	return;}
int main (){
	srand(time(NULL));
	cout<<"                                              TRO CHOI ME CUNG";
	int x;
	cout<<"\nNhap do dai doan duong (mot con so nguyen): ";
	cin>>x;
	TheLuc=100;
	while(x<1) {
		cout<<"Do dai doan duong khong hop le , vui long nhap lai mot so nguyen lon hon 0: ";
		cin>>x;}
	cout<<"Ban tinh day sau mot giac ngu dai , the nhung thu doi ban lai khong phai nhung tia nang ban mai";
	cout<<" ma la mot noi toi tam   mit mu , truoc mat ban la mot con duong hep voi 2 day tuong song song nhau , ";
	cout<<"het nhu 1 me cung.";
	int SoCanhCua = RanDom(2,8);
	cout<<"\nBan di thang mot doan nho thi thay "<<SoCanhCua<<" canh cua.";
	while(true){
		int LuaChon;
		for(int j=1;j<=SoCanhCua;j++) cout<<"\n"<<j<<".Canh cua thu "<<j;  
		cout<<"\nBan chon: "; cin>>LuaChon;
		while(LuaChon<1||LuaChon>SoCanhCua){
			cout<<"Cau lenh khong hop le , vui long nhap lai 1 so tu 1 den "<<SoCanhCua<<": ";
			cin>>LuaChon;}
		cout<<"Ban quyet dinh di canh cua thu "<<LuaChon<<" , day duong trai dai ra nhu vo tan , du vay ban van co gang chay.";
		if(LuaChon==Again) {
			cout<<"\nCon duong nay co ve hoi quen thuoc , sau khi ban di duoc 1 doan , ban gap 1 bay ong gom ghiec ";
			cout<<", ban bi chon vui boi bay ong va mai mai khong the tinh lai.";
			cout<<"\nRat tiec , ban da thua."; break;}
		if(Fixed) {
			Road = RanDom(1,SoCanhCua);
			if(Lost) {delete [] Lost; Lost=NULL;}
			Lost = new int [SoCanhCua+1];
			for(int j=1;j<=SoCanhCua;j++) Lost[j]=RanDom(10,20);}
		Goodcase=RanDom(1,100);
		if(Goodcase>79&&Goodcase<101) Lucky=1;
		if(Load){
			Badcase=RanDom(1,100);
			if(Badcase>0&&Badcase<16) Dangerous=1;}
		TheLuc=TheLuc-Lost[LuaChon]+Boost*3;
		if(TheLuc<0) TheLuc=0;
		cout<<"\nThe luc giam sut con "<<TheLuc<<"%.";
		if(Check()) {Lose(); break;}
		if(LuaChon==Road) {
			Percent=RanDom(1,100);
			if(Percent>0&&Percent<7&&!Note[0]){
				if(Boost!=0) {
				cout<<"\nDang chay giua chung ban lai thay 1 doi giay moi , ban lien coi doi giay hien tai ra";
				cout<<" va deo doi moi vao , cam giac di   rat thuan chan.";}
				else cout<<"\nDang chay giua chung ban thay 1 doi giay , ban lien deo vao va cam thay di rat thuan chan.";
				Boost=3; Note[0]=true;}
			else if(Percent>6&&Percent<16&&!Note[0]&&!Note[1]){
				if(Boost==1) {
				cout<<"\nDang chay giua chung ban lai thay 1 doi giay moi , ban lien coi doi giay hien tai ra";
				cout<<" va deo doi moi vao , cam thay kha  vua chan.";}
				else cout<<"\nDang chay giua chung ban thay 1 doi giay , ban lien deo vao va cam thay kha vua chan.";
				Boost=2; Note[1]=true;}
			else if(Percent>15&&Percent<28&&!Note[0]&&!Note[1]&&!Note[2]){
				cout<<"\nDang chay giua chung ban thay 1 doi giay , ban lien deo vao va cam thay de di hon mot chut.";
				Boost=1; Note[2]=true;}
			else if(Percent>50&&Percent<66){
				cout<<"\nDang chay giua chung dot nhien ban thay 1 con suoi , nhin dong nuoc rat sach , ban lien lay tay ra hung va uong mot it  nuoc ";
				cout<<"de lay lai suc.";
				Enhance=RanDom(5,15);
				TheLuc+=Enhance;
				if(TheLuc>100) TheLuc=100;
				cout<<"\nThe luc tang len thanh "<<TheLuc<<"%."; }
			cout<<"\nDen cuoi duong , ban thay 1 canh cua to lon va sang trong , mo cua ra ";
			if(Round==x) {
				cout<<"ban lien tinh giac , ac mong me cung da cham dut , chuc mung , ban da chien thang.";
				cout<<"\nEnd."; return 0;}
			else {
				SoCanhCua = RanDom(2,8);
				cout<<"ban lien nhin thay mot tham thuc an da duoc chuan bi tu truoc , khong suy nghi nhieu ban an sach het dong thuc an do vi bung ban dang doi.";
				TheLuc+=70;
				if(TheLuc>100) TheLuc=100;
				cout<<"\nThe luc tang manh thanh "<<TheLuc<<"%.";
				cout<<"\nAn xong ban di tiep 1 doan thi lai thay "<<SoCanhCua<<" canh cua.";
				Load=1; Fixed=1; Again=0; Dangerous=0; Lucky=0; Round++;}}
		else {
			if(Dangerous) {
			cout<<"\nDang chay giua chung dot nhien co 1 bay ong tu dau bay ra tan cong ban";
			if(TheLuc>30) {cout<<". Cung may ban van con kha khoe , co chan len chaymot mach cuoi cung cung thoat duoc dam ong ay.";
			TheLuc-=5;
			if(TheLuc<0) TheLuc=0;
			cout<<"\nThe luc giam sut con "<<TheLuc<<"%.";
			if(Check()) {Lose(); break;}}
			else {cout<<". Ban co gang chay khoi chung nhung vi qua met , ban da khong con suc nua , ban bi chon vui boi bay ong va mai mai khong the tinh lai.";
				  cout<<"\nRat tiec , ban da thua."; break;}
			Load=0; Again=LuaChon; Dangerous=0;}
			else {
				if(Lucky) {
				cout<<"\nDang chay giua chung thi ban thay 1 cai cay da ket trai , ban lien treo len va hai trai cay de an.";
				Enhance=RanDom(3,8);
				TheLuc+=Enhance;
				if(TheLuc>100) TheLuc=100;
				cout<<"\nThe luc tang len thanh "<<TheLuc<<"%."; 
				Lucky=0;}}
			cout<<"\nDen cuoi duong , ban moi nhan ra day hoan toan la 1 ngo cut , cong suc cua ban da thanh cong coc gio ban phai chay lai  con duong cu";
			cout<<" de ve noi co nhung canh cua ay.";
			TheLuc=TheLuc-Lost[LuaChon]+Boost*3;
			if(TheLuc<0) TheLuc=0;
			cout<<"\nThe luc giam sut con "<<TheLuc<<"%.";
			if(Check()) {Lose(); break;}
			cout<<"\nChay ve cho cu , ban lai thay "<<SoCanhCua<<" canh cua.";
			Fixed=0;}}
	cout<<"\nChang duong hoan thanh: "<<Round<<"/"<<x<<".";
	return 0;}