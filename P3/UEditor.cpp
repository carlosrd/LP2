//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UEditor.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormEditor *FormEditor;
//---------------------------------------------------------------------------
__fastcall TFormEditor::TFormEditor(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormEditor::FormCreate(TObject *Sender)
{
        inicializarDibujo();
}
//---------------------------------------------------------------------------
void TFormEditor::inicializarDibujo()
{
        colorFondo = clWhite;
        FormEditor->Color = colorFondo;
        colorActual = clBlack;
        relleno = false;

        graficoActual = NULL;
        posGraficoActual = -1;
        grosorActual = 1;
        tamFuenteActual = 10;

        rutaArchivoActual = "";

        // inicializar booleanas sobre el estado del dibujo
        distanciaX = distanciaY = 0;
        
        dibujando = false;
        moviendo = false;
        StatusBar1->SimpleText = "Nuevo dibujo iniciado...";
        tipo_grafico = ninguno;

        DoubleBuffered = true;
        ForceCurrentDirectory = true;


        FormEditor->Caption = "Editor de Gráficos - Nuevo Dibujo";

} // inicializarDibujo

//---------------------------------------------------------------------------
void TFormEditor::limpiarDibujo()
{

        //graficoActual = NULL;
        vectorGraficos.borraTodo();
        Repaint();


} // inicializarDibujo

//---------------------------------------------------------------------------
void __fastcall TFormEditor::FormMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if (tipo_grafico == rectangulo){
           if (Button==mbLeft){
              graficoActual = new tRectangulo(X,Y,X,Y,colorActual,relleno,grosorActual);
              dibujando = true;
              } // if
           } // if

        if (tipo_grafico == elipse){
           if (Button==mbLeft){
              graficoActual = new tElipse(X,Y,X,Y,colorActual,relleno,grosorActual);
              dibujando = true;
              } // if
           } // if

        if (tipo_grafico == linea){
           if (Button==mbLeft){
              graficoActual = new tLinea(X,Y,X,Y,colorActual,relleno,grosorActual);
              dibujando = true;
              } // if
           } // if

        if ((!dibujando) && (tipo_grafico == texto)){
           if (Button==mbLeft){
              graficoActual = new tTexto(X,Y,X,Y,colorActual,relleno,grosorActual);
              ((tTexto*)graficoActual)->setTamFuente(tamFuenteActual);
              dibujando = true;
              } // if
           } // if

        if (tipo_grafico == BMP){
           if (Button==mbLeft){
              graficoActual = new tBMP(X,Y,OpenDialog1->FileName);
              vectorGraficos.ponElemento(graficoActual);
              graficoActual = NULL;
              Repaint();
              tipo_grafico = ninguno;
              } // if
           } // if

        if (tipo_grafico == selectGrafico){
           if (Button==mbLeft){
              graficoActual = buscaGrafico(X,Y,posGraficoActual);
              }
           }

        if (tipo_grafico == moveGrafico){
           if (Button==mbLeft){
              graficoActual = buscaGrafico(X,Y,posGraficoActual);
              if (graficoActual!=NULL){
                 int x1,y1,x2,y2;
                 graficoActual->getPuntoSingular(x1,y1);
                 graficoActual->getPuntoNoSingular(x2,y2);
                 distanciaX = x2-x1;
                 distanciaY = y2-y1;
                 moviendo = true;
                 }
              }
           }

        if ((tipo_grafico == copyGrafico) && (graficoActual!=NULL)){
           if (Button == mbLeft){
              tGrafico *copia;
              copia = graficoActual->copiar();

              int x1,y1,x2,y2;
              copia->getPuntoSingular(x1,y1);
              copia->getPuntoNoSingular(x2,y2);

              distanciaX = x2-x1;
              distanciaY = y2-y1;
              copia->setCoordenadas(X,Y,X+distanciaX,Y+distanciaY);

              vectorGraficos.ponElemento(copia);
              distanciaX = distanciaY = 0;
              copia = NULL;
              Repaint();
              }
           }



} // OnMouseDown
//---------------------------------------------------------------------------
void __fastcall TFormEditor::FormMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
        if ((dibujando) && (tipo_grafico!=texto)){
           int x,y;
           graficoActual->getPuntoSingular(x,y);
           graficoActual->setCoordenadas(x,y,X,Y);
           Repaint();
           }

        if (moviendo){
           graficoActual->setCoordenadas(X,Y,X+distanciaX,Y+distanciaY);
           Repaint();
           }
}
//---------------------------------------------------------------------------
void __fastcall TFormEditor::FormMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if ((dibujando) && (tipo_grafico!=texto)) {

           int x,y;
           graficoActual->getPuntoSingular(x,y);
           graficoActual->setCoordenadas(x,y,X,Y);

           vectorGraficos.ponElemento(graficoActual);
           Repaint();
           graficoActual = NULL;
           dibujando = false;
           }

        if (moviendo) {
           graficoActual->setCoordenadas(X,Y,X+distanciaX,Y+distanciaY);
           Repaint();
           graficoActual = NULL;
           moviendo = false;
           distanciaX = distanciaY = 0;
           }

}
//---------------------------------------------------------------------------
void __fastcall TFormEditor::pintarRectanguloClick(TObject *Sender)
{
        tipo_grafico = rectangulo;
        StatusBar1->SimpleText = "Herramienta Rectangulo - Archivo: " + rutaArchivoActual;
}
//---------------------------------------------------------------------------
void __fastcall TFormEditor::FormPaint(TObject *Sender)
{
        if ((tipo_grafico == selectGrafico) || (tipo_grafico == moveGrafico) ||
            (tipo_grafico == copyGrafico))
           dibujarGraficosConPS(Canvas);
         else {
           dibujarGraficos(Canvas);
           if (graficoActual !=NULL)
              graficoActual->dibujar(Canvas);
           }
}
//---------------------------------------------------------------------------
void TFormEditor::dibujarGraficos(TCanvas* canvas){

        tGrafico* grafico;
        int max = this->vectorGraficos.getNumElementos();

        for (int i=0; i<max; i++){
            grafico = vectorGraficos[i];
            grafico->dibujar(canvas);
            } // for

} // dibujarGraficos


