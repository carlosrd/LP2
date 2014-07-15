object FormAux: TFormAux
  Left = 203
  Top = 151
  Width = 199
  Height = 112
  Caption = 'FormAux'
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
    Width = 32
    Height = 13
    Caption = 'Label1'
  end
  object ButtonAceptar: TButton
    Left = 104
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Aceptar'
    TabOrder = 0
    OnClick = ButtonAceptarClick
  end
  object ButtonCancelar: TButton
    Left = 104
    Top = 40
    Width = 75
    Height = 25
    Caption = 'Cancelar'
    TabOrder = 1
    OnClick = ButtonCancelarClick
  end
  object ComboBox1: TComboBox
    Left = 8
    Top = 32
    Width = 89
    Height = 21
    ItemHeight = 13
    ParentShowHint = False
    ShowHint = False
    TabOrder = 2
  end
end
