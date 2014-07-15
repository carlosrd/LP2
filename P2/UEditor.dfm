object Form1: TForm1
  Left = 116
  Top = 164
  Width = 696
  Height = 480
  Caption = 'Editor de Polilineas'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  OnMouseDown = FormMouseDown
  PixelsPerInch = 96
  TextHeight = 13
  object MainMenu1: TMainMenu
    Left = 104
    Top = 80
    object Polilinea1: TMenuItem
      Caption = 'Polilinea'
      object DibujarPolilinea1: TMenuItem
        Caption = 'Dibujar Polilinea'
      end
      object EliminarPolilinea1: TMenuItem
        Caption = 'Eliminar Polilinea'
      end
    end
    object ColorFondo1: TMenuItem
      Caption = 'Color Fondo'
    end
    object ColorPolilinea1: TMenuItem
      Caption = 'Color Polilinea'
    end
    object GrosorLinea1: TMenuItem
      Caption = 'Grosor Linea'
      object N11: TMenuItem
        Caption = '1'
      end
      object N21: TMenuItem
        Caption = '2'
      end
      object N31: TMenuItem
        Caption = '3'
      end
    end
  end
  object ColorDialog1: TColorDialog
    Ctl3D = True
    Left = 144
    Top = 80
  end
end
