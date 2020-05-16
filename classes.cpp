//---------------------------------------------------------------------------


#pragma hdrstop

#include "classes.h"

//---------------------------------------------------------------------------
AnsiString FindSym(const char lol,AnsiString l)
{
       AnsiString type="",temp="";
       int pos=0;
       for(pos=l.Length();pos!=0;pos--)
                {
                        if(l[pos]!=lol)
                        {
                                temp+=l[pos];
                        }
                        else
                        {
                                break;
                        }
                }
                for(pos=temp.Length();pos!=0;pos--)  //переставить буквы в обратном порядке
                {
                        type+=temp[pos];
                }
       return type;
}
//---------------------------------------------------------------------------
long long int FileSize(AnsiString Path)
{
        struct stat FileSize;
        stat(Path.c_str(),&FileSize);
                return FileSize.st_size;
}
//---------------------------------------------------------------------------
AnsiString PathToFile(AnsiString ExePath)   //получаем полный путь к папке с файлом
{
        ExePath.Delete(ExePath.Length()-FindSym('\\',ExePath).Length(),ExePath.Length()); //удаляем название проекта из пути
        return ExePath;
}
//---------------------------------------------------------------------------
void read_file(char *path,const AnsiString  ExePath,const AnsiString &password) //ExePath-путь к файлу с программой
{
        AnsiString pth=PathToFile(ExePath);
        if(ExtractType(path)!="LOL"){ //проверка расширения файла
                pth+= "\\files\\Res\\Зашифровані файли\\CryptedFile.LOL" ;//дописываем путь

        }
        else{
                pth+="\\files\\Res\\Розшифровані файли\\UncryptedFile.";
                pth+=TypeFile(path);
        }
        if(FileSize(pth)!=0)   //если зашифрованный/расшифрованный файл существует
        {
                if(file_exist->ShowModal()==mrOk){ //перезаписать?
                      crypth(path,pth,password);
                }
        }
        else {
                file_exist->ModalResult=mrNone;
                crypth(path,pth,password);
        }
}
//---------------------------------------------------------------------------
void _random_password::generate()
{
        fill_temp();
        srand(time(0));
        switch(lang_code)
        {
                case RUS:
                        tmp(sym->_rus_sym);
                break;
                case ENG:
                        tmp(sym->_eng_sym);
                break;
                case UKR:
                        tmp(sym->_ukr_sym);
                break;
                case ALL:
                        temp=sym->all_sym;
                break;
        }
        fill_rnd();
}
//---------------------------------------------------------------------------
void _random_password::fill_rnd()
{
_pass="";
for( int i=0,x=0; i<size ; i++ )
                        {
                               x=rand()%temp.Length();
                               _pass+=temp[(x==0)?x+1:x];
                        }
}
//---------------------------------------------------------------------------
vector<AnsiString> key::keys()
        {
                int size= c_key.Length()/4;  //длина 1 подключа
                vector<AnsiString> temp(4); //4 подключа
                for(size_t x=0;x<temp.size();x++)
                        for(int i=1;i<c_key.Length();i++)
                        {
                                if(i%size==0)
                                {
                                        temp[x]+=c_key[i];
                                        (x==temp.size())?x:x++;
                                }
                                else
                                {
                                        temp[x]+=c_key[i];
                                }
                        }
                return temp;

        }
