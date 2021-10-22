
// MFCApplication11564651567Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication11564651567.h"
#include "MFCApplication11564651567Dlg.h"
#include "afxdialogex.h"
#include "Game.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Colors Sheet
int color[6][3] = {  /* Black */0, 0, 0, /* Blue */0, 0, 255, /* Gray */230, 230, 230, /* Green */0,255, 0, /* Red */255, 0, 0, /* Yellow */255, 255, 0 };

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// Temporary Points For Drawing
int pointX1 = 0;
int pointX2 = 0;
int pointY1 = 0;
int pointY2 = 0;

// Build Combo Boxes Parameters
void ColorsCombo(CComboBox& Combo)
{
	Combo.AddString(_T("Gray"));
	Combo.AddString(_T("Green"));
	Combo.AddString(_T("Red"));
	Combo.AddString(_T("Blue"));
	Combo.AddString(_T("Black"));
	Combo.AddString(_T("Yellow"));
}

// Draw The Ball
void CMFCApplication11564651567Dlg::Draw_Ball(CPaintDC& dc, Ball& ball)
{
	// Get Ball Position
	pointX1 = (int)(ball.Get_x_pixel(myGame->getParams()) + SHIFT);
	pointY1 = (int)(ball.Get_y_pixel(myGame->getParams()) + SHIFT);
	int radius = ball.Get_Radius_Pixel(myGame->getParams());
	
	// Draw Ball
	dc.Ellipse (pointX1- radius, pointY1- radius, pointX1 + radius, pointY1 + radius);
}

// Draw Walls & Racquet
void CMFCApplication11564651567Dlg::Draw_Line(CPaintDC& dc, Wall* wall)
{
	// Get Wall Position
	pointX1 = wall->Get_x1_pixel(myGame->getParams()) + SHIFT;
	pointY1 = wall->Get_y1_pixel(myGame->getParams()) + SHIFT;
	pointX2 = wall->Get_x2_pixel(myGame->getParams()) + SHIFT;
	pointY2 = wall->Get_y2_pixel(myGame->getParams()) + SHIFT;

	// Draw Wall Or Racquet
	dc.MoveTo(pointX1, pointY1);
	dc.LineTo(pointX2, pointY2);
}

CMFCApplication11564651567Dlg::CMFCApplication11564651567Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION11564651567_DIALOG, pParent)
	, Velocity(8)
	, ReturnNoise(0)
	, CurrentScore(0)
	, BestScore(0)
	, LeftWallComboValue(0)
	, RightWallComboValue(0)
	, UpperWallComboValue(0)
	, RacquetComboValue(0)
	, BallComboValue(0)
	, isPressed(false)
	, CurrentScoreStr(_T("0"))
	, BestScoreStr(_T("0"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication11564651567Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_COMBO1, LeftWallComboControl);
	DDX_CBIndex(pDX, IDC_COMBO1, LeftWallComboValue);
	DDX_Control(pDX, IDC_COMBO2, RightWallComboBox);
	DDX_CBIndex(pDX, IDC_COMBO2, RightWallComboValue);
	DDX_Control(pDX, IDC_COMBO3, UpperWallComboBox);
	DDX_CBIndex(pDX, IDC_COMBO3, UpperWallComboValue);
	DDX_Control(pDX, IDC_COMBO4, RacquetComboBox);
	DDX_CBIndex(pDX, IDC_COMBO4, RacquetComboValue);
	DDX_Control(pDX, IDC_COMBO5, BallComboBox);
	DDX_CBIndex(pDX, IDC_COMBO5, BallComboValue);

	DDX_Text(pDX, IDC_EDIT2, Velocity);
	DDV_MinMaxDouble(pDX, Velocity, 1, 15);

	DDX_Text(pDX, IDC_EDIT3, ReturnNoise);
	DDV_MinMaxDouble(pDX, ReturnNoise, 0, 320);

	DDX_Text(pDX, IDC_EDIT5, CurrentScoreStr);
	DDX_Text(pDX, IDC_EDIT4, BestScoreStr);
}

BEGIN_MESSAGE_MAP(CMFCApplication11564651567Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_EN_CHANGE(IDC_EDIT2, &CMFCApplication11564651567Dlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CMFCApplication11564651567Dlg::OnEnChangeEdit3)

	ON_CBN_SELCHANGE(IDC_COMBO1, &CMFCApplication11564651567Dlg::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CMFCApplication11564651567Dlg::OnCbnSelchangeCombo2)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CMFCApplication11564651567Dlg::OnCbnSelchangeCombo3)
	ON_CBN_SELCHANGE(IDC_COMBO4, &CMFCApplication11564651567Dlg::OnCbnSelchangeCombo4)
	ON_CBN_SELCHANGE(IDC_COMBO5, &CMFCApplication11564651567Dlg::OnCbnSelchangeCombo5)

	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()

	ON_WM_TIMER()

	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication11564651567Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication11564651567Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication11564651567Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication11564651567Dlg::OnBnClickedButton5)

