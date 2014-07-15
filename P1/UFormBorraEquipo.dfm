object FormBorrarEquipo: TFormBorrarEquipo
  Left = 198
  Top = 110
  Width = 237
  Height = 135
  Caption = 'Borrar equipo'
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
  object ComboBoxEquipo: TComboBox
    Left = 24
    Top = 24
    Width = 185
    Height = 21
    ItemHeight = 13
    TabOrder = 0
    Text = 'Elige un equipo'
  end
  object ButtonBorrarEquipo: TButton
    Left = 24
    Top = 56
    Width = 89
    Height = 25
    Caption = 'Borrar'
    TabOrder = 1
    OnClick = ButtonBorrarEquipoClick
  end
  object ButtonCancelar: TButton
    Left = 120
    Top = 56
    Width = 89
    Height = 25
    Caption = 'Cancelar'
    TabOrder = 2
    OnClick = ButtonCancelarClick
  end
end
