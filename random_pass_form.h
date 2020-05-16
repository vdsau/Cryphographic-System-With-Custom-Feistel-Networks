//---------------------------------------------------------------------------

#ifndef random_pass_formH
#define random_pass_formH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include"classes.h"
#include <Buttons.hpp>

//---------------------------------------------------------------------------
class T_random_pass_form : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox2;
        TEdit *Edit1;
        TLabel *Label1;
        TComboBox *cb;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TEdit *Edit2;
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall Edit1Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall T_random_pass_form(TComponent* Owner);
        _random_password *lol;
};
//---------------------------------------------------------------------------
extern PACKAGE T_random_pass_form *_random_pass_form;
//---------------------------------------------------------------------------
#endif
