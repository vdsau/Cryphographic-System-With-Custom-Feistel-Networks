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
AnsiString FindSym(const char lol,AnsiString l);//Удалить до указанного знака(справа-налево)
AnsiString PathToFile(AnsiString ExePath);//вычисление полного пути к папке с файлом
long long int FileSize(AnsiString Path);//размер файла
void crypth(char *path,AnsiString pth,const AnsiString &password);
AnsiString TypeFile(char *path); //прочитать и удалить из файла расширение
void read_file(char *path,const AnsiString  ExePath,const AnsiString &password); //ExePath-путь к файлу с программой
//---------------------------------------------------------------------------
inline void XOR_Ansi_elem(AnsiString &str)
{
        for(int i=1; i<str.Length(); i++)
                str[i]^=1;
}
//---------------------------------------------------------------------------
inline AnsiString ExtractType(AnsiString &path)//расширение файла
{
        return FindSym('.',path);
}
//---------------------------------------------------------------------------
inline vector<char> read(ifstream *from)
        {//создать массив с данными
                from->seekg(0, ifstream::end); // перемотаем файл в конец, чтобы в (*) узнать размер
                vector<char> data(from->tellg()); // (*) создадим вектор размером с файл
                from->seekg(0, ifstream::beg); // перемотаем файл обратно на начало
                from->read(&data[0], data.size()); // прочитаем файл
                return data;
        }
//---------------------------------------------------------------------------
enum {RUS,ENG,UKR,ALL};//использовать 0-только русские буквы,1-только англ.буквы,2-все языки
//---------------------------------------------------------------------------
struct files
{
        ifstream *from; //считать файл
        ofstream *to;  //записать в файл
        inline files(ifstream &FromFile,ofstream  &ToFile){
                from=&FromFile;
                to=&ToFile;
        }
        void write(); //запись в файл
        inline vector<char> read()
        {//создать массив с данными
                from->seekg(0, ifstream::end); // перемотаем файл в конец, чтобы в (*) узнать размер
                vector<char> data(from->tellg()); // (*) создадим вектор размером с файл
                from->seekg(0, ifstream::beg); // перемотаем файл обратно на начало
                from->read(&data[0], data.size()); // прочитаем файл
                return data;
        }
        ~files(){
           delete from;
           delete to;
        }
};
//---------------------------------------------------------------------------
struct dictionary //наборы символов для генерации пароля
{
      AnsiString  all_sym,//все символы
                _nums,//цифры
                _eng_sym,//английские буквы в верхнем/нижнем регистре
                _rus_sym,//русские буквы в верхнем/нижнем регистре
                _ukr_sym,//украинские буквы в обоих регистрах
                _spec_sym;//спец.символы
                dictionary(){
                        _nums="0123456789";
                        _eng_sym="abcdefghklmnopqrstuvwxyz";
                        _eng_sym+=_eng_sym.UpperCase();  //английский алфавит в верхнем регистре
                        _rus_sym="абвгдеёжзийклмопрстуфхцчшщъыьэюя";
                        _rus_sym+=_rus_sym.UpperCase(); //руссский алфавит в верхнем регистре
                        _ukr_sym="абвгґдеєжзиіїйклмнопрстуфхцчшщьюя";
                        _ukr_sym+=_ukr_sym.UpperCase();//украинский алфавит
                        _spec_sym="_~#@!*/-+%";     //спец.символы
                        all_sym+=_rus_sym;
                        all_sym+=_eng_sym;
                        all_sym+=_nums;
                        all_sym+=_spec_sym;
                        }
                ~dictionary(){}
};
//---------------------------------------------------------------------------
class _random_password //генерация случайного пароля
{
dictionary *sym;
AnsiString _pass,//сгенерированный пароль
        temp;//нужный набор символов
int     size,//длина пароля
        lang_code;//код языка
void fill_rnd();//заполнить случайными символами
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
_random_password(int Length,int _Lang){//Length количество символов в пароле
        _random_password();
        lang_code=_Lang;
        if(Length==0)
        ShowMessage("Довжина пароля не може дорівнювати 0!");
        if(Length>32)
        ShowMessage("Довжина пароля не може перевищувати 32 символа");
        else
        size=Length;
}
inline void change_size(int new_size)//для изменения длины пароля
{
        if(new_size==0)
        ShowMessage("Довжина пароля не може дорівнювати 0!");
        if(new_size>32){
                ShowMessage("Довжина пароля не може перевищувати 32 символа\nПароль буде скорочено до 32 символів");
                size=32;
        }
        else
        size=new_size;
}
inline void change_lang(int lang) //изменение языка
{
        lang_code=lang;
}
void generate();//создать пароль
inline const AnsiString out()
{
        generate();
        return _pass;
}
~_random_password(){}
};
//---------------------------------------------------------------------------
class key{
         AnsiString c_key;    //ключ
         inline void check_length()  //проверка длины пароля
         {
               if(c_key.Length()<16) //если число символов в пароле <16-дополнить его
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
	inline key(AnsiString text):c_key(text){ //конструктор
                reverse(&c_key[1],&c_key[c_key.Length()]+1); //в обратном порядке
                check_length();
        }
	~key(){}
        vector<AnsiString> keys(); //вектор подключей для каждого раунда
	inline const AnsiString out()//вывод созданного ключа
	{
                keys();
                return c_key;
	}
};
//---------------------------------------------------------------------------
class _crypt
{
        key *k;//ключ
        files *f;//работа с файлом
        vector<char> data;//вектор со считанным файлом
        static const int Round_cnt=128;//количество раундов шифрования
        AnsiString FileType;
        struct _block//обрабатываемый блок (128 байт)
        {
                static const int size=128;//размер 1 блока шифруемой информации(байт)
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
                inline void merge_in_block(vector<char> &first, vector<char> &second)//слияние в 1 блок
                {
                        size_t i=0;
                       this->bl.clear();
                       for( i=0; i < first.size(); i++)
                                this->bl.push_back(first[i]);
                       for(i=0; i<second.size(); i++)
                                this->bl.push_back(second[i]);
                }
        }*block;
        size_t size;//количество блоков
        size_t last_length;//длина последнего блока
        int size_count();// вычисляет количество блоков и размер последнего блока
        void fill_block();//заполняет блоки по 128 байт
        void crypt_block(_block &b, vector<AnsiString >&subkey);//зашифровать отдельный блок
        void function_crypt(vector<char> &blk);
        inline void XOR_elem(char &sym)
        {
                sym^=1;
        }
        inline void XOR_subKey(vector<char> &block, AnsiString &subkey) //наложение подключа на блок
        {
                for(size_t x=0; x < block.size(); x++) {
                for(int y=1;y < subkey.Length(); y++)
                        block[x]^=subkey[y];
                }
        }
        void XOR_subBlocks(vector<char> &first, vector<char> &second); //XOR для двух блоков
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
        void execute();//процесс шифрования
        inline _crypt(AnsiString _Password,AnsiString _From,AnsiString _To)
        {
             k=new key(_Password);
                ifstream from1(_From.c_str(), ifstream::in | ifstream::binary ); // откроем файл
                ofstream to1(_To.c_str(),  ios_base::trunc | ios_base::binary ); //файл для записи
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
