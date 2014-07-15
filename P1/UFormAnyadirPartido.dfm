object FormAnyadirPartido: TFormAnyadirPartido
  Left = 376
  Top = 156
  Width = 293
  Height = 191
  Caption = 'Añadir partido'
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
    Top = 16
    Width = 59
    Height = 13
    Caption = 'Equipo casa'
  end
  object Label2: TLabel
    Left = 16
    Top = 64
    Width = 75
    Height = 13
    Caption = 'Equipo visitante'
  end
  object Label3: TLabel
    Left = 200
    Top = 16
    Width = 30
    Height = 13
    Caption = 'Goles:'
  end
  object Label4: TLabel
    Left = 200
    Top = 64
    Width = 30
    Height = 13
    Caption = 'Goles:'
  end
  object ComboBoxEquipoCasa: TComboBox
    Left = 16
    Top = 32
    Width = 153
    Height = 21
    ItemHeight = 13
    TabOrder = 0
    Text = 'Elige el equipo de casa'
  end
  object ComboBoxEquipoVisitante: TComboBox
    Left = 16
    Top = 80
    Width = 153
    Height = 21
    ItemHeight = 13
    TabOrder = 1
    Text = 'Elige el equipo visitante'
  end
  object EditGolesEquipoCasa: TEdit
    Left = 200
    Top = 32
    Width = 65
    Height = 21
    TabOrder = 2
  end
  object EditGolesEquipoVisitante: TEdit
    Left = 200
    Top = 80
    Width = 65
    Height = 21
    TabOrder = 3
  end
  object ButtonAnyadirEquipo: TButton
    Left = 48
    Top = 120
    Width = 81
    Height = 25
    Caption = 'Añadir'
    TabOrder = 4
    OnClick = ButtonAnyadirEquipoClick
  end
  object ButtonCancelar: TButton
    Left = 152
    Top = 120
    Width = 81
    Height = 25
    Caption = 'Cancelar'
    TabOrder = 5
    OnClick = ButtonCancelarClick
  end
end
