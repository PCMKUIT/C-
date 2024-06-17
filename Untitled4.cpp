#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
class NgheNghiep{
	protected: string HoTen;
			   int Ngay, Thang, Nam;
			   float ChieuCao;
			   float CanNang;
	public:
	NgheNghiep(string n="", int d=0, int m=0, int y=0, float h=0, float w=0) {
		HoTen=n;Ngay=d;Thang=m;Nam=y;ChieuCao=h;CanNang=w;}
	~NgheNghiep(){}

    void ChuanHoaXau(string &chuoi) {
    	int cnt=0;
		while(chuoi[cnt]==' ') cnt++; 
		chuoi=chuoi.substr(cnt,chuoi.size());
		chuoi[0]=toupper (chuoi[0]);
		for (int i=1;i<chuoi.size();i++){
			if (chuoi[i-1]==' ') chuoi[i]=toupper (chuoi[i]);
	 		else chuoi[i]= tolower (chuoi[i]);}
		for (int i=1;i<chuoi.size();i++){
			if ((chuoi[i]==' ')&&(chuoi[i+1]==' ')){
				chuoi.erase(chuoi.begin()+i);i--;}}}
				
    int NgayToiDa(int Thang,int Nam) const {
		switch(Thang){
		    case 1:case 3:case 5:case 7:case 8:case 10:case 12: return 31;
		    case 2:{if((Nam%4==0&&Nam%100!=0)||Nam%400==0) 
					return 29; return 28;}
		    case 4:case 6:case 9:case 11: return 30;}}
		    
	virtual void Nhap(){
		cin.ignore();
		cout<<"Nhap ho ten: "; getline(cin,HoTen);
		ChuanHoaXau(HoTen);
		cout<<"Nhap nam sinh: ";  cin>>Nam;
		cout<<"Nhap thang sinh: ";cin>>Thang;
		while(Thang<1||Thang>12) {
			cout<<"Thang sinh khong hop le, vui long nhap lai: ";
			cin>>Thang;}
	    cout<<"Nhap ngay sinh: ";cin>>Ngay;
		while(Ngay<1||Ngay>31||(Ngay>(NgayToiDa(Thang,Nam)))) {
			cout<<"Ngay sinh khong hop le, vui long nhap lai: ";
			cin>>Ngay;}
		cout<<"Nhap chieu cao (tinh bang centimet): "; cin>>ChieuCao;
		while(ChieuCao<=0){
			cout<<"Chieu cao (tinh bang centimet) khong the am";
			cout<<", vui long nhap lai: ";
			cin>>ChieuCao;}
		cout<<"Nhap can nang (tinh bang kilogram): "; cin>>CanNang;
		while(CanNang<=0){
			cout<<"Can nang (tinh bang kilogram) khong the am";
			cout<<", vui long nhap lai: ";
			cin>>CanNang;}}

	virtual void Xuat() const {
		cout<<"Ho va ten: "<<HoTen;
		cout<<"\nSinh ngay: "<<Ngay<<"/"<<Thang<<"/"<<Nam;
		cout<<"\nChieu cao: ";
		int sub1 = int(round(ChieuCao)/100);
		int sub2 = round(ChieuCao) - sub1*100;
		if (sub1==0) cout<<sub2<<"cm";
		else if (sub2==0) cout<<sub1<<"m ";
		else cout<<sub1<<"m "<<sub2<<"cm";
		cout<<"\nCan nang: "<<round(CanNang*100)/100<<"kg";}
};

class SinhVien : public NgheNghiep {
	private: string TenTruong;
			 string ChuyenNganh;
			 string MSSV;
			 int SoNamHoc;
	public:
	SinhVien(string a="", string b="", int c=0){
		TenTruong=a; ChuyenNganh=b; SoNamHoc=c;}
	~SinhVien(){}
	
	void Nhap(){
		NgheNghiep::Nhap();
		cin.ignore();
		cout<<"Nhap ten truong: ";getline(cin,TenTruong);
		ChuanHoaXau(TenTruong);
		cout<<"Nhap ten chuyen nganh: ";getline(cin,ChuyenNganh);
		ChuanHoaXau(ChuyenNganh);
		cout<<"Nhap ma so sinh vien: "; cin>>MSSV;
		cout<<"Nhap so nam da hoc tai truong: ";cin>>SoNamHoc;
		while(SoNamHoc<1||SoNamHoc>15){
			cout<<"So nam da hoc tai truong khong hop le";
			cout<<", vui long nhap lai: ";
			cin>>SoNamHoc;}}
	
