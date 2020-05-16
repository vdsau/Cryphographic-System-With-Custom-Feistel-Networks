//---------------------------------------------------------------------------

#ifndef classesH
#define classesH
//---------------------------------------------------------------------------
#include <vcl.h>
#include<bitset.h>
#include<algorithm.h>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include<string>
#include<time.h>
#include <sys/stat.h>

#include"file_exist_form.h"
//---------------------------------------------------------------------------
#define tmp(x) temp+=x

//---------------------------------------------------------------------------
AnsiString FindSym(const char lol,AnsiString l);//������� �� ���������� �����(������-������)
AnsiString PathToFile(AnsiString ExePath);//���������� ������� ���� � ����� � ������
long long int FileSize(AnsiString Path);//������ �����
void crypth(char *path,AnsiString pth,const AnsiString &password);
AnsiString TypeFile(char *path); //��������� � ������� �� ����� ����������
void read_file(char *path,const AnsiString  ExePath,const AnsiString &password); //ExePath-���� � ����� � ����������
//---------------------------------------------------------------------------
inline void XOR_Ansi_elem(AnsiString &str)
{
        for(int i=1; i<str.Length(); i++)
                str[i]^=1;
}
//---------------------------------------------------------------------------
inline AnsiString ExtractType(AnsiString &path)//���������� �����
{
        return FindSym('.',path);
}
//---------------------------------------------------------------------------
inline vector<char> read(ifstream *from)
        {//������� ������ � �������
                from->seekg(0, ifstream::end); // ���������� ���� � �����, ����� � (*) ������ ������
                vector<char> data(from->tellg()); // (*) �������� ������ �������� � ����
                from->seekg(0, ifstream::beg); // ���������� ���� ������� �� ������
                from->read(&data[0], data.size()); // ��������� ����
                return data;
        }