END_MESSAGE_MAP()


// CMFCApplication11564651567Dlg message handlers

BOOL CMFCApplication11564651567Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	CPaintDC dc(this);
	myGame = new Game; // Create Game On Run

	// Build Combo Box
	ColorsCombo(LeftWallComboControl);
	ColorsCombo(RightWallComboBox);
	ColorsCombo(UpperWallComboBox);
	ColorsCombo(BallComboBox);
	ColorsCombo(RacquetComboBox);

	// Current Parameter On Combo Box
	LeftWallComboControl.SetCurSel(myGame->getParams().getLeftColor());
	RightWallComboBox.SetCurSel(myGame->getParams().getRightColor());
	UpperWallComboBox.SetCurSel(myGame->getParams().getUpperColor());
	BallComboBox.SetCurSel(myGame->getParams().getBallColor());
	RacquetComboBox.SetCurSel(myGame->getParams().getRacquetColor());
	Invalidate();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication11564651567Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication11564651567Dlg::OnPaint()
{
	CPaintDC dc(this);

	// Draw Left Wall
	CPen pen1(PS_SOLID, WALL_WIDTH, RGB(color[myGame->getParams().getLeftColor()][0],
		color[myGame->getParams().getLeftColor()][1],
		color[myGame->getParams().getLeftColor()][2]));
	dc.SelectObject(&pen1);
	Draw_Line(dc, &(myGame->getLeftWall()));

	// Draw Upper Wall
	CPen pen2(PS_SOLID, WALL_WIDTH , RGB(color[myGame->getParams().getUpperColor()][0],
		color[myGame->getParams().getUpperColor()][1],
		color[myGame->getParams().getUpperColor()][2]));
	dc.SelectObject(&pen2);
	Draw_Line(dc, &(myGame->getUpperWall()));

	// Draw Right Wall
	CPen pen3(PS_SOLID, WALL_WIDTH, RGB(color[myGame->getParams().getRightColor()][0],
		color[myGame->getParams().getRightColor()][1],
		color[myGame->getParams().getRightColor()][2]));
	dc.SelectObject(&pen3);
	Draw_Line(dc, &(myGame->getRightWall()));

	// Draw Goal Wall = ALWAYS GRAY!!
	CPen pen4(PS_SOLID, WALL_WIDTH, RGB(color[myGame->getInvisibleWall().getcolor()][0],
		color[myGame->getInvisibleWall().getcolor()][1],
		color[myGame->getInvisibleWall().getcolor()][2]));
	dc.SelectObject(&pen4);
	Draw_Line(dc, &(myGame->getInvisibleWall()));

	// Draw Racquet
	CPen pen5(PS_SOLID, WALL_WIDTH/2, RGB(color[myGame->getParams().getRacquetColor()][0],
		color[myGame->getParams().getRacquetColor()][1],
		color[myGame->getParams().getRacquetColor()][2]));
	dc.SelectObject(&pen5);
	Draw_Line(dc, &(myGame->getRacquetWall()));

	// Draw Ball
	CPen pen6(PS_SOLID, WALL_WIDTH / 2, RGB(color[myGame->getParams().getBallColor()][0],
		color[myGame->getParams().getBallColor()][1],
		color[myGame->getParams().getBallColor()][2]));
	dc.SelectObject(&pen6);
	Draw_Ball(dc, myGame->getBall());
}


// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication11564651567Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// Set Ball Velocity By The User --> BALL VELOCITY EDIT BOX
void CMFCApplication11564651567Dlg::OnEnChangeEdit2()
{
	UpdateData(TRUE);
	myGame->getParams().setVelocity(Velocity);
	myGame->getBall().setVelocity(Velocity);
	UpdateData(FALSE);
}

// Set Noise Of Return Angle By The User --> RETURN NOISE ANGLE EDIT BOX
void CMFCApplication11564651567Dlg::OnEnChangeEdit3()
{
	UpdateData(TRUE);
	myGame->getParams().setRetnoise(ReturnNoise);
	UpdateData(FALSE);
}

// Set Left Wall Color By The User --> LEFT WALL COMBO BOX
void CMFCApplication11564651567Dlg::OnCbnSelchangeCombo1()
{
	UpdateData(TRUE);
	myGame->getParams().setLeftColor(LeftWallComboValue);
	RacquetComboBox.SetCurSel((myGame->getParams()).getLeftColor());
	UpdateData(FALSE);
}

// Set Right Wall Color By The User --> RIGHT WALL COMBO BOX
void CMFCApplication11564651567Dlg::OnCbnSelchangeCombo2()
{
	UpdateData(TRUE);
	myGame->getParams().setRightColor(RightWallComboValue);
	RacquetComboBox.SetCurSel((myGame->getParams()).getRightColor());
	UpdateData(FALSE);
}

