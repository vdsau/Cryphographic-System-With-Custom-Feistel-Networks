//---------------------------------------------------------------------------

#ifndef file_exist_formH
#define file_exist_formH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class Tfile_exist : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
private:	// User declarations
public:		// User declarations
        __fastcall Tfile_exist(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfile_exist *file_exist;
//---------------------------------------------------------------------------
#endif
