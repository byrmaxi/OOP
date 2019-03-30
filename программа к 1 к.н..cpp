#include <iostream>
#include <cstring>

using std::ostream;
using std::istream;

class shtraf;     

class rabotnik
{
	friend class shtraf;         // ����� ����
	private:
		char name [70] ;
		int opyt;
		int zp;
		int proguly;
		static int num_rab;
		
	public:
		// ������������
		rabotnik ();
		rabotnik (const char * n);
		rabotnik (const rabotnik &); 
		
		//���������
		~rabotnik();
		
		//������������� �������� 
		rabotnik & operator = (const rabotnik & rab);
		
		//������������� ������� ��� ������������� ����������
		friend bool operator >(const rabotnik &rab1, int n);
		friend bool operator <(const rabotnik &rab1, const rabotnik & rab2);
		friend bool operator >(const rabotnik &rab1, const rabotnik & rab2);
		friend ostream & operator << (ostream & os, const rabotnik & rab);
		friend istream & operator >> (istream & is, rabotnik & rab) ;
		
		// �������������� ������� 
		static int howmany();
			
};

class shtraf
{
	public: 
	void vychet(rabotnik & rab )
	   {
	   	 int sh=rab.zp*0.05;
	   	 rab.zp-=sh;
	   } 
};

int rabotnik::num_rab = 0;

int rabotnik::howmany()
{
	return num_rab;
}

rabotnik::rabotnik()
{
	name[0]='/0';
	opyt=0;
	num_rab++;
}


rabotnik::rabotnik (const char *n)
{
	opyt=std::strlen(n);
}


rabotnik::rabotnik(const rabotnik & rab)
{
	num_rab++;
	opyt=rab.opyt;
	std::strcpy(name, rab.name);	
}


rabotnik::~rabotnik()
{
	--num_rab;
	std::cout<< "������ ������" << std::endl;
	std::cout<< "�������� " << howmany() << " �������(��)" << std::endl;
}


rabotnik & rabotnik::operator =(const rabotnik & rab)
{
	std::strcpy(name, rab.name);
	opyt=rab.opyt;
	return *this ;                                        //��������� this
} 

bool operator >(const rabotnik &rab1, int n)
{
	return rab1.proguly<n;
}

bool operator <(const rabotnik & rab1, const rabotnik & rab2)
{
	return (std::strcmp(rab2.name,rab1.name)<0);
}


bool operator >(const rabotnik &rab1, const rabotnik & rab2)
{
	return rab2.opyt>rab1.opyt;
}


ostream & operator << (ostream & os, const rabotnik & rab)
{
	
	os << rab.name;
	return os;
}


istream & operator >> (istream & is, rabotnik & rab) 
{
	std::cout<< "������� ���: ";
	std::cin >> rab.name ;
	std::cout<< "������� ��� ���� ������: ";
	std::cin >> rab.opyt;
	std::cout<< "������� ��� ��������: ";
	std::cin >> rab.zp;
	std::cout<< "������� ���������� ��������: ";
	std::cin >> rab.proguly;
	return is;
}



int main() 
{
	setlocale(LC_ALL, "Russian");
	
	using std::cout;
	using std::cin;
	using std::endl;
	


   int arsize=0;
   cout << "������� ���������� ����������"<< endl;
   cin >> arsize;
   rabotnik chel[arsize];
   cout << "������� ������ � �����������"<< endl;
   for (int i=0; i<arsize; i++)
      {
      	cin >> chel [i];
      	cout<< endl;
	  }
    
    rabotnik temp;
    for (int i=0; i<arsize; i++)
       {
       	 for (int j=i+1; j<arsize; j++)
       	    {
       	       if (chel[i]>chel[j])
       	          temp=chel[i];
			}
	   }
	 
	 
	for (int i=0; i<arsize; i++)
	   {
	   	  for (int j=i+1; j<arsize; j++)
	   	     {
	   	      	if (chel[i]<chel[j])
	   	      	    {
	   	      	    	chel[i]=chel[j];
					}
		   	 }
	   	 
	   } 
	   
	shtraf sh;
	for (int i=0; i<arsize; i++)
     {
     	sh.vychet (chel[i]);
	 } 
		
	cout << temp << "-�������� � ����� ��������� ������" << endl;
	cout << chel[0]<< "- ������ �������� �� ��������"<< endl;
	cout << "��������� ������������ " << rabotnik::howmany() << " �������(��)" << endl;
	
	return 0;
}
