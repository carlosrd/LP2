object FormClasificacion: TFormClasificacion
  Left = 181
  Top = 215
  Width = 816
  Height = 456
  Caption = 'Clasificación'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MenuDesplegable
  OldCreateOrder = False
  OnCreate = crear_clasificacion
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object GridClasificacion: TStringGrid
    Left = 16
    Top = 16
    Width = 657
    Height = 361
    ColCount = 11
    FixedCols = 0
    RowCount = 10
    TabOrder = 0
    ColWidths = (
      62
      123
      86
      67
      65
      37
      35
      30
      29
      26
      64)
  end
  object ButtonAnyadirEquipo: TButton
    Left = 696
    Top = 16
    Width = 97
    Height = 33
    Caption = 'Añadir equipo'
    TabOrder = 1
    OnClick = b_anyadir_equipo
  end
  object ButtonBorrarEquipo: TButton
    Left = 696
    Top = 64
    Width = 97
    Height = 33
    Caption = 'Borrar equipo'
    TabOrder = 2
    OnClick = b_borrar_equipo
  end
  object ButtonAnyadirPartido: TButton
    Left = 696
    Top = 112
    Width = 97
    Height = 33
    Caption = 'Añadir partido'
    TabOrder = 3
    OnClick = b_anyadir_partido
  end
  object ButtonBorrarPartido: TButton
    Left = 696
    Top = 160
    Width = 97
    Height = 33
    Caption = 'Borrar Partido'
    TabOrder = 4
    OnClick = b_borrar_partido
  end
  object ButtonListadoPartidos: TButton
    Left = 696
    Top = 208
    Width = 97
    Height = 33
    Caption = 'Listado Partidos'
    TabOrder = 5
    OnClick = b_listado_partidos
  end
  object ButtonSalir: TButton
    Left = 696
    Top = 344
    Width = 97
    Height = 33
    Caption = 'Salir'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 6
    OnClick = ButtonSalirClick
  end
  object NuevoTorneo: TButton
    Left = 696
    Top = 296
    Width = 97
    Height = 33
    Caption = 'Nuevo Torneo...'
    TabOrder = 7
    OnClick = NuevoTorneoClick
  end
  object MenuDesplegable: TMainMenu
    Left = 696
    Top = 256
    object Archivo1: TMenuItem
      Caption = '&Archivo'
      object Nuevotorneo1: TMenuItem
        Caption = 'Nuevo torneo...'
        OnClick = Nuevotorneo1Click
      end
      object Abrirtorneo1: TMenuItem
        Caption = '&Abrir torneo'
        OnClick = Abrirtorneo1Click
      end
      object Guardartorneo1: TMenuItem
        Caption = '&Guardar torneo...'
        OnClick = Guardartorneo1Click
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object Salir1: TMenuItem
        Caption = '&Salir'
        OnClick = Salir1Click
      end
    end
  end
  object DlgAbrirTorneo: TOpenDialog
    Left = 728
    Top = 256
  end
  object DlgGuardarTorneo: TSaveDialog
    Left = 760
    Top = 256
  end
end
