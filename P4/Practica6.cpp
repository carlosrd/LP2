//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("Practica6.res");
USEFORM("UFormPrincipal.cpp", FormPrincipal);
USEUNIT("UListaOrd.cpp");
USEUNIT("UtBST.cpp");
USEUNIT("UtPalabra.cpp");
USEUNIT("UtNodoIndice.cpp");
USEFORM("UFormAux.cpp", FormAux);
USEFORM("UFormFiltro.cpp", FormFiltro);
USEUNIT("UExcepciones.cpp");
USEUNIT("USeccion.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TFormPrincipal), &FormPrincipal);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
