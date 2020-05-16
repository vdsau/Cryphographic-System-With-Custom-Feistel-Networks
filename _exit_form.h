//---------------------------------------------------------------------------

#ifndef _exit_formH
#define _exit_formH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class Texit_form : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TBitBtn *btn_ok;
        TBitBtn *btn_no;
private:	// User declarations
public:		// User declarations
        __fastcall Texit_form(TComponent* Owner);
        void ShowExit(){
                if(this->ShowModal()==mrOk) Application->Terminate();
                else    Application->Run();
        }
};
//---------------------------------------------------------------------------
extern PACKAGE Texit_form *exit_form;
//---------------------------------------------------------------------------
#endif
