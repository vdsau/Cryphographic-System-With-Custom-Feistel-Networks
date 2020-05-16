//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "file_exist_form.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfile_exist *file_exist;
//---------------------------------------------------------------------------
__fastcall Tfile_exist::Tfile_exist(TComponent* Owner)
        : TForm(Owner)
{
        Label1->Caption="  Файл буде перезаписаний!\n\tПродовжити?";
}
//---------------------------------------------------------------------------
