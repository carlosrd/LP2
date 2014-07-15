//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UtTexto.h"
void tTexto::dibujar(TCanvas* canvas){

        canvas->Font->Size = tam;
        canvas->Font->Color = color;
        canvas->Brush->Style = bsClear;

        canvas->TextOutA(Xini,Yini,cadena);

} // dibujar
//---------------------------------------------------------------------------
tGrafico* tTexto::copiar(){
        tGrafico* grafico;
        grafico = new tTexto(Xini,Yini,Xfin,Yfin,color,
        relleno,grosorLinea);

        ((tTexto*)grafico)->cadena = this->cadena;
        ((tTexto*)grafico)->tam = this->tam;

        return grafico;
        }
//--------------------------------------------------------
void tTexto::salvarFich(ofstream& archivo)
{
        archivo << " \\XIni " << Xini << " \\YIni " << Yini
        << " \\Cadena " << cadena.c_str() << " \\TamFuente " << tam
        << " \\Color " << color << endl;
}
//---------------------------------------------------------------------------
void tTexto::leerFich(ifstream& archivo)
{
        string id;

        archivo >> id; // lee \XIni
        archivo >> Xini;
        archivo >> id; // lee \YIni
        archivo >> Yini;
        archivo >> id; // lee \Cadena
        archivo >> id;
        while (id !="\\TamFuente"){
              cadena += id.c_str();
              archivo >> id;
              cadena += " ";
              }
        // Leemos "\TamFuente" en el bucle
        archivo >> tam;
        archivo >> id; // lee \Color
        archivo >> id;
        color = StrToInt(id.c_str());

}

//---------------------------------------------------------------------------
#pragma package(smart_init)
