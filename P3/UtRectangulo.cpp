//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UtRectangulo.h"


// Métodos
// *******
void tRectangulo::dibujar(TCanvas* canvas)
{
        canvas->Brush->Color = color;

        if (relleno == true)
           canvas->Brush->Style = bsSolid;
         else
           canvas->Brush->Style = bsClear;

        canvas->Pen->Width = grosorLinea;
        canvas->Pen->Color = color;
        canvas->Rectangle(Xini,Yini,Xfin,Yfin);
} // dibujar
//--------------------------------------------------------
tGrafico* tRectangulo::copiar()
{
        tGrafico* grafico;
        grafico = new tRectangulo(Xini,Yini,Xfin,Yfin,color,
                                  relleno,grosorLinea);
        return grafico;

} // copiarRectangulo
//--------------------------------------------------------
void tRectangulo::salvarFich(ofstream& archivo)
{
        archivo << " \\XIni " << Xini << " \\YIni " << Yini
        << " \\XFin " << Xfin << " \\YFin " << Yfin
        << " \\GrosorLapiz " << grosorLinea
        << " \\Color " << color
        << " \\Relleno " << relleno << endl;
}
//---------------------------------------------------------------------------
void tRectangulo::leerFich(ifstream& archivo)
{
        string id;
        archivo >> id; // lee \XIni
        archivo >> Xini;
        archivo >> id; // lee \YIni
        archivo >> Yini;
        archivo >> id; // lee \XFin
        archivo >> Xfin;
        archivo >> id; // lee \YFin
        archivo >> Yfin;
        archivo >> id; // lee \GrosorLapiz
        archivo >> grosorLinea;
        archivo >> id; // lee \Color
        archivo >> id;
        color = StrToInt(id.c_str());
        archivo >> id; // lee \Relleno
        archivo >> relleno;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