void TFormEditor::dibujarGraficosConPS(TCanvas* canvas){

        tGrafico* grafico;
        int max = this->vectorGraficos.getNumElementos();

        for (int i=0; i<max; i++){
            grafico = vectorGraficos[i];
            grafico->dibujarConPS(canvas);
            } // for

} // dibujarGraficos

//---------------------------------------------------------------------------

void __fastcall TFormEditor::pintarElipseClick(TObject *Sender)
{
        tipo_grafico = elipse;
        StatusBar1->SimpleText = "Herramienta Elipse - Archivo: " + rutaArchivoActual;
}
//---------------------------------------------------------------------------

void __fastcall TFormEditor::pintarLineaClick(TObject *Sender)
{
        tipo_grafico = linea;
        StatusBar1->SimpleText = "Herramienta Linea - Archivo: " + rutaArchivoActual;
}
//---------------------------------------------------------------------------

void __fastcall TFormEditor::FormKeyPress(TObject *Sender, char &Key)
{
        //  "\r" = Enter (retorno carro)
        //  "\b" = Borrar (backspace)

        if (tipo_grafico == texto) {
           if (Key=='\r'){
              //tipo_grafico = ninguno;
              dibujando = false;
              vectorGraficos.ponElemento(graficoActual);
              graficoActual = NULL;
              }
            else {
              if (Key=='\b')
                 ((tTexto*)graficoActual)->borrarChar();
               else
                 ((tTexto*)graficoActual)->ponChar(Key);
              }
           }
        Repaint();
}
//---------------------------------------------------------------------------


void __fastcall TFormEditor::pintarTextoClick(TObject *Sender)
{
        tipo_grafico = texto;
        StatusBar1->SimpleText = "Herramienta Texto - Archivo: " + rutaArchivoActual;
}


void __fastcall TFormEditor::pintarBMPClick(TObject *Sender)
{
         OpenDialog1->Filter = "Imágenes de Mapas de Bits (*.bmp)|*.BMP";
        if (OpenDialog1->Execute())
           tipo_grafico = BMP;
           StatusBar1->SimpleText = "Insertar BMP - Archivo: " + rutaArchivoActual;
}
//---------------------------------------------------------------------------

void __fastcall TFormEditor::setRellenoClick(TObject *Sender)
{
        if (relleno!=true)
           setRelleno->Down = relleno = true;
         else 
           setRelleno->Down = relleno = false;

}
//---------------------------------------------------------------------------

