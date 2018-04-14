//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::leftPaddleUpTimer(TObject *Sender)
{
        if (paddleLeft->Top > 5) paddleLeft->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::leftPaddleDownTimer(TObject *Sender)
{
        if (paddleLeft->Top + paddleLeft->Height < background->Height - 10) paddleLeft->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if ((Key == 'a') || (Key == 'A')) leftPaddleUp->Enabled = true;
        if ((Key == 'z') || (Key == 'Z')) leftPaddleDown->Enabled = true;
        if (Key == VK_UP) rightPaddleUp->Enabled = true;
        if (Key == VK_DOWN) rightPaddleDown->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if ((Key == 'a') || (Key == 'A')) leftPaddleUp->Enabled = false;
        if ((Key == 'z') || (Key == 'Z')) leftPaddleDown->Enabled = false;
        if (Key == VK_UP) rightPaddleUp->Enabled = false;
        if (Key == VK_DOWN) rightPaddleDown->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::rightPaddleUpTimer(TObject *Sender)
{
        if (paddleRight->Top > 5) paddleRight->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::rightPaddleDownTimer(TObject *Sender)
{
        if (paddleRight->Top + paddleRight->Height < background->Height - 10) paddleRight->Top += 10;
}
//---------------------------------------------------------------------------
