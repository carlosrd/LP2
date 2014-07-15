object FormListadoPartidos: TFormListadoPartidos
  Left = 194
  Top = 112
  Width = 696
  Height = 337
  Caption = 'Listado de partidos'
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
    Top = 16
    Width = 265
    Height = 21
    ItemHeight = 13
    TabOrder = 0
    Text = 'Elige un equipo'
    OnChange = ComboBoxEquipoChange
  end
  object GridListadoPartidos: TStringGrid
    Left = 24
    Top = 48
    Width = 633
    Height = 193
    FixedCols = 0
    RowCount = 10
    TabOrder = 1
    ColWidths = (
      94
      110
      99
      134
      171)
  end
  object ButtonCancelar: TButton
    Left = 560
    Top = 256
    Width = 97
    Height = 25
    Caption = 'Cancelar'
    TabOrder = 2
    OnClick = ButtonCancelarClick
  end
end
