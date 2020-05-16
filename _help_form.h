//---------------------------------------------------------------------------

#ifndef _help_formH
#define _help_formH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

//---------------------------------------------------------------------------
class Thelp_form : public TForm
{
__published:	// IDE-managed Components
        TMemo *Memo1;
        void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Thelp_form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Thelp_form *help_form;
//---------------------------------------------------------------------------
#endif
