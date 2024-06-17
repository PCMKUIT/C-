#include <iostream>
#include <ctime>
#include <vector>
using namespace std;
class GiaSuc{
	protected: int SoLuongSinh;
			   float SoLitSua;
	public:
	GiaSuc(int a=0,float b=0){SoLuongSinh=a;SoLitSua=b;}
	~GiaSuc(){}
	int Random(int min,int max){
    	return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));}
	virtual void Nhap() = 0;
	virtual void TiengKeu() const = 0;
	virtual void Xuat() = 0;
	virtual int TongSoLuong() const = 0;
	virtual int SoLuong() const = 0;
	virtual void ThongKe() const = 0;
	float LuongSua() const { return SoLitSua; }
};

class Bo : public GiaSuc {
	private: int SoLuongBo;
	public:
	Bo(int a=0){SoLuongBo=a;}
	~Bo(){}
	void Nhap(){
		cout<<"Nhap so luong bo: "; cin>>SoLuongBo;
		while (SoLuongBo<0) { 
			cout<<"So luong bo khong the am, vui long nhap lai: ";
			cin>>SoLuongBo;}}
			
	void TiengKeu() const {
		for(int i=0;i<SoLuongBo;i++){
			cout<<"Um bo! ";
			if(i==SoLuongBo-1) cout<<"\n";}}
			
	void Xuat(){
		for(int i=0;i<SoLuongBo;i++){
			int   temp1=Random(1,3);
			float temp2=float(Random(0,200))/10;
			SoLuongSinh+=temp1;
			SoLitSua+=temp2;
			cout<<"Con bo thu "<<i+1<<" sinh "<<temp1<<" con ";
			if(temp2==0) cout<<"va khong cho sua.\n";
			else cout<<"va cho "<<temp2<<" lit sua.\n";}}
			
	int TongSoLuong() const { return (SoLuongBo+SoLuongSinh);}	
	int SoLuong() const { return SoLuongBo; }
			
	void ThongKe() const { 
		cout<<"\nTong so luong bo sau lua sinh la: ";
		cout<<TongSoLuong();}
};

class Cuu : public GiaSuc {
	private: int SoLuongCuu;
	public:
	Cuu(int a=0){SoLuongCuu=a;}
	~Cuu(){}
	void Nhap(){
		cout<<"Nhap so luong cuu: "; cin>>SoLuongCuu;
		while (SoLuongCuu<0) { 
			cout<<"So luong cuu khong the am, vui long nhap lai: ";
			cin>>SoLuongCuu;}}
			
	void TiengKeu() const {
		for(int i=0;i<SoLuongCuu;i++){
			cout<<"Baaa! ";
			if(i==SoLuongCuu-1) cout<<"\n";}}
			
	void Xuat(){
		for(int i=0;i<SoLuongCuu;i++){
			int   temp1=Random(1,3);
			float temp2=float(Random(0,50))/10;
			SoLuongSinh+=temp1;
			SoLitSua+=temp2;
			cout<<"Con cuu thu "<<i+1<<" sinh "<<temp1<<" con ";
			if(temp2==0) cout<<"va khong cho sua.\n";
			else cout<<"va cho "<<temp2<<" lit sua.\n";}}
	
	int TongSoLuong() const { return (SoLuongCuu+SoLuongSinh);}	
	int SoLuong() const { return SoLuongCuu; }
				
	void ThongKe() const { 
		cout<<"\nTong so luong cuu sau lua sinh la: ";
		cout<<TongSoLuong();}
};

class De : public GiaSuc {
	private: int SoLuongDe;
	public:
	De(int a=0){SoLuongDe=a;}
	~De(){}
	
	void Nhap(){
		cout<<"Nhap so luong de: "; cin>>SoLuongDe;
		while (SoLuongDe<0) { 
			cout<<"So luong de khong the am, vui long nhap lai: ";
			cin>>SoLuongDe;}}
			
	void TiengKeu() const {
		for(int i=0;i<SoLuongDe;i++){
		 	cout<<"Beee! ";
			if(i==SoLuongDe-1) cout<<"\n";}}
			
	void Xuat(){
		for(int i=0;i<SoLuongDe;i++){
			int   temp1=Random(1,3);
			float temp2=float(Random(0,100))/10;
			SoLuongSinh+=temp1;
			SoLitSua+=temp2;
			cout<<"Con de thu "<<i+1<<" sinh "<<temp1<<" con ";
			if(temp2==0) cout<<"va khong cho sua.\n";
			else cout<<"va cho "<<temp2<<" lit sua.\n";}}
			
	int TongSoLuong() const { return (SoLuongDe+SoLuongSinh);}	
	int SoLuong() const { return SoLuongDe; }
			
	void ThongKe() const { 
		cout<<"\nTong so luong de sau lua sinh la: ";
		cout<<TongSoLuong();}
};

class QuanLyGiaSuc{
	private: vector <GiaSuc*> DuLieu;
	public:
	QuanLyGiaSuc(){}
    ~QuanLyGiaSuc(){ 
		if(DuLieu.size() > 0){
			for(int i = 0; i < DuLieu.size(); i++){
				if(DuLieu[i]!=NULL){
					delete DuLieu[i];
					DuLieu[i]=NULL;}}
		DuLieu.clear();}}
			
	void Nhap(){
		DuLieu.resize(0);
		DuLieu.push_back(new Bo);
		DuLieu.push_back(new Cuu);
		DuLieu.push_back(new De);
		DuLieu[0]->Nhap();
		DuLieu[1]->Nhap();
		DuLieu[2]->Nhap();}
		
	void TiengKeu() const {
		cout<<"\nKhi nguoi chu nong trai di vang, ";
		cout<<"nhung tieng keu se nghe duoc trong nong trai la:\n";
		DuLieu[0]->TiengKeu();
		DuLieu[1]->TiengKeu();
		DuLieu[2]->TiengKeu();}
		
	void Xuat() const {
		cout<<"\n";
		DuLieu[0]->Xuat();
		DuLieu[1]->Xuat();
		DuLieu[2]->Xuat();
		DuLieu[0]->ThongKe();
		DuLieu[1]->ThongKe();
		DuLieu[2]->ThongKe();
		cout<<"\nTong so luong gia suc sau lua sinh la: ";
		int socon = DuLieu[0]->SoLuong()+DuLieu[1]->SoLuong()
		+DuLieu[2]->SoLuong();
		cout<<DuLieu[0]->TongSoLuong()+DuLieu[1]->TongSoLuong()
		+DuLieu[2]->TongSoLuong();
		cout<<"\nTong so lit sua ma tat ca cac gia suc da cho la: ";
		float sosua = DuLieu[0]->LuongSua()+DuLieu[1]->LuongSua()
		+DuLieu[2]->LuongSua();
		cout<<sosua;
		if(socon!=0){
		cout<<"\nNhu vay trung binh 1 con se cho duoc ";
		cout<<sosua/socon<<" lit sua.";}}
};

int main(){
	srand(time(NULL));
	QuanLyGiaSuc ThongTin;
	ThongTin.Nhap();
	ThongTin.TiengKeu();
	ThongTin.Xuat();
	return 0;}