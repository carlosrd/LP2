//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UtBMP.h"
//---------------------------------------------------------------------------
void tBMP::dibujar(TCanvas* canvas){

        canvas->Draw(Xini,Yini,bmp);

} // dibujarBMP
//---------------------------------------------------------------------------
tGrafico* tBMP::copiar(){
        tGrafico* grafico;
        grafico = new tBMP(Xini,Yini,this->nombreArchivo);
        return grafico;
} // copiarBMP
//---------------------------------------------------------------------------
void tBMP::salvarFich(ofstream& archivo)
{
        archivo << " \\XIni " << Xini << " \\YIni " << Yini
        << " \\archivo " << nombreArchivo.c_str() << " \\FinRuta " << endl;
}
//---------------------------------------------------------------------------
void tBMP::leerFich(ifstream& archivo)
{
        string id;

        archivo >> id; // lee \XIni
        archivo >> Xini;
        archivo >> id; // lee \YIni
        archivo >> Yini;
        archivo >> id; // lee \Cadena
        archivo >> id;
        while (id !="\\FinRuta"){
              nombreArchivo += id.c_str();
              archivo >> id;
              nombreArchivo += " ";
              }
        nombreArchivo.Delete(nombreArchivo.Length(),1);
        try{
           bmp->LoadFromFile(nombreArchivo.c_str());
           }
        catch (const Exception &e){
           AnsiString msj = "Error al cargar BMP! Se esperaba el archivo: ";
           msj+=nombreArchivo;
           msj+=" Por favor compruebe que el archivo no haya sido movido o borrado.";
           ShowMessage(msj);
           bmp = NULL;
           }
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