void __fastcall TFormEditor::setColorRellenoClick(TObject *Sender)
{
        if (ColorDialog1->Execute()){
           Canvas->Pen->Color = ColorDialog1->Color;
           Canvas->Brush->Color = colorActual = ColorDialog1->Color;
           }
}
//---------------------------------------------------------------------------

void __fastcall TFormEditor::setColorFondoClick(TObject *Sender)
{
        if (ColorDialog1->Execute()){
           colorFondo = ColorDialog1->Color;
           FormEditor->Color = colorFondo;
           }
}
//---------------------------------------------------------------------------

void __fastcall TFormEditor::setGrosorLineaClick(TObject *Sender)
{
        TFormAux* x = new TFormAux(this);

        x->Caption = "Grosor";
        x->Label1->Caption = "Grosor de Línea:";
        x->ComboBox1->Text = "Sel. grosor";
        x->ComboBox1->Items->Values[1] = 1;
        x->ComboBox1->Items->Values[2] = 2;
        x->ComboBox1->Items->Values[3] = 3;
        x->ComboBox1->Items->Values[4] = 4;
        x->ShowModal();
        if (x->ModalResult == mrOk)
           grosorActual = x->ComboBox1->ItemIndex+1;

        delete x;
}
//---------------------------------------------------------------------------

void __fastcall TFormEditor::setTamFuenteClick(TObject *Sender)
{
        TFormAux* x = new TFormAux(this);

        x->Caption = "Fuente";
        x->Label1->Caption = "Tamaño de Fuente:";
        x->ComboBox1->Text = "Sel. tamaño";
        x->ComboBox1->Items->Values[0] = 10;
        x->ComboBox1->Items->Values[1] = 12;
        x->ComboBox1->Items->Values[2] = 14;
        x->ShowModal();
        if (x->ModalResult == mrOk){
           switch (x->ComboBox1->ItemIndex){
                case(0): tamFuenteActual = 10;
                         break;
                case(1): tamFuenteActual = 12;
                         break;
                case(2): tamFuenteActual = 14;
                         break;
                } // switch
           } // if

        delete x;
}
//---------------------------------------------------------------------------
tGrafico* TFormEditor::buscaGrafico(int x,int y,int &pos){

        int i = 0;
        int max = vectorGraficos.getNumElementos();
        int xg,yg;
        tGrafico *grafico = NULL;
        bool encontrado = false;

        while ((!encontrado) && (i<max)){
              grafico = vectorGraficos[i];
              grafico->getPuntoSingular(xg,yg);
              if (((x-4 <= xg) && (xg <= x+4)) &&
                  ((y-4 <= yg) && (yg <= y+4)))
                 encontrado = true;
               else {
                 encontrado = false;
                 i++;
                 } // else
              } // while

        if (encontrado) {
           pos = i;
           return grafico;
           }
         else {
           pos = -1;
           return NULL;
           }

} // seleccionarGrafico


void __fastcall TFormEditor::seleccionarGraficoClick(TObject *Sender)
{
        tipo_grafico = selectGrafico;
        Repaint();
        StatusBar1->SimpleText = "Herramienta de Selección - Archivo: " + rutaArchivoActual;       
}
//---------------------------------------------------------------------------

void __fastcall TFormEditor::borrarGraficoClick(TObject *Sender)
{
        StatusBar1->SimpleText = "Borrar Gráfico - Archivo: " + rutaArchivoActual;
        if ((graficoActual!=NULL) && (posGraficoActual!=-1)) {
           vectorGraficos.borraElemento(posGraficoActual);
           graficoActual = NULL;
           posGraficoActual = -1;
           Repaint();
           }
}
//---------------------------------------------------------------------------

void __fastcall TFormEditor::moverGraficoClick(TObject *Sender)
{
        StatusBar1->SimpleText = "Mover Gráfico - Archivo: " + rutaArchivoActual;
        tipo_grafico = moveGrafico;
        Repaint();        
}
//---------------------------------------------------------------------------

void __fastcall TFormEditor::copiarGraficoClick(TObject *Sender)
{
        tipo_grafico = copyGrafico;
        StatusBar1->SimpleText = "Copiar Gráfico - Archivo: " + rutaArchivoActual;
}
//---------------------------------------------------------------------------
void __fastcall TFormEditor::Guardarcomo1Click(TObject *Sender)
{
        SaveDialog1->Filter = "Dibujo de Gráficos (*.ddg)|*.DDG|Documento de Texto (*.txt)|*.TXT";
        if (SaveDialog1->Execute()){
           rutaArchivoActual = SaveDialog1->FileName.c_str();
           ofstream fs(rutaArchivoActual.c_str());

           fs << this->colorFondo << endl;
           vectorGraficos.guardarVector(fs);
           
           fs.close();

           FormEditor->Caption = "Editor de Gráficos - " + rutaArchivoActual;
           StatusBar1->SimpleText = "Dibujo guardado en: " + rutaArchivoActual;
           }
}
//---------------------------------------------------------------------------