	void Xuat() const {
		NgheNghiep::Xuat();
		cout<<"\nDang hoc tai: "<<TenTruong;
		cout<<"\nChuyen nganh: "<<ChuyenNganh;
		cout<<"\nLa sinh vien nam "<<SoNamHoc<<endl;}
};

class HocSinh : public NgheNghiep {
	private: string TenTruong;
			 int Lop;
	public:
	HocSinh(string a="", int b=0){TenTruong=a; Lop=b;}
	~HocSinh(){}
	
	void Nhap(){
		NgheNghiep::Nhap();
		cin.ignore();
		cout<<"Nhap ten truong: ";getline(cin,TenTruong);
		ChuanHoaXau(TenTruong);
		cout<<"Nhap lop: "; cin>>Lop;
		while(Lop<1||Lop>12){
			cout<<"Lop khong hop le, vui long nhap lai: ";
			cin>>Lop;}}
			
	void Xuat() const {
		NgheNghiep::Xuat();
		cout<<"\nDang hoc tai: "<<TenTruong;
		cout<<"\nLa hoc sinh lop "<<Lop<<endl;}
};

class CongNhan : public NgheNghiep {
	private: string LinhVuc; 
			 int SoNamKinhNghiem;
			 long long ThuNhap;
	public:
	CongNhan(string a="", int b=0, long long c=0){
		LinhVuc=a;SoNamKinhNghiem=b;ThuNhap=c;}
	~CongNhan(){}
	
	void Nhap(){
		NgheNghiep::Nhap();
		cin.ignore();
		cout<<"Nhap linh vuc lam viec: ";getline(cin,LinhVuc);
		ChuanHoaXau(LinhVuc);
		cout<<"Nhap so nam kinh nghiem: ";cin>>SoNamKinhNghiem;
		while(SoNamKinhNghiem<0){
			cout<<"So nam kinh nghiem khong hop le";
			cout<<", vui long nhap lai";
			cin>>SoNamKinhNghiem;}
		cout<<"Nhap thu nhap tinh theo don vi dong/thang: ";
		cin>>ThuNhap;
		while(ThuNhap<0){
			cout<<"Muc thu nhap hang thang khong the am";
			cout<<", vui long nhap lai: ";
			cin>>ThuNhap;}}
	
	void Xuat() const {
		NgheNghiep::Xuat();
		cout<<"\nLa cong nhan trong linh vuc "<<LinhVuc;
		cout<<" voi "<<SoNamKinhNghiem<<" nam kinh nghiem";
		cout<<"\nThu nhap hang thang: "<<ThuNhap<<" dong\n";}
};

class NgheSi : public NgheNghiep {
	private: string CongViecCuThe;
			 int SoNamKinhNghiem;
			 long long ThuNhap;
	public:
	NgheSi(string a="", int b=0, int c=0){
		CongViecCuThe=a;SoNamKinhNghiem=b;ThuNhap=c;}
	~NgheSi(){}
			 
	void Nhap(){
		NgheNghiep::Nhap();
		cin.ignore();
		cout<<"Nhap cong viec cu the: ";getline(cin,CongViecCuThe);
		ChuanHoaXau(CongViecCuThe);
		cout<<"Nhap so nam kinh nghiem: ";cin>>SoNamKinhNghiem;
		while(SoNamKinhNghiem<0){
			cout<<"So nam kinh nghiem khong the am";
			cout<<", vui long nhap lai: ";
			cin>>SoNamKinhNghiem;}
		cout<<"Nhap thu nhap tinh theo don vi dong/thang: ";
		cin>>ThuNhap;
		while(ThuNhap<0){
			cout<<"Muc thu nhap hang thang khong the am";
			cout<<", vui long nhap lai: ";
			cin>>ThuNhap;}}		
	
