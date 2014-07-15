object FormBorrarPartido: TFormBorrarPartido
  Left = 216
  Top = 130
  Width = 329
  Height = 146
  Caption = 'Borrar partido'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 8
    Width = 59
    Height = 13
    Caption = 'Equipo casa'
  end
  object Label2: TLabel
    Left = 16
    Top = 56
    Width = 75
    Height = 13
    Caption = 'Equipo visitante'
  end
  object ComboBoxEquipoCasa: TComboBox
    Left = 16
    Top = 24
    Width = 161
    Height = 21
    ItemHeight = 13
    TabOrder = 0
    Text = 'Elige el equipo de casa'
  end
  object ComboBoxEquipoVisitante: TComboBox
    Left = 16
    Top = 72
    Width = 161
    Height = 21
    ItemHeight = 13
    TabOrder = 1
    Text = 'Elige el equipo visitante'
  end
  object ButtonBorrarEquipo: TButton
    Left = 200
    Top = 24
    Width = 105
    Height = 25
    Caption = 'Borrar'
    TabOrder = 2
    OnClick = ButtonBorrarEquipoClick
  end
  object ButtonCancelar: TButton
    Left = 200
    Top = 64
    Width = 105
    Height = 25
    Caption = 'Cancelar'
    TabOrder = 3
    OnClick = ButtonCancelarClick
  end
end