//---------------------------------------------------------------------------
enum {RUS,ENG,UKR,ALL};//������������ 0-������ ������� �����,1-������ ����.�����,2-��� �����
//---------------------------------------------------------------------------
struct files
{
        ifstream *from; //������� ����
        ofstream *to;  //�������� � ����
        inline files(ifstream &FromFile,ofstream  &ToFile){
                from=&FromFile;
                to=&ToFile;
        }
        void write(); //������ � ����
        inline vector<char> read()
        {//������� ������ � �������
                from->seekg(0, ifstream::end); // ���������� ���� � �����, ����� � (*) ������ ������
                vector<char> data(from->tellg()); // (*) �������� ������ �������� � ����
                from->seekg(0, ifstream::beg); // ���������� ���� ������� �� ������
                from->read(&data[0], data.size()); // ��������� ����
                return data;
        }
        ~files(){
           delete from;
           delete to;
        }
};
//---------------------------------------------------------------------------
struct dictionary //������ �������� ��� ��������� ������
{
      AnsiString  all_sym,//��� �������
                _nums,//�����
                _eng_sym,//���������� ����� � �������/������ ��������
                _rus_sym,//������� ����� � �������/������ ��������
                _ukr_sym,//���������� ����� � ����� ���������
                _spec_sym;//����.�������
                dictionary(){
                        _nums="0123456789";
                        _eng_sym="abcdefghklmnopqrstuvwxyz";
                        _eng_sym+=_eng_sym.UpperCase();  //���������� ������� � ������� ��������
                        _rus_sym="�������������������������������";
                        _rus_sym+=_rus_sym.UpperCase(); //�������� ������� � ������� ��������
                        _ukr_sym="��������賿��������������������";
                        _ukr_sym+=_ukr_sym.UpperCase();//���������� �������
                        _spec_sym="_~#@!*/-+%";     //����.�������
                        all_sym+=_rus_sym;
                        all_sym+=_eng_sym;
                        all_sym+=_nums;
                        all_sym+=_spec_sym;
                        }
                ~dictionary(){}
};
//---------------------------------------------------------------------------
class _random_password //��������� ���������� ������
{
dictionary *sym;
AnsiString _pass,//��������������� ������
        temp;//������ ����� ��������
int     size,//����� ������
        lang_code;//��� �����
void fill_rnd();//��������� ���������� ���������
inline void fill_temp()
{
        temp="";
        tmp(sym->_nums);
        tmp(sym->_spec_sym);
}
public:
inline _random_password(){
        sym=new dictionary();
        fill_temp();
        size=1;
        lang_code=0;
        }
_random_password(int Length,int _Lang){//Length ���������� �������� � ������
        _random_password();
        lang_code=_Lang;
        if(Length==0)
        ShowMessage("������� ������ �� ���� ���������� 0!");
        if(Length>32)
        ShowMessage("������� ������ �� ���� ������������ 32 �������");
        else
        size=Length;
}
inline void change_size(int new_size)//��� ��������� ����� ������
{
        if(new_size==0)
        ShowMessage("������� ������ �� ���� ���������� 0!");
        if(new_size>32){
                ShowMessage("������� ������ �� ���� ������������ 32 �������\n������ ���� ��������� �� 32 �������");
                size=32;
        }
        else
        size=new_size;
}
inline void change_lang(int lang) //��������� �����
{
        lang_code=lang;
}
void generate();//������� ������
inline const AnsiString out()
{
        generate();
        return _pass;
}
~_random_password(){}
};
//---------------------------------------------------------------------------
class key{
         AnsiString c_key;    //����
         inline void check_length()  //�������� ����� ������
         {
               if(c_key.Length()<16) //���� ����� �������� � ������ <16-��������� ���
               {
                        int diff=16-c_key.Length();
                        for(int i=0;i<diff;i++)
                        {
                                c_key+=i;
                        }
               }
         }
public:
        key(){}
	inline key(AnsiString text):c_key(text){ //�����������
                reverse(&c_key[1],&c_key[c_key.Length()]+1); //� �������� �������
                check_length();
        }
	~key(){}
        vector<AnsiString> keys(); //������ ��������� ��� ������� ������
	inline const AnsiString out()//����� ���������� �����
	{
                keys();
                return c_key;
	}
};
//---------------------------------------------------------------------------
class _crypt
{
        key *k;//����
        files *f;//������ � ������
        vector<char> data;//������ �� ��������� ������
        static const int Round_cnt=128;//���������� ������� ����������
        AnsiString FileType;
        struct _block//�������������� ���� (128 ����)
        {
                static const int size=128;//������ 1 ����� ��������� ����������(����)
                vector<char> bl;
                inline void set_size(size_t size)
                {
                        vector<char>temp(size);
                        bl=temp;
                }
                inline void change_size(size_t new_size)
                {
                        bl.resize(new_size);
                }
                inline AnsiString out()
                {
                        AnsiString l="";
                        for(vector<char>::iterator i=bl.begin(); i!=bl.end(); i++ )  {
                             l+=*i;    }
                        return l;
                }
                inline void merge_in_block(vector<char> &first, vector<char> &second)//������� � 1 ����
                {
                        size_t i=0;
                       this->bl.clear();
                       for( i=0; i < first.size(); i++)
                                this->bl.push_back(first[i]);
                       for(i=0; i<second.size(); i++)
                                this->bl.push_back(second[i]);
                }
        }*block;
        size_t size;//���������� ������
        size_t last_length;//����� ���������� �����
        int size_count();// ��������� ���������� ������ � ������ ���������� �����
        void fill_block();//��������� ����� �� 128 ����
        void crypt_block(_block &b, vector<AnsiString >&subkey);//����������� ��������� ����
        void function_crypt(vector<char> &blk);
        inline void XOR_elem(char &sym)
        {
                sym^=1;
        }
        inline void XOR_subKey(vector<char> &block, AnsiString &subkey) //��������� �������� �� ����
        {
                for(size_t x=0; x < block.size(); x++) {
                for(int y=1;y < subkey.Length(); y++)
                        block[x]^=subkey[y];
                }
        }
        void XOR_subBlocks(vector<char> &first, vector<char> &second); //XOR ��� ���� ������
        inline void write_block(_block &l)
        {
                for(size_t i=0; i < l.bl.size(); i++)
                *f->to<<l.bl[i];
        }
        inline void swap_Blocks(vector<char> &first, vector<char> &second)
        {
                vector<char>temp(first);
                first=second;
                second=temp;
        }
        void subBlock_operations(vector<char> &fb, vector<char> &sb, vector<AnsiString> &subkey, int &Round,int &sub_index);
        public:
        inline void fillType(AnsiString &type)
        {
                FileType+=".";
                XOR_Ansi_elem(type);
                FileType+=type;
        }
        void execute();//������� ����������
        inline _crypt(AnsiString _Password,AnsiString _From,AnsiString _To)
        {
             k=new key(_Password);
                ifstream from1(_From.c_str(), ifstream::in | ifstream::binary ); // ������� ����
                ofstream to1(_To.c_str(),  ios_base::trunc | ios_base::binary ); //���� ��� ������
             f=new files(from1,to1);
                fill_block();
        }
        inline _crypt(key &_Key,files &_File)
        {
                k=&_Key;
                f=&_File;
                fill_block();
        }
        ~_crypt(){
              delete []block;
        }
        inline void out(vector<char> &vec)
        {
                AnsiString lel="";
                for(vector<char>::iterator i=vec.begin(); i!=vec.end(); i++)
                        lel+=*i;
                ShowMessage(lel);
                lel="";
        }
        inline void out()
        {
                AnsiString lel="";
                ShowMessage(size);
                for(size_t x=0;x<size;x++) {
                        lel+=x;
                        lel+='\n';
                      ShowMessage(lel+block[x].out());
                      lel="";}
        }
};
//---------------------------------------------------------------------------

#endif
