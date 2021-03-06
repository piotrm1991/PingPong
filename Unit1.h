//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *background;
        TImage *paddleLeft;
        TTimer *leftPaddleUp;
        TTimer *leftPaddleDown;
        TImage *paddleRight;
        TTimer *rightPaddleUp;
        TTimer *rightPaddleDown;
        TImage *ball;
        TTimer *ballMovement;
        TLabel *winnerLeft;
        TLabel *winnerRight;
        TLabel *points;
        TLabel *bounces;
        TButton *nextRound;
        TButton *newGame;
        TButton *newGameStart;
        void __fastcall leftPaddleUpTimer(TObject *Sender);
        void __fastcall leftPaddleDownTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall rightPaddleUpTimer(TObject *Sender);
        void __fastcall rightPaddleDownTimer(TObject *Sender);
        void __fastcall ballMovementTimer(TObject *Sender);
        void __fastcall nextRoundClick(TObject *Sender);
        void __fastcall newGameClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall newGameStartClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
