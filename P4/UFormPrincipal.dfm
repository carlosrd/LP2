object FormPrincipal: TFormPrincipal
  Left = 209
  Top = 154
  Width = 523
  Height = 538
  Caption = 'Indices'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 200
    Top = 8
    Width = 79
    Height = 37
    Caption = 'Texto'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Memo1: TMemo
    Left = 40
    Top = 56
    Width = 425
    Height = 393
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
  end
  object MainMenu1: TMainMenu
    Left = 40
    Top = 16
    object Archivo1: TMenuItem
      Caption = 'Archivo'
      object Nuevotexto1: TMenuItem
        Caption = 'Nuevo texto'
        OnClick = Nuevotexto1Click
      end
      object Abrirtexto1: TMenuItem
        Caption = 'Abrir'
        OnClick = Abrirtexto1Click
      end
      object Guardartexto1: TMenuItem
        Caption = 'Guardar'
        OnClick = Guardartexto1Click
      end
      object Guardarcomo1: TMenuItem
        Caption = 'Guardar como...'
        OnClick = Guardarcomo1Click
      end
      object Salir1: TMenuItem
        Caption = 'Salir'
        OnClick = Salir1Click
      end
    end
    object IndicedePalabras1: TMenuItem
      Caption = 'Indice de Palabras'
      object Generar1: TMenuItem
        Caption = 'Generar'
        OnClick = Generar1Click
      end
      object Mostrar1: TMenuItem
        Caption = 'Mostrar'
        OnClick = Mostrar1Click
      end
    end
    object IndiceGeneral2: TMenuItem
      Caption = 'Indice General'
      object Generar2: TMenuItem
        Caption = 'Generar'
        OnClick = Generar2Click
      end
      object Mostrar2: TMenuItem
        Caption = 'Mostrar'
      end
    end
    object IndiceGeneral1: TMenuItem
      Caption = 'Filtro'
      object Archivo2: TMenuItem
        Caption = 'Archivo'
        object NuevoFiltro1: TMenuItem
          Caption = 'Nuevo filtro'
          OnClick = NuevoFiltro1Click
        end
        object Abrirfiltro1: TMenuItem
          Caption = 'Abrir filtro...'
          OnClick = Abrirfiltro1Click
        end
        object Guardar1: TMenuItem
          Caption = 'Guardar'
          OnClick = Guardar1Click
        end
        object Guardarfiltrocomo1: TMenuItem
          Caption = 'Guardar filtro como...'
          OnClick = Guardarfiltrocomo1Click
        end
      end
      object AnyadirPalabra1: TMenuItem
        Caption = 'Añadir palabra'
        OnClick = AnyadirPalabra1Click
      end
      object Eliminarpalabra1: TMenuItem
        Caption = 'Eliminar palabra'
        OnClick = Eliminarpalabra1Click
      end
      object MostrarFiltro1: TMenuItem
        Caption = 'Mostrar Filtro'
        OnClick = MostrarFiltro1Click
      end
    end
  end
  object SaveDialog1: TSaveDialog
    Left = 104
    Top = 16
  end
  object OpenDialog1: TOpenDialog
    Left = 72
    Top = 16
  end
end
