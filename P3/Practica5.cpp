//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("Practica5.res");
USEFORM("UEditor.cpp", FormEditor);
USEUNIT("UtGrafico.cpp");
USEUNIT("UtRectangulo.cpp");
USEUNIT("UtVector.cpp");
USEUNIT("UtElipse.cpp");
USEUNIT("UtLinea.cpp");
USEUNIT("UtTexto.cpp");
USEUNIT("UtBMP.cpp");
USEFORM("UFormAux.cpp", FormAux);
USEUNIT("UExcepciones.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TFormEditor), &FormEditor);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
