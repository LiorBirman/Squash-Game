
// MFCApplication11564651567Dlg.h : header file
//

#pragma once
#include "Game.h"	

#define SHIFT 30 // Add 30 to Walls position	

// CMFCApplication11564651567Dlg dialog
class CMFCApplication11564651567Dlg : public CDialogEx
{
// Construction
public:
	void Draw_Ball(CPaintDC & dc, Ball & ball);
	void Draw_Line(CPaintDC & dc, Wall * wall);
	CMFCApplication11564651567Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION11564651567_DIALOG };
#endif
	bool isPressed;
	CPoint startP;
	CPoint endP;

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	int Draw_Type = 0;
	Game* myGame;
public:

	  afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	  afx_msg void OnRButtonUp(UINT nFlags, CPoint point);

	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnCbnSelchangeCombo3();
	afx_msg void OnCbnSelchangeCombo4();
	afx_msg void OnCbnSelchangeCombo5();

	double Velocity;
	double ReturnNoise;

	int CurrentScore;
	int BestScore;

	CComboBox LeftWallComboControl;
	int LeftWallComboValue = 0;

	CComboBox RightWallComboBox;
	int RightWallComboValue = 0;

	CComboBox UpperWallComboBox;
	int UpperWallComboValue = 0;

	CComboBox RacquetComboBox;
	int RacquetComboValue = 0;

	CComboBox BallComboBox;
	int BallComboValue = 0;


	afx_msg void OnTimer(UINT_PTR nIDEvent);

	CString CurrentScoreStr;
	CString BestScoreStr;

	bool End_Of_Game = true;
	bool Loaded = 0;
};