	void Xuat() const {
		NgheNghiep::Xuat();
		cout<<"\nLa nghe si voi cong viec cu the la ";
		cout<<CongViecCuThe<<" voi "<<SoNamKinhNghiem;
		cout<<" nam kinh nghiem";
		cout<<"\nThu nhap hang thang: "<<ThuNhap<<" dong\n";}
};

class CaSi : public NgheNghiep {
	private: string TheLoaiNhac;
			 int SoNamKinhNghiem;
			 long long ThuNhap;
	public:
	CaSi(string a="", int b=0, int c=0){
		TheLoaiNhac=a;SoNamKinhNghiem=b;ThuNhap=c;}
	~CaSi(){}
	
	void Nhap(){
		NgheNghiep::Nhap();
		cin.ignore();
		cout<<"Nhap the loai nhac: ";getline(cin,TheLoaiNhac);
		ChuanHoaXau(TheLoaiNhac);
		cout<<"Nhap so nam kinh nghiem: ";cin>>SoNamKinhNghiem;
		while(SoNamKinhNghiem<0){
			cout<<"So nam kinh nghiem khong the am";
			cout<<", vui long nhap lai: ";
			cin>>SoNamKinhNghiem;}
		cout<<"Nhap thu nhap tinh theo don vi dong/thang: ";
		cin>>ThuNhap;
		while(ThuNhap<0){
			cout<<"Muc thu nhap hang thang khong the am";
			cout<<", vui long nhap lai: ";
			cin>>ThuNhap;}}
	
	void Xuat() const {
		NgheNghiep::Xuat();
		cout<<"\nLa ca si choi the loai nhac "<<TheLoaiNhac;
		cout<<" voi "<<SoNamKinhNghiem<<" nam kinh nghiem";
		cout<<"\nThu nhap hang thang: "<<ThuNhap<<" dong\n";}
};

class QuanLyDanhSach{
	private: vector <NgheNghiep*> DuLieu;
	public:
	QuanLyDanhSach(){}
	~QuanLyDanhSach(){
		if(DuLieu.size() > 0){
			for(int i = 0; i < DuLieu.size(); i++){
				if(DuLieu[i]!=NULL){
					delete DuLieu[i];
					DuLieu[i]=NULL;}}
		DuLieu.clear();}}
	
	void Nhap(){
		int LoaiDoiTuong, cnt = 1;
		bool close = 0;
		while (true){
			cout<<"Nhap thong tin cua doi tuong thu "<<cnt++<<":";
			cout<<"\nNhap 1 de nhap du lieu cho sinh vien";
			cout<<"\nNhap 2 de nhap du lieu cho hoc sinh";
			cout<<"\nNhap 3 de nhap du lieu cho cong nhan";
			cout<<"\nNhap 4 de nhap du lieu cho nghe si";
			cout<<"\nNhap 5 de nhap du lieu cho ca si";
			cout<<"\nNhap 6 de chot danh sach va xuat ra danh sach thong ke";
			cout<<"\nNhap mot so nguyen tu 1 den 6: ";
			cin>>LoaiDoiTuong;
			while(LoaiDoiTuong!=1&&LoaiDoiTuong!=2&&LoaiDoiTuong!=3&&LoaiDoiTuong!=4&&LoaiDoiTuong!=5&&LoaiDoiTuong!=6)
				{cout<<"Cau lenh khong hop le, vui long nhap lai mot so nguyen tu 1 den 6: "; cin>>LoaiDoiTuong;}
			switch (LoaiDoiTuong){
				case 1: DuLieu.push_back(new SinhVien); break;
				case 2: DuLieu.push_back(new HocSinh); break;
				case 3: DuLieu.push_back(new CongNhan); break;
				case 4: DuLieu.push_back(new NgheSi); break;
				case 5: DuLieu.push_back(new CaSi); break;
				case 6: close = 1; break;}
			if(close) break;
			DuLieu.back()->Nhap();}}
			
	void Xuat() const {
		cout<<"\nSo luong doi tuong trong danh sach: "<<DuLieu.size();
		for(int i = 0; i < DuLieu.size(); i++){
			cout<<"\nThong tin cua doi tuong thu "<<i+1<<":\n";
			DuLieu[i]->Xuat();}}
};

int main (){
	QuanLyDanhSach DanhSach;
	DanhSach.Nhap();
	DanhSach.Xuat();
	return 0;}