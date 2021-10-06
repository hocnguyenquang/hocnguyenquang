#include<iostream.h>
#include<iomanip.h>
#include<string.h>
using namespace std;
class GV {
	private : 
	  char ht[30];
	  int tuoi ;
	  char bc [15];
	  char cn [20];
	  float bl ;
   public :
      GV (){}
      GV( char * ht , int tuoi , char* bc , char *cn , float bl ){
      	strcpy ( this->ht,ht);
      	this -> tuoi = tuoi ;
      	strcpy ( this->bc,bc);
      	strcpy ( this->cn,cn);
      	this -> bl = bl ;
      }
      ~GV(){} 
      friend istream& operator >>( istream &is , GV &a){
      	cin.ignore();
      	cout<<"\n Nhap ho ten : ";
      	cin.getline( a.ht,30);
      	cout<<" Nhap tuoi : ";
      	cin>>a.tuoi ;
      	cin.ignore();
      	do{
 		  cout<<" Nhap bang cap ( 1: gioi , 2: kha , 3: TB ) : ";
      	  cin.getline( a.bc,15);
      	  if(strcmpi(a.bc, "1") != 0 && strcmpi(a.bc, "2") != 0 && strcmpi(a.bc, "3") != 0){
					cout<<"\n Ban nhap sai roi nhap lai : ";
				}
	      }while(strcmpi(a.bc, "1") != 0 && strcmpi(a.bc, "2") != 0 && strcmpi(a.bc, "3") != 0);
      	cout<<" Nhap chuyen nganh : ";
      	cin.getline( a.cn,20);
      	cout<<" Nhap bac luong : ";
      	cin>>a.bl;
      	return is ;
      }
      void td (){
      	cout<<setw(20)<<" HO TEN "
      	    <<setw(10)<<" TUOI "
      	    <<setw(10)<<" BANG CAP "
      	    <<setw(20)<<" CHUYEN NGANH "
      	    <<setw(20)<<" BAC LUONG "<<endl;
      }
        friend ostream& operator <<( ostream &os , GV &a){
        	cout <<setw(20)<<a.ht
      	    	<<setw(10)<<a.tuoi ;
   	    	if(strcmpi(a.bc, "1") == 0){
				cout<<setw(10)<<"Gioi";
			}
			else if(strcmpi(a.bc, "2") == 0){
				cout<<setw(10)<<"Kha";
			}
			else{
				cout<<setw(10)<<"TB";
			}
      	    cout <<setw(20)<<a.cn
      	    	<<setw(20)<<a.bl<<endl;
      	    	return os ;
        }
        
        float lcb (){
        	return bl*610;
        }
        
        friend bool operator ==( GV &a,GV &b )
        {
        	return ( strcmpi(a.bc,b.bc)==0) ;
        }
        
        friend bool operator >=( GV &a,GV &b )
        {
        	return ( strcmpi(a.bc,b.bc)>0) ;
        }
        
      
};
int main(){
	int n;
	do{
		cout<<" \n Nhap n : ";
		cin>>n;
		if( n<=0)
		cout<<" Vui long nhap lai :";
	}while(n<=0);
	
	GV *gv = new GV[n];
	cout << "\n Nhap thong tin GV ";
	for( int i=0;i<n;i++)
	{
		cout<<" \n Nhap tt GV thu "<<i+1<<" la :";
		cin>>gv[i];
	}
    gv -> td();
	for(int i = 0; i < n; i++){
		for(int j =i+1 ; j < n; j++){
			if(gv[i] >= gv[j]){
				GV temp = gv[i];
				   gv[i] = gv[j];
			       gv[j] = temp;
			}
		}
		cout<<gv[i] ;
	}
	cout<<endl;
	return 0;	
}