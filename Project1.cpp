//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("mc.cpp", main_form);
USEFORM("_exit_form.cpp", exit_form);
USEFORM("file_exist_form.cpp", file_exist);
USEFORM("random_pass_form.cpp", _random_pass_form);
USEFORM("_help_form.cpp", help_form);
USEFORM("_hello_form.cpp", hello_form);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->Title = "Диплом";
                 Application->CreateForm(__classid(Tmain_form), &main_form);
                 Application->CreateForm(__classid(Texit_form), &exit_form);
                 Application->CreateForm(__classid(Tfile_exist), &file_exist);
                 Application->CreateForm(__classid(T_random_pass_form), &_random_pass_form);
                 Application->CreateForm(__classid(Thelp_form), &help_form);
                 Application->CreateForm(__classid(Thello_form), &hello_form);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
