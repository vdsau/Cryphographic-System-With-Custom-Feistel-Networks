//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "_help_form.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Thelp_form *help_form;
//---------------------------------------------------------------------------
__fastcall Thelp_form::Thelp_form(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall Thelp_form::FormActivate(TObject *Sender)
{
        Memo1->Lines->LoadFromFile("files\\help.txt");
}
//---------------------------------------------------------------------------


