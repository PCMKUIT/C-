#include <iostream>
#include <string>
using namespace std;
class String{
    private: char * Str; int Len;
    public:
        String(const char *s){ Len=strlen(s); Str=new char[Len+1]; strcpy(Str,s);}      
        String(){ Len=0; Str =new char[1]; Str[0]='\0';}          
        String(const String &s){ Len=s.Len; Str = new char [Len+1]; strcpy(Str,s.Str);}    
        ~String(){ if(Str!=NULL) delete [] Str; }
        
        String & operator = (const char *s){
        		Len=strlen(s); delete [] Str;
    			Str=new char [Len+1];
    			strcpy(Str,s);
    			return *this;}    
    			
    	String & operator = (const String &s){
        	    if(this==&s) return *this;
    			Len=s.Len;	delete [] Str;
    			Str =new char[Len+1];
    			strcpy(Str,s.Str);
    			return *this;}
        
        String  operator + (const String &s){
    			char *str=new char[Len+s.Len+1];
    			strcpy(str,Str);
    			strcat(str,s.Str);
    			String ans(str);
    			return ans;}    
    			
        friend istream & operator >> (istream & In,String & s){
        		char temp[500]; In.getline(temp,500); s=temp;
    			return In;}
        friend ostream & operator << (ostream & Out,const String & s){ Out<<s.Str; return Out; }
        int GetLen() const{return Len;}
    			
        void ReverseString(){
        		char *TempStr=new char[Len+1]; int j=0;
    			for(int i=Len-1;i>=0;i--) TempStr[j++]=Str[i];
    			TempStr[j]='\0';
    			delete [] Str;
    			Str=TempStr;}
};

int main(){
    String a,b,c;
    cout<<"Nhap vao du lieu cua chuoi ky tu thu nhat: "; cin>>a;
    cout<<"Nhap vao du lieu cua chuoi ky tu thu hai: ";  cin>>b;
    c=a+b;
    cout<<"Chuoi ky tu thu nhat: "<<a<<endl;
    a.ReverseString();
    cout<<"Chuoi ky tu thu nhat sau khi dao nguoc: "<<a<<endl;
    cout<<"Chieu dai chuoi ky tu thu nhat: "<<a.GetLen()<<endl;
    cout<<"Chuoi ky tu thu hai: "<<b<<endl;
    b.ReverseString();
    cout<<"Chuoi ky tu thu hai sau khi dao nguoc: "<<b<<endl;
    cout<<"Chieu dai chuoi ky tu thu hai: "<<b.GetLen()<<endl;
    cout<<"Ket qua sau khi noi hai chuoi la: "<<c<<endl;
    c.ReverseString();
    cout<<"Ket qua sau khi noi hai chuoi lai va dao nguoc la: "<<c<<endl;
    cout<<"Chieu dai cua chuoi ky tu noi boi hai chuoi ky tu ban dau la: "<<c.GetLen();
    return 0;
}