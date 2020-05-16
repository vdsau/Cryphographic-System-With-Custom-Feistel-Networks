object main_form: Tmain_form
  Left = 327
  Top = 122
  Width = 709
  Height = 572
  Caption = #1044#1080#1087#1083#1086#1084
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -21
  Font.Name = 'Times New Roman'
  Font.Style = [fsBold]
  Menu = MainMenu1
  OldCreateOrder = False
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 24
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 329
    Height = 526
    Align = alLeft
    Caption = #1042#1110#1076#1086#1084#1086#1089#1090#1110' '#1087#1088#1086' '#1092#1072#1081#1083
    TabOrder = 0
    object Label: TLabel
      Left = 107
      Top = 232
      Width = 109
      Height = 24
      Caption = #1058#1080#1087' '#1092#1072#1081#1083#1072':'
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label1: TLabel
      Left = 72
      Top = 144
      Width = 158
      Height = 24
      Caption = #1042#1080#1073#1088#1072#1085#1080#1081' '#1092#1072#1081#1083':'
    end
    object Label2: TLabel
      Left = 96
      Top = 32
      Width = 155
      Height = 24
      Caption = #1064#1083#1103#1093' '#1076#1086' '#1092#1072#1081#1083#1091':'
    end
    object Label3: TLabel
      Left = 72
      Top = 336
      Width = 192
      Height = 24
      Caption = #1056#1086#1079#1084#1110#1088' '#1092#1072#1081#1083#1072'('#1073#1072#1081#1090'):'
    end
    object type_of_file: TEdit
      Left = 96
      Top = 272
      Width = 137
      Height = 39
      Enabled = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
    end
    object name_of_file: TEdit
      Left = 24
      Top = 176
      Width = 281
      Height = 32
      TabOrder = 1
    end
    object path_of_file: TEdit
      Left = 24
      Top = 72
      Width = 281
      Height = 32
      TabOrder = 2
    end
    object size_of_file: TEdit
      Left = 24
      Top = 392
      Width = 281
      Height = 32
      Enabled = False
      TabOrder = 3
    end
    object Button1: TButton
      Left = 102
      Top = 458
      Width = 147
      Height = 25
      Cursor = crHandPoint
      Caption = #1042#1080#1073#1088#1072#1090#1080' '#1092#1072#1081#1083
      TabOrder = 4
      OnClick = Button1Click
    end
  end
  object GroupBox4: TGroupBox
    Left = 344
    Top = 0
    Width = 357
    Height = 526
    Align = alRight
    TabOrder = 1
    object GroupBox3: TGroupBox
      Left = 2
      Top = 265
      Width = 353
      Height = 145
      Align = alTop
      Caption = #1055#1088#1086#1075#1088#1077#1089' '#1087#1088#1086#1094#1077#1089#1091
      TabOrder = 0
      object Label4: TLabel
        Left = 34
        Top = 40
        Width = 286
        Height = 24
        Caption = #1064#1080#1092#1088#1091#1074#1072#1085#1085#1103'/'#1088#1086#1079#1096#1080#1092#1088#1091#1074#1072#1085#1085#1103
      end
      object pb: TProgressBar
        Left = 23
        Top = 88
        Width = 305
        Height = 33
        Cursor = crArrow
        Enabled = False
        Min = 0
        Max = 100
        Smooth = True
        Step = 1
        TabOrder = 0
      end
    end
    object GroupBox2: TGroupBox
      Left = 2
      Top = 410
      Width = 353
      Height = 105
      Align = alTop
      TabOrder = 1
      object show_complete: TButton
        Left = 80
        Top = 48
        Width = 209
        Height = 25
        Cursor = crHandPoint
        Caption = #1055#1086#1082#1072#1079#1072#1090#1080' '#1074' '#1082#1072#1090#1072#1083#1086#1079#1110
        TabOrder = 0
        OnClick = show_completeClick
      end
    end
    object GroupBox5: TGroupBox
      Left = 2
      Top = 26
      Width = 353
      Height = 239
      Align = alTop
      Caption = #1055#1072#1088#1086#1083#1100' '#1076#1083#1103' '#1092#1072#1081#1083#1072
      TabOrder = 2
      object Label5: TLabel
        Left = 40
        Top = 104
        Width = 4
        Height = 19
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Edit1: TEdit
        Left = 16
        Top = 40
        Width = 281
        Height = 32
        TabOrder = 0
        Text = #1042#1074#1077#1076#1110#1090#1100' '#1087#1072#1088#1086#1083#1100
      end
      object BitBtn1: TBitBtn
        Left = 304
        Top = 40
        Width = 30
        Height = 30
        Cursor = crHandPoint
        Hint = #1054#1095#1080#1089#1090#1080#1090#1100' '#1087#1086#1083#1077' '#1074#1074#1086#1076#1072
        Caption = '&'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
        OnClick = BitBtn1Click
        Kind = bkRetry
      end
      object BitBtn2: TBitBtn
        Left = 256
        Top = 192
        Width = 75
        Height = 25
        Cursor = crHandPoint
        TabOrder = 2
        OnClick = BitBtn2Click
        Kind = bkOK
      end
      object cb: TCheckBox
        Left = 16
        Top = 80
        Width = 217
        Height = 17
        Cursor = crHandPoint
        Caption = #1057#1093#1086#1074#1072#1090#1080' '#1089#1080#1084#1074#1086#1083#1080
        TabOrder = 3
        OnClick = cbClick
      end
    end
  end
  object op: TOpenDialog
    Left = 656
    Top = 488
  end
  object MainMenu1: TMainMenu
    Left = 608
    Top = 488
    object N1: TMenuItem
      Caption = #1055#1072#1088#1086#1083#1100
      object N4: TMenuItem
        Caption = #1057#1090#1074#1086#1088#1080#1090#1080' '#1074#1080#1087#1072#1076#1082#1086#1074#1080#1081' '#1087#1072#1088#1086#1083#1100
        OnClick = N4Click
      end
    end
    object N3: TMenuItem
      Caption = #1044#1086#1087#1086#1084#1086#1075#1072
      OnClick = N3Click
    end
    object N2: TMenuItem
      Caption = #1042#1080#1093#1110#1076
      OnClick = N2Click
    end
  end
end
