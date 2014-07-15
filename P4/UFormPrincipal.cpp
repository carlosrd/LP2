//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormPrincipal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormPrincipal *FormPrincipal;
//---------------------------------------------------------------------------
__fastcall TFormPrincipal::TFormPrincipal(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormPrincipal::FormCreate(TObject *Sender)
{
        indicePalabras = NULL;
        filtro = new tBST<string>;
        Memo1->Lines->Clear();

        rutaArchivoActual = "";
        rutaArchivoFiltro = "";
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::FormDestroy(TObject *Sender)
{
       //if (indicePalabras != NULL)
        delete indicePalabras;
        delete filtro;
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::Generar1Click(TObject *Sender)
{
        delete indicePalabras;
        indicePalabras = new tBST<tNodoIndice*>;
        int numPag = 1;
        for (int i=0; i<Memo1->Lines->Count; i++){
            AnsiString linea = Memo1->Lines->Strings[i];
            procesarLinea(linea,numPag);
            }
        //ShowMessage("Indice de palabras generado correctamente!");
        Mostrar1Click(this);
        MostrarFiltro1Click(this);
}
//---------------------------------------------------------------------------
void TFormPrincipal::procesarLinea(AnsiString linea,int &numPag)
{
        int longLinea = linea.Length(); // 1..Length
        int i = 1;
        string pal;
        while (i <= longLinea){
              leerBlancos(linea,i);
              leerPalabra(linea,i,pal,numPag);
              }
}
//---------------------------------------------------------------------------
void TFormPrincipal::leerBlancos(AnsiString linea,int &i)
{
        int longLinea = linea.Length();
        while ((i <= longLinea) && (linea[i] == 32)) // ASCII: 32 = ' '
              i++;
}
//---------------------------------------------------------------------------
void TFormPrincipal::leerPalabra(AnsiString linea,int &i,string pal,int &numPag)
{
        int longLinea = linea.Length();
        while ((i <= longLinea) && (linea[i] != 32)){
              if (((65 <= linea[i]) && (linea[i] <= 90)) || // ASCII: A..Z = 65..90
                 ((97 <= linea[i]) && (linea[i] <= 122)) || // ASCII: a..z = 97..122
                 ((48 <= linea[i]) && (linea[i] <= 57)))    // ASCII: 0..1 = 48..57
                 pal += linea[i];
              i++;
              }

        if (pal != ""){
           if (pal =="newpage")
              numPag++;
            else {
              char letra = UpCase(pal[0]);
              bool estaEnFiltro = filtro->esta(pal);
              if (!estaEnFiltro){
                 tNodoIndice* ni = new tNodoIndice(letra,pal,numPag);
                 this->indicePalabras->insertar(ni);
                 }
              }
           }
}
void __fastcall TFormPrincipal::Mostrar1Click(TObject *Sender)
{
        if (this->indicePalabras != NULL){
           TFormAux* x = new TFormAux(this);
           x->Caption = "Indice de palabras";
           x->Label1->Caption = "Indice";
           x->Memo1->Clear();
           this->indicePalabras->mostrar(x->Memo1->Lines);
           x->Show();


           if (x->ModalResult == mrOk)
              delete x;
           }
         else
           ShowMessage("No se ha generado ningun indice de palabras!");
        
}
//---------------------------------------------------------------------------


void __fastcall TFormPrincipal::NuevoFiltro1Click(TObject *Sender)
{
        delete filtro;
        filtro = new tBST<string>;
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::AnyadirPalabra1Click(TObject *Sender)
{
        TFormFiltro* x = new TFormFiltro(this);

        x->Caption = "Añadir al filtro...";
        x->Label1->Caption = "Introduzca palabras para añadir al filtro:";
        x->Button1->Caption = "Añadir";

        x->ShowModal();

        if (x->ModalResult == mrOk){
           if (x->Edit1->Text != "")
              filtro->insertar(x->Edit1->Text.c_str());
           if (x->Edit2->Text != "")
              filtro->insertar(x->Edit2->Text.c_str());
           if (x->Edit3->Text != "")
              filtro->insertar(x->Edit3->Text.c_str());
           }
        delete x;
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::MostrarFiltro1Click(TObject *Sender)
{
        TFormAux* x = new TFormAux(this);

        x->Caption = "Filtro de palabras";
        x->Label1->Caption = "Filtro";
        x->Memo1->Clear();
        this->filtro->mostrar(x->Memo1->Lines);
        x->Show();

        if (ModalResult == mrOk)
                delete x;
}
//---------------------------------------------------------------------------


void __fastcall TFormPrincipal::Nuevotexto1Click(TObject *Sender)
{
        Memo1->Clear();        
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::Guardarcomo1Click(TObject *Sender)
{
        SaveDialog1->Filter = "Documento de Texto (*.txt)|*.TXT";
        if (SaveDialog1->Execute()){
           rutaArchivoActual = SaveDialog1->FileName;
           Memo1->Lines->SaveToFile(rutaArchivoActual);
           }
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::Abrirtexto1Click(TObject *Sender)
{
        OpenDialog1->Filter = "Documento de Texto (*.txt)|*.TXT";
        if (OpenDialog1->Execute()){
           rutaArchivoActual = OpenDialog1->FileName;
           Memo1->Lines->LoadFromFile(rutaArchivoActual);
           }
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::Salir1Click(TObject *Sender)
{
        Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::Guardarfiltrocomo1Click(TObject *Sender)
{
        SaveDialog1->Filter = "Filtro de palabras (*.FDP)|*.FDP|Documento de Texto (*.txt)|*.TXT";
        if (SaveDialog1->Execute()){
           rutaArchivoFiltro = SaveDialog1->FileName;
           ofstream fs(rutaArchivoFiltro.c_str());
           this->filtro->salvarArbol(fs);
           fs.close();
           }
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::Abrirfiltro1Click(TObject *Sender)
{
        OpenDialog1->Filter = "Filtro de palabras (*.FDP)|*.FDP|Documento de Texto (*.txt)|*.TXT";
        if (OpenDialog1->Execute()){
           delete filtro;
           filtro = new tBST<string>;
           rutaArchivoFiltro = OpenDialog1->FileName;
           ifstream fe(rutaArchivoFiltro.c_str());
           string tmp;

           while (fe >> tmp)
                 this->filtro->insertar(tmp);

           fe.close();

           MostrarFiltro1Click(this);
           }
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::Guardartexto1Click(TObject *Sender)
{
        if (rutaArchivoActual == "")
           Guardarcomo1Click(this);
         else
           Memo1->Lines->SaveToFile(rutaArchivoActual);
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::Guardar1Click(TObject *Sender)
{
        if (rutaArchivoFiltro == "")
           Guardarfiltrocomo1Click(this);
         else {
         /*Aux* x = new TFormAux(this);
           x->Memo1->Lines->Clear();
           this->filtro->mostrar(x->Memo1->Lines);
           x->Memo1->Lines->SaveToFile(rutaArchivoFiltro);

           delete x;
           /*/
           }
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::Eliminarpalabra1Click(TObject *Sender)
{
        TFormFiltro* x = new TFormFiltro(this);

        x->Caption = "Eliminar del filtro...";
        x->Label1->Caption = "Introduzca palabras para eliminar del filtro:";
        x->Button1->Caption = "Eliminar";
        x->ShowModal();


        if (x->ModalResult == mrOk){
           if (x->Edit1->Text != "")
              filtro->eliminar(x->Edit1->Text.c_str());
           if (x->Edit2->Text != "")
              filtro->eliminar(x->Edit2->Text.c_str());
           if (x->Edit3->Text != "")
              filtro->eliminar(x->Edit3->Text.c_str());
           }
        delete x;
}
//---------------------------------------------------------------------------


void __fastcall TFormPrincipal::Generar2Click(TObject *Sender)
{
        delete indiceGeneral;
        indicePalabras = new tListaOrd<Seccion>;
        int numSec = 0;
        int numSubSec = 0;
        int numSubSubSec = 0;
        int nivelSeccion = 0;
        int numPag = 1;
        for (int i=0; i<Memo1->Lines->Count; i++){
            AnsiString linea = Memo1->Lines->Strings[i];
            procesarLineaGeneral(linea,numPag,numSec,numSubSec,numSubSubSec,nivelSeccion);
            }
        //ShowMessage("Indice de palabras generado correctamente!");
        Mostrar1Click(this);
        MostrarFiltro1Click(this);
}
//---------------------------------------------------------------------------
void TFormPrincipal::procesarLineaGeneral(AnsiString linea,int &numPag,int &sec,int &subsec,int &subsubsec,int &nivel)
{
        int longLinea = linea.Length(); // 1..Length
        int i = 1;
        string pal;
        while (i <= longLinea){
              leerBlancos(linea,i);
              leerPalabraGeneral(linea,i,numPag,sec,subsec,subsubsec,nivel);
              }
}
//---------------------------------------------------------------------------
void TFormPrincipal::leerPalabraGeneral(AnsiString linea,int &i,int &numPag,int &sec,int &subsec,int &subsubsec,int &nivel)
{
        int longLinea = linea.Length();
        while ((i <= longLinea) && (linea[i] != 32)){
              if (((65 <= linea[i]) && (linea[i] <= 90)) || // ASCII: A..Z = 65..90
                 ((97 <= linea[i]) && (linea[i] <= 122)) || // ASCII: a..z = 97..122
                 ((48 <= linea[i]) && (linea[i] <= 57)))    // ASCII: 0..1 = 48..57
                 pal += linea[i];
              i++;
              }
        enum nivelActual{nada,seccion,subseccion,subsubseccion};
        nivelActual nivel = nada;
        if (pal != ""){
           if (pal =="\\newpage")
              numPag++;
            else {
              if ((pal == "\\seccion") || (pal == "\\subseccion") || (pal == "\\subsubseccion))
                 switch (pal){
                        case "\\seccion": nivel = seccion; break;
                        case "\\subseccion": {
                                             if (nivel == seccion)
                                                nivel = subseccion;
                                              else
                                                nivel = seccion;
                                              }
                                             break;
                        case "\\subsubsec": {
                                            if (nivel == seccion)
                                                nivel = subseccion;
                                              else
                                                if (nivel == subseccion);
                                                   nivel = subsubseccion;
                                            }
                                             break;
                        }
                 Seccion s;
                 // Generar string seccion
                 AnsiString aux = sec:
                 aux += "."
                 if (subsec != 0){
                    aux += subsec;
                    aux += ".";
                    }
                  else
                    aux += "..";
                 if (subsubsec != 0){
                    aux += subsubsec;
                    aux += ".";
                    }
                  else
                    aux += "..";
              // Generar titulo
                 AnsiString title = "";
                 while ((i <= longLinea){
                        title += linea[i];
                        i++;
                        }
                 while ((longLinea <=20){
                        title += ".";
                        i++;
                        }

                 s.seccion = aux;
                 s.titulo = title;
                 s.numPag = numPag;
                 indiceGeneral->insertar(s);



              char letra = UpCase(pal[0]);
              bool estaEnFiltro = filtro->esta(pal);
              if (!estaEnFiltro){
                 tNodoIndice* ni = new tNodoIndice(letra,pal,numPag);
                 this->indicePalabras->insertar(ni);
                 }
              }
           }

}
//---------------------------------------------------------------------------

