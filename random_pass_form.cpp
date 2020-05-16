//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "random_pass_form.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
T_random_pass_form *_random_pass_form;
//---------------------------------------------------------------------------
__fastcall T_random_pass_form::T_random_pass_form(TComponent* Owner)
        : TForm(Owner)
{
        lol=new _random_password();
}
//---------------------------------------------------------------------------
void __fastcall T_random_pass_form::BitBtn2Click(TObject *Sender)
{
        lol->change_size(Edit1->Text.ToInt());
        lol->change_lang(cb->ItemIndex);
        Edit2->Text=lol->out();
        BitBtn1->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall T_random_pass_form::BitBtn1Click(TObject *Sender)
{
        Edit2->Text="";
        Edit2->Text=lol->out();
}
//---------------------------------------------------------------------------
void __fastcall T_random_pass_form::Edit1Change(TObject *Sender)
{
BitBtn1->Enabled=false;        
}
//---------------------------------------------------------------------------
