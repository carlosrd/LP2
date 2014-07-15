object FormFiltro: TFormFiltro
  Left = 192
  Top = 124
  Width = 255
  Height = 186
  Caption = 'Añadir al filtro...'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 16
    Width = 185
    Height = 13
    Caption = 'Introduzca palabras para añadir al filtro:'
  end
  object Edit1: TEdit
    Left = 8
    Top = 32
    Width = 217
    Height = 21
    TabOrder = 0
  end
  object Button1: TButton
    Left = 72
    Top = 112
    Width = 75
    Height = 25
    Caption = 'Añadir'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Edit2: TEdit
    Left = 8
    Top = 56
    Width = 217
    Height = 21
    TabOrder = 2
  end
  object Edit3: TEdit
    Left = 8
    Top = 80
    Width = 217
    Height = 21
    TabOrder = 3
  end
end
