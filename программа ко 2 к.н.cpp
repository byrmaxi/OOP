#include <iostream>
#include <cstring>
#include <string>


using std::cout;
using std::endl;
using std::string;
using std::cin;
 
                                                           
class rabotnik                                                   // ����������� ������� ����
{      
	private:
		char name [70] ;
		int opyt;
		int proguly;
		
	public:
		int show_opyt () {return (opyt);};
		int show_progyly () {return (proguly);};
		virtual void zarplata()=0;       // ������ ����������� �������
		rabotnik ();
		rabotnik (char n[70], int op, int pr)
		   {
		   	  strncpy(name, n, 69);
		   	  opyt=op;
		   	  proguly=pr; 	
		   };
		
		 ~rabotnik();                                 
	
			
};



class sotrudnik_po_kadram: public rabotnik                    //��������� ������������
{
	private:
		int spk_zp;
		class info_pretendenty                               // ��������� �����
		{
			private:	
		        string FIO ;
		        string vakansiy;
		        char kategoriy [1];
		        int opyt_;
		    public:
			     info_pretendenty();
			     info_pretendenty(string *f, string *v, char* kat, int op);
				 void show (info_pretendenty *i_p) 
				    {
				    	cout<< "���������� � ���������� �� �����:" << endl;
				    	cout<< "���: " << FIO << endl;
				    	cout<< "������������ ��������" << vakansiy << endl;
				    	cout << "��������� ������������" << kategoriy[0] << endl;
				    	cout << "���� � ������ ����� "  << opyt_ << endl;
					}
		
		 void spisok (int size)
		  {
		  	info_pretendenty ip [size];
		  	for (int i=0; i<size; i++)
		  	    {
		  	      cin>> ip[i].FIO ;
		          cin>> ip[i].vakansiy;
		          cin>> ip[i].kategoriy [1];
		          cin>> ip[i].opyt_;
				};
		  };
		};
	
	public:
		sotrudnik_po_kadram();
		~sotrudnik_po_kadram();
		virtual int zarplatar()
		     {
		     	if (show_opyt()>=4 && show_progyly()==0)
		     	   {
		     	   	spk_zp=29000;
				   } 
				  else { spk_zp=25000; } 
				  
				  return spk_zp;
              };
};

class manager: public rabotnik                                            
{
	private:
		int manager_zp;
		int size_produc;		
	public:
		manager ();
		~manager();
		virtual int zarplatar()
		     {
		     	if (show_opyt()>=4 && show_progyly()==0)
		     	   {
		     	   	manager_zp=29000;
				   } 
				  else { manager_zp=25000; } 
				  
				  return manager_zp;
			 };
		void info()
		     {
		     	class produc                                                       // ��������� �����
		     	{
		     		private:
		     			string name_prod;
					    int pribyl;
					    char otzyv [30]; 
		     		public:
		     			produc();
		     			~produc();
		     			void reshenie (produc *pr)
		     			    {
		     			       if (pr->pribyl >=10000 && strcmp(pr->otzyv,"good"))
		     			           cout << "������� '"  << name_prod << "' c ������� ����������" ;
							};
					     
					
				};
				
				produc pr;
				
			 };
	
};     


class nachalnik:public manager, public sotrudnik_po_kadram                                     //������������� ������������
{
	private:
		int nach_zp;
	public:
		virtual int zarplatar()
		     {
		     	if (rabotnik::show_opyt()>=4 && rabotnik::show_progyly()==0)
		     	   {
		     	   	nach_zp=45000;
				   } 
				  else { nach_zp=40000; } 
				  
				  return nach_zp;
			 };
			 
		void otchet ()
		    {
		    	cout << "�������������� ��������� �� �����:" << endl;
		    	info() ;
			};	 

	
	
};


int main() 
{
	 setlocale(LC_ALL, "rus");
	 
	 nachalnik pr;
	 pr.otchet();
	 
	 manager mn;
	 mn.info;
	 
	 sotrudnik_po_kadram spk;
	 

	return 0;
}
