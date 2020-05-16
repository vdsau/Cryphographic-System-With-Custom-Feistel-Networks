//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tmain_form *main_form;
//---------------------------------------------------------------------------
__fastcall Tmain_form::Tmain_form(TComponent* Owner)
        : TForm(Owner)
{
        Label5->Caption="При введенні паролю можно\nвикористовувати символи:\n1)A-Z;\n2)a-z;\n3)числа 0-9;";
}
//---------------------------------------------------------------------------

void __fastcall Tmain_form::Button1Click(TObject *Sender)
{
        if (op->Execute())    {
                  fill_file_info();
           }
}
//---------------------------------------------------------------------------
void Tmain_form::fill_file_info(){
                type_of_file->Text=FindSym('.',op->FileName);
                path_of_file->Text=op->FileName;
                name_of_file->Text=FindSym('\\',op->FileName);
                size_of_file->Text=FileSize(op->FileName);
}
//---------------------------------------------------------------------------
void Tmain_form::fill_bar(){
        for(double i=0.0;i< pb->Max;i+=0.0001)
        {
                pb->Position=i;
        }
        ShowMessage("   Готово!");
}
//---------------------------------------------------------------------------
void __fastcall Tmain_form::show_completeClick(TObject *Sender)
{
        AnsiString FilePath=PathToFile(Application->ExeName);
        if(type_of_file->Text==""){
                FilePath+="\\files\\Res\\";
                ShellExecute(Handle, "open", FilePath.c_str(), NULL, NULL, SW_SHOWNORMAL);  }
         if(type_of_file->Text=="LOL"){
                FilePath+="\\files\\Res\\Розшифровані файли\\";
                ShellExecute(Handle, "open", FilePath.c_str(), NULL, NULL, SW_SHOWNORMAL);  }
        else{
                FilePath+="\\files\\Res\\Зашифровані файли\\";
                ShellExecute(Handle, "open", FilePath.c_str(), NULL, NULL, SW_SHOWNORMAL);
        }
}
//---------------------------------------------------------------------------
void __fastcall Tmain_form::FormClose(TObject *Sender, TCloseAction &Action)
{
          exit_form->ShowExit();
}
//---------------------------------------------------------------------------
void __fastcall Tmain_form::BitBtn1Click(TObject *Sender)
{
        Edit1->Text="";
}
//---------------------------------------------------------------------------
void __fastcall Tmain_form::BitBtn2Click(TObject *Sender)
{
        if(op->FileName=="")
        {
                ShowMessage("Выберите файл!");
        }
        else
        {
               if(Edit1->Text=="Введите пароль"||Edit1->Text=="")
                {
                        ShowMessage("Введите пароль!");
                }
                else{
                ShowMessage("\tУвага!\nЙде підготовка файлу!");
                  read_file(op->FileName.c_str(),Application->ExeName,Edit1->Text);
                  if( file_exist->ModalResult==mrNone || file_exist->ModalResult==mrOk)
                  fill_bar();
                  }
        }
}
//---------------------------------------------------------------------------
void __fastcall Tmain_form::cbClick(TObject *Sender)
{
        if(cb->Checked==false)
        {
                Edit1->PasswordChar=0;
        }
        else
        {
                Edit1->PasswordChar='*';
        }
}
//---------------------------------------------------------------------------
void __fastcall Tmain_form::N2Click(TObject *Sender)
{
          exit_form->ShowExit();
}
//---------------------------------------------------------------------------
void __fastcall Tmain_form::N4Click(TObject *Sender)
{
        _random_pass_form->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall Tmain_form::N3Click(TObject *Sender)
{
       help_form->ShowModal();
}
//---------------------------------------------------------------------------



void __fastcall Tmain_form::FormShow(TObject *Sender)
{
        hello_form->ShowModal();
}
//---------------------------------------------------------------------------

