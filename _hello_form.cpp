//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "_hello_form.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Thello_form *hello_form;
//---------------------------------------------------------------------------
__fastcall Thello_form::Thello_form(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Thello_form::FormCreate(TObject *Sender)
{
        Label1->Caption="������� ������� � �������� �SF!\n�������� ���� ��� �������:\n1)��������� ������������ ������;\n2)���������� �����;\n3)������������� �����;";
}
//---------------------------------------------------------------------------