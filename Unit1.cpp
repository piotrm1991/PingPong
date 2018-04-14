//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "mmsystem.h"

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

 int ballMovementX = -8;
 int ballMovementY = -8;

 int pointsLeftPlayer = 0;
 int pointsRightPlayer = 0;

 int numberBounce = 0;

 bool winLeftPlayer = false;
 bool winRightPlayer = false;

 void menu()
 {
        Form1->ballMovement->Enabled = false;
        Form1->ball->Visible = false;

        if (winLeftPlayer)
        {
                Form1->winnerLeft->Visible = true;
                winLeftPlayer = false;
        }
        if (winRightPlayer)
        {
                Form1->winnerRight->Visible = true;
                winRightPlayer = false;
        }
        Form1->points->Caption = IntToStr(pointsLeftPlayer)+":"+IntToStr(pointsRightPlayer);
        Form1->points->Visible = true;
        Form1->bounces->Caption = "Iloœæ odbiæ: "+IntToStr(numberBounce);
        Form1->bounces->Visible = true;
        Form1->nextRound->Visible = true;
        Form1->newGame->Visible = true;
 }
 
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
void __fastcall TForm1::ballMovementTimer(TObject *Sender)
{
        ball->Left += ballMovementX;
        ball->Top += ballMovementY;

        //bounce top
        if (ball->Top-5 <= background->Top) ballMovementY = -ballMovementY;

        //bounce bottom
        if (ball->Top+ball->Height >= background->Height) ballMovementY = -ballMovementY;

        //bounce left paddle
        if (ball->Top > paddleLeft->Top-ball->Height/2 &&
            ball->Top < paddleLeft->Top+paddleLeft->Height &&
            ball->Left <= paddleLeft->Left+paddleLeft->Width)
            {
                if (ballMovementX<0)
                {
                numberBounce++;

                if (ball->Top > paddleLeft->Top+paddleLeft->Height/4 &&
                    ball->Top < paddleLeft->Top+(paddleLeft->Height/4)*3)
                    {
                        ballMovement->Interval -= 6;
                        ballMovementX = -ballMovementX;
                        sndPlaySound("snd/ping_pong_8bit_beeep.wav", SND_ASYNC);
                    } else
                    {
                        ballMovement->Interval = 20;
                        ballMovementX = -ballMovementX;
                        sndPlaySound("snd/ping_pong_8bit_peeeeeep.wav", SND_ASYNC);
                    }
                }
            }

        //lose left player
        if (ball->Left <= 0)
        {
                pointsRightPlayer++;
                winRightPlayer = true;
                menu();
        }

        //bounce right paddle
        if (ball->Top > paddleRight->Top-ball->Height/2 &&
            ball->Top < paddleRight->Top+paddleRight->Height &&
            ball->Left+ball->Width >= paddleRight->Left)
            {
                if (ballMovementX>0)
                {
                numberBounce++;

                if (ball->Top > paddleRight->Top+paddleRight->Height/4 &&
                    ball->Top < paddleRight->Top+(paddleRight->Height/4)*3)
                    {
                        ballMovement->Interval -= 6;
                        ballMovementX = -ballMovementX;
                        sndPlaySound("snd/ping_pong_8bit_beeep.wav", SND_ASYNC);
                    } else
                    {
                        ballMovement->Interval = 20;
                        ballMovementX = -ballMovementX;
                        sndPlaySound("snd/ping_pong_8bit_peeeeeep.wav", SND_ASYNC);
                    }
                }
            }

        //lose right player
        if (ball->Left >= paddleRight->Left+paddleRight->Width)
        {
                pointsLeftPlayer++;
                winLeftPlayer = true;
                menu();
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::nextRoundClick(TObject *Sender)
{
        ball->Top = 300;
        ball->Left = 630;
        points->Visible = false;
        bounces->Visible = false;
        winnerLeft->Visible = false;
        winnerRight->Visible = false;
        nextRound->Visible = false;
        newGame->Visible = false;
        ball->Visible = true;
        ballMovement->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::newGameClick(TObject *Sender)
{
        if (Application->MessageBox("Czy napewno chcesz zacz¹ænow¹ grê?" , "PotwierdŸ", MB_YESNO | MB_ICONQUESTION) == IDYES)
        {
                numberBounce = 0;
                pointsLeftPlayer = 0;
                pointsRightPlayer = 0;
                nextRoundClick(Form1);
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
        AnsiString part1 = "Witaj w grze PingPong!";
        AnsiString part2 = "Lewy gracz steruje wciskaj¹c klawisze A oraz Z.";
        AnsiString part3 = "Prawy gracz steruje wciskaj¹c strza³ki do góry i w dó³.";
        AnsiString part4 = "Kiedy odbijesz pi³kê œrodkiem paletki jej k¹t odbicia siê zmieni i pi³ka przyspieszy.";
        AnsiString part5 = "Mi³ej zabawy!";

        ShowMessage(part1 + sLineBreak + sLineBreak + part2 + sLineBreak + part3 + sLineBreak + sLineBreak + part4 + sLineBreak + sLineBreak + part5);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::newGameStartClick(TObject *Sender)
{
                numberBounce = 0;
                pointsLeftPlayer = 0;
                pointsRightPlayer = 0;
                newGameStart->Visible = false;
                nextRoundClick(Form1);
}
//---------------------------------------------------------------------------