// Set Upper Wall Color By The User --> UPPER WALL COMBO BOX
void CMFCApplication11564651567Dlg::OnCbnSelchangeCombo3()
{
	UpdateData(TRUE);
	myGame->getParams().setUpperColor(UpperWallComboValue);
	RacquetComboBox.SetCurSel((myGame->getParams()).getUpperColor());
	UpdateData(FALSE);
}

// Set Racquet Color By The User --> RACQUET COMBO BOX
void CMFCApplication11564651567Dlg::OnCbnSelchangeCombo4()
{
	UpdateData(TRUE);
	(myGame->getParams()).setRacquetColor(RacquetComboValue);
	RacquetComboBox.SetCurSel((myGame->getParams()).getRacquetColor());
	UpdateData(FALSE);}

// Set Ball Color By The User --> BALL COMBO BOX
void CMFCApplication11564651567Dlg::OnCbnSelchangeCombo5()
{
	UpdateData(TRUE);
	myGame->getParams().setBallColor(BallComboValue);
	RacquetComboBox.SetCurSel((myGame->getParams()).getBallColor());
	UpdateData(FALSE);
}

// Calculate And Display Next Move, Stops On Goal
void CMFCApplication11564651567Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// If Goal
	if (myGame->Move(CurrentScore, BestScore))
	{
		End_Of_Game = true;
	}

	// Score Set
	UpdateData(TRUE);
	CurrentScoreStr.Format(_T("%d"), CurrentScore);
	BestScoreStr.Format(_T("%d"), BestScore);
	UpdateData(FALSE);

	// Kill Timer On Goal
	if (End_Of_Game)
		KillTimer(nIDEvent);

	Invalidate();
}

// Move Racquet Left
void CMFCApplication11564651567Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	isPressed = true;

	myGame->getRacquetWall().MoveLeftRight(-1);

	if (myGame->getRacquetWall().getX1() < 0)
	{
		myGame->getRacquetWall().MoveLeftRight(-(myGame->getRacquetWall().getX1()));
	}

	Invalidate();
}

// Move Racquet Right
void CMFCApplication11564651567Dlg::OnRButtonUp(UINT nFlags, CPoint point)
{
	isPressed = true;

	myGame->getRacquetWall().MoveLeftRight(1);

	double exceed = (myGame->getRacquetWall().getX2() - myGame->getParams().getWidth());

	if (exceed > 0)
	{
		myGame->getRacquetWall().MoveLeftRight(-exceed);
	}

	Invalidate();
}

// Save Parameters To File --> SAVE GAME BUTTON
void CMFCApplication11564651567Dlg::OnBnClickedButton2()
{
	CFile file(_T("Saved Parameters.$$"), CFile::modeWrite | CFile::modeCreate);
	CArchive ar(&file, CArchive::store);
	myGame->getParams().serialize(ar);
	ar.Close();
	file.Close();
}

// Load Parameters From File --> LOAD GAME BUTTON
void CMFCApplication11564651567Dlg::OnBnClickedButton3()
{
	CFile file(_T("Saved Parameters.$$"), CFile::modeRead);
	CArchive ar(&file, CArchive::load);
	myGame->getParams().serialize(ar); 

	UpdateData(TRUE);
	LeftWallComboValue = myGame->getParams().getLeftColor();
	RightWallComboValue = myGame->getParams().getRightColor();
	UpperWallComboValue = myGame->getParams().getUpperColor();
	RacquetComboValue = myGame->getParams().getRacquetColor();
	BallComboValue = myGame->getParams().getBallColor();
	Velocity = myGame->getParams().getVelocity();
	myGame->getBall().setVelocity(Velocity);
	ReturnNoise = myGame->getParams().getRetnoise();
	UpdateData(FALSE);
}

// START GAME BUTTON
void CMFCApplication11564651567Dlg::OnBnClickedButton1()
{
	if (End_Of_Game)
	{
		End_Of_Game = false;
		SetTimer(9876, (int)deltaT * 1000, NULL);
	}
}

// NEW GAME BUTTON
void CMFCApplication11564651567Dlg::OnBnClickedButton5()
{
	delete myGame; // Delete All Game Objects

	myGame = new Game; // Create New Game

	// Restore Default Parameters Values
	UpdateData(TRUE);
	LeftWallComboValue = myGame->getParams().getLeftColor();
	RightWallComboValue = myGame->getParams().getLeftColor();
	UpperWallComboValue = myGame->getParams().getLeftColor();
	RacquetComboValue = myGame->getParams().getLeftColor();
	BallComboValue = myGame->getParams().getLeftColor();
	Velocity = myGame->getParams().getVelocity();
	myGame->getBall().setVelocity(Velocity);
	ReturnNoise = myGame->getParams().getRetnoise();
	UpdateData(FALSE);

	End_Of_Game = true; // Stop Game
	Invalidate();
}
