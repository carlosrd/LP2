//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UtLinea.h"
//-----------------------------------------------------
void tLinea::dibujar(TCanvas* canvas){

        canvas->Pen->Width = grosorLinea;
        canvas->Pen->Color = color;
        canvas->MoveTo(Xini,Yini);
        canvas->LineTo(Xfin,Yfin);

} // dibujar
//------------------------------------------------------
tGrafico* tLinea::copiar()
{
        tGrafico* grafico;
        grafico = new tLinea(Xini,Yini,Xfin,Yfin,color,
                             relleno,grosorLinea);
        return grafico;
}
//--------------------------------------------------------
void tLinea::salvarFich(ofstream& archivo)
{
        archivo << " \\XIni " << Xini << " \\YIni " << Yini
        << " \\XFin " << Xfin << " \\YFin " << Yfin
        << " \\GrosorLapiz " << grosorLinea
        << " \\Color " << color << endl;
}
//---------------------------------------------------------------------------
void tLinea::leerFich(ifstream& archivo)
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
}




//---------------------------------------------------------------------------

#pragma package(smart_init)
