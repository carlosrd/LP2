//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("Practica4.res");
USEFORM("UEditor.cpp", Form1);
USEUNIT("ULista.cpp");
USEUNIT("UPolilinea.cpp");
USEUNIT("UPunto.cpp");
USEUNIT("UtDibujo.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
