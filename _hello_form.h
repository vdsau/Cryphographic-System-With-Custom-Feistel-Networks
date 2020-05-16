//---------------------------------------------------------------------------

#ifndef _hello_formH
#define _hello_formH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class Thello_form : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Thello_form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Thello_form *hello_form;
//---------------------------------------------------------------------------
#endif
