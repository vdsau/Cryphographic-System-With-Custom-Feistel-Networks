//---------------------------------------------------------------------------

#ifndef mcH
#define mcH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
#include <Menus.hpp>
#include <sys/stat.h>


#include"classes.h"
#include"_exit_form.h"
#include"random_pass_form.h"
#include"_help_form.h"
#include"_hello_form.h"

//---------------------------------------------------------------------------
class Tmain_form : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TOpenDialog *op;
        TLabel *Label;
        TGroupBox *GroupBox1;
        TEdit *type_of_file;
        TLabel *Label1;
        TLabel *Label2;
        TEdit *name_of_file;
        TEdit *path_of_file;
        TEdit *size_of_file;
        TLabel *Label3;
        TProgressBar *pb;
        TLabel *Label4;
        TButton *show_complete;
        TGroupBox *GroupBox2;
        TGroupBox *GroupBox3;
        TGroupBox *GroupBox4;
        TGroupBox *GroupBox5;
        TEdit *Edit1;
        TLabel *Label5;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TCheckBox *cb;
        TMainMenu *MainMenu1;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *N3;
        TMenuItem *N4;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall show_completeClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall cbClick(TObject *Sender);
        void __fastcall N2Click(TObject *Sender);
        void __fastcall N4Click(TObject *Sender);
        void __fastcall N3Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tmain_form(TComponent* Owner);
        void fill_file_info();
        void fill_bar();
};
//---------------------------------------------------------------------------
extern PACKAGE Tmain_form *main_form;
//---------------------------------------------------------------------------
#endif
