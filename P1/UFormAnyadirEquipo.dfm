object FormAnyadirEquipo: TFormAnyadirEquipo
  Left = 401
  Top = 133
  Width = 238
  Height = 125
  Caption = 'Añadir equipo'
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
    Left = 16
    Top = 8
    Width = 89
    Height = 13
    Caption = 'Nombre del equipo'
  end
  object EditNombreEquipo: TEdit
    Left = 16
    Top = 24
    Width = 201
    Height = 21
    TabOrder = 0
  end
  object ButtonAnyadirEquipo: TButton
    Left = 16
    Top = 56
    Width = 97
    Height = 25
    Caption = 'Añadir'
    TabOrder = 1
    OnClick = ButtonAnyadirEquipoClick
  end
  object ButtonCancelar: TButton
    Left = 128
    Top = 56
    Width = 89
    Height = 25
    Caption = 'Cancelar'
    TabOrder = 2
    OnClick = ButtonCancelarClick
  end
end
