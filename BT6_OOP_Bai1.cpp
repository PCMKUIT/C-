#include <iostream>
#include <string>
using namespace std;
class NhanVien{
	protected: string HoTen; 
			   int Ngay, Thang, Nam;
	public:
    NhanVien(){}
    ~NhanVien(){}
    
    void ChuanHoaTen(string &chuoi) {
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
	    cout << "Nhap ho ten: ";
	    getline(cin,HoTen); ChuanHoaTen(HoTen);
	    cout<<"Nhap nam sinh: ";cin>>Nam;
		cout<<"Nhap thang sinh: ";cin>>Thang;
		while(Thang<1||Thang>12) {
			cout<<"Thang sinh khong hop le, vui long nhap lai: ";
			cin>>Thang;}
	    cout<<"Nhap ngay sinh: ";cin>>Ngay;
		while(Ngay<1||Ngay>31||(Ngay>(NgayToiDa(Thang,Nam)))) {
			cout<<"Ngay sinh khong hop le, vui long nhap lai: ";
			cin>>Ngay;}}
			
    virtual void Xuat() const {
	    cout<<"Ho ten nhan vien: "<<HoTen;
	    cout<<"\nNgay thang nam sinh: "<<Ngay<<"/"<<Thang<<"/"<<Nam<<'\n';}
	    
    virtual long long Luong() const = 0;
};


class NhanVienSanXuat : public NhanVien {
	private:long long LuongCanBan;
			long long SoSanPham;
	public:
    NhanVienSanXuat(){}
    ~NhanVienSanXuat(){}
    
    void Nhap(){
		NhanVien::Nhap();
	    cout<<"Nhap muc luong can ban: ";cin>>LuongCanBan;
	    while(LuongCanBan<0){
	    	cout<<"Muc luong can ban khong the am, vui long nhap lai: ";
	    	cin>>LuongCanBan;}
	    cout<<"Nhap so san pham: ";cin>>SoSanPham;
	    while(SoSanPham<0){
	    	cout<<"So san pham khong the am, vui long nhap lai: ";
	    	cin>>SoSanPham;}
		cout<<'\n';}
	    
    void Xuat() const {
	    NhanVien::Xuat();
	    cout<<"Muc luong can ban: "<<LuongCanBan<<'\n';
	    cout<<"So san pham lam duoc: "<< SoSanPham<<'\n';}
	    
    long long Luong() const {return (LuongCanBan+SoSanPham*5000);}
};

class NhanVienVanPhong : public NhanVien{
	private: long long SoNgayLamViec;
	public:
    NhanVienVanPhong(){}
    ~NhanVienVanPhong(){}
    
    void Nhap(){
	    NhanVien::Nhap();
	    cout<< "Nhap so ngay lam viec: ";
	    cin >> SoNgayLamViec;
	    while(SoNgayLamViec<0) {
	    	cout<<"So ngay lam viec khong the am, ";
	    	cout<<"vui long nhap lai: ";
	    	cin >>SoNgayLamViec;}
		cout<<'\n';}
	    
    void Xuat() const {
	    NhanVien::Xuat();
	    cout<<"So ngay lam viec: "<<SoNgayLamViec<<'\n';}
	    
    long long Luong() const {return SoNgayLamViec*100000;}
};

class QuanLyNhanVien{
	private: NhanVien **DuLieu;
	    	 int SoLuongNhanVien;
	public:
    QuanLyNhanVien(int x=0){
	    SoLuongNhanVien = x;
	    DuLieu = new NhanVien * [SoLuongNhanVien];}
    ~QuanLyNhanVien(){ 
		if(DuLieu!=NULL) {
			for (int i = 0; i < SoLuongNhanVien; i++) {
		    	if (DuLieu[i]!=NULL) {
		       		delete DuLieu[i];
		       		DuLieu[i] = NULL;}}
		delete[] DuLieu; }}
    
    void Nhap(){
	    cout << "Nhap so luong nhan vien: ";
	    cin >> SoLuongNhanVien;
	    int LoaiNhanVien = 0;
	    for (int i = 0; i < SoLuongNhanVien; i++){
	        cout<<"Nhap thong tin cua nhan vien thu "<<i+1<<":";
	        cout<<"\nSo 1 la nhan vien san xuat" ;
	        cout<<"\nSo 2 la nhan vien van phong";
	        cout<<"\nNhap mot so nguyen tuong ung voi loai nhan vien: ";
	        cin >> LoaiNhanVien;
	        while (LoaiNhanVien != 1 && LoaiNhanVien != 2)
	            {cout<< "So nguyen khong hop le, vui long nhap lai: ";
				 cin >> LoaiNhanVien;}
	        if (LoaiNhanVien == 1) DuLieu[i] = new NhanVienSanXuat;
	        else DuLieu[i] = new NhanVienVanPhong;
	        DuLieu[i]->Nhap();}}
	        
	void Xuat() const {
	    cout << "So luong nhan vien cua cong ty: " << SoLuongNhanVien << endl;
	    for (int i = 0; i < SoLuongNhanVien; i++) {
	        cout << "\nThong tin nhan vien thu "<< i+1 << ":\n";
	        DuLieu[i]->Xuat();
	        cout << "Tien luong nhan duoc: "<< DuLieu[i]->Luong() << endl;}}
};

int main(){
    QuanLyNhanVien CongTy;
    CongTy.Nhap();
    CongTy.Xuat();
    return 0;}