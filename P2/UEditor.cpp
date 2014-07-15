//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UEditor.h"
#include "UtDibujo.h"
#include "UtDibujo.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"                                   
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
        dibujo = new UtDibujo();
        colorFondo = clWhite;
        colorActual = clBlack;
        //poliLineaActual = new PoliLinea();

        // inicializar booleanas sobre el estado del dibujo
        dibujarPolilinea = false;


        DoubleBuffered = true;
        ForceCurrentDirectory=true;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        if (dibujarPoliLinea){
           if (b==mbLeft){
                //...
              Punto* p = new Punto(X,Y,colorActual);
              poliLineaActual->ponPunto(p);
              }
            else
              if (b==mbRight) {
                 dibujo->ponPoliLinea(poliLineaActual);
                 poliLineaActual = new PoliLinea();
                 //...
                 }
            }
//---------------------------------------------------------------------------

