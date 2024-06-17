#include <iostream>
#include <string>
using namespace std;
class NhanVien{
	protected: string HoTen; 
			   int Ngay, Thang, Nam;
	public:
    NhanVien(){}
    ~NhanVien(){}
    
    int NgayToiDa(int Thang,int Nam){
		switch(Thang){
		    case 1:case 3:case 5:case 7:case 8:case 10:case 12: return 31;
		    case 2:{if((Nam%4==0&&Nam%100!=0)||Nam%400==0) 
					return 29; return 28;}
		    case 4:case 6:case 9:case 11: return 30;}}
		    
    virtual void Nhap(){
		cin.ignore();
	    cout << "Nhap ho ten: ";
	    getline(cin,HoTen);
	    cout<<"Nhap nam sinh: ";cin>>Nam;
		cout<<"Nhap thang sinh: ";cin>>Thang;
		while(Thang<1||Thang>12) {
			cout<<"Thang sinh khong hop le , vui long nhap lai: ";
			cin>>Thang;}
	    cout<<"Nhap ngay sinh: ";cin>>Ngay;
		while(Ngay<1||Ngay>31||(Ngay>(NgayToiDa(Thang,Nam)))) {
			cout<<"Ngay sinh khong hop le , vui long nhap lai: ";
			cin>>Ngay;}}
			
    virtual void Xuat(){
	    cout<<"Ho ten nhan vien: "<<HoTen<<endl;
	    cout<<"Ngay thang nam sinh: "<<Ngay<<"/"<<Thang<<"/"<<Nam<<'\n';}
	    
    virtual long long Luong(){return 0;}
};


class NhanVienSanXuat : public NhanVien {
	protected:long long LuongCanBan;
			  int SoSanPham;
	public:
    NhanVienSanXuat(){}
    ~NhanVienSanXuat(){}
    
    virtual void Nhap(){
		NhanVien::Nhap();
	    cout << "Nhap muc luong can ban: "; cin >> LuongCanBan;
	    cout << "Nhap so san pham: "; cin >> SoSanPham;}
	    
    virtual void Xuat(){
	    NhanVien::Xuat();
	    cout << "Muc luong can ban: " << LuongCanBan << endl;
	    cout << "So san pham lam duoc: " << SoSanPham << endl;}
	    
    virtual long long Luong(){return (LuongCanBan+SoSanPham*5000);}
};

class NhanVienVanPhong : virtual public NhanVien{
	protected: int SoNgayLamViec;
	public:
    NhanVienVanPhong(){}
    ~NhanVienVanPhong(){}
    
    virtual void Nhap(){
	    NhanVien::Nhap();
	    cout << "Nhap so ngay lam viec: ";
	    cin >> SoNgayLamViec;}
	    
    virtual void Xuat(){
	    NhanVien::Xuat();
	    cout << "So ngay lam viec: " << SoNgayLamViec << endl;}
	    
    virtual long long Luong(){return SoNgayLamViec*100000;}
};

class QuanLyNhanVien{
	protected: NhanVien **DuLieu;
	    	   int SoLuongNhanVien;
	    	   long long TongSoLuongPhaiTra;
	    	   long long LuongCaoNhat, Max;
	    	   long long LuongThapNhat, Min;
	public:
    QuanLyNhanVien(){
	    SoLuongNhanVien = 0;
	    DuLieu = new NhanVien * [SoLuongNhanVien];
	    TongSoLuongPhaiTra = 0;
	    LuongCaoNhat = 0; Max = 0;
	    LuongThapNhat = 0; Min = 0;}
    ~QuanLyNhanVien(){ if(DuLieu!=NULL) delete [] DuLieu; }
    
    void Nhap(){
	    cout << "Nhap so luong nhan vien: ";
	    cin >> SoLuongNhanVien;
	    int LuaChon = 0;
	    for (int i = 0; i < SoLuongNhanVien; i++){
	        do {cout << "==============================" << endl;
	            cout << "Nhap thong tin nhan vien thu: " << i + 1 << endl;
	            cout << "Menu nhap du lieu:" << endl;
	            cout << "Nhap so 1 neu la nhan vien san xuat" << endl;
	            cout << "Nhap so 2 neu la nhan vien van phong" << endl;
	            cout << "Nhap su lua chon: ";
	            cin >> LuaChon;
	            if (LuaChon != 1 && LuaChon != 2)
	            {cout << "Lua chon khong hop le, vui long nhap lai!" << endl;}}
			while (LuaChon != 1 && LuaChon != 2);
	        if (LuaChon == 1) DuLieu[i] = new NhanVienSanXuat;
	        else DuLieu[i] = new NhanVienVanPhong;
	        DuLieu[i]->Nhap();
	        TongSoLuongPhaiTra += DuLieu[i]->Luong();}}
	        
	void Xuat(){
	    cout << "So luong nhan vien cua cong ty: " << SoLuongNhanVien << endl;
	    for (int i = 0; i < SoLuongNhanVien; i++) {
	        cout << "=================================================" << endl;
	        cout << "Thong tin nhan vien thu: " << i + 1 << endl;
	        DuLieu[i]->Xuat();
	        cout << "Tien luong nhan duoc: " << DuLieu[i]->Luong() << endl;}
	    cout << "======================================================" << endl;
	    cout << "Tong so tien luong ma cong ty phai tra cho nhan vien: " << TongSoLuongPhaiTra << endl;
	    LuongCaoNhat = DuLieu[0]->Luong();
	    LuongThapNhat = DuLieu[0]->Luong();
	    for (int i = 0; i < SoLuongNhanVien; i++) {
	        if (DuLieu[i]->Luong() > LuongCaoNhat){
	        	LuongCaoNhat = DuLieu[i]->Luong();
	            Max = i;}
	        if (DuLieu[i]->Luong() < LuongThapNhat){
	            LuongThapNhat = DuLieu[i]->Luong();
	            Min = i;}}
	    cout << "Nhan vien co muc luong cao nhat la: " << endl;
	    DuLieu[Max]->Xuat(); cout << endl;
	    cout << "Nhan vien co muc luong thap nhat la: " << endl;
	    DuLieu[Min]->Xuat(); cout << endl;}
};

int main(){
    QuanLyNhanVien DuLieu;
    DuLieu.Nhap();
    DuLieu.Xuat();
    return 0;}