void __fastcall TFormEditor::AbrirDibujo1Click(TObject *Sender)
{
        OpenDialog1->Filter = "Dibujo de Gráficos (*.ddg)|*.DDG|Documento de Texto (*.txt)|*.TXT";
        if (OpenDialog1->Execute()){

                rutaArchivoActual = OpenDialog1->FileName.c_str();
                ifstream fe(rutaArchivoActual.c_str());

                try {
                    string tmp;
                    getline(fe,tmp);
                    colorFondo = StrToInt(tmp.c_str());
                    }
                catch (const Exception& e) {
                    StatusBar1->SimpleText = "¡Error al cargar el archivo!: " + rutaArchivoActual;
                    Repaint();
                    rutaArchivoActual = "";
                    fe.close();
                    FormEditor->Color = clWhite;
                    throw Exception("¡Error al cargar colorFondo desde fichero! Compruebe que el archivo elegido es un archivo valido");
                    }

                FormEditor->Color = colorFondo;
                vectorGraficos.borraTodo();
                vectorGraficos.cargarVector(fe);

                FormEditor->Caption = "Editor de Gráficos - " + rutaArchivoActual;
                StatusBar1->SimpleText = "Dibujo abierto desde: " + rutaArchivoActual;

                Repaint();   
                fe.close();
           }
}
//---------------------------------------------------------------------------

void __fastcall TFormEditor::NuevoDibujo1Click(TObject *Sender)
{
        if (MessageDlg("Se va a crear un nuevo dibujo. Los cambios no guardados se perderán. ¿Desea continuar?",mtConfirmation,TMsgDlgButtons()<<mbYes<<mbNo,0)==mrYes)
        {
        vectorGraficos.borraTodo();
        Repaint();
        rutaArchivoActual = "";
        FormEditor->Caption = "Editor de Gráficos - Nuevo Dibujo";
        StatusBar1->SimpleText = "Nuevo dibujo iniciado...";
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormEditor::NuevoDibujoButtonClick(TObject *Sender)
{
        NuevoDibujo1Click(this);
}
//---------------------------------------------------------------------------

void __fastcall TFormEditor::AbrirDibujoButtonClick(TObject *Sender)
{
        AbrirDibujo1Click(this);
}
//---------------------------------------------------------------------------

void __fastcall TFormEditor::Guardar1Click(TObject *Sender)
{
        if (rutaArchivoActual!=""){
           ofstream fs(rutaArchivoActual.c_str());

           fs << this->colorFondo << endl;
           vectorGraficos.guardarVector(fs);

           fs.close();
           }
         else
           Guardarcomo1Click(this);
}
//---------------------------------------------------------------------------

void __fastcall TFormEditor::GuardarDibujoButtonClick(TObject *Sender)
{
        Guardar1Click(this);
}
//---------------------------------------------------------------------------

void __fastcall TFormEditor::Salir1Click(TObject *Sender)
{
        Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormEditor::FormCloseQuery(TObject *Sender,
      bool &CanClose)
{
  if (MessageDlg("¿Desea salir de la aplicación? Los cambios no guardados se perderán", mtConfirmation, TMsgDlgButtons() << mbYes << mbCancel,0) == mrCancel)
    CanClose = false;

}
//---------------------------------------------------------------------------

void __fastcall TFormEditor::Seleccionar1Click(TObject *Sender)
{
        seleccionarGraficoClick(this);
}
//---------------------------------------------------------------------------

void __fastcall TFormEditor::CopiarGrafico1Click(TObject *Sender)
{
        borrarGraficoClick(this);
}
//---------------------------------------------------------------------------

void __fastcall TFormEditor::CopiarGrfico1Click(TObject *Sender)
{
        moverGraficoClick(this);        
}
//---------------------------------------------------------------------------

void __fastcall TFormEditor::CopiarGrfico2Click(TObject *Sender)
{
        copiarGraficoClick(this);        
}
//---------------------------------------------------------------------------