//---------------------------------------------------------------------------
void files::write()
{
                vector<char> data=read();
                for(size_t i=0;i<data.size();i++)
	                {
			        data[i]^=1;
                                 *to<<data[i];
		        }
}
//---------------------------------------------------------------------------
void _crypt::fill_block()
{
        size_t i=0;
         data=f->read();
                size=size_count();
                block=new _block[size];
                if(size==1)
                {
                        block[0].bl=data;
                }  else{
                for(i=0;i<size;i++)
                  for(size_t x=0; x <data.size() ; x++ )
                        {
                        if(x % _block::size==0){
                                        block[i].bl.push_back(data[x]);
                                        (i==size-1)?i:i++;    //чтобы не выйти за пределы массива
                                }
                                 else{
                                        block[i].bl.push_back(data[x]);
                                }
                        }
                }
}
//---------------------------------------------------------------------------
int _crypt::size_count()
{
        if(data.size()%_block::size == 0 ) //количество блоков по _block::size байт
        {
                return (data.size()/_block::size);
        }
        else
        {
                last_length= data.size() % _block::size; //остаток
                return ((data.size()/_block::size)+1);
        }
}
//---------------------------------------------------------------------------
void _crypt::crypt_block(_block &b,vector<AnsiString >&subkey)
{
        size_t i=0;
        vector<char> fb;//первый блок
        vector<char> sb; //второй блок
        for(i=0; i < b.bl.size(); i++)
        {
               if(i < b.bl.size()/2 )
               {
                        fb.push_back( b.bl[i] );
               }
               if(i >= b.bl.size()/2 )
               {
                        sb.push_back( b.bl[i] );
               }
        }
        int Round=0,sub_key_index=0;
        subBlock_operations(fb,sb,subkey,Round,sub_key_index);
        b.merge_in_block(fb,sb);
}
//---------------------------------------------------------------------------
void _crypt::function_crypt(vector<char> &blk)
{
        for_each(blk.begin(),blk.end(),&XOR_elem);
        reverse(blk.begin(),blk.end());
}
//---------------------------------------------------------------------------
void _crypt::execute()
{
        for(size_t i=0; i<size; i++)   {
                crypt_block(block[i],k->keys());
                write_block(block[i]);   }
                *f->to<<FileType.c_str();
}
//---------------------------------------------------------------------------
void _crypt::XOR_subBlocks(vector<char> &first, vector<char> &second)
{
        for(vector<char>::iterator x=first.begin(); x!=first.end(); x++)
                for(vector<char>::iterator y=second.begin(); y!=second.end(); y++)
                {
                        *x^=*y;
                }
}
//---------------------------------------------------------------------------
void _crypt::subBlock_operations(vector<char> &fb, vector<char> &sb, vector<AnsiString> &subkey, int &Round,int &sub_index)
{
        if(Round<=Round_cnt){
                (sub_index==4)?sub_index=0:sub_index;
                function_crypt(fb);  //шифрование первого блока
                XOR_subKey(fb,subkey[sub_index]); //наложение подключа на субблок
                XOR_subBlocks(sb,fb);//наложение одного блока на другой(шифрование второго субблока)
                Round+=1;
                sub_index+=1;
                subBlock_operations(sb,fb,subkey,Round,sub_index); //рекурсия
        }
}
//---------------------------------------------------------------------------
void crypth(char *path,AnsiString pth,const AnsiString &password)
{
AnsiString type=ExtractType(path);
ifstream from1(path, ifstream::in | ifstream::binary ); // откроем файл
ofstream to1(pth.c_str(),  ios_base::trunc | ios_base::binary );//файл для записи
files *fl=new files(from1,to1);
key k(password);
_crypt *lol=new _crypt(k,*fl);
        if(type!="LOL")//если файл не зашифрован
                lol->fillType(type);
lol->execute();
delete lol;
}
//---------------------------------------------------------------------------
AnsiString TypeFile(char *path)
{
        ShowMessage("   Почекайте,будь-ласка,\nвідбувається налаштування");
        ifstream from(path, ifstream::in | ifstream::binary);//открыть файл
        AnsiString type="",temp=path,str="";
        vector<char> lel=read(&from);
        vector<char>::iterator i;
        for(i=lel.end()-1; i!=lel.begin(); i--)
        {
                if(*i!='.')  {
                        type+=*i;//запись типа файла
                        lel.erase(i);
                }
                else {
                       lel.erase(i);
               break;  }
        }
        ofstream to(path,  ios_base::trunc | ios_base::binary );//файл для записи
        for(i=lel.begin(); i!=lel.end(); i++)
        {
              to<<*i;
        }
        for(size_t x=type.Length(); x>0; x--)
        {
               str+=type[x];
        }
        type=str;
        XOR_Ansi_elem(type);
        from.close();
        to.close();
        return type;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
